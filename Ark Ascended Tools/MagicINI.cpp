#include "pch.h"
#include "Features.h"
#include <windows.h>
#include <vector>

// Function to detect if the current layout is AZERTY
bool IsAZERTY() {
    HKL layout = GetKeyboardLayout(0);
    return LOWORD(layout) == MAKELANGID(LANG_FRENCH, SUBLANG_FRENCH);
}

void SendKey(WORD vk, bool shift = false, bool altGr = false) {
    std::vector<INPUT> inputs;

    if (altGr) {
        inputs.push_back(INPUT{ INPUT_KEYBOARD, {VK_CONTROL, 0} });
        inputs.push_back(INPUT{ INPUT_KEYBOARD, {VK_MENU, 0} });
    }

    if (shift) {
        inputs.push_back(INPUT{ INPUT_KEYBOARD, {VK_SHIFT, 0} });
    }

    inputs.push_back(INPUT{ INPUT_KEYBOARD, {vk, 0} });
    inputs.push_back(INPUT{ INPUT_KEYBOARD, {vk, KEYEVENTF_KEYUP} });

    if (shift) {
        inputs.push_back(INPUT{ INPUT_KEYBOARD, {VK_SHIFT, KEYEVENTF_KEYUP} });
    }

    if (altGr) {
        inputs.push_back(INPUT{ INPUT_KEYBOARD, {VK_MENU, KEYEVENTF_KEYUP} });
        inputs.push_back(INPUT{ INPUT_KEYBOARD, {VK_CONTROL, KEYEVENTF_KEYUP} });
    }

    SendInput(static_cast<UINT>(inputs.size()), inputs.data(), sizeof(INPUT));
}

void TypeString(const char* str) {
    for (const char* p = str; *p; p++) {
        bool isAzerty = IsAZERTY();
        SHORT vk = VkKeyScanA(*p);

        if (*p == '|') {
            if (isAzerty) {
                SendKey(0x36, false, true); // AltGr + 6 for AZERTY
            }
            else {
                SendKey(0xDC, true); // Shift + \ on US QWERTY
            }
            continue;
        }

        if (vk == -1) continue; // Skip characters that can't be mapped

        bool shiftState = HIBYTE(vk) & 1;
        WORD vkKey = LOBYTE(vk);
        SendKey(vkKey, shiftState);
        Sleep(30); // Adjust delay to ensure each key press is registered
    }
}

void MagicINI()
{
    while (true)
    {
        // Get the selected item from the MagicINISel drop-down box
        LRESULT selIndex = SendMessage(MagicINISel, CB_GETCURSEL, 0, 0); // Store result in LRESULT
        WCHAR selItem[256] = { 0 };
        if (selIndex != CB_ERR) { // Ensure valid index
            SendMessage(MagicINISel, CB_GETLBTEXT, (int)selIndex, (LPARAM)selItem); // Cast selIndex to int
            selItem[255] = 0; // Ensure null-termination
        }

        // Get the selected item from the MagicINIo drop-down box
        LRESULT ioIndex = SendMessage(MagicINIo, CB_GETCURSEL, 0, 0); // Store result in LRESULT
        WCHAR ioItem[256] = { 0 };
        SendMessage(MagicINIo, CB_GETLBTEXT, (int)ioIndex, (LPARAM)ioItem); // Cast ioIndex to int
        ioItem[255] = 0; // Ensure null-termination

        // Implement the functionality based on the selected items
        if (wcscmp(selItem, L"Clean Air") == 0 && wcscmp(ioItem, L"Enable") == 0)
        {
            // Enable Clean Air
            // Press the "`" key
            Sleep(1000);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            TypeString("r.VolumetricCloud 0");
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            TypeString(" | r.VolumetricFog 0");
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Press the Enter key
            SendKey(VK_RETURN);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Press the "`" key twice
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_F4);
            Sleep(100);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
        else if (wcscmp(selItem, L"Clean Air") == 0 && wcscmp(ioItem, L"Disable") == 0)
        {
            // Enable Clean Air
            // Press the "`" key
            Sleep(1000);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Type the command "r.VolumetricCloud 0 | r.VolumetricFog 0"
            TypeString("r.VolumetricCloud 1");
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            TypeString(" | r.VolumetricFog 1");
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Press the Enter key
            SendKey(VK_RETURN);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            // Press the "`" key twice
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_OEM_3);
            Sleep(25);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
            SendKey(VK_F4);
            Sleep(100);
            if (!shouldContinueLoop) {
                break; // Exit the loop immediately
            }
        }
    }
}
    //else if (wcscmp(selItem, L"No Trees") == 0) {
    //    if (wcscmp(ioItem, L"Enable") == 0) {
    //        // Enable No Trees
    //    }
    //    else {
    //        // Disable No Trees
    //    }
    //}
    //else if (wcscmp(selItem, L"Clear Water") == 0) {
    //    if (wcscmp(ioItem, L"Enable") == 0) {
    //        // Enable Clear Water
    //    }
    //    else {
    //        // Disable Clear Water
    //    }
    //}