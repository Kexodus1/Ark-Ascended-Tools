#ifndef Features_H
#define Features_H
#include <atomic>
#include <string>
#include <vector>

// Declare TimerBoxProc function
LRESULT CALLBACK TimerProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Function declarations
void HandleButtonClick(HWND hWnd, WPARAM wParam);
void StartTimer(HWND hWnd, int hours, int minutes, int seconds);
std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter);

// External Variables
extern bool timerRunning;
extern int TimerHours, TimerMinutes, TimerSeconds;
extern HWND hButton;
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
void AntiAFK();
void SoloNanny(HWND Nanny);
void MassBabyFeed(HWND Nanny);
void DropThief();
void Timer();
void CropPlots();
void AutoWalk();

#endif // Features_H