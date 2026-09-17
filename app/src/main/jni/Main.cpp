#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <jni.h>
#include <string>
#include <fstream>

// ==========================================
// VARIAVEIS DA CATEGORIA: GENERAL
// ==========================================
bool showKeybinds = false;
bool allowKeybindsChat = false;
bool clickThroughMenu = false;
bool extraCommands = false;
bool showMenuStartup = false;
bool panicWarning = false;
bool autoExitLowFps = false;
int minimumFps = 30;
bool setAccountName = false;
bool autoSetName = false;
bool replaceStreamerCode = false;
bool rgbLobbyCode = false;
bool unlockCosmetics = false;
bool unlockAchievements = false;
bool showModUsers = false;

// ==========================================
// VARIAVEIS DA CATEGORIA: SPOOFING
// ==========================================
bool spoofGuest = false;
bool customFriendCode = false;
int spoofLevel = 1;
bool spoofPlatform = false;
bool spoofPsnId = false;
bool spoofXboxId = false;
bool reduceAnticheat = false;

// ==========================================
// VARIAVEIS DA CATEGORIA: CUSTOMIZATION
// ==========================================
bool hideWatermark = false;
bool hideModStamp = false;
bool menuThemeColor = false;
bool gradientTheme1 = false;
bool gradientTheme2 = false;
bool matchBackground = false;
bool rgbMenuTheme = false;
int opacityValue = 100;
bool darkGameTheme = false;
bool customGameTheme = false;
bool changeChatFont = false;
bool showFps = false;
bool showTime = false;
bool lightMode = false;
bool showUiBorders = false;
int menuScale = 100;
bool disableAnimations = false;
int animationSpeed = 5;
int roundingRadius = 5;
bool roleColors = false;
bool otherColors = false;

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_android_support_Menu_getFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;
    const char *features[] = {
        "Category_General", // Index 0
        "Toggle_Show Keybinds", // Index 1
        "Toggle_Allow Activating Keybinds while Chatting", // 2
        "Toggle_Allow Clicking Through Menu UIs", // 3
        "Toggle_Extra Commands", // 4
        "Toggle_Always Show Menu on Startup", // 5
        "Toggle_Panic Warning", // 6
        "Button_Config", // 7
        "Toggle_Auto-Exit Due To Low FPS", // 8
        "SeekBar_Minimum FPS_10_60", // 9
        "Toggle_Set As Account Name", // 10
        "Button_Set Name", // 11
        "Toggle_Automatically Set Name", // 12
        "Button_Custom Code", // 13
        "Toggle_Replace Streamer Mode Lobby Code", // 14
        "Toggle_RGB Lobby Code", // 15
        "Toggle_Unlock Cosmetics", // 16
        "Toggle_Unlock All Achievements", // 17
        "Toggle_Allow other mod users to see you're using SickoMenu", // 18

        "Category_Spoofing", // Index 19
        "Toggle_Spoof Guest Account (Quick Chat ONLY)", // 20
        "Toggle_Use Custom Friend Code (For New/Guest Account ONLY)", // 21
        "SeekBar_Spoof Level_1_100", // 22
        "Toggle_Spoof Platform", // 23
        "Toggle_Spoof PSN Platform ID", // 24
        "Toggle_Spoof Xbox Platform ID", // 25
        "Toggle_Reduce Anticheat While Hosting (+25 Mode)", // 26

        "Category_Customization", // Index 27
        "Toggle_Hide Watermark", // 28
        "Toggle_Hide Mod Stamp", // 29
        "Toggle_Menu Theme Color", // 30
        "Toggle_Gradient Theme", // 31
        "Toggle_Gradient Theme (Alternate)", // 32
        "Toggle_Match Background with Theme", // 33
        "Toggle_RGB Menu Theme", // 34
        "Button_Reset Menu Theme", // 35
        "SeekBar_Opacity_10_100", // 36
        "Toggle_Dark Game Theme", // 37
        "Toggle_Custom Game Theme", // 38
        "Toggle_Change Chat Font", // 39
        "Toggle_Show FPS", // 40
        "Toggle_Show Time", // 41
        "Toggle_Light Mode", // 42
        "Toggle_Show UI Borders", // 43
        "SeekBar_Menu Scale_50_150", // 44
        "Toggle_Disable Animations", // 45
        "SeekBar_Animation Speed_1_10", // 46
        "SeekBar_Rounding Radius Multiplier_1_10", // 47
        "Toggle_Role Colors", // 48
        "Toggle_Other Colors" // 49
    };
    
    int Total_Feature = sizeof(features) / sizeof(features[0]);
    ret = (jobjectArray) env->NewObjectArray(Total_Feature, env->FindClass("java/lang/String"), env->NewStringUTF(""));
    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
    return ret;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_android_support_Preferences_changes(JNIEnv *env, jclass clazz, jobject obj, jint feature, jint value, jboolean boolean, jstring str) {
    switch (feature) {
        // GENERAL
        case 1: showKeybinds = boolean; break;
        case 2: allowKeybindsChat = boolean; break;
        case 3: clickThroughMenu = boolean; break;
        case 4: extraCommands = boolean; break;
        case 5: showMenuStartup = boolean; break;
        case 6: panicWarning = boolean; break;
        case 8: autoExitLowFps = boolean; break;
        case 9: minimumFps = value; break;
        case 10: setAccountName = boolean; break;
        case 12: autoSetName = boolean; break;
        case 14: replaceStreamerCode = boolean; break;
        case 15: rgbLobbyCode = boolean; break;
        case 16: unlockCosmetics = boolean; break;
        case 17: unlockAchievements = boolean; break;
        case 18: showModUsers = boolean; break;

        // SPOOFING
        case 20: spoofGuest = boolean; break;
        case 21: customFriendCode = boolean; break;
        case 22: spoofLevel = value; break;
        case 23: spoofPlatform = boolean; break;
        case 24: spoofPsnId = boolean; break;
        case 25: spoofXboxId = boolean; break;
        case 26: reduceAnticheat = boolean; break;

        // CUSTOMIZATION
        case 28: hideWatermark = boolean; break;
        case 29: hideModStamp = boolean; break;
        case 30: menuThemeColor = boolean; break;
        case 31: gradientTheme1 = boolean; break;
        case 32: gradientTheme2 = boolean; break;
        case 33: matchBackground = boolean; break;
        case 34: rgbMenuTheme = boolean; break;
        case 36: opacityValue = value; break;
        case 37: darkGameTheme = boolean; break;
        case 38: customGameTheme = boolean; break;
        case 39: changeChatFont = boolean; break;
        case 40: showFps = boolean; break;
        case 41: showTime = boolean; break;
        case 42: lightMode = boolean; break;
        case 43: showUiBorders = boolean; break;
        case 44: menuScale = value; break;
        case 45: disableAnimations = boolean; break;
        case 46: animationSpeed = value; break;
        case 47: roundingRadius = value; break;
        case 48: roleColors = boolean; break;
        case 49: otherColors = boolean; break;
    }
}
