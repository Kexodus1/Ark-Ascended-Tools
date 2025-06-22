#include "../Headers/Menus.h"
#include "../Headers/resource.h"

// Global variable to store the background brush
extern HBRUSH hbrBackground;

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

// Message handler for PlayerXP box.
INT_PTR CALLBACK PlayerXP(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (message)
    {
    case WM_INITDIALOG:
    {
        // Get handle to the static control where the image will be displayed
        HWND hStaticImage = GetDlgItem(hDlg, IDB_PLAYERXP);

        // Load the PNG image
        HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, L"PlayerXP.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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

// Message handler for the Abb Surface Times dialog box
INT_PTR CALLBACK AbbTime(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
    {
        HWND hStaticNW = GetDlgItem(hDlg, IDC_ABBTIMENW);
        if (hStaticNW)
        {
            const char* AbbTimeNWText =
                "NORTHWEST/EAST\r\n"
                "50%d=50%n 0-3\r\n"
                "06:51 - 18:51\r\n"
                "90%d>10%n 4-6\r\n"
                "02:27 - 23:08\r\n"
                "10%d<90%n 7-9\r\n"
                "11:08 - 14:16\r\n";
            SetWindowTextA(hStaticNW, AbbTimeNWText);
        }

        HWND hStaticSW = GetDlgItem(hDlg, IDC_ABBTIMESW);
        if (hStaticSW)
        {
            const char* AbbTimeSWText =
                "SOUTHWEST\r\n"
                "50%d=50%n 0-3\r\n"
                "08:01 - 18:51\r\n"
                "90%d>10%n 4-6\r\n"
                "04:19 - 23:08\r\n"
                "10%d<90%n 7-9\r\n"
                "11:23 - 14:16\r\n";
            SetWindowTextA(hStaticSW, AbbTimeSWText);
        }

        // Recreate the background brush and set the background color
        HBRUSH hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
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

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        // Set the current version message
        std::wstring currentVersion = ConvertToWideString(GetCurrentVersion());
        SetDlgItemTextW(hDlg, IDC_CURRENT_VERSION, currentVersion.c_str());
        return (INT_PTR)TRUE;

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
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