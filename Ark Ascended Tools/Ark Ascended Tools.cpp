// Ark Ascended Tools.cpp : Defines the entry point for the application.
//

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Menu.h"
#include "Features.h"
#include <codecvt>
#include <CommCtrl.h>
#include <thread> // for std::thread
#include <atomic>
#include <vector>
#include <string>
#pragma comment(lib, "comctl32.lib")
#define WM_UPDATE_TRANSPARENCY (WM_USER + 1)

// Global Variables:
std::atomic<bool> shouldContinueLoop(true);
std::atomic<bool> functionsRunning(false); // Variable to keep track of whether the functions are running
bool keepOnTop = true;
bool isTimerRunning = false;
UINT customHotkey = 0;
UINT_PTR timerID = 0;
HWND ServerN = NULL, BackupJN, AutoFarm = NULL, AFKFD, Nanny = NULL, AutoRun;
HWND TimerHR, TimerMN, TimerSC, hHUB, hHDB, hMUB, hMDB, hSUB, hSDB, TimerSND;
HWND DevTool, MagicINI, ClubARK, AutoFish;
HWND hDropDown, hButton, hStaticRes, hStaticText;
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HBRUSH hbrBackground = CreateSolidBrush(RGB(0, 0, 0));

class Settings
{
public:
    static std::atomic<int> TransparencySetting;

    static int GetTransparencySetting()
    {
        return TransparencySetting.load();
    }

    static void SetTransparencySetting(int transparency)
    {
        TransparencySetting.store(transparency);
    }
};

std::atomic<int> Settings::TransparencySetting(255); // Default to fully opaque

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    ColorID(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    ChangeLog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    UserGuide(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    SettingsDlgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
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

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

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

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
        CW_USEDEFAULT, 0, 300, 400, nullptr, nullptr, hInstance, nullptr);

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

    // Register F4 as a hotkey
    RegisterHotKey(hWnd, 1, 0, VK_F4);

    // Set transparency based on the setting
    int transparency = Settings::GetTransparencySetting();
    SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), transparency, LWA_ALPHA);


    return TRUE;
}

// Function to check if a resolution is supported
//
// Code for Supported Resolution
//
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

