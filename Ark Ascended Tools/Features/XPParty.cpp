#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"
#include "../Headers/Menus.h"

// Global Variables
void typeText(const std::wstring& text);

// Function to press 'A' key ten times
void pressAKeyTenTimes() {
    for (int i = 0; i < 10; ++i) {
        keybd_event('A', 0, 0, 0); // Key down
        Sleep(50); // Small delay between key down and key up
        keybd_event('A', 0, KEYEVENTF_KEYUP, 0); // Key up
        Sleep(100); // Small delay between key presses
    }
}

// Function to press 'O' key five times
void pressOKeyTenTimes() {
    for (int i = 0; i < 10; ++i) {
        keybd_event('O', 0, 0, 0); // Key down
        Sleep(100); // Small delay between key down and key up
        keybd_event('O', 0, KEYEVENTF_KEYUP, 0); // Key up
        Sleep(150); // Small delay between key presses
    }
}

// Function to press LCTRL for X seconds
void PerformLCTRLClickForSeconds() {
    const int clickDuration = 20 * 1000; // Seconds in milliseconds
    ULONGLONG startTime = GetTickCount64(); // Get the current time

    while (GetTickCount64() - startTime < clickDuration) {
        if (!shouldContinueLoop) {
            break; // Exit the loop immediately if stop condition is met
        }
        // Perform LCTRL click
        keybd_event(VK_LCONTROL, 0, 0, 0); // Key down
        Sleep(50); // Wait for the specified interval
        keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0); // Key up
        Sleep(50); // Wait for the specified interval before the next click
    }
}

void CheckWater()
{
    LoadSettings();
    while (true) {
        // Check Water Needed
        COLORREF water = GetPixelColor(DrinkX, DrinkY);
        if (IsColorWithinTolerance(water, RGB(173, 173, 173), 85))
        {
            Sleep(100);
            break;
        }
        else
        {
            // key to drink water
            PerformKeyPress(static_cast<BYTE>(drinkingHotkey), 100, 500);
            break;
        }
        Sleep(500);
        if (!shouldContinueLoop) break;
    }
}

void CheckFood()
{
    LoadSettings();
    while (true) {
        // Check Food Needed
        COLORREF food = GetPixelColor(EatinX, EatinY);
        if (IsColorWithinTolerance(food, RGB(173, 173, 173), 85))
        {
            Sleep(100);
            break;
        }
        else
        {
            // Press Settings key (to eat food)
            PerformKeyPress(static_cast<BYTE>(eatingHotkey), 100, 500);
            break;
        }
        Sleep(500);
        if (!shouldContinueLoop) break;
    }
}

