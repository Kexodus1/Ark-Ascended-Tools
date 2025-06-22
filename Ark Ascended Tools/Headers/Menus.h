#ifndef Menus_H
#define Menus_H
#include <windows.h>
#include <atomic>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <iomanip>
#include <unordered_map>

#define WM_UPDATE_TRANSPARENCY (WM_USER + 1)

// Function declarations
std::string GetLatestVersionFromGitHub();
std::string GetCurrentVersion();
void CheckForUpdates(HINSTANCE hInst, HWND hWnd, HWND hDlg);
std::wstring ConvertToWideString(const std::string& str);

// Hotkey variables
extern DWORD hotkey;
extern DWORD openDinoHotkey;
extern DWORD openPlayerHotkey;
extern DWORD useitHotkey;
extern DWORD proneHotkey;
extern DWORD weaponHotkey;
extern DWORD eatingHotkey;
extern DWORD drinkingHotkey;
extern DWORD brothHotkey;
extern std::string customini;
extern int acxpos, acypos, doedturn, fov, gamma, gamma1, gamma2, transparency;
extern HWND hDropDown;
extern HWND hWnd;

// Function to load hotkeys
void LoadSettings();
std::wstring MapKeyToString(DWORD key);

// Dialog Boxes for Menus
INT_PTR CALLBACK UserGuide(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ChangeLog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Trouble(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Update(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Current(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ColorID(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PlayerXP(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK AbbTime(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Hotkeys(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK General(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ClubARK(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

// Test Settings
void OnProgramStartup(HINSTANCE hInst, HWND hWnd);
void RegisterSettingsWndClass(HINSTANCE hInstance);
void ShowSettingsWindow(HWND hWnd);
LRESULT CALLBACK SettingsWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif // Menus_H