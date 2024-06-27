#include "pch.h"
#include "Menu.h"
#include "resource.h"

// Global variable to store the background brush
extern HBRUSH hbrBackground;

// Message handler for userguidebox box.
INT_PTR CALLBACK UserGuide(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        HWND hStatic = GetDlgItem(hDlg, IDC_USERGUIDE);
        if (hStatic)
        {
            const char* UserGuideText =
                "     - Click Start on AutoJoiner and on server selection screen without any server highlighted and should take over\r\n\r\n"
                "     - Select task you want from drop down box and click \"Start\" button.\r\n\r\n"
                "     - The Button will change to \"Stop\" to stop the current command from running.\r\n\r\n"
                "     - Will automatically eat/drink every 1hr on AntiAFK, please have food/drink in hotbar 9/0\r\n\r\n"
                "     - If the program is not working for you right click and \"Run as Administrator\"\r\n\r\n"
                "     - Currently only works for resolutions 3440x1440, 2560x1440, 1920x1080, 1920x1200, 1536x864\r\n";

            SetWindowTextA(hStatic, UserGuideText);
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