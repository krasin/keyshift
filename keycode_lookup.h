#include <linux/input-event-codes.h>

#include <iostream>

// clang-format off
std::string keyCodeToString(int key_code) {
  switch (key_code) {
    case KEY_RESERVED: return "KEY_RESERVED";
    case KEY_ESC: return "KEY_ESC";
    case KEY_1: return "KEY_1";
    case KEY_2: return "KEY_2";
    case KEY_3: return "KEY_3";
    case KEY_4: return "KEY_4";
    case KEY_5: return "KEY_5";
    case KEY_6: return "KEY_6";
    case KEY_7: return "KEY_7";
    case KEY_8: return "KEY_8";
    case KEY_9: return "KEY_9";
    case KEY_0: return "KEY_0";
    case KEY_MINUS: return "KEY_MINUS";
    case KEY_EQUAL: return "KEY_EQUAL";
    case KEY_BACKSPACE: return "KEY_BACKSPACE";
    case KEY_TAB: return "KEY_TAB";
    case KEY_Q: return "KEY_Q";
    case KEY_W: return "KEY_W";
    case KEY_E: return "KEY_E";
    case KEY_R: return "KEY_R";
    case KEY_T: return "KEY_T";
    case KEY_Y: return "KEY_Y";
    case KEY_U: return "KEY_U";
    case KEY_I: return "KEY_I";
    case KEY_O: return "KEY_O";
    case KEY_P: return "KEY_P";
    case KEY_LEFTBRACE: return "KEY_LEFTBRACE";
    case KEY_RIGHTBRACE: return "KEY_RIGHTBRACE";
    case KEY_ENTER: return "KEY_ENTER";
    case KEY_LEFTCTRL: return "KEY_LEFTCTRL";
    case KEY_A: return "KEY_A";
    case KEY_S: return "KEY_S";
    case KEY_D: return "KEY_D";
    case KEY_F: return "KEY_F";
    case KEY_G: return "KEY_G";
    case KEY_H: return "KEY_H";
    case KEY_J: return "KEY_J";
    case KEY_K: return "KEY_K";
    case KEY_L: return "KEY_L";
    case KEY_SEMICOLON: return "KEY_SEMICOLON";
    case KEY_APOSTROPHE: return "KEY_APOSTROPHE";
    case KEY_GRAVE: return "KEY_GRAVE";
    case KEY_LEFTSHIFT: return "KEY_LEFTSHIFT";
    case KEY_BACKSLASH: return "KEY_BACKSLASH";
    case KEY_Z: return "KEY_Z";
    case KEY_X: return "KEY_X";
    case KEY_C: return "KEY_C";
    case KEY_V: return "KEY_V";
    case KEY_B: return "KEY_B";
    case KEY_N: return "KEY_N";
    case KEY_M: return "KEY_M";
    case KEY_COMMA: return "KEY_COMMA";
    case KEY_DOT: return "KEY_DOT";
    case KEY_SLASH: return "KEY_SLASH";
    case KEY_RIGHTSHIFT: return "KEY_RIGHTSHIFT";
    case KEY_KPASTERISK: return "KEY_KPASTERISK";
    case KEY_LEFTALT: return "KEY_LEFTALT";
    case KEY_SPACE: return "KEY_SPACE";
    case KEY_CAPSLOCK: return "KEY_CAPSLOCK";
    case KEY_F1: return "KEY_F1";
    case KEY_F2: return "KEY_F2";
    case KEY_F3: return "KEY_F3";
    case KEY_F4: return "KEY_F4";
    case KEY_F5: return "KEY_F5";
    case KEY_F6: return "KEY_F6";
    case KEY_F7: return "KEY_F7";
    case KEY_F8: return "KEY_F8";
    case KEY_F9: return "KEY_F9";
    case KEY_F10: return "KEY_F10";
    case KEY_NUMLOCK: return "KEY_NUMLOCK";
    case KEY_SCROLLLOCK: return "KEY_SCROLLLOCK";
    case KEY_KP7: return "KEY_KP7";
    case KEY_KP8: return "KEY_KP8";
    case KEY_KP9: return "KEY_KP9";
    case KEY_KPMINUS: return "KEY_KPMINUS";
    case KEY_KP4: return "KEY_KP4";
    case KEY_KP5: return "KEY_KP5";
    case KEY_KP6: return "KEY_KP6";
    case KEY_KPPLUS: return "KEY_KPPLUS";
    case KEY_KP1: return "KEY_KP1";
    case KEY_KP2: return "KEY_KP2";
    case KEY_KP3: return "KEY_KP3";
    case KEY_KP0: return "KEY_KP0";
    case KEY_KPDOT: return "KEY_KPDOT";

    case KEY_ZENKAKUHANKAKU: return "KEY_ZENKAKUHANKAKU";
    case KEY_102ND: return "KEY_102ND";
    case KEY_F11: return "KEY_F11";
    case KEY_F12: return "KEY_F12";
    case KEY_RO: return "KEY_RO";
    case KEY_KATAKANA: return "KEY_KATAKANA";
    case KEY_HIRAGANA: return "KEY_HIRAGANA";
    case KEY_HENKAN: return "KEY_HENKAN";
    case KEY_KATAKANAHIRAGANA: return "KEY_KATAKANAHIRAGANA";
    case KEY_MUHENKAN: return "KEY_MUHENKAN";
    case KEY_KPJPCOMMA: return "KEY_KPJPCOMMA";
    case KEY_KPENTER: return "KEY_KPENTER";
    case KEY_RIGHTCTRL: return "KEY_RIGHTCTRL";
    case KEY_KPSLASH: return "KEY_KPSLASH";
    case KEY_SYSRQ: return "KEY_SYSRQ";
    case KEY_RIGHTALT: return "KEY_RIGHTALT";
    case KEY_LINEFEED: return "KEY_LINEFEED";
    case KEY_HOME: return "KEY_HOME";
    case KEY_UP: return "KEY_UP";
    case KEY_PAGEUP: return "KEY_PAGEUP";
    case KEY_LEFT: return "KEY_LEFT";
    case KEY_RIGHT: return "KEY_RIGHT";
    case KEY_END: return "KEY_END";
    case KEY_DOWN: return "KEY_DOWN";
    case KEY_PAGEDOWN: return "KEY_PAGEDOWN";
    case KEY_INSERT: return "KEY_INSERT";
    case KEY_DELETE: return "KEY_DELETE";
    case KEY_MACRO: return "KEY_MACRO";
    case KEY_MUTE: return "KEY_MUTE";
    case KEY_VOLUMEDOWN: return "KEY_VOLUMEDOWN";
    case KEY_VOLUMEUP: return "KEY_VOLUMEUP";
    case KEY_POWER: return "KEY_POWER";
    case KEY_KPEQUAL: return "KEY_KPEQUAL";
    case KEY_KPPLUSMINUS: return "KEY_KPPLUSMINUS";
    case KEY_PAUSE: return "KEY_PAUSE";
    case KEY_SCALE: return "KEY_SCALE";

    case KEY_KPCOMMA: return "KEY_KPCOMMA";
    case KEY_HANGEUL: return "KEY_HANGEUL";
    case KEY_HANJA: return "KEY_HANJA";
    case KEY_YEN: return "KEY_YEN";
    case KEY_LEFTMETA: return "KEY_LEFTMETA";
    case KEY_RIGHTMETA: return "KEY_RIGHTMETA";
    case KEY_COMPOSE: return "KEY_COMPOSE";

    case KEY_STOP: return "KEY_STOP";
    case KEY_AGAIN: return "KEY_AGAIN";
    case KEY_PROPS: return "KEY_PROPS";
    case KEY_UNDO: return "KEY_UNDO";
    case KEY_FRONT: return "KEY_FRONT";
    case KEY_COPY: return "KEY_COPY";
    case KEY_OPEN: return "KEY_OPEN";
    case KEY_PASTE: return "KEY_PASTE";
    case KEY_FIND: return "KEY_FIND";
    case KEY_CUT: return "KEY_CUT";
    case KEY_HELP: return "KEY_HELP";
    case KEY_MENU: return "KEY_MENU";
    case KEY_CALC: return "KEY_CALC";
    case KEY_SETUP: return "KEY_SETUP";
    case KEY_SLEEP: return "KEY_SLEEP";
    case KEY_WAKEUP: return "KEY_WAKEUP";
    case KEY_FILE: return "KEY_FILE";
    case KEY_SENDFILE: return "KEY_SENDFILE";
    case KEY_DELETEFILE: return "KEY_DELETEFILE";
    case KEY_XFER: return "KEY_XFER";
    case KEY_PROG1: return "KEY_PROG1";
    case KEY_PROG2: return "KEY_PROG2";
    case KEY_WWW: return "KEY_WWW";
    case KEY_MSDOS: return "KEY_MSDOS";
    case KEY_COFFEE: return "KEY_COFFEE";
    case KEY_ROTATE_DISPLAY: return "KEY_ROTATE_DISPLAY";
    case KEY_CYCLEWINDOWS: return "KEY_CYCLEWINDOWS";
    case KEY_MAIL: return "KEY_MAIL";
    case KEY_BOOKMARKS: return "KEY_BOOKMARKS";
    case KEY_COMPUTER: return "KEY_COMPUTER";
    case KEY_BACK: return "KEY_BACK";
    case KEY_FORWARD: return "KEY_FORWARD";
    case KEY_CLOSECD: return "KEY_CLOSECD";
    case KEY_EJECTCD: return "KEY_EJECTCD";
    case KEY_EJECTCLOSECD: return "KEY_EJECTCLOSECD";
    case KEY_NEXTSONG: return "KEY_NEXTSONG";
    case KEY_PLAYPAUSE: return "KEY_PLAYPAUSE";
    case KEY_PREVIOUSSONG: return "KEY_PREVIOUSSONG";
    case KEY_STOPCD: return "KEY_STOPCD";
    case KEY_RECORD: return "KEY_RECORD";
    case KEY_REWIND: return "KEY_REWIND";
    case KEY_PHONE: return "KEY_PHONE";
    case KEY_ISO: return "KEY_ISO";
    case KEY_CONFIG: return "KEY_CONFIG";
    case KEY_HOMEPAGE: return "KEY_HOMEPAGE";
    case KEY_REFRESH: return "KEY_REFRESH";
    case KEY_EXIT: return "KEY_EXIT";
    case KEY_MOVE: return "KEY_MOVE";
    case KEY_EDIT: return "KEY_EDIT";
    case KEY_SCROLLUP: return "KEY_SCROLLUP";
    case KEY_SCROLLDOWN: return "KEY_SCROLLDOWN";
    case KEY_KPLEFTPAREN: return "KEY_KPLEFTPAREN";
    case KEY_KPRIGHTPAREN: return "KEY_KPRIGHTPAREN";
    case KEY_NEW: return "KEY_NEW";
    case KEY_REDO: return "KEY_REDO";

    case KEY_F13: return "KEY_F13";
    case KEY_F14: return "KEY_F14";
    case KEY_F15: return "KEY_F15";
    case KEY_F16: return "KEY_F16";
    case KEY_F17: return "KEY_F17";
    case KEY_F18: return "KEY_F18";
    case KEY_F19: return "KEY_F19";
    case KEY_F20: return "KEY_F20";
    case KEY_F21: return "KEY_F21";
    case KEY_F22: return "KEY_F22";
    case KEY_F23: return "KEY_F23";
    case KEY_F24: return "KEY_F24";

    case KEY_PLAYCD: return "KEY_PLAYCD";
    case KEY_PAUSECD: return "KEY_PAUSECD";
    case KEY_PROG3: return "KEY_PROG3";
    case KEY_PROG4: return "KEY_PROG4";
    case KEY_ALL_APPLICATIONS: return "KEY_ALL_APPLICATIONS";
    case KEY_SUSPEND: return "KEY_SUSPEND";
    case KEY_CLOSE: return "KEY_CLOSE";
    case KEY_PLAY: return "KEY_PLAY";
    case KEY_FASTFORWARD: return "KEY_FASTFORWARD";
    case KEY_BASSBOOST: return "KEY_BASSBOOST";
    case KEY_PRINT: return "KEY_PRINT";
    case KEY_HP: return "KEY_HP";
    case KEY_CAMERA: return "KEY_CAMERA";
    case KEY_SOUND: return "KEY_SOUND";
    case KEY_QUESTION: return "KEY_QUESTION";
    case KEY_EMAIL: return "KEY_EMAIL";
    case KEY_CHAT: return "KEY_CHAT";
    case KEY_SEARCH: return "KEY_SEARCH";
    case KEY_CONNECT: return "KEY_CONNECT";
    case KEY_FINANCE: return "KEY_FINANCE";
    case KEY_SPORT: return "KEY_SPORT";
    case KEY_SHOP: return "KEY_SHOP";
    case KEY_ALTERASE: return "KEY_ALTERASE";
    case KEY_CANCEL: return "KEY_CANCEL";
    case KEY_BRIGHTNESSDOWN: return "KEY_BRIGHTNESSDOWN";
    case KEY_BRIGHTNESSUP: return "KEY_BRIGHTNESSUP";
    case KEY_MEDIA: return "KEY_MEDIA";

    case KEY_SWITCHVIDEOMODE: return "KEY_SWITCHVIDEOMODE";
    case KEY_KBDILLUMTOGGLE: return "KEY_KBDILLUMTOGGLE";
    case KEY_KBDILLUMDOWN: return "KEY_KBDILLUMDOWN";
    case KEY_KBDILLUMUP: return "KEY_KBDILLUMUP";

    case KEY_SEND: return "KEY_SEND";
    case KEY_REPLY: return "KEY_REPLY";
    case KEY_FORWARDMAIL: return "KEY_FORWARDMAIL";
    case KEY_SAVE: return "KEY_SAVE";
    case KEY_DOCUMENTS: return "KEY_DOCUMENTS";

    case KEY_BATTERY: return "KEY_BATTERY";

    case KEY_BLUETOOTH: return "KEY_BLUETOOTH";
    case KEY_WLAN: return "KEY_WLAN";
    case KEY_UWB: return "KEY_UWB";

    case KEY_UNKNOWN: return "KEY_UNKNOWN";

    case KEY_VIDEO_NEXT: return "KEY_VIDEO_NEXT";
    case KEY_VIDEO_PREV: return "KEY_VIDEO_PREV";
    case KEY_BRIGHTNESS_CYCLE: return "KEY_BRIGHTNESS_CYCLE";
    case KEY_BRIGHTNESS_AUTO: return "KEY_BRIGHTNESS_AUTO";
    case KEY_DISPLAY_OFF: return "KEY_DISPLAY_OFF";

    case KEY_WWAN: return "KEY_WWAN";
    case KEY_RFKILL: return "KEY_RFKILL";

    case KEY_MICMUTE: return "KEY_MICMUTE";
//clang-format on

    default:
      return "UNRECOGNIZED_KEY_CODE(" + std::to_string(key_code) + ")";
  }
}