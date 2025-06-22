#include "Headers\framework.h"
#include "Headers\resource.h"
#include "Headers\Features.h"
#include "Headers\Menus.h"

// Global Variables:
std::atomic<bool> shouldContinueLoop(true);
std::atomic<bool> functionsRunning(false);
bool keepOnTop = true;
bool isTimerRunning = false;
UINT customHotkey = 0;
UINT_PTR timerID = 0;
HWND hDlg;
HWND ServerN = NULL, BackupJN, FarmTools, AutoFarm = NULL, AutoDrop, AFKM, AFKFD, AFKFDM, AFKFDI, 
BreedTools, Nanny = NULL, Spacing, SpacingD, AutoGrab, AutoGrabSel, SnailPoly, PVPTool, AutoRun;
HWND TimerHR, TimerMN, TimerSC, hHUB, hHDB, hMUB, hMDB, hSUB, hSDB, TimerSND;
HWND MagicINISel, MagicINIo, ClubARKGame, ClubARKPing, ClubARKDiff, AutoFishAFK, AutoFishCon;
HWND CATurnT, CATurn, CAFOVT, CAFOV, CAP1, DevToolsSel;
HWND ACKey, ACInt, ACIntT, ACPos, XPCraft, XPTurnT, XPTurn, XPPutT, XPPut;
HWND hDropDown, hButton, hStaticRes, hStaticText;
HINSTANCE hInst;                                // current instance
HWND hWnd = nullptr;
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HBRUSH hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
int transparency = 255;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// WinMain
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    // Register the Settings window class
    RegisterSettingsWndClass(hInstance);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ARKASCENDEDTOOLS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ARKASCENDEDTOOLS));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

// Register the window class.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex = { 0 }; // Zero-initialize the structure

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ARKASCENDEDTOOLS));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_ARKASCENDEDTOOLS);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

// Initialize instance
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
        CW_USEDEFAULT, 0, 300, 400, nullptr, nullptr, hInstance, nullptr);

    OnProgramStartup(hInst, hWnd);

    if (!hWnd)
    {
        MessageBox(NULL, L"Window creation failed!", L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Set the window to be always on top
    if (!SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 295, 145, SWP_NOMOVE | SWP_NOZORDER))
    {
        MessageBox(NULL, L"SetWindowPos failed!", L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }

    // Load hotkeys from the configuration file
    LoadSettings(); // Call to load hotkeys

    // Register Settings hotkey
    RegisterHotKey(hWnd, 1, 0, hotkey);

    // Set transparency based on the setting
    SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hWnd, 0, transparency, LWA_ALPHA);

    return TRUE;
}

// Code for Supported Resolution
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

