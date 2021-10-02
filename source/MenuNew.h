#pragma once
#define MENUSETTINGS_VERSION 0.01
#define MENU_OPEN_CLOSE_WAIT_TIME 500
#define MENU_SCREEN_CHANGE_WAIT_TIME 250

#include "PadNew.h"

class CSprite2d;

enum eMouseType : char {
    MOUSE_ARROW,
    MOUSE_FUCKU,
    MOUSE_GRAB,
    MOUSE_HAND,
};

enum eMenuSprites {
    MENU_MOUSE_ARROW,
    MENU_MOUSE_FUCKU,
    MENU_MOUSE_GRAB,
    MENU_MOUSE_HAND, 
    MENU_ROCKSTARLOGO256,
    MENU_XBOX_GAMEPAD,
    MENU_ARROW_LEFT,
    MENU_ARROW_RIGHT,
    NUM_MENU_SPRITES,
};

enum eMiscSprites {
    MISC_RECTGRAD,
    MISC_RECTGRADCENTERED,
    MISC_SKIPICON,
    MISC_SPINNER,
    NUM_MISC_SPRITES,
};

enum eLandingSprites {
    LANDING_BACK_0,
    LANDING_FRONT_0,
    NUM_LANDING_SPRITES
};

enum eLandingScreenshotSprites {
    INFOSCREEN_0,
    NUM_SCREENSHOTS_SPRITES
};

enum eMenuBarItems {
    MENUBAR_MAP,
    MENUBAR_BRIEF,
    MENUBAR_STATS,
    MENUBAR_SETTINGS,
    MENUBAR_GAME,
    MENUBAR_GALLERY,
};

enum eMenuScreens {
    MENUSCREEN_NONE,
    MENUSCREEN_MAP,
    MENUSCREEN_BRIEF,
    MENUSCREEN_STATS,
    MENUSCREEN_SETTINGS,
    MENUSCREEN_GAME,
    MENUSCREEN_GALLERY,
    MENUSCREEN_LANDING,
    MENUSCREEN_SAVE,
    NUM_MENUSCREENS
};

enum eMenuEntries {
    MENUENTRY_NONE = 0,
    MENUENTRY_CHANGETAB,
    MENUENTRY_SCREENTYPE,
    MENUENTRY_CHANGERES,
    MENUENTRY_ASPECTRATIO,
    MENUENTRY_MIPMAPPING,
    MENUENTRY_REFRESHRATE,
    MENUENTRY_MSAA,
    MENUENTRY_FRAMELIMITER,
    MENUENTRY_DRAWDISTANCE,
    MENUENTRY_VISUALQUALITY,
    MENUENTRY_SFXVOLUME,
    MENUENTRY_RADIOVOLUME,
    MENUENTRY_RADIOSTATION,
    MENUENTRY_RADIOAUTOSELECT,
    MENUENTRY_RADIOEQ,
    MENUENTRY_TRACKSAUTOSCAN,
    MENUENTRY_RADIOMODE,
    MENUENTRY_MOUSESENSITIVITY,
    MENUENTRY_INVERTMOUSEY,
    MENUENTRY_MOUSESTEER,
    MENUENTRY_MOUSEFLYING,
    MENUENTRY_INVERTPADX1,
    MENUENTRY_INVERTPADY1,
    MENUENTRY_INVERTPADX2,
    MENUENTRY_INVERTPADY2,
    MENUENTRY_SWAPPADAXIS1,
    MENUENTRY_SWAPPADAXIS2,
    MENUENTRY_BRIGHTNESS,
    MENUENTRY_GAMMA,
    MENUENTRY_SHOWHUD,
    MENUENTRY_SHOWRADAR,
    MENUENTRY_GPSROUTE,
    MENUENTRY_SAFEZONESIZE,
    MENUENTRY_MEASUREMENTSYS,
    MENUENTRY_SUBTITLES,
    MENUENTRY_RESTOREDEFAULTS,
    MENUENTRY_LANDINGPAGE,
    MENUENTRY_LOADGAME,
    MENUENTRY_NUMOFSAVEGAMES,
    MENUENTRY_ACTION,
    MENUENTRY_PAD,
    MENUENTRY_GFX,
    MENUENTRY_POPULATESAVESLOT,
    MENUENTRY_SAVEGAME,
    MENUENTRY_STORYMODE,
    MENUENTRY_SETTINGS,
    MENUENTRY_QUIT,
};

