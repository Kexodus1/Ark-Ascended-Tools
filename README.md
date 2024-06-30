Tools to automate Ark Survival Ascended
======================================


Ark Ascended Tools User Guide
==========================
--General Guide--<BR><BR>
     - Select the function you want from the drop down box and press the "Start" button<BR>
     - The Button will change to "Stop" to stop the current function from running.<BR>
     - If the program is not working for you right click and "Run as Administrator"<BR>
     - Currently only works for resolutions 3440x1440, 2560x1440, 1920x1080, 1920x1200, 1536x864<BR><BR>

--Auto Join Server--<BR><BR>
     - Type the server number in the "Input Server Number" box and hit the "Start" button while on the main server selection screen.  The program will take over and automatically attempt to join a full server.  If this function is not working for you check the "Backup Joiner" box and re attempt.<BR><BR>

--Auto Farmer--<BR><BR>
     - This function is for a tribemate or alt account while being a rider on a farming Dino.  This will automatically left click every 2.5 seconds.  Once Dino becomes black weighted the function will automatically drop items listed in the box below.  Please separate these items by a comma(,).<BR><BR>

--Anti AFK--<BR><BR>
     - Anti AFK will automatically move left and right periodically while going prone to prevent getting kicked from server.  If the checkbox is clicked it will eat/drink every 1 hour with 9 and 0 on the keyboard.<BR><BR>

--Solo Nanny--<BR><BR>
     - Allows you to automatically hand feed one baby while being in the inventory.  Select which food you want to hand feed and will periodically every 1 minute refeed baby.  Make sure you have the appropriate quantity of selected food in your inventory.<BR><BR>

--Mass Baby Feed--<BR><BR>
     - This will automatically upon opening baby Dino inventory refresh the food and close the inventory, allowing you to quickly go around and feed multiple baby Dino's.<BR><BR>

--Drop Thief--<BR><BR>
     - Quickly grabs the drop when you open the inventory, taking all instantly.<BR><BR>

--Alarm / Timer--<BR><BR>
     - Set the HR:MIN:SEC then start the timer for it to count down.  Will play a sound when it reaches zero if the checkbox is selected.<BR><BR>

--Empty Crop Plots--<BR><BR>
     - Have function started and open crop plot, will automatically take all from crop plot and put the fertilizer back.  Will also refill fertilizer if you have extra in your inventory.<BR><BR>

--Auto Walk / Fly--<BR><BR>
     - As name implies, will just automatically move you forward without pressing anything.<BR><BR>
     
CHANGELOG
==========================
v3.1<BR>
     - Fix for "Timer / Alarm" function to perform as<BR>
       intended<BR>
     - "Timer / Alarm" will now play sound when<BR>
       reaching "0" if "Enable Sound" checkbox clicked<BR><BR>
       
v3.0.1<BR>
      - Minor fix for Color IDs not loading properly<BR><BR>
      
v3.0<BR>
     - New features "Solo Nanny", "Empty Crop<BR>
       Plots", "Mass Baby Feed", "Drop Thief",<BR>
      "Alarm / Timer" and "Auto Walk / Fly"<BR>
     - Updated user guide for better explaining of<BR>
       each feature<BR>
     - Added server number for Auto Joiner<BR>
     - Added item auto drop for Auto Farmer<BR>
     - Added ASA color chart to menu<BR>
     - First implementation of settings with known<BR>
       hotkeys / transparency slider<BR>
     - Finalized major build with reduced size and files<BR>
     - Project is now "open source" with link in<BR>
      "About" to allow others to add to or fix in the<BR>
       future<BR><BR>

v2.6<BR>
     - Added "User Guide" and "Changelog" to help<BR>
       menu<BR>
     - Implemented hotkey "F4" to start and stop<BR>
     - Changed "Auto Clicker" to "Auto Farmer" and<BR>
       removed moving of cursor<BR>
     - Changed a lot of backend code for better<BR>
       optimization / organization<BR><BR>

v2.5.1<BR>
     - Fixed Auto Joiner for 1920x1080 and 1536x864<BR>
     - Added small sleep delay for Backup Joiner<BR>

v2.5<BR>
     - Adjusted Auto Joiner / Backup Joiner to<BR>
       compensate for button movement on join<BR>
       screen<BR>
     - Added/Fixed 1536x864 support<BR><BR>

v2.4<BR>
     - Added an alternative "Backup Auto Joiner" for users that the original "Auto Join Server" is not working for. This function works like the original; please hit the start button on the main server selection page with the server you want to join at the top of the list.<BR><BR>

v2.3<BR>
     - Changed AntiAFK to A & D (Strafe) with X (Prone) in between for better movement control, will continue to monitor (reports of moving too much forward into the wall)<BR>
     - minor fix to AutoJoiner stop logic<BR>
     - minor fix for 3440x1440 / 1920x1200 (small adjustments)<BR><BR>

v2.2<BR>
     - Added Eating and Drinking to AntiAFK every 1hr (make sure you have food and drink on 9 and 0, can adjust if too slow)<BR>
     - Added extra logic to immediately stop when stop is clicked (would previously try to finish task then stop)<BR>
     - Increased delay on AutoJoiner from 0.1 to 0.5 seconds between clicks to prevent program from becoming unresponsive.<BR>
     - Adjusted some program padding<BR><BR>

v2.1<BR>
     - Fixed 1920x1200 Resolution Scaling<BR>
     - Fixed AntiAFK to press keys longer<BR>
     - Fixed misclick on join screen for people with/without Bob's Tall Tales DLC<BR><BR>

v2.0<BR>
     - Added New features AntiAFK and AutoClicker<BR>
     - Fixed code to detect resolution and scale accordingly<BR>
     - Fixed Button to toggle the start and stop process<BR>
     - Added show current user screen resolution for troubleshooting<BR><BR>

v1.0<BR>
     - Program created and basic Autojoin (only worked on 3440x1440)<BR><BR>
     