void PutItemsAway()
{
    LoadSettings();
    while (true) {
        // Get the selected item from the XP Put drop-down box
        LRESULT selIndex = SendMessage(XPPut, CB_GETCURSEL, 0, 0);
        if (selIndex != CB_ERR) // Ensure the selection is valid
        {
            WCHAR selItem[256] = { 0 };
            SendMessage(XPPut, CB_GETLBTEXT, (WPARAM)selIndex, (LPARAM)selItem);
            selItem[255] = 0; // Ensure null-termination

            // None
            if (wcscmp(selItem, L"None") == 0)
            {
                Sleep(100);
                if (!shouldContinueLoop) break;
                break;
            }
            // Put Items in Grinder
            else if (wcscmp(selItem, L"Grind") == 0)
            {
                // Press Open Grinder Inv
                PerformKeyPress(static_cast<BYTE>(openDinoHotkey), 100, 500);
                Sleep(500); // Wait for open
                if (!shouldContinueLoop) break;

                // Transfer All
                PerformMouseClick(xfer1x, xfer1y);
                Sleep(500); // 500 ms delay
                if (!shouldContinueLoop) break;

                // Close Inventory
                PerformMouseClick(closex, closey);
                Sleep(500); // 500 ms delay
                if (!shouldContinueLoop) break;
                break;
            }
            // Put Items in Dedi
            else if (wcscmp(selItem, L"Dedi") == 0)
            {
                // Put Items In Dedi
                PerformKeyPress(static_cast<BYTE>(useitHotkey), 100, 500);
                Sleep(200); // 200 ms delay
                if (!shouldContinueLoop) break;
                break;
            }
            // Drop All
            else if (wcscmp(selItem, L"Drop") == 0)
            {
                // Open Inventory
                PerformKeyPress(static_cast<BYTE>(openPlayerHotkey), 100, 1000);
                Sleep(200);
                if (!shouldContinueLoop) break;

                // Click Player Text Input
                PerformMouseClick(text1x, text1y);
                Sleep(500);
                if (!shouldContinueLoop) break;

                // Retrieve the text from the XPCraft input
                wchar_t selectedValue[256];
                GetWindowText(XPCraft, selectedValue, 256);
                // Type the selected value
                typeText(selectedValue);
                Sleep(500); // Wait for the text input
                if (!shouldContinueLoop) break;

                // Drop All
                PerformMouseClick(drop1x, drop1y);
                Sleep(500); // 500 ms delay
                if (!shouldContinueLoop) break;

                // Check Menu Transitions
                COLORREF MenuTran = GetPixelColor(promptx, prompty);
                if (IsColorWithinTolerance(MenuTran, RGB(193, 245, 255), 30)) // Popup Prompt color
                {
                    // Click Okay on popup
                    PerformMouseClick(okayx, okayy);
                    Sleep(300);
                    if (!shouldContinueLoop) break;
                }
                else
                {
                    Sleep(300);
                    if (!shouldContinueLoop) break;
                }
                if (!shouldContinueLoop) break;

                // Close Inventory
                PerformMouseClick(closex, closey);
                Sleep(500); // 500 ms delay
                if (!shouldContinueLoop) break;
                break;
            }
            // Throw Items
            else if (wcscmp(selItem, L"Throw") == 0)
            {
                // Look Up
                PerformKeyPress(VK_UP, 500, 500);
                Sleep(200);
                if (!shouldContinueLoop) break;
                
                // Open Inventory
                PerformKeyPress(static_cast<BYTE>(openPlayerHotkey), 100, 1000);
                Sleep(200);
                if (!shouldContinueLoop) break;

                // Click Player Text Input
                PerformMouseClick(text1x, text1y);
                Sleep(500);
                if (!shouldContinueLoop) break;

                // Retrieve the text from the XPCraft input
                wchar_t selectedValue[256];
                GetWindowText(XPCraft, selectedValue, 256);
                // Type the selected value
                typeText(selectedValue);
                Sleep(500); // Wait for the text input
                if (!shouldContinueLoop) break;

                // Move mouse to 1st slot player inv
                PerformMouseClick(slot1x, slot1y);
                Sleep(500);
                if (!shouldContinueLoop) break;

                // Press O (throw item out)
                pressOKeyTenTimes();
                Sleep(200);
                if (!shouldContinueLoop) break;

                // Close Inventory
                PerformMouseClick(closex, closey);
                Sleep(500); // 500 ms delay
                if (!shouldContinueLoop) break;

                // Look Down
                PerformKeyPress(VK_DOWN, 500, 500);
                if (!shouldContinueLoop) break;
                break;
            }
        }
    }
}

// Function to check if needing to poop and perform LCTRL if not needed
void CheckPoopAndPerformLCTRL(int x, int y) {
    while (true) {
        COLORREF poopColor = GetPixelColor(PoopnX, PoopnY);
        if (IsColorWithinTolerance(poopColor, RGB(200, 215, 215), 40)) {
            Sleep(100); // Wait before rechecking
            break; // Exit Loop if so
        }
        else {
            // Perform LCTRL click for X seconds
            PerformLCTRLClickForSeconds();
            Sleep(100);
            // Check Food
            CheckFood();
            Sleep(100);
            // Check Water
            CheckWater();
            // Wait for Stam
            Sleep(5500);
        }

        // Check shouldContinueLoop to allow breaking the outer loop if needed
        if (!shouldContinueLoop) break;
    }
}

