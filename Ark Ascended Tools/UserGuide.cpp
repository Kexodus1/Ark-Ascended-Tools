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
                "     - There is a delay on most functions when you start them to be able to click the ark program before the function starts.  It is better to start each function using the hotkey while ARK is the active window.  Select the function you want from the drop down box and press the \"Start\" button (Hotkey \"F4\").  The Button will change to \"Stop\" to stop the current function from running.\r\n\r\n"
                "--Auto Join Server--\r\n\r\n"
                "     - Type the server number in the \"Input Server Number\" box and hit the \"Start\" button while on the main server selection screen.  The program will take over and automatically attempt to join a full server.  If this function is not working for you check the \"Backup Joiner\" box and re attempt.\r\n\r\n"
                "--Auto Farmer--\r\n\r\n"
                "     - This function is for a tribemate or alt account while being a rider on a farming Dino.  This will automatically left click every 2.5 seconds.  Once Dino becomes black weighted the function will automatically drop items listed in the box below.  Please separate these items by a comma(,).\r\n\r\n"
                "--Auto Drop Items--\r\n\r\n"
                "     - While activated anytime you open the Dino's inventory it will type the inputed items in the text box one by one and drop all of each item.  Please separate these items by a comma(,).  Example: Doing a meat run and typing \"Prime,Hide,Chitin,Keratin\" into the box, this would drop these items every time you open the Dino's inventory.\r\n\r\n"
                "--Anti AFK--\r\n\r\n"
                "     - Anti AFK will automatically move left(A) and right(D) periodically while going prone(X) if the \"Move\" checkbox is checked to prevent getting kicked from server.  If the \"Eat / Drink\" checkbox is checked it will automatically eat and drink with 9 and 0 on the keyboard.  You may input time in minutes to automatically eat and drink, default is 60 minutes.  You may use both \"Move\" and \"Eat / Drink\" together or separately.\r\n\r\n"
                "--AFK Club ARK--\r\n\r\n"
                "     - Will automatically farm club ark points without user input.  It is best to start at the far left mission board so you don't accidentally try to trade a player.  You can either walk up to the mission board or join selected game then start the program.  Currently only supports one game but backend code established to easily add future games.  Duck Duck Jump uses \"E\" for accessing mission board and \"Spacebar\" / \"C\" for the game. (Currently only works for 3440x1440, 2560x1440, and 1920x1080)\r\n\r\n"
                "--Mass Baby Feed--\r\n\r\n"
                "     - This will automatically upon opening baby Dino inventory refresh the food and close the inventory, allowing you to quickly go around and feed multiple baby Dino's.  Select which food type from drop down to feed the babies when you open inventory.  If \"Solo Nanny\" is check marked it will allow you to AFK inside a single baby's inventory and refresh the selected food from the dropdown every 1 minute.  Make sure you have appropriate food in your inventory.\r\n\r\n"
                "--Auto Grabber--\r\n\r\n"
                "     - Depending on which function you have selected from the dropdown when you start this feature.  \"Air Drop\", \"Raptor Claus\", \"Death Bag\", or \"Empty Crop plots\" will quickly grab the items when you open the inventory, taking all instantly, then closing the inventory instantly. \"Empty Crop Plots\" will automatically put fertilizer back before closing inventory.  Any extra fertilizer in inventory will top the crop plot up.\r\n\r\n"
                "--Auto Fishing--\r\n\r\n"
                "     - Added this feature incase they rework fishing in the future.  Will automatically reel in fish when started.  If on controller checkmark the controller box and it will go off of controller prompts.  Selecting AFK will automatically cast and reel in.\r\n\r\n"
                "--Auto Walk / Fly--\r\n\r\n"
                "     - As name implies, will just automatically move you forward without pressing anything.  Check the \"Run Modifier\" box to change it to running forward automatically.\r\n\r\n"
                "--Magic INI--\r\n\r\n"
                "     - Currently only one INI setting is added, \"Clean Air\".  When selected will remove fog and clouds, you can enable / disable this with the dropdown.  Implemented the code to be able to easily add future INI settings.  I have not been in the ARK loop for a little while so my old \"No Trees\" and \"Invisible Ground\" no longer work.  If new INI's come out I can quickly add them for future use.\r\n\r\n"
                "--Alarm / Timer--\r\n\r\n"
                "     - Set the HR:MIN:SEC then start the timer for it to count down.  Will play a sound when it reaches zero if the checkbox is selected.\r\n\r\n";
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