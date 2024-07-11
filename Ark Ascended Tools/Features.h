#ifndef Features_H
#define Features_H
#include <atomic>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// Function declarations
LRESULT CALLBACK TimerProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK UserGuide(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ChangeLog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Trouble(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Update(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Current(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void UpdateAntiAFKControlsVisibility();
void HandleButtonClick(HWND hWnd, WPARAM wParam);
void StartTimer(HWND hWnd, int hours, int minutes, int seconds);
std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter);
std::string GetLatestVersionFromGitHub();
std::string GetCurrentVersion();
void CheckForUpdates(HINSTANCE hInst, HWND hWnd, HWND hDlg);
std::wstring ConvertToWideString(const std::string& str);

// External Variables
extern bool timerRunning;
extern int TimerHours, TimerMinutes, TimerSeconds;
extern HWND hButton;
extern HWND AFKM, AFKFD, AFKFDM, AFKFDI;
extern HWND ServerN;
extern HWND AutoFarm;
extern HWND Nanny;
extern HWND TimerHR, TimerMN, TimerSC;
extern HWND hHUB, hHDB, hMUB, hMDB, hSUB, hSDB;
extern HWND TimerSND;
extern HWND AutoRun;
extern std::atomic<bool> shouldContinueLoop;
extern std::atomic<bool> functionsRunning;
extern UINT_PTR TimerID;

void typeText(const std::wstring& text);
void AutoJoiner(HWND ServerN);
void BackupJoiner(HWND ServerN);
void AutoFarmer(HWND AutoFarm);
void AutoDropper(HWND AutoFarm);
void AntiAFK(bool isAFKMChecked, bool isAFKFDChecked);
void SoloNanny(HWND Nanny);
void MassBabyFeed(HWND Nanny);
void DropThief();
void Timer();
void CropPlots();
void AutoWalk();

#endif // Features_H