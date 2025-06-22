#include "../Headers/Features.h"
#include "../Headers/Coordinates.h"
#include "../Headers/Menus.h"

// Function for Developer Tools Code
void DevTools()
{
	setCoordinates(); // Set the coordinates based on the screen resolution
	LoadSettings();
	Sleep(1000); // 3 Second Delay before Start
	
	while (true)
	{	
		// Get the selected item from the Dev Tools drop-down box
		LRESULT selIndex = SendMessage(DevToolsSel, CB_GETCURSEL, 0, 0);
		if (selIndex != CB_ERR) // Ensure the selection is valid
		{
			WCHAR selItem[256] = { 0 };
			SendMessage(DevToolsSel, CB_GETLBTEXT, (WPARAM)selIndex, (LPARAM)selItem);
			selItem[255] = 0; // Ensure null-termination

			// STS Code
			if (wcscmp(selItem, L"STS") == 0)
			{
				while (true)
				{
					// Check for the first pixel color #FFBD1F at either (2971, 396) or (2929, 397)
					if (IsColorWithinTolerance(GetPixelColor(2971, 396), RGB(255, 189, 31), 10) ||
						IsColorWithinTolerance(GetPixelColor(2929, 397), RGB(255, 189, 31), 10) ||
						IsColorWithinTolerance(GetPixelColor(2998, 402), RGB(255, 189, 31), 10) ||
						IsColorWithinTolerance(GetPixelColor(3012, 376), RGB(255, 189, 31), 10))
					{
						// Check for the pixel color #EFE46B at any of the given locations
						if (IsColorWithinTolerance(GetPixelColor(2323, 420), RGB(239, 228, 107), 10) ||
							IsColorWithinTolerance(GetPixelColor(2414, 436), RGB(239, 228, 107), 10) ||
							IsColorWithinTolerance(GetPixelColor(2738, 419), RGB(73, 251, 33), 5) ||
							IsColorWithinTolerance(GetPixelColor(2713, 405), RGB(73, 251, 33), 5) ||
							IsColorWithinTolerance(GetPixelColor(2711, 417), RGB(73, 251, 33), 5) ||
							IsColorWithinTolerance(GetPixelColor(2689, 411), RGB(73, 251, 33), 5) ||
							IsColorWithinTolerance(GetPixelColor(2726, 388), RGB(73, 251, 33), 5))
						{
							// If the second color is found, click at (2272, 869) and then at (2846, 972)
							PerformMouseClick(2272, 869);
							Sleep(1000);
							PerformMouseClick(2272, 869);
							Sleep(1000);
							if (!shouldContinueLoop) {
								break; // Exit the loop immediately
							}
							PerformMouseClick(2846, 972);
							Sleep(2000);
							if (!shouldContinueLoop) {
								break; // Exit the loop immediately
							}
						}
						else
						{
							// Ucharge Mouseclick
							//PerformMouseClick(2885, 870);
							//Sleep(4000);


							// Check for the pixel color #EFE46B at any of the given locations
							//if (IsColorWithinTolerance(GetPixelColor(2323, 420), RGB(239, 228, 107), 10) ||
							//	IsColorWithinTolerance(GetPixelColor(2414, 436), RGB(239, 228, 107), 10) ||
							//	IsColorWithinTolerance(GetPixelColor(2738, 419), RGB(73, 251, 33), 5) ||
							//	IsColorWithinTolerance(GetPixelColor(2713, 405), RGB(73, 251, 33), 5) ||
							//	IsColorWithinTolerance(GetPixelColor(2711, 417), RGB(73, 251, 33), 5) ||
							//	IsColorWithinTolerance(GetPixelColor(2689, 411), RGB(73, 251, 33), 5) ||
							//	IsColorWithinTolerance(GetPixelColor(2726, 388), RGB(73, 251, 33), 5))
							//{
								// If the second color is found, click at (2272, 869) and then at (2846, 972)
							//	PerformMouseClick(2272, 869);
							//	Sleep(1000);
							//	PerformMouseClick(2272, 869);
							//	Sleep(1000);
							//	if (!shouldContinueLoop) {
							//		break; // Exit the loop immediately
							//	}
							//	PerformMouseClick(2846, 972);
							//	Sleep(2000);
							//	if (!shouldContinueLoop) {
							//		break; // Exit the loop immediately
							//	}
							//}
							//else
							//{
								// If the second color is not found, click at (2321, 968)
								PerformMouseClick(2321, 968);
								Sleep(3000);
								if (!shouldContinueLoop) {
									break; // Exit the loop immediately
								}
							//}
						}
					}
					else
					{
						Sleep(2000);
						if (!shouldContinueLoop) {
							break; // Exit the loop immediately
						}
					}
				}
			}
			// Temp Code
			if (wcscmp(selItem, L"Temp") == 0)
			{

				// Redeem 1
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 2
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 3
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 4
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 5
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 6
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 7
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Redeem 8
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				
				// Redeem 9
				PerformMouseClick(3226, 1248);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Craft Click
				PerformMouseClick(3334, 1231);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Kit Click
				PerformMouseClick(1817, 1174);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Amt 1
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Amt 2
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 3
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 4
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 5
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 6
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 7
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 8
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
				// Amt 9
				PerformMouseClick(2623, 853);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// Start
				PerformMouseClick(2723, 1071);
				Sleep(1000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}

				// 1Hr Sleep
				Sleep(3600000);
				if (!shouldContinueLoop) {
					break; // Exit the loop immediately
				}
			}
		}
		if (!shouldContinueLoop) break;
	}

}