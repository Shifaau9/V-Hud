#include "VHud.h"
#include "Audio.h"
#include "CellPhone.h"
#include "HudColoursNew.h"
#include "PadNew.h"
#include "FontNew.h"
#include "GPS.h"
#include "HudNew.h"
#include "MenuNew.h"
#include "MenuPanels.h"
#include "OverlayLayer.h"
#include "RadarNew.h"
#include "RadioHud.h"
#include "TextureMgr.h"
#include "Utility.h"
#include "WeaponSelector.h"

#include "VHudAPI.h"

using namespace plugin;

VHud pluginVHud;

inline int OpenConsole(bool console) {
    if (!freopen("conin$", "r", stdin))
        return false;

    if (!freopen("conout$", "w", stdout))
        return false;

    if (!freopen("conout$", "w", stderr))
        return false;

    return false;
}

VHud::VHud() {
    //OpenConsole(AllocConsole());

    if (!IsSupportedGameVersion())
        Error("This version of GTA: San Andreas is not supported by this plugin.");

    Events::initRwEvent += [] {
        Audio.Init();
        HudColourNew.ReadColorsFromFile();
        CFontNew::Init();
        MenuNew.Init();
        CRadioHud::Init();
        COverlayLayer::Init();
    };

    Events::initGameEvent += [] {
        CGPS::Init();
        CHudNew::Init();
        CellPhone.Init();
        CRadarNew::Init();
        CWeaponSelector::Init();
        CMenuPanels::Init();
    };

    Events::reInitGameEvent += [] {
        CHudNew::ReInit();
        CWeaponSelector::ReInit();
    };

    CdeclEvent<AddressList<0x53EB9D, H_CALL>, PRIORITY_BEFORE, ArgPickNone, void()> beforeFading;
    beforeFading += [] {
        CHudNew::Draw();
    };

    CdeclEvent<AddressList<0x53EB9D, H_CALL>, PRIORITY_AFTER, ArgPickNone, void()> afterFading;
    afterFading += [] {
        CHudNew::DrawAfterFade();
    };

    Events::shutdownRwEvent += [] {
        MenuNew.Shutdown();
        CGPS::Shutdown();
        CRadarNew::Shutdown();
        CHudNew::Shutdown();
        CellPhone.Shutdown();
        CRadioHud::Shutdown();
        COverlayLayer::Shutdown();
        CFontNew::Shutdown();
        CWeaponSelector::Shutdown();
        CMenuPanels::Shutdown();
        Audio.Shutdown();
    };
}
