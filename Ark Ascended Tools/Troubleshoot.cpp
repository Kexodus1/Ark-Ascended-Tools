#include "pch.h"
#include "Features.h"
#include "resource.h"

// Global variable to store the background brush
extern HBRUSH hbrBackground;

// Message handler for Troubleshooting box.
INT_PTR CALLBACK Trouble(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        HWND hEdit = GetDlgItem(hDlg, IDC_TROUBLE);
        if (hEdit)
        {
            const char* userguideText =
                "            --Troubleshooting Common Issues--\r\n\r\n"
                "--My resolution is not showing correctly:\r\n"
                "     - Make sure you have scaling in windows System >\r\n"
                "       Display set to 100%. If that is correct then make\r\n"
                "       sure your main display is set to the monitor you\r\n"
                "       are using ARK on.\r\n\r\n"
                "--Does in game resolution matter:\r\n"
                "     - The tools function off of your main display\r\n"
                "       resolution. Using 2560x1440 main display and\r\n"
                "       1920x1080 in game would perform correctly. Make\r\n"
                "       sure your in game aspect ratio is the same as\r\n"
                "       your main display. (21:9, 16:9, or 16:10)\r\n\r\n"
                "--The program isn't functioning:\r\n"
                "     - Try running the program in Administrator mode\r\n"
                "       and relaunch to see if it works.\r\n\r\n"
                "--I see (Unsupported) at the bottom:\r\n"
                "     - Currently only resolutions 3840x2160, 3440x1440,\r\n"
                "       2560x1440, 1920x1080, 1920x1200, and 1536x864\r\n"
                "       are supported.\r\n\r\n"
                "--I have a different issue not listed:\r\n"
                "     - You can always contact me on discord or fill out a\r\n"
                "       new issue on github Ark-Ascended-Tools/issues.\r\n"
                "       Contact info in \"About\"\r\n";


            SetWindowTextA(hEdit, userguideText);
        }

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return TRUE;
    }
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
        return (INT_PTR)hbrBackground; // Return the background brush
    }
    break;
    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0));         // Set background color to black
        return (INT_PTR)hbrBackground;               // Return the background brush
    }
    break;
    }
    return (INT_PTR)FALSE;
}