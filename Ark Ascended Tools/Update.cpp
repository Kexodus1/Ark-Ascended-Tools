#include "pch.h"
#include "Features.h"
#include "Resource.h"
#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <urlmon.h> // For URLDownloadToFile
#pragma comment(lib, "urlmon.lib") // Link against Urlmon library
#pragma comment(lib, "wininet.lib")

// Global variable to store the background brush
extern HBRUSH hbrBackground;

std::string GetCurrentVersion() {
    // Return the current version of your application
    return "v3.5.0";  // Replace this with the actual current version of your application
}

std::string GetLatestVersionFromGitHub() {
    HINTERNET hInternet = InternetOpenA("MyApp", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) {
        std::cerr << "InternetOpenA failed with error: " << GetLastError() << std::endl;
        return "";
    }

    HINTERNET hConnect = InternetOpenUrlA(hInternet, "https://raw.githubusercontent.com/Kexodus1/Ark-Ascended-Tools/master/Ark%20Ascended%20Tools/Version.txt", NULL, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_NO_CACHE_WRITE, 0);
    if (!hConnect) {
        std::cerr << "InternetOpenUrlA failed with error: " << GetLastError() << std::endl;
        InternetCloseHandle(hInternet);
        return "";
    }

    char buffer[256];
    DWORD bytesRead;
    std::string latestVersion;
    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        latestVersion.append(buffer, bytesRead);
    }

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    // Remove any trailing newlines or spaces
    latestVersion.erase(latestVersion.find_last_not_of(" \n\r\t") + 1);
    std::cout << "Fetched latest version: " << latestVersion << std::endl;
    return latestVersion;
}

std::string GetChangelogFromGitHub() {
    HINTERNET hInternet = InternetOpenA("MyApp", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) {
        std::cerr << "InternetOpenA failed with error: " << GetLastError() << std::endl;
        return "";
    }

    HINTERNET hConnect = InternetOpenUrlA(hInternet, "https://raw.githubusercontent.com/Kexodus1/Ark-Ascended-Tools/master/Ark%20Ascended%20Tools/Changelog.txt", NULL, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_NO_CACHE_WRITE, 0);
    if (!hConnect) {
        std::cerr << "InternetOpenUrlA failed with error: " << GetLastError() << std::endl;
        InternetCloseHandle(hInternet);
        return "";
    }

    char buffer[1024];
    DWORD bytesRead;
    std::string changelog;
    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        changelog.append(buffer, bytesRead);
    }

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    std::cout << "Fetched changelog: " << changelog << std::endl;
    return changelog;
}

std::wstring ConvertToWideString(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

void CheckForUpdates(HINSTANCE hInst, HWND hWnd, HWND hDlg) {
    std::string latestVersion = GetLatestVersionFromGitHub();
    std::string currentVersion = GetCurrentVersion();

    if (!latestVersion.empty() && latestVersion != currentVersion) {
        // Show the update dialog with details
        DialogBox(hInst, MAKEINTRESOURCE(IDD_UPDATEBOX), hWnd, Update);
    }
    else {
        // Show current version dialog
        DialogBox(hInst, MAKEINTRESOURCE(IDD_CURRENT), hWnd, Current);
    }
}

// Function to download a file from a URL
std::wstring DownloadFile(const std::wstring& version, const std::wstring& savePath) {
    std::wstring url = L"https://github.com/Kexodus1/Ark-Ascended-Tools/releases/download/";
//OLD zip func
//     url += version + L"/Ark.Ascended.Tools." + version + L".zip";
    url += version + L"/Ark.Ascended.Tools.exe";

    HRESULT hr = URLDownloadToFile(nullptr, url.c_str(), savePath.c_str(), 0, nullptr);
    if (SUCCEEDED(hr)) {
        std::wcout << L"Downloaded file to: " << savePath << std::endl;
        return savePath;
    }
    else {
        std::wcerr << L"Failed to download file. HRESULT: " << hr << std::endl;
        return L"";
    }
}

void DownloadAndUpdate() {
    std::string latestVersionStr = GetLatestVersionFromGitHub(); // Fetch latest version as string
    std::wstring latestVersion = ConvertToWideString(latestVersionStr); // Convert to wide string

    std::wstring savePath = L"Ark.Ascended.Tools." + latestVersion + L".zip"; // Construct save path

    std::wstring downloadedFilePath = DownloadFile(latestVersion, savePath);
    if (!downloadedFilePath.empty()) {
        // Download successful, proceed with update logic
        MessageBoxW(NULL, L"Downloaded update successfully.", L"Update", MB_OK | MB_ICONINFORMATION);

        // Example: Execute the downloaded file or perform update actions
        // Replace with your actual update logic
        // Example: ShellExecuteW(NULL, L"open", downloadedFilePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
    else {
        // Handle download failure
        MessageBoxW(NULL, L"Failed to download update.", L"Update", MB_OK | MB_ICONERROR);
    }
}

// Message handler for update box
INT_PTR CALLBACK Update(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
    {
        // Get the changelog from GitHub or file
        std::string changelog = GetChangelogFromGitHub();
        // Convert changelog to wide string
        std::wstring wchangelog = ConvertToWideString(changelog);
        // Set the changelog to the IDC_CHANGELOG control
        SetDlgItemTextW(hDlg, IDC_CHANGELOG, wchangelog.c_str());

        // Recreate the background brush and set the background color
        hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        SetClassLongPtr(hDlg, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackground);

        return (INT_PTR)TRUE;
    }
    case WM_COMMAND:
        if (LOWORD(wParam) == IDUPDATE) {
            DownloadAndUpdate();
        }
        else if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;

    case WM_CTLCOLORDLG:
    {
        HDC hdcDlg = (HDC)wParam;
        SetTextColor(hdcDlg, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcDlg, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Current(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
    {
        // Set the current version message
        std::wstring currentVersion = ConvertToWideString(GetCurrentVersion());
        SetDlgItemTextW(hDlg, IDC_CURRENT_VERSION, currentVersion.c_str());
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;

    case WM_CTLCOLORDLG:
    {
        HDC hdcDlg = (HDC)wParam;
        SetTextColor(hdcDlg, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcDlg, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, RGB(255, 255, 255)); // Set text color to white
        SetBkColor(hdcStatic, RGB(0, 0, 0)); // Set background color to black
        return (INT_PTR)hbrBackground;
    }
    break;
    }
    return (INT_PTR)FALSE;
}