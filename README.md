Tools to automate Ark Survival Ascended


Ark Ascended Tools User Guide
==========================
--General Guide--
     - Select the function you want from the drop down box and press the "Start" button
     - The Button will change to "Stop" to stop the current function from running.
     - If the program is not working for you right click and "Run as Administrator"
     - Currently only works for resolutions 3440x1440, 2560x1440, 1920x1080, 1920x1200, 1536x864

--Auto Join Server--
     - Type the server number in the "Input Server Number" box and hit the "Start" button while on the main server selection screen.  The program will take over and automatically attempt to join a full server.  If this function is not working for you check the "Backup Joiner" box and re attempt.

--Auto Farmer--
     - This function is for a tribemate or alt account while being a rider on a farming Dino.  This will automatically left click every 2.5 seconds.  Once Dino becomes black weighted the function will automatically drop items listed in the box below.  Please separate these items by a comma(,).

--Anti AFK--
     - Anti AFK will automatically move left and right periodically while going prone to prevent getting kicked from server.  If the checkbox is clicked it will eat/drink every 1 hour with 9 and 0 on the keyboard.

--Solo Nanny--
     - Allows you to automatically hand feed one baby while being in the inventory.  Select which food you want to hand feed and will periodically every 1 minute refeed baby.  Make sure you have the appropriate quantity of selected food in your inventory.

--Mass Baby Feed--
     - This will automatically upon opening baby Dino inventory refresh the food and close the inventory, allowing you to quickly go around and feed multiple baby Dino's.

--Drop Thief--
     - Quickly grabs the drop when you open the inventory, taking all instantly.

--Alarm / Timer--
     - Set the HR:MIN:SEC then start the timer for it to count down.  Will play a sound when it reaches zero if the checkbox is selected.

--Empty Crop Plots--
     - Have function started and open crop plot, will automatically take all from crop plot and put the fertilizer back.  Will also refill fertilizer if you have extra in your inventory.

--Auto Walk / Fly--
     - As name implies, will just automatically move you forward without pressing anything.

	Changelog
==========================
v3.0
     - New features "Solo Nanny", "Empty Crop
       Plots", "Mass Baby Feed", "Drop Thief",
      "Alarm / Timer" and "Auto Walk / Fly"
     - Updated user guide for better explaining of
       each feature
     - Added server number for Auto Joiner
     - Added item auto drop for Auto Farmer
     - Added ASA color chart to menu
     - First implementation of settings with known
       hotkeys / transparency slider
     - Finalized major build with reduced size and files
     - Project is now "open source" with link in
      "About" to allow others to add to or fix in the
       future

v2.6
     - Added "User Guide" and "Changelog" to help
       menu
     - Implemented hotkey "F4" to start and stop
     - Changed "Auto Clicker" to "Auto Farmer" and
       removed moving of cursor
     - Changed a lot of backend code for better
       optimization / organization

v2.5.1
     - Fixed Auto Joiner for 1920x1080 and 1536x864
     - Added small sleep delay for Backup Joiner

v2.5
     - Adjusted Auto Joiner / Backup Joiner to
       compensate for button movement on join
       screen
     - Added/Fixed 1536x864 support

v2.4
     - Added an alternative "Backup Auto Joiner" for users that the original "Auto Join Server" is not working for. This function works like the original; please hit the start button on the main server selection page with the server you want to join at the top of the list.

v2.3
     - Changed AntiAFK to A & D (Strafe) with X (Prone) in between for better movement control, will continue to monitor (reports of moving too much forward into the wall)
     - minor fix to AutoJoiner stop logic
     - minor fix for 3440x1440 / 1920x1200 (small adjustments)

v2.2
     - Added Eating and Drinking to AntiAFK every 1hr (make sure you have food and drink on 9 and 0, can adjust if too slow)
     - Added extra logic to immediately stop when stop is clicked (would previously try to finish task then stop)
     - Increased delay on AutoJoiner from 0.1 to 0.5 seconds between clicks to prevent program from becoming unresponsive.
     - Adjusted some program padding

v2.1
     - Fixed 1920x1200 Resolution Scaling
     - Fixed AntiAFK to press keys longer
     - Fixed misclick on join screen for people with/without Bob's Tall Tales DLC

v2.0
     - Added New features AntiAFK and AutoClicker
     - Fixed code to detect resolution and scale accordingly
     - Fixed Button to toggle the start and stop process
     - Added show current user screen resolution for troubleshooting

v1.0
     - Program created and basic Autojoin (only worked on 3440x1440)
     
