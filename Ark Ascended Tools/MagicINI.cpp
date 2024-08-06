#include "pch.h"
#include "Features.h"
#include <windows.h>
#include <vector>

void SendKey(WORD vk, bool shift = false) {
    std::vector<INPUT> inputs(shift ? 4 : 2);

    if (shift) {
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = VK_SHIFT;
        inputs[0].ki.dwFlags = 0;
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = vk;
        inputs[1].ki.dwFlags = 0;
        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.wVk = vk;
        inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.wVk = VK_SHIFT;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
    }
    else {
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = vk;
        inputs[0].ki.dwFlags = 0;
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = vk;
        inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput(static_cast<UINT>(inputs.size()), inputs.data(), sizeof(INPUT));
}

void TypeString(const char* str) {
    for (const char* p = str; *p; p++) 
    {
        SHORT vk = VkKeyScanA(*p);
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
        int selIndex = SendMessage(MagicINISel, CB_GETCURSEL, 0, 0);
        WCHAR selItem[256] = {0};
        SendMessage(MagicINISel, CB_GETLBTEXT, selIndex, (LPARAM)selItem);
        selItem[255] = 0; // Ensure null-termination

        // Get the selected item from the MagicINIo drop-down box
        int ioIndex = SendMessage(MagicINIo, CB_GETCURSEL, 0, 0);
        WCHAR ioItem[256] = {0};
        SendMessage(MagicINIo, CB_GETLBTEXT, ioIndex, (LPARAM)ioItem);
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