// Function for Case 11
void XPParty()
{
    setCoordinates(); // Set the coordinates based on the screen resolution
    LoadSettings();

    bool firstLoop = true;

    Sleep(3000); // 3 Second Delay before Start
    while (true) {
            PerformKeyPress(static_cast<BYTE>(openPlayerHotkey), 100, 1000);
            Sleep(200);
            if (!shouldContinueLoop) break;

            // Click Crafting Tab
            PerformMouseClick(PInvCX, PInvCY);
            Sleep(500);
            if (!shouldContinueLoop) break;

            // Click Player Text Input
            PerformMouseClick(text1x, text1y);
            Sleep(500);
            if (!shouldContinueLoop) break;

            // Retrieve the text from the XPCraft input
            wchar_t selectedValue[256];
            GetWindowText(XPCraft, selectedValue, 256);
            // Type the selected value
            typeText(selectedValue);
            Sleep(500); // Wait for the text input
            if (!shouldContinueLoop) break;

            // Move mouse to 1st slot player inv
            PerformMouseClick(slot1x, slot1y);
            Sleep(500);
            if (!shouldContinueLoop) break;

            // Press A 10 Times
            pressAKeyTenTimes();
            if (!shouldContinueLoop) break;

            // Close Inventory
            PerformMouseClick(closex, closey);
            Sleep(500);
            if (!shouldContinueLoop) break;

            // Get off Toilet
            PerformKeyPress(static_cast<BYTE>(useitHotkey), 100, 2000);
            if (!shouldContinueLoop) break;

            // Put Items Away
            PutItemsAway();
            Sleep(200); // 200 ms delay

            // Check if broth Needed
            COLORREF broth1 = GetPixelColor(Buff1X, Buff1Y);  // Update Buff1 color
            COLORREF broth2 = GetPixelColor(Buff2X, Buff2Y);  // Update Buff2 color
            COLORREF broth3 = GetPixelColor(Buff3X, Buff3Y);  // Update Buff3 color
            COLORREF broth4 = GetPixelColor(Buff4X, Buff4Y);  // Update Buff4 color
            if (IsColorWithinTolerance(broth1, RGB(183, 159, 40), 20) || 
                IsColorWithinTolerance(broth2, RGB(183, 159, 40), 20) || 
                IsColorWithinTolerance(broth3, RGB(183, 159, 40), 20) ||
                IsColorWithinTolerance(broth4, RGB(183, 159, 40), 20))
            {
                Sleep(100);
                if (!shouldContinueLoop) break;
            }
            else
            {
                // Use broth
                PerformKeyPress(static_cast<BYTE>(brothHotkey), 100, 100);
                if (!shouldContinueLoop) break;
            }
            Sleep(500);
            if (!shouldContinueLoop) break;

            // Use Weapon
            PerformKeyPress(static_cast<BYTE>(weaponHotkey), 100, 100);
            Sleep(100); // 100 ms delay
            if (!shouldContinueLoop) break;

            // Check if needing to poop
            CheckPoopAndPerformLCTRL(PoopnX, PoopnY);
            Sleep(100); // 100 ms delay
            if (!shouldContinueLoop) break;

            // Put away weapon
            PerformKeyPress(static_cast<BYTE>(weaponHotkey), 100, 100);
            Sleep(200); // 100 ms delay
            if (!shouldContinueLoop) break;

            // Retrieve the value from the XPTurn edit box
            TCHAR buffer[10];
            GetWindowText(XPTurn, buffer, 10); // Get text from the edit box
            // Convert the retrieved text to an integer
            int TurnTime = std::stoi(buffer) * 100;
            // Turn Towards Toilet
            PerformKeyPress(VK_LEFT, TurnTime, 500);
            if (!shouldContinueLoop) break;

            // Only execute Flush Toilet on the second loop and onward
            if (!firstLoop) {
                // Flush Toilet
                PerformKeyPress(static_cast<BYTE>(useitHotkey), 100, 100);
                Sleep(200);
                if (!shouldContinueLoop) break;
            }

            // Sit On Toilet
            PerformKeyPress(static_cast<BYTE>(useitHotkey), 100, 500);
            Sleep(200);
            if (!shouldContinueLoop) break;
                
            // Check for Toilet Buff
            while (true) {
                COLORREF toilet1 = GetPixelColor(Buff1X, Buff1Y);  // Update Buff1 color
                COLORREF toilet2 = GetPixelColor(Buff2X, Buff2Y);  // Update Buff2 color
                COLORREF toilet3 = GetPixelColor(Buff3X, Buff3Y);  // Update Buff3 color
                COLORREF toilet4 = GetPixelColor(Buff4X, Buff4Y);  // Update Buff4 color

                if (!IsColorWithinTolerance(toilet1, RGB(41, 185, 93), 20) &&
                    !IsColorWithinTolerance(toilet2, RGB(41, 185, 93), 20) &&
                    !IsColorWithinTolerance(toilet3, RGB(41, 185, 93), 20) &&
                    !IsColorWithinTolerance(toilet4, RGB(41, 185, 93), 20)) {
                    break;  // Exit the loop if both colors are no longer present
                }   

                Sleep(500);  // Wait before checking again
                if (!shouldContinueLoop) break;
            }

            // Press Numberpad + (To poop)
            PerformKeyPress(VK_ADD, 100, 500);
            if (!shouldContinueLoop) break;

            firstLoop = false;
    }
}