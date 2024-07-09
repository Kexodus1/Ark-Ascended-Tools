#include "pch.h"
#include "Features.h"
#include "resource.h"

// Global variable to store the background brush
extern HBRUSH hbrBackground;

// Message handler for UserGuide box.
INT_PTR CALLBACK UserGuide(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        HWND hEdit = GetDlgItem(hDlg, IDC_USERGUIDE);
        if (hEdit)
        {
            const char* userguideText =
                "--General Guide--\r\n\r\n"
                "     - Select the function you want from the drop down box and press the \"Start\" button\r\n"
                "     - The Button will change to \"Stop\" to stop the current function from running.\r\n"
                "     - If the program is not working for you right click and \"Run as Administrator\"\r\n"
                "     - Currently only works for resolutions 3440x1440, 2560x1440, 1920x1080, 1920x1200, 1536x864\r\n\r\n"
                "--Auto Join Server--\r\n\r\n"
                "     - Type the server number in the \"Input Server Number\" box and hit the \"Start\" button while on the main server selection screen.  The program will take over and automatically attempt to join a full server.  If this function is not working for you check the \"Backup Joiner\" box and re attempt.\r\n\r\n"
                "--Auto Farmer--\r\n\r\n"
                "     - This function is for a tribemate or alt account while being a rider on a farming Dino.  This will automatically left click every 2.5 seconds.  Once Dino becomes black weighted the function will automatically drop items listed in the box below.  Please separate these items by a comma(,).\r\n\r\n"
                "--Auto Drop Items--\r\n\r\n"
                "     - While activated anytime you open Dino inventory will type the inputed items in the text box one by one and drop all of each item.  Please separate these items by a comma(,).  Example: Doing a meat run and typing \"Prime,Hide,Chitin,Keratin\" into the box, this would drop these items everytime you open the Dino inventory.\r\n\r\n"
                "--Anti AFK--\r\n\r\n"
                "     - Anti AFK will automatically move left(A) and right(D) periodically while going prone(X) if the \"Move\" checkbox is checked to prevent getting kicked from server.  If the \"Eat / Drink\" checkbox is checked it will automatically eat and drink with 9 and 0 on the keyboard.  You may input time in minutes to automatically eat and drink, default is 60 minutes.  You may use both \"Move\" and \"Eat / Drink\" together or separately.\r\n\r\n"
                "--Solo Nanny--\r\n\r\n"
                "     - Allows you to automatically hand feed one baby while being in the inventory.  Select which food you want to hand feed and will periodically every 1 minute refeed baby.  Make sure you have the appropriate quantity of selected food in your inventory.\r\n\r\n"
                "--Mass Baby Feed--\r\n\r\n"
                "     - This will automatically upon opening baby Dino inventory refresh the food and close the inventory, allowing you to quickly go around and feed multiple baby Dino's.\r\n\r\n"
                "--Drop Thief--\r\n\r\n"
                "     - Quickly grabs the drop when you open the inventory, taking all instantly.\r\n\r\n"
                "--Alarm / Timer--\r\n\r\n"
                "     - Set the HR:MIN:SEC then start the timer for it to count down.  Will play a sound when it reaches zero if the checkbox is selected.\r\n\r\n"
                "--Empty Crop Plots--\r\n\r\n"
                "     - Have function started and open crop plot, will automatically take all from crop plot and put the fertilizer back.  Will also refill fertilizer if you have extra in your inventory.\r\n\r\n"
                "--Auto Walk / Fly--\r\n\r\n"
                "     - As name implies, will just automatically move you forward without pressing anything.\r\n\r\n";


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