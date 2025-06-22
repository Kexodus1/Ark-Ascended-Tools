#include "../Headers/Menus.h"
#include "../Headers/resource.h"
#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

// Define MOD_NONE for no modifier keys
#define MOD_NONE 0x0000 

// Global variables
static HWND hSettingsWnd = NULL;
static HWND hGeneralDialog = NULL;
static HWND hHotkeysDialog = NULL;
static HWND hClubARKDialog = NULL;
static HWND hLogBotDialog = NULL;
extern HINSTANCE hInst;
extern HBRUSH hbrBackground;
const std::wstring CONFIG_FILE = L"AATool Settings.ini";
bool isSettingCoordinates = false;
HHOOK g_hMouseHook = NULL;
HWND g_hDialog = NULL;

// Hotkey variables
DWORD hotkey = 0;
DWORD openDinoHotkey = 0;
DWORD openPlayerHotkey = 0;
DWORD useitHotkey = 0;
DWORD proneHotkey = 0;
DWORD weaponHotkey = 0;
DWORD eatingHotkey = 0;
DWORD drinkingHotkey = 0;
DWORD brothHotkey = 0;
std::string customini;
int update = 0, fov = 0, gamma = 0, gamma1 = 0, gamma2 = 0, acxpos = 0, acypos = 0, doedturn=0;
extern int transparency;

