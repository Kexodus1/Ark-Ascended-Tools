#include "../Headers/Menus.h"
#include "../Headers/resource.h"

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
                "            -----------------------------------------------\r\n"
                "            --Troubleshooting Common Issues--\r\n"
                "            -----------------------------------------------\r\n\r\n"
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
                "     - Try running the program in Administrator mode and\r\n"
                "       relaunch to see if it works.\r\n\r\n"
                "--I see (Unsupported) at the bottom:\r\n"
                "     - Currently only resolutions 3840x2160, 3840x1080,\r\n"
                "       3440x1440, 2560x1440, 1920x1080, 1920x1200,\r\n"
                "       and 1536x864 are supported.\r\n\r\n"
                "              --------------------------------------------\r\n"
                "              --Troubleshooting AFK Club ARK--\r\n"
                "              --------------------------------------------\r\n\r\n"
                "--I keep getting hit in Club ARK:\r\n"
                "     - To achieve the best possible success rate you\r\n"
                "       should copy the video and camera settings each\r\n"
                "       resolution was calibrated for.\r\n"
                "     1. Video Settings:\r\n"
                "         - Max Frame Rate: Uncapped\r\n"
                "         - DLSS: Ultra Performance\r\n"
                "         - Resolution Scaling 80%\r\n"
                "         - Default Gamma: 1.8\r\n"
                "         - VSYNC: Off\r\n"
                "     2. Camera Settings:\r\n"
                "         - 50 FOV (the FOV is critical and can be slightly\r\n"
                "           increased to jump slower or decreased to jump\r\n"
                "           faster)\r\n\r\n"
                "              --------------------------------------------\r\n"
                "              --Troubleshooting AFK XP Party--\r\n"
                "              --------------------------------------------\r\n\r\n"
                "--XP Party is not working for me:\r\n"
                "     - Currently only resolutions 3440x1440, 2560x14440,\r\n"
                "       and 1920x1080 are supported. Make sure you are\r\n"
                "       using base gamma 2.2\r\n\r\n"
                "--XP Party is using too much food and drink:\r\n"
                "     - Calibrated at gamma 2.2, since the backgrounds\r\n"
                "       are translucent for food and water, the background\r\n"
                "       is too dark behind them.  Increase gamma in\r\n"
                "       increments of 0.1 (e.g. 2.3, 2.4) until it is eating\r\n"
                "       and drinking correctly.\r\n\r\n"
                "--XP Party is not using food and drink:\r\n"
                "     - Same as mentioned above except the background\r\n"
                "       is too light behind the icons.  Starting with gamma\r\n"
                "       2.2 slowly decrease by 0.1 (e.g. 2.1, 2.0) until\r\n"
                "       working properly.\r\n\r\n"
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