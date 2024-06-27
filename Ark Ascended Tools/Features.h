#ifndef Features_H
#define Features_H
#include <atomic>
#include <string>

// Declare TimerBoxProc function
LRESULT CALLBACK TimerBoxProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Function declarations
void UpdateTimerHours(int hoursToAdd);
void UpdateTimerMinutes(int minutesToAdd);
void UpdateTimerSeconds(int secondsToAdd);

extern HWND ServerN;
extern HWND AutoFarm;
extern HWND Nanny;
extern HWND TimerHR, TimerMN, TimerSC;
extern HWND hHUB, hHDB, hMUB, hMDB, hSUB, hSDB;
extern HWND TimerSND;
extern HWND AutoRun;
extern std::atomic<bool> shouldContinueLoop;
extern std::atomic<bool> functionsRunning;

void typeText(const std::wstring& text);
void AutoJoiner(HWND ServerN);
void BackupJoiner(HWND ServerN);
void AutoFarmer(HWND AutoFarm);
void AntiAFK();
void SoloNanny(HWND Nanny);
void MassBabyFeed(HWND Nanny);
void DropThief();
void Timer();
void CropPlots();
void AutoWalk();

#endif // Features_H