void LoadSettings() {
    static bool firstLaunchDetected = false; // Track if first launch message has been shown

    std::ifstream config("AATool Settings.ini"); // Ensure this matches your actual file location
    std::string line;

    if (!config.is_open()) {
        if (!firstLaunchDetected) {
            MessageBox(
                NULL,
                L"          !First Launch Detected!\nPlease go to Settings and setup keys\n  After please RESTART the program",
                L"Notice",
                MB_OK | MB_ICONINFORMATION
            );
            firstLaunchDetected = true; // Set the flag to true after showing the message
        }
        return; // Exit the function if the file can't be opened
    }

    while (std::getline(config, line)) {
        try {
            if (line.find("Hotkey=") != std::string::npos) {
                hotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Open Dino Inventory=") != std::string::npos) {
                openDinoHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Open Player Inventory=") != std::string::npos) {
                openPlayerHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Use Item/Structure=") != std::string::npos) {
                useitHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Prone=") != std::string::npos) {
                proneHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Pull out Weapon=") != std::string::npos) {
                weaponHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Eating=") != std::string::npos) {
                eatingHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Drinking=") != std::string::npos) {
                drinkingHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Broth of Enlightenment=") != std::string::npos) {
                brothHotkey = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("CheckForUpdates=") != std::string::npos) {
                update = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Auto Clicker X=") != std::string::npos) {
                acxpos = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Auto Clicker Y=") != std::string::npos) {
                acypos = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("FOV=") != std::string::npos) {
                fov = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("Gamma=") != std::string::npos) {
                std::string gammaValue = line.substr(line.find('=') + 1); // Extract the value as string (e.g., "2.4")

                // Find the position of the decimal point
                size_t decimalPos = gammaValue.find('.');

                if (decimalPos != std::string::npos) {
                    // Extract integer part before the decimal point
                    std::string integerPart = gammaValue.substr(0, decimalPos);

                    // Extract fractional part after the decimal point
                    std::string fractionalPart = gammaValue.substr(decimalPos + 1);

                    // Assign to gamma1 (integer part) and gamma2 (fractional part)
                    gamma1 = std::stoi(integerPart);  // Convert to integer
                    gamma2 = std::stoi(fractionalPart);  // Convert to integer
                }
                else {
                    // If there's no decimal point, assign gamma1 as the whole number, gamma2 as 0
                    gamma1 = std::stoi(gammaValue);
                    gamma2 = 0; // No fractional part
                }
            }
            else if (line.find("Transparency=") != std::string::npos) {
                transparency = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
            else if (line.find("CustomINI=") != std::string::npos) {
                customini = line.substr(line.find('=') + 1);
            }
            else if (line.find("Doed Turn=") != std::string::npos) {
                doedturn = std::stoi(line.substr(line.find('=') + 1)); // Extract and assign value
            }
        }
        catch (const std::invalid_argument&) {
            if (line.find("CustomINI=") != std::string::npos) {
                // Skip invalid argument exception for CustomINI
                continue;
            }
            // Show which line caused the problem
            std::wstring msg = L"Invalid value for a key in AATool Settings.ini: " + std::wstring(line.begin(), line.end());
            MessageBox(NULL, msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
        }
        catch (const std::out_of_range&) {
            if (line.find("CustomINI=") != std::string::npos) {
                // Skip invalid argument exception for CustomINI
                continue;
            }
            // Handle out of range errors
            std::wstring msg = L"Value out of range for key in AATool Settings.ini: " + std::wstring(line.begin(), line.end());
            MessageBox(NULL, msg.c_str(), L"Error", MB_OK | MB_ICONERROR);
        }
    }

    config.close();
}

// Function to map virtual key codes to string representations
std::wstring MapKeyToString(DWORD key) {
    static const std::unordered_map<DWORD, std::wstring> keyMap = {
        {VK_BACK, L"Back"}, {VK_TAB, L"Tab"}, {VK_RETURN, L"Ent"}, {VK_ESCAPE, L"Esc"},
        {VK_SPACE, L"Spac"}, {VK_LEFT, L"Left"}, {VK_UP, L"Up"}, {VK_RIGHT, L"Right"}, {VK_DOWN, L"Down"},
        {VK_DELETE, L"Del"}, {VK_INSERT, L"Ins"}, {VK_HOME, L"Home"}, {VK_END, L"End"},
        {VK_PRIOR, L"PgUp"}, {VK_NEXT, L"PgDwn"}, {VK_F1, L"F1"}, {VK_F2, L"F2"}, {VK_F3, L"F3"},
        {VK_F4, L"F4"}, {VK_F5, L"F5"}, {VK_F6, L"F6"}, {VK_F7, L"F7"}, {VK_F8, L"F8"}, {VK_F9, L"F9"},
        {VK_F10, L"F10"}, {VK_F11, L"F11"}, {VK_F12, L"F12"}, {VK_CAPITAL, L"Caps"},
        {VK_SHIFT, L"SHIFT"}, {VK_CONTROL, L"CTRL"}, {VK_MENU, L"ALT"},   // Modifier keys
        {VK_LSHIFT, L"LSHIFT"}, {VK_RSHIFT, L"RSHIFT"},
        {VK_LCONTROL, L"LCTRL"}, {VK_RCONTROL, L"RCTRL"},
        {VK_LMENU, L"LALT"}, {VK_RMENU, L"RALT"},
        // Alphanumeric and other keys
        {'A', L"A"}, {'B', L"B"}, {'C', L"C"}, {'D', L"D"}, {'E', L"E"}, {'F', L"F"}, {'G', L"G"},
        {'H', L"H"}, {'I', L"I"}, {'J', L"J"}, {'K', L"K"}, {'L', L"L"}, {'M', L"M"}, {'N', L"N"},
        {'O', L"O"}, {'P', L"P"}, {'Q', L"Q"}, {'R', L"R"}, {'S', L"S"}, {'T', L"T"}, {'U', L"U"},
        {'V', L"V"}, {'W', L"W"}, {'X', L"X"}, {'Y', L"Y"}, {'Z', L"Z"},
        {VK_NUMPAD0, L"Num0"}, {VK_NUMPAD1, L"Num1"}, {VK_NUMPAD2, L"Num2"}, {VK_NUMPAD3, L"Num3"},
        {VK_NUMPAD4, L"Num4"}, {VK_NUMPAD5, L"Num5"}, {VK_NUMPAD6, L"Num6"}, {VK_NUMPAD7, L"Num7"},
        {VK_NUMPAD8, L"Num8"}, {VK_NUMPAD9, L"NUM 9"}, {VK_DIVIDE, L"Num/"}, {VK_MULTIPLY, L"Num*"},
        {VK_SUBTRACT, L"Num-"}, {VK_ADD, L"Num+"}, {VK_DECIMAL, L"Num."}
    };

    auto it = keyMap.find(key);
    return it != keyMap.end() ? it->second : std::to_wstring(key); // Fallback to the numeric value
}

// Function to map string representations to virtual key codes
DWORD MapStringToKey(const std::wstring& keyStr) {
    static const std::unordered_map<std::wstring, DWORD> stringToKeyMap = {
        {L"BACKSPACE", VK_BACK}, {L"TAB", VK_TAB}, {L"ENTER", VK_RETURN}, {L"ESC", VK_ESCAPE},
        {L"SPACE", VK_SPACE}, {L"LEFT", VK_LEFT}, {L"UP", VK_UP}, {L"RIGHT", VK_RIGHT}, {L"DOWN", VK_DOWN},
        {L"DELETE", VK_DELETE}, {L"INSERT", VK_INSERT}, {L"HOME", VK_HOME}, {L"END", VK_END},
        {L"PAGE UP", VK_PRIOR}, {L"PAGE DOWN", VK_NEXT}, {L"F1", VK_F1}, {L"F2", VK_F2}, {L"F3", VK_F3},
        {L"F4", VK_F4}, {L"F5", VK_F5}, {L"F6", VK_F6}, {L"F7", VK_F7}, {L"F8", VK_F8}, {L"F9", VK_F9},
        {L"F10", VK_F10}, {L"F11", VK_F11}, {L"F12", VK_F12},
        {L"SHIFT", VK_SHIFT}, {L"CTRL", VK_CONTROL}, {L"ALT", VK_MENU},   // Modifier keys
        {L"LEFT SHIFT", VK_LSHIFT}, {L"RIGHT SHIFT", VK_RSHIFT},
        {L"LEFT CTRL", VK_LCONTROL}, {L"RIGHT CTRL", VK_RCONTROL},
        {L"LEFT ALT", VK_LMENU}, {L"RIGHT ALT", VK_RMENU},
        {L"A", 'A'}, {L"B", 'B'}, {L"C", 'C'}, {L"D", 'D'}, {L"E", 'E'}, {L"F", 'F'}, {L"G", 'G'},
        {L"H", 'H'}, {L"I", 'I'}, {L"J", 'J'}, {L"K", 'K'}, {L"L", 'L'}, {L"M", 'M'}, {L"N", 'N'},
        {L"O", 'O'}, {L"P", 'P'}, {L"Q", 'Q'}, {L"R", 'R'}, {L"S", 'S'}, {L"T", 'T'}, {L"U", 'U'},
        {L"V", 'V'}, {L"W", 'W'}, {L"X", 'X'}, {L"Y", 'Y'}, {L"Z", 'Z'},
        {L"NUM 0", VK_NUMPAD0}, {L"NUM 1", VK_NUMPAD1}, {L"NUM 2", VK_NUMPAD2}, {L"NUM 3", VK_NUMPAD3},
        {L"NUM 4", VK_NUMPAD4}, {L"NUM 5", VK_NUMPAD5}, {L"NUM 6", VK_NUMPAD6}, {L"NUM 7", VK_NUMPAD7},
        {L"NUM 8", VK_NUMPAD8}, {L"NUM 9", VK_NUMPAD9}, {L"NUM /", VK_DIVIDE}, {L"NUM *", VK_MULTIPLY},
        {L"NUM -", VK_SUBTRACT}, {L"NUM +", VK_ADD}, {L"NUM .", VK_DECIMAL}
    };

    auto it = stringToKeyMap.find(keyStr);
    return it != stringToKeyMap.end() ? it->second : 0; // Fallback to 0 (invalid key)
}

LRESULT CALLBACK HotkeySubclassProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    switch (message)
    {
    case WM_GETDLGCODE:
        // process the Tab key
        if (wParam == VK_TAB) {
            return DLGC_WANTALLKEYS; // Prevent default tab behavior (moving focus)
        }
        break;

    case WM_KEYDOWN:
        if (wParam == VK_TAB) {
            // Set the Tab key as the hotkey
            SendMessage(hWnd, HKM_SETHOTKEY, MAKELPARAM(VK_TAB, 0), 0);
            return 0; // Prevent default behavior
        }
        break;

    case WM_KEYUP:
        if (wParam == VK_TAB) {
            return 0; // Prevent default behavior for key release
        }
        break;
    }

    return DefSubclassProc(hWnd, message, wParam, lParam);
}

void ShowSettingsWindow(HWND hWnd)
{
    if (!hSettingsWnd)
    {
        hSettingsWnd = CreateWindowEx(
            WS_EX_CONTROLPARENT,
            L"SettingsWndClass",
            L"Ark Ascended Tools Settings",
            WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_CLIPCHILDREN,
            CW_USEDEFAULT, CW_USEDEFAULT,
            423, 295,
            hWnd,
            NULL,
            hInst,
            NULL
        );

        if (!hSettingsWnd)
        {
            MessageBox(hWnd, L"Failed to create Settings window.", L"Error", MB_ICONERROR);
            return;
        }
    }

    ShowWindow(hSettingsWnd, SW_SHOW);
    UpdateWindow(hSettingsWnd);
}

// Register the Settings window class
void RegisterSettingsWndClass(HINSTANCE hInstance)
{
    WNDCLASS wc = { 0 };

    wc.lpfnWndProc = SettingsWndProc;    // Window procedure
    wc.hInstance = hInstance;            // Instance handle
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ARKASCENDEDTOOLS));
    wc.lpszClassName = L"SettingsWndClass"; // Class name

    RegisterClass(&wc);
}

