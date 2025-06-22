#include "../Headers/Menus.h"
#include "../Headers/resource.h"

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
                "                          ----------------------\r\n"
                "                          --General Guide--\r\n"
                "                          ----------------------\r\n\r\n"
                "     - There is a delay on most functions when you start them to be able to click the ark program before the function starts.  It is better to start each function using the hotkey while ARK is the active window.  Select the function you want from the drop down box and press the \"Start\" button (Hotkey \"F4\").  The Button will change to \"Stop\" to stop the current function from running.\r\n\r\n"
                "                        -------------------------\r\n"
                "                        --Auto Join Server--\r\n"
                "                        -------------------------\r\n\r\n"
                "     - Type the server number in the \"Input Server Number\" box and hit the \"Start\" button while on the main server selection screen.  The program will take over and automatically attempt to join a full server.  If this function is not working for you check the \"Backup Joiner\" box and re attempt.\r\n\r\n"
                "                           -------------------\r\n"
                "                           --Auto Clicker--\r\n"
                "                           -------------------\r\n\r\n"
                "     - Select the key you would like it to press and input a time in milliseconds to press the key.  Wherever the mouse is located when it is started is were it will press the key.  Selecting Set Position checkbox will click at specified position from settings.\r\n\r\n"
                "                             ---------------\r\n"
                "                             --Anti AFK--\r\n"
                "                             ---------------\r\n\r\n"
                "     - Anti AFK will automatically open and close a door, please place a door in front of player.  If the \"Eat / Drink\" checkbox is checked it will automatically eat and drink with specified hotkeys in settings.  You may input time in minutes to automatically eat and drink, default is 60 minutes.\r\n\r\n"
                "                          ----------------------\r\n"
                "                          --AFK Club ARK--\r\n"
                "                          ----------------------\r\n\r\n"
                "     - Will automatically farm club ark points without user input.\r\n\r\n"
                "-{ Doed Dodge }-\r\n"
                "     - Will automatically run around the wall while jumping to complete Doed Dodge.  Adjust turn radius in settings to turn slower or faster.\r\n\r\n"
                "-{ Duck Duck Jump }-\r\n"
                "     - Duck Duck Jump uses specified hotkey for accessing player inventory and \"Spacebar\" / \"S\" for the game.  Gamma adjustment and FOV adjustment from settings will change how Duck Duck Jump performs.\r\n\r\n"
                "                          ----------------------\r\n"
                "                          --Farming Tools--\r\n"
                "                          ----------------------\r\n\r\n"
                "-{ Auto Farmer }-\r\n"
                "     - This function is for a tribemate or alt account while being a rider on a farming Dino.  This will automatically left click every 2.5 seconds.  Once Dino becomes black weighted the function will automatically drop items listed in the box below.  Please separate these items by a comma(,).\r\n\r\n"
                "-{ Auto Dropper }-\r\n"
                "     - While activated anytime you open the Dino's inventory it will type the inputed items in the text box one by one and drop all of each item.  Please separate these items by a comma(,).  Example: Doing a meat run and typing \"Prime,Hide,Chitin,Keratin\" into the box, this would drop these items every time you open the Dino's inventory.\r\n\r\n"
                "                          -----------------------\r\n"
                "                          --Breeder Tools--\r\n"
                "                          -----------------------\r\n\r\n"
                "-{ Solo Nanny }-\r\n"
                "     - Allows you to AFK inside a single baby's inventory and refresh the selected food from the dropdown every 1 minute.  Make sure you have appropriate food in your inventory.\r\n\r\n"
                "-{ Mass Baby Feed }-\r\n"
                "     - This will automatically upon opening baby Dino inventory refresh the food and close the inventory, allowing you to quickly go around and feed multiple baby Dino's.  Select which food type from drop down to feed the babies when you open inventory.\r\n\r\n"
                "-{ Fert Egg Dropper }-\r\n"
                "     - Will automatically open inventory and drop fertilized eggs then slightly move backwards.  Adjust how far apart you want the eggs in the spacing box.  Looking down at the ground before starting allows the eggs to be in a straight line.\r\n\r\n"
                "                         ----------------------\r\n"
                "                         --Auto Grabber--\r\n"
                "                         ----------------------\r\n\r\n"
                "-{ Air Drop }-\r\n"
                "     - When active will automatically take items from drop and close immediately upon opening drop inventory.  You may leave it active if opening drops around map and will perform at every drop you open.  Perfect for places like abberation where time is of the essence.\r\n\r\n"
                "-{ Raptor Claus }-\r\n"
                "     - While active when you open a raptor claus present will immediately take the items mashing transfer all to ensure you get the present.\r\n\r\n"
                "-{ Empty Snails }-\r\n"
                "     - Takes all paste when snail inventory is opened, if poly is checkmarked will also take poly from the snail and close inventory.\r\n\r\n"
                "-{ Empty Crop Plots }-\r\n"
                "     - If yoiu don't have the robot this is a great feature, automatically takes all from crop plot when opened and will transfer the feertilizer bacck.  Fill your inventory with fertilizer to top off the crop plots with fertilizer as well.\r\n\r\n"
                "-{ Auto Fishing }-\r\n"
                "     - Will automatically reel in fish when started.  If on controller checkmark the controller box and it will go off of controller prompts.  Selecting AFK will automatically cast and reel in.\r\n\r\n"
                "                            -----------------\r\n"
                "                            --PVP Tools--\r\n"
                "                            -----------------\r\n\r\n"
                "-{ Death Bag Grab }-\r\n"
                "     - Will grab death bag instantly when you open allowing you to get your items and geet out.  Great feature for PVP especially.\r\n\r\n"
                "-{ Auto Flak Changer }-\r\n"
                "     - (WIP) Automatically changes broken flak when opening inventory.\r\n\r\n"
                "-{ Tribelog Bot }-\r\n"
                "     - (WIP) Will send tribelog activities to disccord.\r\n\r\n"
                "                        ------------------------\r\n"
                "                        --Auto Walk / Fly--\r\n"
                "                        ------------------------\r\n\r\n"
                "     - As name implies, will just automatically move you forward without pressing anything.  Check the \"Run Modifier\" box to change it to running forward automatically.\r\n\r\n"
                "                            -----------------\r\n"
                "                            --Magic INI--\r\n"
                "                            -----------------\r\n\r\n"
                "     - Currently only one INI setting is added, \"Clean Air\".  When selected will remove fog and clouds, you can enable / disable this with the dropdown.  Implemented the code to be able to easily add future INI settings.  I have not been in the ARK loop for a little while so my old \"No Trees\" and \"Invisible Ground\" no longer work.  If new INI's come out I can quickly add them for future use.\r\n\r\n"
                "                          ----------------------\r\n"
                "                          --Alarm / Timer--\r\n"
                "                          ----------------------\r\n\r\n"
                "     - Set the HR:MIN:SEC then start the timer for it to count down.  Will play a sound when it reaches zero if the checkbox is selected.\r\n\r\n"
                "                           ---------------------\r\n"
                "                           --AFK XP Party--\r\n"
                "                           ---------------------\r\n\r\n"
                "     - Start  this function while sitting on a toilet, will automatically que up items to craft that are input in the box.  Every time you stand up it will put the crafted items in what you choose from the dropdown menu.  Then it will pull out a weapon(preferably a bow) and either LCTRL the weapon or punch, auto detecting food, drink, or broth.  The number box is for turning around back to the toilet, depending on fps this value might need to be increased.  Will autodetect poop buff and wait until it goes away before using again then repeating the process over again.  Due to the food/drink bars being translucent, please adjust gamma up from 2.2 by 0.1 increments if eating when not low, and vice versa, adjust gamma down from 2.2 in 0.1 increments if eating when full. (Currently only works for 3440x1440, 2560x1440, and 1920x1080)\r\n\r\n";
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