enum eMenuMessages {
    MENUMESSAGE_NONE,
    MENUMESSAGE_NEW_GAME,
    MENUMESSAGE_LOAD_GAME,
    MENUMESSAGE_SAVE_GAME,
    MENUMESSAGE_EXIT_GAME,
    MENUMESSAGE_DELETE_GAME,
    MENUMESSAGE_LOSE_CHANGES_ASK,
};

enum {
    MAX_MENU_BAR_ITEMS = 12,
    MAX_MENU_SCREENS = 12,
    MAX_MENU_TABS = 32,
    MAX_MENU_ENTRIES = 32,
    MAX_HELP_TEXT = 8,
};

enum {
    MENU_HOVER_NONE = -1,
};

enum {
    MENUINPUT_BAR = 1,
    MENUINPUT_TAB, 
    MENUINPUT_ENTRY,
    MENUINPUT_MESSAGE,
};

enum eSettingsIndex {
    SETTINGS_GAMEPAD,
    SETTINGS_KEYBOARD,
    SETTINGS_AUDIO,
    SETTINGS_DISPLAY,
    SETTINGS_GRAPHICS,
    SETTINGS_SAVINGANDSTARTUP,
    NUM_SETTINGS,
};

enum eMenuAlerts {
    MENUALERT_NONE,
    MENUALERT_PENDINGCHANGES,
};

enum eHelpTextType {
    HELP_TEXT_NONE,
    HELP_TEXT_SELECT,
    HELP_TEXT_BACK,
};

/*
-MENUBAR:
     _________________   _________________
    |       MAP       | |      BRIEF      |

-SCREEN:
   -MENUTAB:          -MENUENTRY:

    DISPLAY  |         Resolution: 1920x1080x32
    GRAPHICS |         Aspect Ratio: Auto
    AUDIO    |
*/

class CMenuBar {
public:
    char barName[16];
    int targetScreen;

public:
    inline CMenuBar* AddItem(char* name, int screen) {
        strcpy(barName, name);
        targetScreen = screen;
        return this;
    }
};

class CMenuEntry {
public:
    int type;
    char entryName[16];
    int x;
    int y;

public:
    inline CMenuEntry* AddEntry(int _type, char* _entryName, int _x, int _y) {
        type = _type;
        strcpy(entryName, _entryName);
        x = _x;
        y = _y;
        return this;
    }
};

class CMenuTab {
public:
    int type;
    char tabName[16];
    char actionName[16];
    CMenuEntry Entries[MAX_MENU_ENTRIES]; 
    bool full;

public:
    inline void AddTab(int _type, char* _tabName, char* _actionName, bool _full) {
        type = _type;
        strcpy(tabName, _tabName);
        if (_actionName)
            strcpy(actionName, _actionName);
        full = _full;
    }
};

class CMenuScreen {
public:
    char screenName[16];
    CMenuTab Tab[MAX_MENU_TABS];

public:
    inline void AddScreen(char* _screenName) {
        strcpy(screenName, _screenName);
    }
};

class CMenuSettings {
public:
    // Keyboard & Mouse
    float mouseSensitivity;
    bool invertMouseY;
    bool mouseSteering;
    bool mouseFlying;

    // Gamepad
    int controller;
    bool invertPadX1;
    bool invertPadY1;
    bool invertPadX2;
    bool invertPadY2;
    bool swapPadAxis1;
    bool swapPadAxis2;

    // Audio
    char sfxVolume;
    char radioVolume;
    char radioStation;
    bool radioAutoSelect;
    bool radioEQ;
    bool tracksAutoScan;
    char radioMode;

    // Display
    int brightness;
    float gamma;
    bool subtitles;
    int language;
    bool showHUD;
    bool showRadar;
    bool savePhotos;
    bool mapLegend;
    bool gpsRoute;
    float safeZoneSize;
    int measurementSys;

    // Graphics
    int screenType;
    int videoMode;
    int aspectRatio;
    bool mipMapping;
    int antiAliasing;
    float drawDist;
    int visualQuality;
    bool widescreen;
    bool frameLimiter;

    // Saving and Startup
    bool landingPage;
    int saveSlot;

    // Misc
    char uiMainColor[32];

public:
    void Clear();
    void Load();
    void Save();
};

class CMenuNew {
public:
    CSprite2d* MenuSprites[NUM_MENU_SPRITES];
    CSprite2d* MiscSprites[NUM_MISC_SPRITES];
    CSprite2d* LandingSprites[NUM_LANDING_SPRITES];
    CSprite2d* InfoScreensSprites[NUM_SCREENSHOTS_SPRITES];