#define MENU_WIDTH 100

// Declare global variables
int selectedMenu = 0;  // Stores the selected menu item (0: General, 1: Hotkeys, 2: ClubARK)
int hoveredMenu = -1;  // Stores the hovered menu item for highlighting

// Function prototypes
void ShowGeneralSettings(HWND hSettingsWnd);
void ShowHotkeysSettings(HWND hSettingsWnd);
void ShowClubARKSettings(HWND hSettingsWnd);
void ShowLogBotSettings(HWND hSettingsWnd);

LRESULT CALLBACK SettingsWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Handle menu selections:
        switch (wmId)
        {
        case 1: // General Settings
            selectedMenu = 0;
            InvalidateRect(hWnd, nullptr, TRUE);
            break;
        case 2: // Hotkeys
            selectedMenu = 1;
            InvalidateRect(hWnd, nullptr, TRUE);
            break;
//        case 3: // ClubARK
//            selectedMenu = 2;
//            InvalidateRect(hWnd, nullptr, TRUE);
//            break;
//        case 4: // LogBot
//            selectedMenu = 3;
//            InvalidateRect(hWnd, nullptr, TRUE);
//            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_LBUTTONDOWN: // Handle left mouse button down
    {
        POINT pt = { LOWORD(lParam), HIWORD(lParam) }; // Get mouse coordinates

        // Check if the click is within the menu area
        if (pt.x < MENU_WIDTH)
        {
            // Check which menu item was clicked
            if (pt.y >= 10 && pt.y < 40) // General
            {
                selectedMenu = 0;
            }
            else if (pt.y >= 40 && pt.y < 70) // Hotkeys
            {
                selectedMenu = 1;
            }
//            else if (pt.y >= 70 && pt.y < 100) // ClubARK
//            {
//                selectedMenu = 2;
//            }
//            else if (pt.y >= 100 && pt.y < 130) // LogBot
//            {
//                selectedMenu = 2;
//            }
            InvalidateRect(hWnd, nullptr, TRUE); // Redraw the window
        }
    }
    break;

    case WM_MOUSEMOVE: // Handle mouse move to track hover
    {
        POINT pt = { LOWORD(lParam), HIWORD(lParam) }; // Get mouse coordinates
        if (pt.x < MENU_WIDTH) // If mouse is over the menu
        {
            int newHoveredMenu = -1; // Reset hovered menu

            // Check which menu item is hovered
            if (pt.y >= 10 && pt.y < 40) newHoveredMenu = 0; // General
            else if (pt.y >= 40 && pt.y < 70) newHoveredMenu = 1; // Hotkeys
//            else if (pt.y >= 70 && pt.y < 100) newHoveredMenu = 2; // ClubARK
//            else if (pt.y >= 100 && pt.y < 130) newHoveredMenu = 3; // LogBot

            if (newHoveredMenu != hoveredMenu) // If hovered menu changed
            {
                hoveredMenu = newHoveredMenu;
                InvalidateRect(hWnd, nullptr, TRUE); // Redraw the window
            }
        }
        else if (hoveredMenu != -1) // If mouse leaves the menu
        {
            hoveredMenu = -1; // Reset hovered menu
            InvalidateRect(hWnd, nullptr, TRUE); // Redraw the window
        }
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Fill the background
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0)); // Black background
        FillRect(hdc, &ps.rcPaint, hBrush);
        DeleteObject(hBrush);

        HFONT hFont = CreateFont(
            20,        // Height of the font (double the size of 20)
            0,         // Width of the font
            0,         // Angle of the font
            0,         // Escape character
            FW_NORMAL, // Font weight
            FALSE,     // Italic
            FALSE,     // Underline
            FALSE,     // Strikeout
            DEFAULT_CHARSET, // Character set
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            0,         // Family (0 means default font)
            L"Arial"   // Font face
        );

        HFONT oldFont = (HFONT)SelectObject(hdc, hFont); // Select the new font

        // Draw the side menu
        HBRUSH hMenuBrush = CreateSolidBrush(RGB(50, 50, 50)); // Dark gray for menu
        RECT menuRect = { 0, 0, MENU_WIDTH, ps.rcPaint.bottom };
        FillRect(hdc, &menuRect, hMenuBrush);
        DeleteObject(hMenuBrush);

        // Draw menu items with hover effect
        SetTextColor(hdc, RGB(255, 255, 255)); // White text
        SetBkMode(hdc, TRANSPARENT);

        // Highlight box for hovered menu item
        if (hoveredMenu != -1)
        {
            RECT highlightRect = { 0, 10 + hoveredMenu * 30, MENU_WIDTH, 40 + hoveredMenu * 30 };
            HBRUSH hHighlightBrush = CreateSolidBrush(RGB(100, 100, 100)); // Gray for highlight
            FillRect(hdc, &highlightRect, hHighlightBrush);
            DeleteObject(hHighlightBrush);
        }

        // Draw menu items
        SetTextColor(hdc, RGB(255, 255, 255)); // White text
        SetBkMode(hdc, RGB(0, 0, 0));
        TextOut(hdc, 10, 15, L"General", 7);
        TextOut(hdc, 10, 45, L"Hotkeys", 7);
        // TextOut(hdc, 10, 75, L"ClubARK", 8);
        // TextOut(hdc, 10, 105, L"LogBot", 6);

        // Draw the right content based on selected menu
        SetBkMode(hdc, RGB(0, 0, 0)); // Opaque background for content
        if (selectedMenu == 0)
            ShowGeneralSettings(hWnd);
        else if (selectedMenu == 1)
            ShowHotkeysSettings(hWnd);
        else if (selectedMenu == 2)
            ShowClubARKSettings(hWnd);
        else if (selectedMenu == 3)
            ShowLogBotSettings(hWnd);

        SelectObject(hdc, oldFont); // Restore the old font
        DeleteObject(hFont); // Clean up the new font
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_DESTROY:
        DestroyWindow(hSettingsWnd);
        hSettingsWnd = NULL;
        hGeneralDialog = NULL;
        hClubARKDialog = NULL;
        hHotkeysDialog = NULL;
        hLogBotDialog = NULL;
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//////////////////////////////////////////////////////////////////
//
//      Mouse Position
//
//////////////////////////////////////////////////////////////////