bool IsResolutionSupported(int width, int height) {
    std::vector<std::pair<int, int>> supportedResolutions = {
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


// 
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_UPDATE_TRANSPARENCY:
    {
        int transparency = (int)wParam;
        SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), transparency, LWA_ALPHA);
        break;
    }
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
        if (wParam == 1)
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
        if (LOWORD(wParam) >= 1 && LOWORD(wParam) <= 6) {
            // Handle button clicks
            HandleButtonClick(hWnd, wParam);
        }
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
                // Update the button text to "Start"
                SetWindowText(hButton, L"Start - F4");
                // Redraw the button to update its appearance
                RedrawWindow(hButton, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
                
            }
            else
            {
                // Start the selected function in a new thread
                shouldContinueLoop = true;
                int selectedIndex = SendMessage(hDropDown, CB_GETCURSEL, 0, 0);
                if (selectedIndex != CB_ERR)
                {
                    switch (selectedIndex)
                    {
                    case 0:
                    {
                        bool isBackupChecked = SendMessage(BackupJN, BM_GETCHECK, 0, 0) == BST_CHECKED;
                        if (isBackupChecked)
                        {
                            std::thread([=] {
                                while (shouldContinueLoop)
                                {
                                    BackupJoiner(ServerN);
                                    Sleep(100); // Adjust as needed
                                }
                                }).detach();
                        }
                        else
                        {
                            std::thread([=] {
                                while (shouldContinueLoop)
                                {
                                    AutoJoiner(ServerN);
                                    Sleep(100); // Adjust as needed
                                }
                                }).detach();
                        }
                    }
                    break;
                    case 1:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                AutoFarmer(AutoFarm);
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 2:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                AutoDropper(AutoFarm);
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 3:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                AntiAFK();
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 4:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                SoloNanny(Nanny);
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 5:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                MassBabyFeed(Nanny);
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 6:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                DropThief();
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 7: // Timer start button clicked
                    {
                        // Assuming TimerHR, TimerMN, TimerSC are the IDs or handles of your edit controls
                        int hours = GetDlgItemInt(hWnd, IDC_TIMER_HOUR, NULL, FALSE);
                        int minutes = GetDlgItemInt(hWnd, IDC_TIMER_MINUTE, NULL, FALSE);
                        int seconds = GetDlgItemInt(hWnd, IDC_TIMER_SECOND, NULL, FALSE);

                        // Start the timer
                        StartTimer(hWnd, hours, minutes, seconds);
                        break;
                    }
                    break;
                    case 8:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                CropPlots();
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    case 9:
                        std::thread([=] {
                            while (shouldContinueLoop)
                            {
                                AutoWalk();
                                Sleep(100); // Adjust as needed
                            }
                            }).detach();
                            break;
                    }
                }
                // Update the button text to "Stop"
                SetWindowText(hButton, L"Stop - F4");
                // Redraw the button to update its appearance
                RedrawWindow(hButton, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);

                functionsRunning = true;
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == hDropDown)
        {
            // Drop-down selection changed
            int selectedIndex = SendMessage(hDropDown, CB_GETCURSEL, 0, 0);
            if (selectedIndex != CB_ERR)
            {
                // Hide all windows first
                ShowWindow(ServerN, SW_HIDE);
                ShowWindow(BackupJN, SW_HIDE);
                ShowWindow(AutoFarm, SW_HIDE);
                ShowWindow(AFKFD, SW_HIDE);
                ShowWindow(Nanny, SW_HIDE);
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
                ShowWindow(AutoRun, SW_HIDE);
                ShowWindow(hButton, SW_HIDE);
                ShowWindow(DevTool, SW_HIDE);
                ShowWindow(MagicINI, SW_HIDE);
                ShowWindow(ClubARK, SW_HIDE);
                ShowWindow(AutoFish, SW_HIDE);

                // Show windows based on the selected index
                switch (selectedIndex)
                {
                case 0: // Auto Joiner
                    ShowWindow(ServerN, SW_SHOW);
                    ShowWindow(BackupJN, SW_SHOW);
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 1: // Auto Farmer
                case 2: // Auto Drop Items
                    ShowWindow(AutoFarm, SW_SHOW);
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 3: // Anti AFK
                    ShowWindow(AFKFD, SW_SHOW);
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 4: // Solo Nanny
                case 5: // Mass Baby Feed
                    ShowWindow(Nanny, SW_SHOW);
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 6: // Drop Thief
                case 8: // Crop plots
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 7: // Timer
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
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 9: // Auto Walk
                    ShowWindow(AutoRun, SW_HIDE);
                    ShowWindow(hButton, SW_SHOW);
                    break;
                case 10: // Developer Tools
                    ShowWindow(DevTool, SW_SHOW);
                    int DevToolSel = SendMessage(DevTool, CB_GETCURSEL, 0, 0);
                    switch (DevToolSel)
                    {
                    case 0: // "Magic INI" selected
                        ShowWindow(MagicINI, SW_SHOW);
                        ShowWindow(ClubARK, SW_HIDE);
                        ShowWindow(AutoFish, SW_HIDE);
                        break;
                    case 1: // "Club ARK" selected
                        ShowWindow(MagicINI, SW_HIDE);
                        ShowWindow(ClubARK, SW_SHOW);
                        ShowWindow(AutoFish, SW_HIDE);
                        break;
                    case 2: // "Auto Fishing" selected
                        ShowWindow(MagicINI, SW_HIDE);
                        ShowWindow(ClubARK, SW_HIDE);
                        ShowWindow(AutoFish, SW_SHOW);
                        break;
                    default:
                        ShowWindow(MagicINI, SW_HIDE);
                        ShowWindow(ClubARK, SW_HIDE);
                        ShowWindow(AutoFish, SW_HIDE);
                        break;
                    }
                    break;
                }
            }
        }
            else if (HIWORD(wParam) == CBN_SELCHANGE && (HWND)lParam == DevTool)
            {
                // DevTool dropdown selection changed
                int DevToolSel = SendMessage(DevTool, CB_GETCURSEL, 0, 0);
                switch (DevToolSel)
                {
                case 0: // "Magic INI" selected
                    ShowWindow(MagicINI, SW_SHOW);
                    ShowWindow(ClubARK, SW_HIDE);
                    ShowWindow(AutoFish, SW_HIDE);
                    break;
                case 1: // "Club ARK" selected
                    ShowWindow(MagicINI, SW_HIDE);
                    ShowWindow(ClubARK, SW_SHOW);
                    ShowWindow(AutoFish, SW_HIDE);
                    break;
                case 2: // "Auto Fishing" selected
                    ShowWindow(MagicINI, SW_HIDE);
                    ShowWindow(ClubARK, SW_HIDE);
                    ShowWindow(AutoFish, SW_SHOW);
                    break;
                default:
                    ShowWindow(MagicINI, SW_HIDE);
                    ShowWindow(ClubARK, SW_HIDE);
                    ShowWindow(AutoFish, SW_HIDE);
                    break;
                }
            }
        switch (LOWORD(wParam))
        {
        case IDM_COLORID:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_COLORIDBOX), hWnd, ColorID);
            break;
        case IDM_SETTINGS:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_SETTINGSBOX), hWnd, SettingsDlgProc);
            break;
        case IDM_USERGUIDE:
            // Show the user guide dialog
            DialogBox(hInst, MAKEINTRESOURCE(IDD_USERGUIDEBOX), hWnd, UserGuide);
            break;
        case IDM_CHANGELOG:
            // Show the changelog dialog
            DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGELOGBOX), hWnd, ChangeLog);
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
        // Create the start \ stop button as an owner-drawn button
        hButton = CreateWindowEx(0, L"BUTTON", L"Start - F4", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
            170, 10, 100, 25, hWnd, NULL, hInst, NULL);

        // Create the drop-down box
        hDropDown = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 10, 150, 300, hWnd, NULL, hInst, NULL);

        // Add items to the drop-down box
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Join Server");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Farmer");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Drop Items");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Anti AFK");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Solo Nanny");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Mass Baby Feed");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Drop Thief");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Alarm / Timer");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Empty Crop Plots");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Auto Walk / Fly");
        SendMessage(hDropDown, CB_ADDSTRING, 0, (LPARAM)L"Developer Tools");

        // Select "Auto Join Server" by default
        SendMessage(hDropDown, CB_SETCURSEL, 0, 0);

        // Create the ServerNumber edit box
        ServerN = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Input Server Number", WS_CHILD | WS_VISIBLE | ES_NUMBER,
            10, 40, 145, 20, hWnd, NULL, hInst, NULL);
        // Create Checkbox for Backup Joiner
        BackupJN = CreateWindow(L"BUTTON", L"Backup Joiner", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 160, 41, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the AutoFarm Edit Box
        AutoFarm = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"Stone,Flint,Thatch,Wood", WS_CHILD | WS_VISIBLE,
            10, 40, 260, 20, hWnd, NULL, hInst, NULL);

        // Create Checkbox for AntiAFK
        AFKFD = CreateWindow(L"BUTTON", L"Auto Eating / Drinking", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 10, 41, 250, 20, hWnd, NULL, hInst, NULL);
        // Automatically check the checkbox
        SendMessage(AFKFD, BM_SETCHECK, BST_CHECKED, 0);

        // Create the Nanny drop-down box
        Nanny = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 150, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(Nanny, CB_ADDSTRING, 0, (LPARAM)L"Raw meat");
        SendMessage(Nanny, CB_ADDSTRING, 0, (LPARAM)L"Berry");
        SendMessage(Nanny, CB_ADDSTRING, 0, (LPARAM)L"Kibble");
        SendMessage(Nanny, CB_SETCURSEL, 0, 0);

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
        AutoRun = CreateWindow(L"BUTTON", L"Shift Modifier", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 10, 41, 110, 20, hWnd, NULL, hInst, NULL);

        // Create the DevTools drop-down box
        DevTool = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            10, 40, 125, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(DevTool, CB_ADDSTRING, 0, (LPARAM)L"Magic INI");
        SendMessage(DevTool, CB_ADDSTRING, 0, (LPARAM)L"Club ARK");
        SendMessage(DevTool, CB_ADDSTRING, 0, (LPARAM)L"Auto Fishing");
        SendMessage(DevTool, CB_SETCURSEL, 0, 0);

        // Create the MagicINI drop-down box
        MagicINI = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            145, 40, 125, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(MagicINI, CB_ADDSTRING, 0, (LPARAM)L"Clean Air");
        SendMessage(MagicINI, CB_ADDSTRING, 0, (LPARAM)L"No Trees");
        SendMessage(MagicINI, CB_ADDSTRING, 0, (LPARAM)L"Invisible Map");
        SendMessage(MagicINI, CB_SETCURSEL, 0, 0);

        // Create the ClubARK drop-down box
        ClubARK = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
            145, 40, 125, 200, hWnd, NULL, hInst, NULL);
        // Add items to the drop-down box
        SendMessage(ClubARK, CB_ADDSTRING, 0, (LPARAM)L"Train Heist");
        SendMessage(ClubARK, CB_ADDSTRING, 0, (LPARAM)L"Whacka-Mole");
        SendMessage(ClubARK, CB_ADDSTRING, 0, (LPARAM)L"Dueling");
        SendMessage(ClubARK, CB_SETCURSEL, 0, 0);

        // Create the AutoFish checkbox
        AutoFish = CreateWindow(L"BUTTON", L"Controller", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 145, 41, 110, 20, hWnd, NULL, hInst, NULL);

        // Initially hide the boxes
        ShowWindow(AFKFD, SW_HIDE);
        ShowWindow(AutoFarm, SW_HIDE);
        ShowWindow(Nanny, SW_HIDE);
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
        ShowWindow(AutoRun, SW_HIDE);
        ShowWindow(DevTool, SW_HIDE);
        ShowWindow(MagicINI, SW_HIDE);
        ShowWindow(ClubARK, SW_HIDE);
        ShowWindow(AutoFish, SW_HIDE);

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