bool IsResolutionSupported(int width, int height) {
    std::vector<std::pair<int, int>> supportedResolutions = {
        {3840, 2160},
        {3840, 1080},
        {3440, 1440},
        {2560, 1440},
        {1920, 1080},
        {1920, 1200},
        {1536, 864}
    };

    for (const auto& res : supportedResolutions) {
        if (res.first == width && res.second == height) {
            return true;
        }
    }
    return false;
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_UPDATE_TRANSPARENCY:
    {
        int transparencyValue = (int)wParam;
        SetLayeredWindowAttributes(hWnd, 0, transparencyValue, LWA_ALPHA);
        break;
    }
    break;
    case WM_DRAWITEM:
    {
        LPDRAWITEMSTRUCT lpDrawItem = (LPDRAWITEMSTRUCT)lParam;

        if (lpDrawItem->hwndItem == hButton)
        {
            // Determine the button color based on functionsRunning flag
            COLORREF bgColor = functionsRunning ? RGB(128, 0, 0) : RGB(0, 128, 0); // Red if running, green if stopped

            // Fill the button background with the determined color
            HBRUSH hBrush = CreateSolidBrush(bgColor);
            FillRect(lpDrawItem->hDC, &lpDrawItem->rcItem, hBrush);
            DeleteObject(hBrush);

            // Draw the button text centered
            wchar_t buttonText[50];
            GetWindowText(hButton, buttonText, 50);
            SetTextColor(lpDrawItem->hDC, RGB(255, 255, 255)); // White text
            SetBkMode(lpDrawItem->hDC, TRANSPARENT);
            RECT textRect = lpDrawItem->rcItem;
            DrawText(lpDrawItem->hDC, buttonText, -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    }
    break;
    case WM_ACTIVATE:
    {
        if (LOWORD(wParam) != WA_INACTIVE && keepOnTop)
        {
            // Set the window to be always on top when activated
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }
        else
        {
            // Set the window to not be always on top when deactivated
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }
        break;
    }
    case WM_HOTKEY:
    {
        if (wParam == 1) // Hotkey
        {
            // Simulate a button click
            SendMessage(hButton, BM_CLICK, 0, 0);
        }
        break;
    }
    case WM_COMMAND:
    {
        if (HIWORD(wParam) == EN_SETFOCUS && (HWND)lParam == ServerN)
        {
            // When the edit box gains focus, clear the text if it is the ghost text
            wchar_t text[100];
            GetWindowText(ServerN, text, 100);
            if (wcscmp(text, L"Input Server Number") == 0)
                SetWindowText(ServerN, L"");
        }
        else if (HIWORD(wParam) == EN_KILLFOCUS && (HWND)lParam == ServerN)
        {
            // When the edit box loses focus, restore the ghost text if it is empty
            wchar_t text[100];
            GetWindowText(ServerN, text, 100);
            if (wcslen(text) == 0)
                SetWindowText(ServerN, L"Input Server Number");
        }
        if (HIWORD(wParam) == EN_SETFOCUS && (HWND)lParam == XPCraft)
        {
            // When the edit box gains focus, clear the text if it is the ghost text
            wchar_t text[100];
            GetWindowText(XPCraft, text, 100);
            if (wcscmp(text, L"Craft Item") == 0)
                SetWindowText(XPCraft, L"");
        }
        else if (HIWORD(wParam) == EN_KILLFOCUS && (HWND)lParam == XPCraft)
        {
            // When the edit box loses focus, restore the ghost text if it is empty
            wchar_t text[100];
            GetWindowText(XPCraft, text, 100);
            if (wcslen(text) == 0)
                SetWindowText(XPCraft, L"Craft Item");
        }
        if (LOWORD(wParam) >= 1 && LOWORD(wParam) <= 6) {
            // Handle button clicks
            HandleButtonClick(hWnd, wParam);
        }
        // Update button text dynamically based on the hotkey
        std::wstring hotkeyString = MapKeyToString(hotkey);
        if (LOWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton)
        {
            // Start/stop button clicked
            if (functionsRunning)
            {
                // Stop the timer
                KillTimer(hWnd, TimerID);
                // Stop the functions
                shouldContinueLoop = false;
                // Wait for threads to terminate
                Sleep(100);
                functionsRunning = false;
                // Update the button text to "Start" with the current hotkey
                SetWindowText(hButton, (L"Start - " + hotkeyString).c_str());
                // Redraw the button to update its appearance
                RedrawWindow(hButton, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
            }
            else
            {
                // Start the selected function in a new thread
                shouldContinueLoop = true;
                int selectedIndex = static_cast<int>(SendMessage(hDropDown, CB_GETCURSEL, 0, 0));
                if (selectedIndex != CB_ERR)
                {
                    switch (selectedIndex)
                    {
                    case 0: // Auto Join Server
                    {
                        bool isBackupChecked = SendMessage(BackupJN, BM_GETCHECK, 0, 0) == BST_CHECKED;
                        if (isBackupChecked)
                        {
                            std::thread([=] {
                                while (shouldContinueLoop)
                                {
                                    BackupJoiner(ServerN);
                                    Sleep(100);
                                }
                                }).detach();
                        }
                        else
                        {
                            std::thread([=] {
                                while (shouldContinueLoop)
                                {
                                    AutoJoiner(ServerN);
                                    Sleep(100);
                                }
                                }).detach();
                        }
                    }
                    break;
                    case 1: // Auto Clicker
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                bool isACPosChecked = SendMessage(ACPos, BM_GETCHECK, 0, 0) == BST_CHECKED;
                                AutoClicker(isACPosChecked);
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 2: // Anti AFK
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                bool isAFKMChecked = SendMessage(AFKM, BM_GETCHECK, 0, 0) == BST_CHECKED;
                                bool isAFKFDChecked = SendMessage(AFKFD, BM_GETCHECK, 0, 0) == BST_CHECKED;
                                AntiAFK(isAFKMChecked, isAFKFDChecked);
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 3: // AFK Club Ark
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                ClubARK();
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 4: // Farming Tools
                        std::thread([=] {
                            // Get the selected index from FarmTools combobox
                            int selectedFarmTools = static_cast<int>(SendMessage(FarmTools, CB_GETCURSEL, 0, 0));
                            while (shouldContinueLoop)
                            {
                                if (selectedFarmTools == 0) {
                                    AutoFarmer(AutoFarm); // Auto Farmer
                                }
                                else if (selectedFarmTools == 1) {
                                    AutoDropper(AutoDrop); // Auto Dropper
                                }
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 5: // Breeding Tools
                        std::thread([=] {
                            // Get the selected index from BreedTools combobox
                            int selectedBreedTools = static_cast<int>(SendMessage(BreedTools, CB_GETCURSEL, 0, 0));
                            while (shouldContinueLoop)
                            {
                                if (selectedBreedTools == 0) {
                                    SoloNanny(Nanny); // Solo Nanny
                                }
                                else if (selectedBreedTools == 1) {
                                    MassBabyFeed(Nanny); // Mass Baby Feed
                                }
                                else if (selectedBreedTools == 2) {
                                    EggDrop(SpacingD); // Egg Dropper
                                }
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 6: // Auto Grabber
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                AutoGrabber();
                                Sleep(100);
                            }
                            }).detach();
                            break;
                            std::thread([=] {
                                // Get the selected index from PVP Tools combobox
                                int selectedAutoGrab = static_cast<int>(SendMessage(AutoGrab, CB_GETCURSEL, 0, 0));
                                while (shouldContinueLoop)
                                {
                                    if (selectedAutoGrab == 0 || selectedAutoGrab == 1 || selectedAutoGrab == 2 || selectedAutoGrab == 3) {
                                        AutoGrabber();
                                    }
                                    else if (selectedAutoGrab == 4) {
                                        AutoFish(); // Auto Fishing
                                    }
                                    Sleep(100);
                                }
                                }).detach();
                                break;
                    case 7: // PVP Tools
                        std::thread([=] {
                            // Get the selected index from PVP Tools combobox
                            int selectedPVPTools = static_cast<int>(SendMessage(PVPTool, CB_GETCURSEL, 0, 0));
                            while (shouldContinueLoop)
                            {
                                if (selectedPVPTools == 0 || selectedPVPTools == 1) {
                                    PVPTools();
                                }
                                else if (selectedPVPTools == 2) {
                                    TribelogBot(); // Tribelog Bot
                                }
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 8: // Auto Walk / Fly
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                bool isAutoRunChecked = SendMessage(AutoRun, BM_GETCHECK, 0, 0) == BST_CHECKED;
                                AutoWalk(isAutoRunChecked);
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 9: // Magic INI
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                MagicINI();
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 10: // Alarm / Timer
                    {
                        int hours = GetDlgItemInt(hWnd, IDC_TIMER_HOUR, NULL, FALSE);
                        int minutes = GetDlgItemInt(hWnd, IDC_TIMER_MINUTE, NULL, FALSE);
                        int seconds = GetDlgItemInt(hWnd, IDC_TIMER_SECOND, NULL, FALSE);
                        // Start the timer
                        StartTimer(hWnd, hours, minutes, seconds);
                        break;
                    }
                    break;
                    case 11: // XP Party
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                XPParty();
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    case 12: // Dev Tools
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                DevTools();
                                Sleep(100);
                            }
                            }).detach();
                            break;
                    }
                }
                // Update the button text to "Stop" with the current hotkey
                SetWindowText(hButton, (L"Stop - " + hotkeyString).c_str());
                // Redraw the button to update its appearance
                RedrawWindow(hButton, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);

                functionsRunning = true;
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == hDropDown)
        {
            // Drop-down selection changed
            int selectedIndex = static_cast<int>(SendMessage(hDropDown, CB_GETCURSEL, 0, 0));
            if (selectedIndex != CB_ERR)
            {
                // Array of all windows to hide
                HWND windowsToHide[] = {
                    ServerN, BackupJN, FarmTools, AutoFarm, AutoDrop, AFKM, AFKFD, AFKFDM, AFKFDI,
                    ClubARKGame, ClubARKPing, ClubARKDiff, BreedTools, Nanny, Spacing, SpacingD, AutoGrab, AutoRun,
                    AutoFishCon, AutoFishAFK, MagicINISel, MagicINIo, TimerHR, TimerMN, TimerSC, hHUB, 
                    hHDB, hMUB, hMDB, hSUB, hSDB, TimerSND, ACKey, ACInt, ACIntT, ACPos, XPCraft, XPTurnT, XPTurn,
                    XPPutT, XPPut, CATurnT, CATurn, CAFOVT, CAFOV, CAP1, PVPTool, SnailPoly, DevToolsSel
                };
                // Hide all windows in the array
                for (HWND hwnd : windowsToHide)
                {
                    ShowWindow(hwnd, SW_HIDE);
                }
                // Show windows based on the selected index
                switch (selectedIndex)
                {
                case 0: // Auto Joiner
                    ShowWindow(ServerN, SW_SHOW);
                    ShowWindow(BackupJN, SW_SHOW);
                    break;
                case 1: // Auto Clicker
                    ShowWindow(ACKey, SW_SHOW);
                    ShowWindow(ACInt, SW_SHOW);
                    ShowWindow(ACIntT, SW_SHOW);
                    ShowWindow(ACPos, SW_SHOW);
                    break;
                case 2: // Anti AFK
                    ShowWindow(AFKM, SW_SHOW);
                    ShowWindow(AFKFD, SW_SHOW);
                    ShowWindow(AFKFDM, SW_SHOW);
                    ShowWindow(AFKFDI, SW_SHOW);
                    break;
                case 3: // ClubARK
                    ShowWindow(ClubARKGame, SW_SHOW);
                    ShowWindow(ClubARKDiff, SW_SHOW);
                    break;
                case 4: // Farming Tools
                {
                    // Show FarmTools dropdown initially
                    ShowWindow(FarmTools, SW_SHOW);
                    // Check which option is selected in FarmTools dropdown
                    int FarmToolSelection = static_cast<int>(SendMessage(FarmTools, CB_GETCURSEL, 0, 0));
                    if (FarmToolSelection == 0) {
                        ShowWindow(AutoFarm, SW_SHOW);
                        ShowWindow(AutoDrop, SW_HIDE);
                    }
                    else if (FarmToolSelection == 1) {
                        ShowWindow(AutoFarm, SW_HIDE);
                        ShowWindow(AutoDrop, SW_SHOW);
                    }
                    break;
                }
                case 5: // Breeding Tools
                {
                    // Show BreedTools dropdown initially
                    ShowWindow(BreedTools, SW_SHOW);
                    // Check which option is selected in BreedTools dropdown
                    int BreedToolSelection = static_cast<int>(SendMessage(BreedTools, CB_GETCURSEL, 0, 0));
                    if (BreedToolSelection == 0) {
                        ShowWindow(Nanny, SW_SHOW);
                        ShowWindow(Spacing, SW_HIDE);
                        ShowWindow(SpacingD, SW_HIDE);
                    }
                    else if (BreedToolSelection == 1) {
                        ShowWindow(Nanny, SW_SHOW);
                        ShowWindow(Spacing, SW_HIDE);
                        ShowWindow(SpacingD, SW_HIDE);
                    }
                    else if (BreedToolSelection == 2) {
                        ShowWindow(Nanny, SW_HIDE);
                        ShowWindow(Spacing, SW_SHOW);
                        ShowWindow(SpacingD, SW_SHOW);
                    }
                    break;
                }
                case 6: // AutoGrabber
                {
                    ShowWindow(AutoGrab, SW_SHOW);
                    // Check which option is selected in AutoGrabber dropdown
                    int AutoGrabSelection = static_cast<int>(SendMessage(AutoGrab, CB_GETCURSEL, 0, 0));
                    // Adjust visibility of SnailPoly based on the selection
                    switch (AutoGrabSelection) {
                    case 2: // Snails selected
                        ShowWindow(SnailPoly, SW_SHOW);
                        break;
                    default: // All other selections
                        ShowWindow(SnailPoly, SW_HIDE);
                        break;
                    }
                    break;
                }
                case 7: // PVP Tools
                    ShowWindow(PVPTool, SW_SHOW);
                    break;
                case 8: // Auto Walk
                    ShowWindow(AutoRun, SW_SHOW);
                    break;
                case 9: // Magic INI
                {
                    ShowWindow(MagicINISel, SW_SHOW);
                    // Check which option is selected in AutoGrabber dropdown
                    int MagicINISelection = static_cast<int>(SendMessage(MagicINISel, CB_GETCURSEL, 0, 0));
                    // Adjust visibility of SnailPoly based on the selection
                    switch (MagicINISelection) {
                    case 1: // Custom INI
                        ShowWindow(MagicINIo, SW_HIDE);
                        break;
                    default:
                        ShowWindow(MagicINIo, SW_SHOW);
                        break;
                    }
                    break;
                }
                case 10: // Timer
                    ShowWindow(TimerHR, SW_SHOW);
                    ShowWindow(TimerMN, SW_SHOW);
                    ShowWindow(TimerSC, SW_SHOW);
                    ShowWindow(hHUB, SW_SHOW);
                    ShowWindow(hHDB, SW_SHOW);
                    ShowWindow(hMUB, SW_SHOW);
                    ShowWindow(hMDB, SW_SHOW);
                    ShowWindow(hSUB, SW_SHOW);
                    ShowWindow(hSDB, SW_SHOW);
                    ShowWindow(TimerSND, SW_SHOW);
                    break;
                case 11: // XP Party
                    ShowWindow(XPCraft, SW_SHOW);
                    ShowWindow(XPTurnT, SW_SHOW);
                    ShowWindow(XPTurn, SW_SHOW);
                    ShowWindow(XPPutT, SW_SHOW);
                    ShowWindow(XPPut, SW_SHOW);
                    break;
                case 12: // Dev Tools
                    ShowWindow(DevToolsSel, SW_SHOW);
                    break;
                }
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == FarmTools) {
            // Dropdown selection changed, re-check selection and adjust visibility
            int FarmToolSelection = static_cast<int>(SendMessage(FarmTools, CB_GETCURSEL, 0, 0));

            if (FarmToolSelection == 0) { // Auto Farmer selected
                ShowWindow(AutoFarm, SW_SHOW); // Show AutoFarm controls
                ShowWindow(AutoDrop, SW_HIDE); // Hide AutoDrop controls
            }
            else if (FarmToolSelection == 1) { // Auto Dropper selected
                ShowWindow(AutoFarm, SW_HIDE); // Hide AutoFarm controls
                ShowWindow(AutoDrop, SW_SHOW); // Show AutoDrop controls
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == BreedTools) {
            // Dropdown selection changed, re-check selection and adjust visibility
            int BreedToolSelection = static_cast<int>(SendMessage(BreedTools, CB_GETCURSEL, 0, 0));

            if (BreedToolSelection == 0) { // Solo Nanny selected
                ShowWindow(Nanny, SW_SHOW); // Show Nanny controls
                ShowWindow(Spacing, SW_HIDE); // Hide Spacing
                ShowWindow(SpacingD, SW_HIDE); // Hide Spacing Input
            }
            else if (BreedToolSelection == 1) { // Mass Baby Feed selected
                ShowWindow(Nanny, SW_SHOW); // Show Nanny controls
                ShowWindow(Spacing, SW_HIDE); // Hide Spacing
                ShowWindow(SpacingD, SW_HIDE); // Hide Spacing Input
            }
            else if (BreedToolSelection == 2) { // Egg Dropper selected
                ShowWindow(Nanny, SW_HIDE); // Hide Nanny controls
                ShowWindow(Spacing, SW_SHOW); // Show Spacing
                ShowWindow(SpacingD, SW_SHOW); // Show Spacing Input
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == AutoGrab) {
            // Dropdown selection changed, re-check selection and adjust visibility
            int GrabberSelection = static_cast<int>(SendMessage(AutoGrab, CB_GETCURSEL, 0, 0));
            switch (GrabberSelection) {
            case 0: // Air Drop selected
            case 1: // Raptor Claus selected
            case 3: // Crops selected
            case 4: // Auto Fish selected
                ShowWindow(SnailPoly, SW_HIDE);
                break;
            case 2: // Snails selected
                ShowWindow(SnailPoly, SW_SHOW);
                break;
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == MagicINISel) {
            // Dropdown selection changed, re-check selection and adjust visibility
            int MagicINISelection = static_cast<int>(SendMessage(MagicINISel, CB_GETCURSEL, 0, 0));
            switch (MagicINISelection) {
            case 0: // Clean Air selected
                ShowWindow(MagicINIo, SW_SHOW);
                break;
            case 1: // Custom selected
                ShowWindow(MagicINIo, SW_HIDE);
                break;
            }
        }
        switch (LOWORD(wParam))
        {
        case IDM_ABBTIME:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABBTIMEBOX), hWnd, AbbTime);
            break;
        case IDM_COLORID:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_COLORIDBOX), hWnd, ColorID);
            break;
        case IDM_PLAYERXP:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_PLAYERXPBOX), hWnd, PlayerXP);
            break;
        case IDM_SETTINGS:
            ShowSettingsWindow(hWnd);
            break;
        case IDM_USERGUIDE:
            // Show the user guide dialog
            DialogBox(hInst, MAKEINTRESOURCE(IDD_USERGUIDEBOX), hWnd, UserGuide);
            break;
        case IDM_CHANGELOG:
            // Show the changelog dialog
            DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGELOGBOX), hWnd, ChangeLog);
            break;
        case IDM_TROUBLE:
            // Show the troubleshooting dialog
            DialogBox(hInst, MAKEINTRESOURCE(IDD_TROUBLEBOX), hWnd, Trouble);
            break;
        case IDM_UPDATE:
            // Check for updates during initialization
            CheckForUpdates(hInst, hWnd, nullptr);
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_CREATE:
    {
        // Load hotkeys from the configuration file
        LoadSettings(); // Call to load hotkeys

        // Create the start/stop button as an owner-drawn button
        std::wstring hotkeyString = MapKeyToString(hotkey); // Convert hotkey to string
        std::wstring buttonText = L"Start - " + hotkeyString; // Create button label

        hButton = CreateWindowEx(0, L"BUTTON", buttonText.c_str(), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
            170, 10, 100, 25, hWnd, NULL, hInst, NULL);

        // Create the drop-down box
        hDropDown = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 10, 150, 300, hWnd, NULL, hInst, NULL);

        // Add items to the drop-down box
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Join Server"); // Case 0
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Clicker");     // Case 1
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Anti AFK");         // Case 2
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"AFK Club ARK");     // Case 3
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Farming Tools");    // Case 4
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Breeder Tools");    // Case 5
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Grabber");     // Case 6
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"PVP Tools");        // Case 7
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Walk / Fly");  // Case 8
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Magic INI");        // Case 9
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Alarm / Timer");    // Case 10
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"AFK XP Party");     // Case 11
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Dev Tools");        // Case 12
        SendMessage(hDropDown, CB_SETCURSEL, 0, 0);

        // Create the ServerNumber edit box
        ServerN = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Input Server Number", WS_CHILD | WS_VISIBLE,
            10, 41, 150, 22, hWnd, NULL, hInst, NULL);
        // Create Checkbox for Backup Joiner
        BackupJN = CreateWindow(L"BUTTON", L"Backup Join", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 170, 42, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the Farming Tools drop-down box
        FarmTools = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 110, 300, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(FarmTools, CB_ADDSTRING, 0, (LPARAM)L"Auto Farmer");    // Case 0
        SendMessage(FarmTools, CB_ADDSTRING, 0, (LPARAM)L"Auto Dropper");   // Case 1
        SendMessage(FarmTools, CB_SETCURSEL, 0, 0);
        // Create the AutoFarm Edit Box
        AutoFarm = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Stone,Flint,Thatch,Wood", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            125, 40, 144, 24, hWnd, NULL, hInst, NULL);
        AutoDrop = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Raw,Chitin,Hide", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            125, 40, 144, 24, hWnd, NULL, hInst, NULL);

        // Create Checkboxes for AntiAFK
        // AFKM = CreateWindow(L"BUTTON", L"Move", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 10, 42, 60, 20, hWnd, NULL, hInst, NULL);
        AFKFD = CreateWindow(L"BUTTON", L"Eat / Drink", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 75, 42, 95, 20, hWnd, NULL, hInst, NULL);
        // Automatically check the checkbox
        SendMessage(AFKM, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(AFKFD, BM_SETCHECK, BST_CHECKED, 0);
        // Create the AntiAFK Edit Box
        AFKFDM = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"60", WS_CHILD | WS_VISIBLE | ES_NUMBER,
            170, 41, 25, 20, hWnd, NULL, hInst, NULL);
        AFKFDI = CreateWindowEx(0, L"STATIC", L"Minute(s)", WS_VISIBLE | WS_CHILD, 200, 43, 100, 20, hWnd, NULL, hInst, NULL);

        // Create the Breed Tools drop-down box
        BreedTools = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(BreedTools, CB_ADDSTRING, 0, (LPARAM)L"Solo Nanny");
        SendMessage(BreedTools, CB_ADDSTRING, 0, (LPARAM)L"Mass Baby Feed");
        SendMessage(BreedTools, CB_ADDSTRING, 0, (LPARAM)L"Fert Egg Dropper");
        SendMessage(BreedTools, CB_SETCURSEL, 0, 0);
        // Create the Nanny drop-down box
        Nanny = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            170, 40, 100, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(Nanny, CB_ADDSTRING, 0, (LPARAM)L"Raw meat");
        SendMessage(Nanny, CB_ADDSTRING, 0, (LPARAM)L"Berry");
        SendMessage(Nanny, CB_ADDSTRING, 0, (LPARAM)L"Kibble");
        SendMessage(Nanny, CB_SETCURSEL, 0, 0);
        // Create Checkboxes for XP Party
        Spacing = CreateWindowEx(0, L"STATIC", L"Spacing:", WS_VISIBLE | WS_CHILD, 170, 44, 135, 20, hWnd, NULL, hInst, NULL);
        // Create the ServerNumber edit box
        SpacingD = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"50", WS_CHILD | WS_VISIBLE,
            230, 41, 40, 22, hWnd, NULL, hInst, NULL);

        // Create the main timer display box
        TimerHR = CreateWindowEx(0, L"STATIC", L"00:", WS_VISIBLE | WS_CHILD, 20, 40, 20, 20, hWnd, (HMENU)IDC_TIMER_HOUR, hInst, NULL);
        TimerMN = CreateWindowEx(0, L"STATIC", L"00:", WS_VISIBLE | WS_CHILD, 63, 40, 20, 20, hWnd, (HMENU)IDC_TIMER_MINUTE, hInst, NULL);
        TimerSC = CreateWindowEx(0, L"STATIC", L"00", WS_VISIBLE | WS_CHILD, 106, 40, 20, 20, hWnd, (HMENU)IDC_TIMER_SECOND, hInst, NULL);
        // Create buttons for hours, minutes, and seconds adjustments
        hHUB = CreateWindow(L"BUTTON", L"▲", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 40, 10, 20, hWnd, (HMENU)1, hInst, NULL); // Hours up
        hHDB = CreateWindow(L"BUTTON", L"▼", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 40, 40, 10, 20, hWnd, (HMENU)2, hInst, NULL); // Hours down
        hMUB = CreateWindow(L"BUTTON", L"▲", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 53, 40, 10, 20, hWnd, (HMENU)3, hInst, NULL); // Minutes up
        hMDB = CreateWindow(L"BUTTON", L"▼", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 83, 40, 10, 20, hWnd, (HMENU)4, hInst, NULL); // Minutes down
        hSUB = CreateWindow(L"BUTTON", L"▲", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 96, 40, 10, 20, hWnd, (HMENU)5, hInst, NULL); // Seconds up
        hSDB = CreateWindow(L"BUTTON", L"▼", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 126, 40, 10, 20, hWnd, (HMENU)6, hInst, NULL); // Seconds down
        // Create Checkbox for Sound
        TimerSND = CreateWindow(L"BUTTON", L"Enable Sound", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 160, 41, 110, 20, hWnd, (HMENU)7, hInst, NULL);

        // Create Checkbox for AutoWalk
        AutoRun = CreateWindow(L"BUTTON", L"Run Modifier", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 10, 41, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the MagicINI drop-down box
        MagicINISel = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(MagicINISel, CB_ADDSTRING, 0, (LPARAM)L"Clean Air");
        SendMessage(MagicINISel, CB_ADDSTRING, 0, (LPARAM)L"Custom");
        SendMessage(MagicINISel, CB_SETCURSEL, 0, 0);
        // Create the MagicINI enable/disable box
        MagicINIo = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            170, 40, 100, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(MagicINIo, CB_ADDSTRING, 0, (LPARAM)L"Enable");
        SendMessage(MagicINIo, CB_ADDSTRING, 0, (LPARAM)L"Disable");
        SendMessage(MagicINIo, CB_SETCURSEL, 0, 0);

        // Create the ClubARKGame drop-down box
        ClubARKGame = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(ClubARKGame, CB_ADDSTRING, 0, (LPARAM)L"Doed Dodge");
        SendMessage(ClubARKGame, CB_ADDSTRING, 0, (LPARAM)L"Duck Duck Jump");
        SendMessage(ClubARKGame, CB_SETCURSEL, 0, 0);
        
        // Create Turn textbox for CA Doed
        CATurnT = CreateWindowEx(0, L"STATIC", L"Turn", WS_VISIBLE | WS_CHILD, 202, 43, 135, 20, hWnd, NULL, hInst, NULL);
        // Create the XP Party Turn Duration edit box
        CATurn = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"65", WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_AUTOHSCROLL,
            170, 40, 30, 23, hWnd, NULL, hInst, NULL);

        // Create FOV textbox for DDJ
        CAFOVT = CreateWindowEx(0, L"STATIC", L"FOV", WS_VISIBLE | WS_CHILD, 202, 43, 135, 20, hWnd, NULL, hInst, NULL);
        // Create the CA FOV Location edit box
        CAFOV = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"50", WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_AUTOHSCROLL,
            170, 40, 30, 23, hWnd, NULL, hInst, NULL);

        // Create Checkboxes for AntiAFK
        CAP1 = CreateWindow(L"BUTTON", L"P1", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 235, 42, 60, 20, hWnd, NULL, hInst, NULL);
        // Automatically check the checkbox
        SendMessage(CAP1, BM_SETCHECK, BST_CHECKED, 0);

        // Create the ClubARKGame drop-down box
        ClubARKDiff = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            170, 40, 100, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(ClubARKDiff, CB_ADDSTRING, 0, (LPARAM)L"Alpha");
        SendMessage(ClubARKDiff, CB_SETCURSEL, 0, 0);

        // Create the Snail checkbox
        SnailPoly = CreateWindow(L"BUTTON", L"Polymer", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 170, 42, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the AutoFish checkbox
        AutoFishAFK = CreateWindow(L"BUTTON", L"AFK", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 10, 41, 110, 20, hWnd, NULL, hInst, NULL);
        AutoFishCon = CreateWindow(L"BUTTON", L"Controller", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 65, 41, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the AutoGrabber drop-down box
        AutoGrab = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(AutoGrab, CB_ADDSTRING, 0, (LPARAM)L"Air Drop");
        SendMessage(AutoGrab, CB_ADDSTRING, 0, (LPARAM)L"Raptor Claus");
        SendMessage(AutoGrab, CB_ADDSTRING, 0, (LPARAM)L"Empty Snails");
        SendMessage(AutoGrab, CB_ADDSTRING, 0, (LPARAM)L"Empty Crop Plots");
        SendMessage(AutoGrab, CB_ADDSTRING, 0, (LPARAM)L"Auto Fishing");
        SendMessage(AutoGrab, CB_SETCURSEL, 0, 0);

        // Create the PVP Tools drop-down box
        PVPTool = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(PVPTool, CB_ADDSTRING, 0, (LPARAM)L"Death Bag Grab");
        SendMessage(PVPTool, CB_ADDSTRING, 0, (LPARAM)L"Auto Flak Changer");
        SendMessage(PVPTool, CB_ADDSTRING, 0, (LPARAM)L"Tribelog Bot");
        SendMessage(PVPTool, CB_SETCURSEL, 0, 0);

        // Create the AutoClicker drop-down box
        ACKey = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 56, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(ACKey, CB_ADDSTRING, 0, (LPARAM)L"A");
        SendMessage(ACKey, CB_ADDSTRING, 0, (LPARAM)L"E");
        SendMessage(ACKey, CB_ADDSTRING, 0, (LPARAM)L"F");
        SendMessage(ACKey, CB_ADDSTRING, 0, (LPARAM)L"O");
        SendMessage(ACKey, CB_ADDSTRING, 0, (LPARAM)L"LMB");
        SendMessage(ACKey, CB_ADDSTRING, 0, (LPARAM)L"RMB");
        SendMessage(ACKey, CB_SETCURSEL, 0, 0);
        // Create the AutoCliker Interval Edit Box
        ACInt = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"200", WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
            75, 41, 50, 22, hWnd, NULL, hInst, NULL);
        ACIntT = CreateWindowEx(0, L"STATIC", L"Ms", WS_VISIBLE | WS_CHILD, 130, 44, 100, 22, hWnd, NULL, hInst, NULL);
        // Create Position Checkbox for AutoClicker
        ACPos = CreateWindow(L"BUTTON", L"Set Position", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 170, 42, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the XP Party Craft Item edit box
        XPCraft = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Craft Item", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            10, 40, 72, 23, hWnd, NULL, hInst, NULL);
        // Create Turn textbox for XP Party
        XPTurnT = CreateWindowEx(0, L"STATIC", L"Turn:", WS_VISIBLE | WS_CHILD, 92, 44, 135, 20, hWnd, NULL, hInst, NULL);
        // Create the XP Party Turn Duration edit box
        XPTurn = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"36", WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_AUTOHSCROLL,
            130, 40, 30, 23, hWnd, NULL, hInst, NULL);
        // Create Put textbox for XP Party
        XPPutT = CreateWindowEx(0, L"STATIC", L"Put:", WS_VISIBLE | WS_CHILD, 170, 44, 135, 20, hWnd, NULL, hInst, NULL);
        // Create the XP Party Put drop-down box
        XPPut = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            200, 40, 70, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(XPPut, CB_ADDSTRING, 0, (LPARAM)L"None");
        SendMessage(XPPut, CB_ADDSTRING, 0, (LPARAM)L"Grind");
        SendMessage(XPPut, CB_ADDSTRING, 0, (LPARAM)L"Dedi");
        SendMessage(XPPut, CB_ADDSTRING, 0, (LPARAM)L"Drop");
        SendMessage(XPPut, CB_ADDSTRING, 0, (LPARAM)L"Throw");
        SendMessage(XPPut, CB_SETCURSEL, 0, 0);

        // Create the DevTools drop-down box
        DevToolsSel = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(DevToolsSel, CB_ADDSTRING, 0, (LPARAM)L"STS");
        SendMessage(DevToolsSel, CB_ADDSTRING, 0, (LPARAM)L"Temp");
        SendMessage(DevToolsSel, CB_SETCURSEL, 0, 0);

        // Initially hide the boxes
        ShowWindow(AFKM, SW_HIDE);
        ShowWindow(AFKFD, SW_HIDE);
        ShowWindow(AFKFDM, SW_HIDE);
        ShowWindow(AFKFDI, SW_HIDE);
        ShowWindow(FarmTools, SW_HIDE);
        ShowWindow(AutoFarm, SW_HIDE);
        ShowWindow(AutoDrop, SW_HIDE);
        ShowWindow(ClubARKPing, SW_HIDE);
        ShowWindow(ClubARKGame, SW_HIDE);
        ShowWindow(ClubARKDiff, SW_HIDE);
        ShowWindow(CATurnT, SW_HIDE);
        ShowWindow(CATurn, SW_HIDE);
        ShowWindow(CAFOVT, SW_HIDE);
        ShowWindow(CAFOV, SW_HIDE);
        ShowWindow(CAP1, SW_HIDE);
        ShowWindow(BreedTools, SW_HIDE);
        ShowWindow(Nanny, SW_HIDE);
        ShowWindow(Spacing, SW_HIDE);
        ShowWindow(SpacingD, SW_HIDE);
        ShowWindow(AutoGrab, SW_HIDE);
        ShowWindow(SnailPoly, SW_HIDE);
        ShowWindow(PVPTool, SW_HIDE);
        ShowWindow(AutoRun, SW_HIDE);
        ShowWindow(AutoFishCon, SW_HIDE);
        ShowWindow(AutoFishAFK, SW_HIDE);
        ShowWindow(MagicINISel, SW_HIDE);
        ShowWindow(MagicINIo, SW_HIDE);
        ShowWindow(TimerHR, SW_HIDE);
        ShowWindow(TimerMN, SW_HIDE);
        ShowWindow(TimerSC, SW_HIDE);
        ShowWindow(hHUB, SW_HIDE);
        ShowWindow(hHDB, SW_HIDE);
        ShowWindow(hMUB, SW_HIDE);
        ShowWindow(hMDB, SW_HIDE);
        ShowWindow(hSUB, SW_HIDE);
        ShowWindow(hSDB, SW_HIDE);
        ShowWindow(TimerSND, SW_HIDE);
        ShowWindow(XPTurnT, SW_HIDE);
        ShowWindow(XPCraft, SW_HIDE);
        ShowWindow(XPTurn, SW_HIDE);
        ShowWindow(XPPutT, SW_HIDE);
        ShowWindow(XPPut, SW_HIDE);
        ShowWindow(ACKey, SW_HIDE);
        ShowWindow(ACInt, SW_HIDE);
        ShowWindow(ACIntT, SW_HIDE);
        ShowWindow(ACPos, SW_HIDE);
        ShowWindow(DevToolsSel, SW_HIDE);

        // Update the static text control with the actual screen resolution
        RECT rcClient;
        GetClientRect(hWnd, &rcClient);
        hStaticText = CreateWindowEx(0, L"STATIC", L"", WS_VISIBLE | WS_CHILD, 10, 65, 300, 20, hWnd, NULL, hInst, NULL);
        WCHAR text[300];
        if (IsResolutionSupported(screenWidth, screenHeight)) {
            swprintf_s(text, 300, L"Screen Resolution: %dx%d (Supported)", screenWidth, screenHeight);
            SetWindowText(hStaticText, text);
        }
        else {
            swprintf_s(text, 300, L"Screen Resolution: %dx%d (Unsupported)", screenWidth, screenHeight);
            SetWindowText(hStaticText, text);
        }
        HFONT hFont = CreateFont(
            -MulDiv(10, GetDeviceCaps(GetDC(hWnd), LOGPIXELSY), 72), // Height of font (10 pt)
            0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_SWISS, L"Segoe UI"); // Font face name

        SendMessage(hStaticText, WM_SETFONT, (WPARAM)hFont, TRUE);

        // Set the background color of the window to dark gray
        SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(0, 0, 0)));
    }
    break;
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkMode(hdcStatic, TRANSPARENT); // Make background transparent
        return (INT_PTR)hbrBackground;
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;
    }
    break;
    case WM_DESTROY:
        // Unregister the hotkey
        UnregisterHotKey(hWnd, 1);
        // Stop the functions
        shouldContinueLoop = false;
        // Clean up created resources
        DeleteObject(hbrBackground);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}