// Update AC edit boxes
void UpdateCoordinateBoxes(HWND hDlg, int x, int y) {
    SetDlgItemInt(hDlg, IDC_ACXPOS, x, TRUE); // Update X box
    SetDlgItemInt(hDlg, IDC_ACYPOS, y, TRUE); // Update Y box
}

void RemoveMouseHook() {
    if (g_hMouseHook) {
        UnhookWindowsHookEx(g_hMouseHook);
        g_hMouseHook = NULL;
        g_hDialog = NULL;
    }
}

LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && isSettingCoordinates) {
        MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
        if (pMouseStruct) {
            // Dynamically update the coordinate boxes
            UpdateCoordinateBoxes(g_hDialog, pMouseStruct->pt.x, pMouseStruct->pt.y);

            // Capture mouse position on left click
            if (wParam == WM_LBUTTONDOWN) {
                // Finalize coordinates on click
                isSettingCoordinates = false; // Deactivate setting mode
                RemoveMouseHook();            // Remove the mouse hook
            }
        }
    }
    return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}

void InstallMouseHook(HWND hDlg) {
    g_hDialog = hDlg; // Store the dialog handle
    g_hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, NULL, 0);
    if (!g_hMouseHook) {
        MessageBox(hDlg, L"Failed to set mouse hook.", L"Error", MB_ICONERROR);
    }
}

//////////////////////////END////////////////////////////////////

/////////////////////////////////////////////////////////////////
// 
//         SAVE SETTINGS
// 
/////////////////////////////////////////////////////////////////
// Helper function to update or append a section in the settings
void UpdateSection(std::string& settings, const std::string& sectionName, const std::string& newContent) {
    size_t sectionStart = settings.find("[" + sectionName + "]");
    if (sectionStart != std::string::npos) {
        // Find the end of the section
        size_t nextSectionStart = settings.find("[", sectionStart + 1);
        if (nextSectionStart != std::string::npos) {
            // Replace the existing section
            settings.replace(sectionStart, nextSectionStart - sectionStart, newContent);
        }
        else {
            // Replace to the end of the file
            settings.replace(sectionStart, std::string::npos, newContent);
        }
    }
    else {
        // Append the section if it doesn't exist
        settings += "\n" + newContent;
    }
}

// General Settings Save
void SaveGeneralSettings(HWND hDlg) {
    std::ifstream inputFile("AATool Settings.ini");
    std::ostringstream fileContents;

    // Read the entire file into memory
    fileContents << inputFile.rdbuf();
    inputFile.close();

    std::string settings = fileContents.str();

    // Retrieve the transparency value
    HWND hTransSlider = GetDlgItem(hDlg, IDC_TRANSPARENCY_SLIDER); // slider control ID
    int transparencyValue = static_cast<int>(SendMessage(hTransSlider, TBM_GETPOS, 0, 0));
    // Retrieve the FOV value
    HWND hFOVSlider = GetDlgItem(hDlg, IDC_FOV_SLIDER); // slider control ID
    int FOVValue = static_cast<int>(SendMessage(hFOVSlider, TBM_GETPOS, 0, 0));
    // Retrieve the Gamma value
    HWND hGammaSlider = GetDlgItem(hDlg, IDC_GAMMA_SLIDER); // slider control ID
    int GammaValue = static_cast<int>(SendMessage(hGammaSlider, TBM_GETPOS, 0, 0));
    float gammaDecimal = GammaValue / 10.0f; // Convert to decimal

    // Use a minimum transparency value of 25 to avoid invisibility
    if (transparencyValue <= 25) {
        transparencyValue = IDC_TRANSPARENCY_SLIDER;
    }

    // Retrieve Updates checkbox state
    int checkUpdateState = (IsDlgButtonChecked(hDlg, IDC_CHECKUPDATE) == BST_CHECKED) ? 1 : 0;

    // Retrieve coordinate values from the edit boxes
    int ACXPOSValue = GetDlgItemInt(hDlg, IDC_ACXPOS, NULL, TRUE); // X-coordinate
    int ACYPOSValue = GetDlgItemInt(hDlg, IDC_ACYPOS, NULL, TRUE); // Y-coordinate

    // Retrieve the value from the IDC_CUSTINI edit box
    wchar_t customIniValue[1024];  // Adjust the buffer size if necessary
    GetWindowText(GetDlgItem(hDlg, IDC_CUSTINI), customIniValue, 1024); // Get the text from the edit box
    std::wstring customIniStr(customIniValue); // Convert to std::wstring
    // Convert std::wstring to std::string
    std::string customIniStrA(customIniStr.begin(), customIniStr.end());

    // Retrieve value from Doed Turn edit boxes
    int DOEDTValue = GetDlgItemInt(hDlg, IDC_DOEDT, NULL, TRUE);

    // Build the new General section
    std::ostringstream generalSettings;
    generalSettings << "[General]\n";
    generalSettings << "CheckForUpdates=" << checkUpdateState << "\n";
    generalSettings << "FOV=" << FOVValue << "\n";
    generalSettings << "Gamma=" << std::fixed << std::setprecision(1) << gammaDecimal << "\n"; // Save as decimal
    generalSettings << "Transparency=" << transparencyValue << "\n";
    generalSettings << "Auto Clicker X=" << ACXPOSValue << "\n"; // Save X-coordinate
    generalSettings << "Auto Clicker Y=" << ACYPOSValue << "\n"; // Save Y-coordinate
    generalSettings << "CustomINI=" << customIniStrA << "\n"; // Save the custom INI value
    generalSettings << "Doed Turn=" << DOEDTValue << "\n";

    // Update or append the General section
    UpdateSection(settings, "General", generalSettings.str());

    // Write the updated settings back to the file
    std::ofstream outputFile("AATool Settings.ini");
    outputFile << settings;
    outputFile.close();
}