// Message handler for ColorIDs box.
INT_PTR CALLBACK ColorID(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (message)
    {
    case WM_INITDIALOG:
    {
        // Get handle to the static control where the image will be displayed
        HWND hStaticImage = GetDlgItem(hDlg, IDB_COLORID); // Replace IDB_PNG1 with your static control ID

        // Load the BMP image
        HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, L"ColorID.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        if (hBitmap != NULL) {
            // Set the image as the background of the static control
            SendMessage(hStaticImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
        }

        // Recreate the background brush and set the background color
        HBRUSH hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;

    case WM_CTLCOLORDLG:
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcDlg = (HDC)wParam;
        SetTextColor(hdcDlg, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcDlg, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)GetStockObject(BLACK_BRUSH);
    }
    }

    return (INT_PTR)FALSE;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    case WM_CTLCOLORDLG:
    {
        HDC hdcDlg = (HDC)wParam;
        SetTextColor(hdcDlg, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcDlg, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;
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

// Message handler for settings box.
INT_PTR CALLBACK SettingsDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    static HWND hSlider;
    static HWND hEdit;

    switch (message)
    {
    case WM_INITDIALOG:
    {
        hSlider = GetDlgItem(hDlg, IDC_TRANSPARENCY_SLIDER);
        hEdit = GetDlgItem(hDlg, IDC_TRANSPARENCY_EDIT);

        // Initialize the slider range (0 to 255) and position
        SendMessage(hSlider, TBM_SETRANGE, TRUE, MAKELPARAM(25, 255));
        int transparency = Settings::TransparencySetting;
        SendMessage(hSlider, TBM_SETPOS, TRUE, transparency);
        SetDlgItemInt(hDlg, IDC_TRANSPARENCY_EDIT, transparency, FALSE);

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return (INT_PTR)TRUE;
    }

    case WM_HSCROLL:
        if ((HWND)lParam == hSlider) {
            int pos = SendMessage(hSlider, TBM_GETPOS, 0, 0);
            Settings::SetTransparencySetting(pos); // Update the transparency setting
            SetDlgItemInt(hDlg, IDC_TRANSPARENCY_EDIT, pos, FALSE);

            // Send a custom message to the main window to update transparency
            HWND hMainWnd = GetParent(hDlg);
            SendMessage(hMainWnd, WM_UPDATE_TRANSPARENCY, pos, 0);
        }
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK) {
            int transparency = GetDlgItemInt(hDlg, IDC_TRANSPARENCY_EDIT, NULL, FALSE);
            Settings::SetTransparencySetting(transparency);

            // Send a custom message to the main window to update transparency
            HWND hMainWnd = GetParent(hDlg);
            SendMessage(hMainWnd, WM_UPDATE_TRANSPARENCY, transparency, 0);

            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;

    case WM_CTLCOLORDLG:
    {
        HDC hdcDlg = (HDC)wParam;
        SetTextColor(hdcDlg, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcDlg, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }

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