    CMenuSettings TempSettings;
    CMenuSettings Settings;
    CMenuBar MenuBar[MAX_MENU_BAR_ITEMS];
    CMenuScreen MenuScreen[MAX_MENU_SCREENS];

public:
    bool bInitialised;
    char nMouseType;
    bool bDrawMouse;
    CVector2D vMousePos;
    CVector2D vOldMousePos;

    bool bMenuActive;

    bool bShowMenu;

    int nPreviousInputType;
    int nCurrentInputType;

    int nCurrentBarItem;
    int nPreviousBarItem;

    int nCurrentBarItemHover;
    int nPreviousBarItemHover;

    int nCurrentTabItem;
    int nPreviousTabItem;
    int nCurrentTabItemHover;
    int nPreviousTabItemHover;

    int nCurrentEntryItem;
    int nPreviousEntryItem;
    int nCurrentEntryItemHover;
    int nPreviousEntryItemHover;

    int nCurrentScreen;
    int nPreviousScreen;

    bool bRequestScreenUpdate;
    float fScreenAlpha;
    unsigned int nLoadingTime;

    unsigned int nOpenCloseWaitTime;

    unsigned int nUsedVidMemory;
    unsigned int nFreeVidMemory;

    bool bRadioEnabled;

    int nCurrentMessage;
    int nPreviousMessage;

    int nMenuAlert;

    bool bShowMenuExtraText;
    bool bShowMenuBar;
    bool bNoTransparentBackg;
    bool bStylizedBackground;

    bool bLandingPage;
    bool bInvertInput;

    int nNumOfSaveGames;
    bool bSaveSlotsPopulated;

    char nSaveSlots[9][64];
    char nSaveSlotsDate[9][32];

    bool bHelpText;
    int nHelpTextCount;

    struct {
        char type;
    } nHelpTextType[MAX_HELP_TEXT];

    bool bSavePage;

    bool bRequestMenuClose;

public:
    CMenuNew();
    void Init();
    void Shutdown();
    void Clear();
    void BuildMenuBar();
    void BuildMenuScreen();

    void DrawBackground();

    void SetLandingPageBehaviour();
    void SetSavePageBehaviour();
    void SetDefaultPageBehaviour();

    void AddNewBarItem(char* name, int screen);
    CMenuScreen* AddNewScreen(char* name);
    CMenuTab* AddNewTab(CMenuScreen* s, int type, char* tabName, char* actionName, bool full);
    CMenuEntry* AddNewEntry(CMenuTab* t, int type, char* entryName, int x, int y);

    void SetInputTypeAndClear(int input, int n);
    int GetLastMenuBarItem();
    int GetLastMenuScreenTab();
    int GetFirstMenuScreenEntry();
    int GetLastMenuScreenEntry();
    bool HasToContinueLoop(int i);
    bool HasToContinueLoopInverse(int i);
    int GetEntryBackHeight();
    void OpenCloseMenu(bool on, bool force);
    void OpenMenuScreen(int screen);
    void CenterCursor();
    void Process();
    unsigned int GetTimeInMillisecondsRight();
    unsigned char FadeIn(unsigned char alpha);
    void ProcessTabStuff();
    void DoSettingsBeforeStartingAGame(bool load, int slot = -1);
    void DoStuffBeforeSavingAGame(int slot);
    void ProcessMessagesStuff(int enter, int esc, int space, int input);
    void ProcessAlertStuff();
    void ProcessEntryStuff(int enter, int input);
    void StartRadio();
    void StopRadio();
    void CheckSliderMovement(double value);
    void DrawPauseMenuExtraText();
    void Draw();
    void AppendHelpText(int type);
    void SetMenuMessage(int type);
    void UnSetMenuMessage();
    bool IsLoading();
    int GetNumOfSaveGames();
    void DrawDefault();
    void DrawTabMemoryAvailable();
    void DrawTabGamePad();
    void DrawTabNumSaveGames();
    void DrawLandingPage();
    void DrawSliderRightAlign(float x, float y, float progress);
    void DrawTabRadioIcons(float x, float y);
    void DrawSpinningWheel(float x, float y, float w, float h);
    void DrawMap();
    void DrawPatternBackground(CRect rect, CRGBA col);
    void DrawGallery();
    bool CheckHover(int x1, int x2, int y1, int y2);

public:
    static void PassSettingsToCurrentGame(const CMenuSettings* s);
    void FindOutUsedMemory();
    void ChangeVideoMode(int mode, int msaa);
    void ApplyGraphicsChanges();
    void ApplyChanges();
    void RestorePreviousSettings();
    void RestoreDefaults(int index);
};

extern CMenuNew MenuNew;