// Hotkeys Settings Save
void SaveHotkeys(HWND hDlg) {
    std::ifstream inputFile("AATool Settings.ini");
    std::ostringstream fileContents;

    // Read the entire file into memory
    fileContents << inputFile.rdbuf();
    inputFile.close();

    std::string settings = fileContents.str();

    // Retrieve hotkey values
    DWORD hotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_HOTKEY), HKM_GETHOTKEY, 0, 0));
    DWORD openDinoHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_DINOST), HKM_GETHOTKEY, 0, 0));
    DWORD openPlayerHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_INVENT), HKM_GETHOTKEY, 0, 0));
    DWORD useitHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_USEIT), HKM_GETHOTKEY, 0, 0));
    DWORD proneHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_PRONE), HKM_GETHOTKEY, 0, 0));
    DWORD weaponHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_CROUCH), HKM_GETHOTKEY, 0, 0));
    DWORD eatingHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_EATING), HKM_GETHOTKEY, 0, 0));
    DWORD drinkingHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_DRINK), HKM_GETHOTKEY, 0, 0));
    DWORD brothHotkey = static_cast<DWORD>(SendMessage(GetDlgItem(hDlg, IDC_BROTH), HKM_GETHOTKEY, 0, 0));

    // Build the new Hotkeys section
    std::string hotkeys = "[Hotkeys]\n";
    hotkeys += "Hotkey=" + std::to_string(hotkey) + "\n";
    hotkeys += "Open Dino Inventory=" + std::to_string(openDinoHotkey) + "\n";
    hotkeys += "Open Player Inventory=" + std::to_string(openPlayerHotkey) + "\n";
    hotkeys += "Use Item/Structure=" + std::to_string(useitHotkey) + "\n";
    hotkeys += "Prone=" + std::to_string(proneHotkey) + "\n";
    hotkeys += "Pull out Weapon=" + std::to_string(weaponHotkey) + "\n";
    hotkeys += "Eating=" + std::to_string(eatingHotkey) + "\n";
    hotkeys += "Drinking=" + std::to_string(drinkingHotkey) + "\n";
    hotkeys += "Broth of Enlightenment=" + std::to_string(brothHotkey) + "\n";

    // Update or append the Hotkeys section
    UpdateSection(settings, "Hotkeys", hotkeys);

    // Write the updated settings back to the file
    std::ofstream outputFile("AATool Settings.ini");
    outputFile << settings;
    outputFile.close();
}
//////////////////////////END/////////////////////////////////////////////////

