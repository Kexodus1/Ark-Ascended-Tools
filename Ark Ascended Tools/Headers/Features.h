#ifndef Features_H
#define Features_H
#include <windows.h>
#include <thread>
#include <atomic>
#include <string>
#include <vector>
#include <sstream>

// Function declarations
void HandleButtonClick(HWND hWnd, WPARAM wParam);
std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter);

// External Variables
extern bool timerRunning;
extern int TimerHours, TimerMinutes, TimerSeconds;
extern HWND hButton;
extern HWND AFKM, AFKFD, AFKFDM, AFKFDI;
extern HWND ServerN;
extern HWND ClubARKGame, CATurn, CAFOV;
extern HWND AutoFarm, AutoDrop;
extern HWND ACKey, ACInt, ACPos;
extern HWND XPCraft, XPTurn, XPPut;
extern HWND Nanny;
extern HWND AutoGrab, AutoGrabSel;
extern HWND PVPTool;
extern HWND AutoRun;
extern HWND MagicINISel, MagicINIo;
extern HWND TimerHR, TimerMN, TimerSC;
extern HWND hHUB, hHDB, hMUB, hMDB, hSUB, hSDB;
extern HWND TimerSND;
extern std::atomic<bool> shouldContinueLoop;
extern std::atomic<bool> functionsRunning;
extern UINT_PTR TimerID;
extern HWND DevToolsSel;

// Feature Functions
void typeText(const std::wstring& text);
void AutoJoiner(HWND ServerN);
void BackupJoiner(HWND ServerN);
void AutoClicker(bool isACPosChecked);
void AntiAFK(bool isAFKMChecked, bool isAFKFDChecked);
void ClubARK();
void ClubARKTest();
void AutoFarmer(HWND AutoFarm);
void AutoDropper(HWND AutoDrop);
void SoloNanny(HWND Nanny);
void MassBabyFeed(HWND Nanny);
void EggDrop(HWND SpacingD);
void AutoGrabber();
void AutoFish();
void PVPTools();
void TribelogBot();
void AutoWalk(bool isAutoRunChecked);
void MagicINI();
void StartTimer(HWND hWnd, int hours, int minutes, int seconds);
void XPParty();
void DevTools();

#endif // Features_H