// Message handler for General Settings box.
INT_PTR CALLBACK General(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hTransEdit;
    static HWND hTransSlider;
    static HWND hFOVSlider;
    static HWND hFOVEdit;
    static HWND hGammaSlider;
    static HWND hGammaEdit;

    switch (message)
    {
    case WM_INITDIALOG:
    {
        int selectedIndex = -1;
        selectedIndex = (int)SendMessage(hDropDown, CB_GETCURSEL, 0, 0);
        if (selectedIndex != CB_ERR) {
            wchar_t selectedItem[256] = { 0 };
            SendMessage(hDropDown, CB_GETLBTEXT, selectedIndex, (LPARAM)selectedItem);
            SetWindowText(GetDlgItem(hGeneralDialog, IDC_COMBOTOOL), selectedItem);  // hwnd is the dialog handle
        }

        // Disable the checkbox with ID `IDC_MY_CHECKBOX`
        HWND hCheckbox = GetDlgItem(hDlg, IDC_CHECKNVIDIA);
        if (hCheckbox) {
            EnableWindow(hCheckbox, FALSE); // Disable and grey out
        }

        // Get the slider and edit controls for transparency
        hTransSlider = GetDlgItem(hDlg, IDC_TRANSPARENCY_SLIDER);
        hTransEdit = GetDlgItem(hDlg, IDC_TRANSPARENCY_EDIT);
        // Initialize the slider range (25 to 255) and position
        SendMessage(hTransSlider, TBM_SETRANGE, TRUE, MAKELPARAM(25, 255));
        // Get the slider and edit controls for FOV
        hFOVSlider = GetDlgItem(hDlg, IDC_FOV_SLIDER);
        hFOVEdit = GetDlgItem(hDlg, IDC_FOV_EDIT);
        // Initialize the slider range (0 to 100) and position
        SendMessage(hFOVSlider, TBM_SETRANGE, TRUE, MAKELPARAM(0, 100));
        // Get the slider and edit controls for Gamma
        hGammaSlider = GetDlgItem(hDlg, IDC_GAMMA_SLIDER);
        hGammaEdit = GetDlgItem(hDlg, IDC_GAMMA_EDIT);
        // Initialize the slider range (1 to 5) and position
        SendMessage(hGammaSlider, TBM_SETRANGE, TRUE, MAKELPARAM(10, 40));
        SendMessage(hGammaSlider, TBM_SETTICFREQ, 1, 0); // Ticks every 0.1

        // Load General settings from the configuration file
        std::wifstream config("AATool Settings.ini");
        if (config.is_open()) {
            std::wstring line;
            while (std::getline(config, line)) {
                if (line.find(L"CheckForUpdates=") == 0) {
                    std::wstring value = line.substr(wcslen(L"CheckForUpdates="));
                    int checkUpdateState = std::stoi(value);
                    CheckDlgButton(hDlg, IDC_CHECKUPDATE, checkUpdateState ? BST_CHECKED : BST_UNCHECKED);
                }
                else if (line.find(L"Transparency=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Transparency="));
                    try {
                        int transparencyValue = std::stoi(value);
                        SendMessage(hTransSlider, TBM_SETPOS, TRUE, transparencyValue);
                        SetWindowText(hTransEdit, value.c_str());
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid transparency value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Transparency value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"FOV=") == 0) {
                    std::wstring value = line.substr(wcslen(L"FOV="));
                    try {
                        int FOVValue = std::stoi(value);
                        SendMessage(hFOVSlider, TBM_SETPOS, TRUE, FOVValue);
                        SetWindowText(hFOVEdit, value.c_str());
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid FOV value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"FOV value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Gamma=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Gamma="));
                    try {
                        float GammaValue = std::stof(value);
                        int GammaSliderValue = static_cast<int>(GammaValue * 10);
                        SendMessage(hGammaSlider, TBM_SETPOS, TRUE, GammaSliderValue);
                        // Display the decimal value in the edit box
                        wchar_t buffer[10];
                        swprintf(buffer, 10, L"%.1f", GammaValue);
                        SetWindowText(hGammaEdit, value.c_str());
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Gamma value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Gamma value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Auto Clicker X=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Auto Clicker X="));
                    int xCoord = std::stoi(value);
                    SetDlgItemInt(hDlg, IDC_ACXPOS, xCoord, TRUE);
                }
                else if (line.find(L"Auto Clicker Y=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Auto Clicker Y="));
                    int yCoord = std::stoi(value);
                    SetDlgItemInt(hDlg, IDC_ACYPOS, yCoord, TRUE);
                }
                else if (line.find(L"CustomINI=") == 0) {
                    std::wstring value = line.substr(wcslen(L"CustomINI="));
                    // Set the text of the custom INI edit box
                    SetWindowText(GetDlgItem(hDlg, IDC_CUSTINI), value.c_str());
                }
                else if (line.find(L"Doed Turn=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Doed Turn="));
                    int DoedTurn = std::stoi(value);
                    SetDlgItemInt(hDlg, IDC_DOEDT, DoedTurn, TRUE);
                }
            }
            config.close();
        }
        else {
            // Set default values if the config file doesn't exist
            // Default value for checkbox
            CheckDlgButton(hDlg, IDC_CHECKUPDATE, BST_UNCHECKED);
            // Default transparency
            SendMessage(hTransSlider, TBM_SETPOS, TRUE, 255);
            SetDlgItemInt(hDlg, IDC_TRANSPARENCY_EDIT, 255, FALSE);
            // Default FOV
            SendMessage(hFOVSlider, TBM_SETPOS, TRUE, 50);
            SetDlgItemInt(hDlg, IDC_FOV_EDIT, 50, FALSE);
            // Default Gamma
            int DefaultGamma = static_cast<int>(1.8f) * 10;
            SendMessage(hGammaSlider, TBM_SETPOS, TRUE, DefaultGamma);
            SetDlgItemInt(hDlg, IDC_GAMMA_EDIT, DefaultGamma, FALSE);
            // Default Doed Turn
            int DefaultDoedTurn = 65;
            SetDlgItemInt(hDlg, IDC_DOEDT, DefaultDoedTurn, TRUE);
        }
    }
    break;
case WM_COMMAND:
    switch (LOWORD(wParam)) {
    case IDC_ACSET: // Set button clicked
        if (!isSettingCoordinates) {
            isSettingCoordinates = true;  // Activate setting mode
            InstallMouseHook(hDlg);       // Install the global mouse hook
        }
        break;
    case IDC_CUSTQ:
        MessageBox(
            hDlg,
            L"Custom selection under MagicINI.\rSeparate each setting by \" | \"\nEnsuring a space before and after.",
            L"INFO",
            MB_OK | MB_ICONINFORMATION
        );
        break;
    break;
    case IDC_DOEDQ:
        MessageBox(
            hDlg,
            L"   Adjust value to stay off wall\nwhile also staying out of middle.",
            L"INFO",
            MB_OK | MB_ICONINFORMATION
        );
        break;
        break;
    case IDOK: // OK button clicked
        SaveGeneralSettings(hDlg); // Save General settings
        DestroyWindow(hSettingsWnd);
        hSettingsWnd = NULL;
        hHotkeysDialog = NULL;
        return (INT_PTR)TRUE;

    case IDCANCEL: // Cancel button clicked
        DestroyWindow(hSettingsWnd);
        hSettingsWnd = NULL;
        hHotkeysDialog = NULL;
        return (INT_PTR)TRUE;

    default:
        return (INT_PTR)FALSE;
    }
    break;
    case WM_MOUSEMOVE:
    if (isSettingCoordinates) {
        // Capture global mouse coordinates
        POINT cursorPos;
        GetCursorPos(&cursorPos); // Get global screen coordinates

        // Dynamically update the X and Y boxes
        UpdateCoordinateBoxes(hDlg, cursorPos.x, cursorPos.y);
    }
    break;
    case WM_LBUTTONDOWN: // Finalize coordinates on click
        if (isSettingCoordinates) {
            POINT cursorPos;
            GetCursorPos(&cursorPos);

            // Update the X and Y boxes one last time
            UpdateCoordinateBoxes(hDlg, cursorPos.x, cursorPos.y);

            isSettingCoordinates = false; // Deactivate setting mode
            RemoveMouseHook();            // Remove the mouse hook
            ReleaseCapture();
        }
        break;
    case WM_HSCROLL:
        if (HWND(hTransSlider) == (HWND)lParam) {
            // Update transparency edit box value when the slider moves
            int transparencyValue = static_cast<int>(SendMessage(hTransSlider, TBM_GETPOS, 0, 0));
            wchar_t buffer[10];
            swprintf(buffer, 10, L"%d", transparencyValue);
            SetWindowText(hTransEdit, buffer);
            // Directly update transparency
            SendMessage(hWnd, WM_UPDATE_TRANSPARENCY, transparencyValue, 0);
        }
        else if (HWND(hFOVSlider) == (HWND)lParam) {
            // Update FOV edit box value when the slider moves
            int FOVValue = static_cast<int>(SendMessage(hFOVSlider, TBM_GETPOS, 0, 0));
            wchar_t buffer[10];
            swprintf(buffer, 10, L"%d", FOVValue);
            SetWindowText(hFOVEdit, buffer);
        }
        else if (HWND(hGammaSlider) == (HWND)lParam) {
            // Update Gamma edit box value when the slider moves
            int GammaValue = static_cast<int>(SendMessage(hGammaSlider, TBM_GETPOS, 0, 0));
            float realGammaValue = GammaValue / 10.0f; // Convert to floating-point
            wchar_t buffer[10];
            swprintf(buffer, 10, L"%.1f", realGammaValue); // Use %.1f for one decimal place
            SetWindowText(hGammaEdit, buffer);
        }
        break;
    case WM_CTLCOLORDLG:
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0));         // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    default:
        return FALSE;
    }
    return TRUE;
}

// Message handler for Hotkeys box.
INT_PTR CALLBACK Hotkeys(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    static HWND hHotkeyControl;

    switch (message)
    {

    case WM_INITDIALOG:
    {
        // Set focus and capture
        SetForegroundWindow(hDlg);
        SetFocus(hDlg);

        // Subclass hotkey controls to handle Tab key
        HWND hHotkeyControl = GetDlgItem(hDlg, IDC_HOTKEY);
        SetWindowSubclass(hHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hDinoHotkeyControl = GetDlgItem(hDlg, IDC_DINOST);
        SetWindowSubclass(hDinoHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hPlayerHotkeyControl = GetDlgItem(hDlg, IDC_INVENT);
        SetWindowSubclass(hPlayerHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hUseitHotkeyControl = GetDlgItem(hDlg, IDC_USEIT);
        SetWindowSubclass(hUseitHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hProneHotkeyControl = GetDlgItem(hDlg, IDC_PRONE);
        SetWindowSubclass(hProneHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hWeaponHotkeyControl = GetDlgItem(hDlg, IDC_CROUCH);
        SetWindowSubclass(hWeaponHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hEatHotkeyControl = GetDlgItem(hDlg, IDC_EATING);
        SetWindowSubclass(hEatHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hDrinkHotkeyControl = GetDlgItem(hDlg, IDC_DRINK);
        SetWindowSubclass(hDrinkHotkeyControl, HotkeySubclassProc, 0, 0);

        HWND hBrothHotkeyControl = GetDlgItem(hDlg, IDC_BROTH);
        SetWindowSubclass(hBrothHotkeyControl, HotkeySubclassProc, 0, 0);

        // Load the hotkey and transparency from the configuration file
        std::wifstream config("AATool Settings.ini");
        if (config.is_open()) {
            std::wstring line;

            while (std::getline(config, line)) {
                    if (line.find(L"Hotkey=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Hotkey=")); // Extract value
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_HOTKEY), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Open Dino Inventory=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Open Dino Inventory="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_DINOST), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Open Dino Inventory hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Open Dino Inventory hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Open Player Inventory=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Open Player Inventory="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_INVENT), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Open Player Inventory hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Open Player Inventory hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Use Item/Structure=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Use Item/Structure="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_USEIT), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Use Item/Structure hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Use Item/Structure hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Prone=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Prone="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_PRONE), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Prone hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Prone hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Pull out Weapon=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Pull out Weapon="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_CROUCH), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Pull out Weapon hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Pull out Weapon hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Eating=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Eating="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_EATING), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Eating hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Eating hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Drinking=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Drinking="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_DRINK), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Drinking hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Drinking hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
                else if (line.find(L"Broth of Enlightenment=") == 0) {
                    std::wstring value = line.substr(wcslen(L"Broth of Enlightenment="));
                    try {
                        DWORD hotkeyValue = std::stoul(value);
                        SendMessage(GetDlgItem(hDlg, IDC_BROTH), HKM_SETHOTKEY, hotkeyValue, 0);
                    }
                    catch (const std::invalid_argument&) {
                        MessageBox(hDlg, L"Invalid Broth of Enlightenment hotkey value in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                    catch (const std::out_of_range&) {
                        MessageBox(hDlg, L"Broth of Enlightenment hotkey value out of range in settings.", L"Error", MB_OK | MB_ICONERROR);
                    }
                }
            }
            config.close();
        }
        else {
            // Set default values if the config file doesn't exist
            SendMessage(GetDlgItem(hDlg, IDC_HOTKEY), HKM_SETHOTKEY, MAKELPARAM(VK_F4, MOD_NONE), 0); // Default hotkey
            SendMessage(GetDlgItem(hDlg, IDC_DINOST), HKM_SETHOTKEY, MAKELPARAM('F', MOD_NONE), 0); // Open Dino Inventory
            SendMessage(GetDlgItem(hDlg, IDC_INVENT), HKM_SETHOTKEY, MAKELPARAM('I', MOD_NONE), 0); // Open Player Inventory
            SendMessage(GetDlgItem(hDlg, IDC_USEIT), HKM_SETHOTKEY, MAKELPARAM('E', MOD_NONE), 0); // Use Item\Structure
            SendMessage(GetDlgItem(hDlg, IDC_PRONE), HKM_SETHOTKEY, MAKELPARAM('X', MOD_NONE), 0); // Prone
            SendMessage(GetDlgItem(hDlg, IDC_CROUCH), HKM_SETHOTKEY, MAKELPARAM('2', MOD_NONE), 0); // Crouching
            SendMessage(GetDlgItem(hDlg, IDC_EATING), HKM_SETHOTKEY, MAKELPARAM('9', MOD_NONE), 0); // Eating
            SendMessage(GetDlgItem(hDlg, IDC_DRINK), HKM_SETHOTKEY, MAKELPARAM('0', MOD_NONE), 0); // Drinking
            SendMessage(GetDlgItem(hDlg, IDC_BROTH), HKM_SETHOTKEY, MAKELPARAM('1', MOD_NONE), 0); // Broth
        }

        return (INT_PTR)TRUE;
    }

case WM_COMMAND:
    if (LOWORD(wParam) == IDOK) {
        // Call the SaveHotkeys function to save the hotkey settings
        SaveHotkeys(hDlg); // Save all hotkey settings using the updated function

        DestroyWindow(hSettingsWnd);
        hSettingsWnd = NULL;
        hHotkeysDialog = NULL;
        return (INT_PTR)TRUE;
    }
    else if (LOWORD(wParam) == IDCANCEL) {
        DestroyWindow(hSettingsWnd);
        hSettingsWnd = NULL;
        hHotkeysDialog = NULL;
        return (INT_PTR)TRUE;
    }
    break;
    case WM_CTLCOLORDLG:
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    }
    return (INT_PTR)FALSE;
}

// Message handler for ClubARK Settings box.
INT_PTR CALLBACK ClubARK(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            DestroyWindow(hSettingsWnd);
            hSettingsWnd = NULL;
            hClubARKDialog = NULL;
        }
        break;
    case WM_CTLCOLORDLG:
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0));         // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;
    }
    return (INT_PTR)FALSE;
}

// Message handler for ClubARK Settings box.
INT_PTR CALLBACK LogBot(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            DestroyWindow(hSettingsWnd);
            hSettingsWnd = NULL;
            hClubARKDialog = NULL;
        }
        break;
    case WM_CTLCOLORDLG:
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0));         // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;
    }
    return (INT_PTR)FALSE;
}

// Function to display General Settings
void ShowGeneralSettings(HWND hSettingsWnd)
{
    // Hide the Hotkeys dialog if it's shown
    if (hHotkeysDialog)
    {
        ShowWindow(hHotkeysDialog, SW_HIDE);
        hHotkeysDialog = NULL;
    }
    // Hide the ClubARK dialog if it's shown
    if (hClubARKDialog)
    {
        ShowWindow(hClubARKDialog, SW_HIDE);
        hClubARKDialog = NULL;
    }

    if (!hGeneralDialog) // Create only if not already created
    {
        hGeneralDialog = CreateDialogParam(
            hInst,
            MAKEINTRESOURCE(IDD_GENERALBOX),
            hSettingsWnd,
            General, // Dialog procedure for General
            (LPARAM)hWnd  // Pass hWnd as lParam
        );

        SetWindowPos(hGeneralDialog, HWND_TOP, 100, 0, 700, 700, SWP_SHOWWINDOW | SWP_NOACTIVATE);
    }

    // Show the dialog
    ShowWindow(hGeneralDialog, SW_SHOW);
    UpdateWindow(hGeneralDialog);
}

// Function to display Hotkey Settings
void ShowHotkeysSettings(HWND hSettingsWnd)
{
    // Hide the General dialog if it's shown
    if (hGeneralDialog)
    {
        ShowWindow(hGeneralDialog, SW_HIDE);
        hGeneralDialog = NULL;
    }
    // Hide the ClubARK dialog if it's shown
    if (hClubARKDialog)
    {
        ShowWindow(hClubARKDialog, SW_HIDE);
        hClubARKDialog = NULL;
    }

    if (!hHotkeysDialog) // Create only if not already created
    {
        hHotkeysDialog = CreateDialog(
            hInst,
            MAKEINTRESOURCE(IDD_HOTKEYSBOX),
            hSettingsWnd,
            Hotkeys // Dialog procedure for hotkeys
        );
        SetWindowPos(hHotkeysDialog, HWND_TOP, 100, 0, 500, 500, SWP_SHOWWINDOW | SWP_NOACTIVATE);
    }

    // Show the dialog
    ShowWindow(hHotkeysDialog, SW_SHOW);
    UpdateWindow(hHotkeysDialog);
}

// Function to display ClubARK Settings
void ShowClubARKSettings(HWND hSettingsWnd)
{
    // Hide the General dialog if it's shown
    if (hGeneralDialog)
    {
        ShowWindow(hGeneralDialog, SW_HIDE);
        hGeneralDialog = NULL;
    }
    // Hide the Hotkeys dialog if it's shown
    if (hHotkeysDialog)
    {
        ShowWindow(hHotkeysDialog, SW_HIDE);
        hHotkeysDialog = NULL;
    }

    if (!hClubARKDialog) // Create only if not already created
    {
        hClubARKDialog = CreateDialog(
            hInst,
            MAKEINTRESOURCE(IDD_CLUBARKBOX),
            hSettingsWnd,
            ClubARK // Dialog procedure for hotkeys
        );

        // Position the dialog
        SetWindowPos(hClubARKDialog, HWND_TOP, 100, 0, 500, 500, SWP_SHOWWINDOW | SWP_NOACTIVATE);
    }

    // Show the dialog
    ShowWindow(hClubARKDialog, SW_SHOW);
    UpdateWindow(hClubARKDialog);
}

// Function to display ClubARK Settings
void ShowLogBotSettings(HWND hSettingsWnd)
{
    // Hide the General dialog if it's shown
    if (hGeneralDialog)
    {
        ShowWindow(hGeneralDialog, SW_HIDE);
        hGeneralDialog = NULL;
    }
    // Hide the Hotkeys dialog if it's shown
    if (hHotkeysDialog)
    {
        ShowWindow(hHotkeysDialog, SW_HIDE);
        hHotkeysDialog = NULL;
   }

    if (!hLogBotDialog) // Create only if not already created
    {
        hLogBotDialog = CreateDialog(
            hInst,
            MAKEINTRESOURCE(IDD_LOGBOTBOX),
            hSettingsWnd,
            LogBot // Dialog procedure for hotkeys
        );

        // Position the dialog
        SetWindowPos(hLogBotDialog, HWND_TOP, 100, 0, 500, 500, SWP_SHOWWINDOW | SWP_NOACTIVATE);
    }

    // Show the dialog
    ShowWindow(hLogBotDialog, SW_SHOW);
    UpdateWindow(hLogBotDialog);
}