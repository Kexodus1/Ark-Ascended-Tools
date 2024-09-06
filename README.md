<p align="center">
   <img width="60%" height="60%" src="https://github.com/Kexodus1/Ark-Ascended-Tools/blob/master/AscendedToolsLogo.png"><BR>
   <img src="https://img.shields.io/badge/Maintained%3F-Yes-green">
   <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/releases"><img src="https://img.shields.io/github/v/release/Kexodus1/Ark-Ascended-Tools"></A>
   <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/commits/master/"><img src="https://img.shields.io/github/commit-activity/m/Kexodus1/Ark-Ascended-Tools"></A>
   <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/issues"><img src="https://img.shields.io/github/issues/Kexodus1/Ark-Ascended-Tools"></A>
   <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/issues?q=is%3Aissue+is%3Aclosed"><img src="https://img.shields.io/github/issues-closed/Kexodus1/Ark-Ascended-Tools"></A>
   <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/tree/master/Ark%20Ascended%20Tools"><img src="https://img.shields.io/github/languages/code-size/Kexodus1/Ark-Ascended-Tools"></A>
   <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/releases"><img src="https://img.shields.io/github/downloads/Kexodus1/Ark-Ascended-Tools/total"></A>
</p>

Table of Contents
======================================
- [About](#about)
- [Installation](#installation)<BR>
- [User Guide](#user-guide)<BR>
- [Troubleshooting](#troubleshooting)<BR>
- [Changelog](#changelog)<BR><BR>

About
=====================================
Ark Ascended Tools is a set of functions for users to streamline their Ark experience for better efficiency and multitasking.  With this program you can reduce manual input for repetitive tasks and even AFK on other tasks within Ark.  Please read the [user guide](#user-guide) for better understanding of the key features and how to use them.<BR><BR>

Installation
=====================================
Download the latest zipped version from <a href="https://github.com/Kexodus1/Ark-Ascended-Tools/releases">releases</a> and unzip the executable.  Run the Ark Ascended Tools executable to perform various functions within Ark.  The program has a check for updates in the help menu that will download the latest zip when available.  Windows security may flag the file as virus when downloading sometimes; goto virus and threat protection and allow the program.<BR><BR>

User Guide
==========================
- General Guide<BR>
   - There is a delay on most functions when you start them to be able to click the ark program before the function starts.  It is better to start each function using the hotkey while ARK is the active window.  Select the function you want from the drop down box and press the "Start" button (Hotkey "F4").  The Button will change to "Stop" to stop the current function from running.<BR><BR>

- Auto Join Server<BR>
   - Type the server number in the "Input Server Number" box and hit the "Start" button while on the main server selection screen.  The program will take over and automatically attempt to join a full server.  If this function is not working for you check the "Backup Joiner" box and re attempt.<BR><BR>

- Auto Farmer<BR>
   - This function is for a tribemate or alt account while being a rider on a farming Dino.  This will automatically left click every 2.5 seconds.  Once Dino becomes black weighted the function will automatically drop items listed in the box below.  Please separate these items by a comma(,).<BR><BR>

- Auto Drop Items<BR>
   - While activated anytime you open the Dino's inventory it will type the inputed items in the text box one by one and drop all of each item.  Please separate these items by a comma(,).  Example: Doing a meat run and typing "Prime,Hide,Chitin,Keratin" into the box, this would drop these items every time you open the Dino's inventory.<BR><BR>

- Anti AFK<BR>
   - Anti AFK will automatically move left(A) and right(D) periodically while going prone(X) if the "Move" checkbox is checked to prevent getting kicked from server.  If the "Eat / Drink" checkbox is checked it will automatically eat and drink with 9 and 0 on the keyboard.  You may input time in minutes to automatically eat and drink, default is 60 minutes.  You may use both "Move" and "Eat / Drink" together or separately.<BR><BR>

- AFK Club ARK<BR>
   - Will automatically farm club ark points without user input.  It is best to start at the far left mission board so you don't accidentally try to trade a player.  You can either walk up to the mission board or join selected game then start the program.  Currently only supports one game but backend code established to easily add future games.  Duck Duck Jump uses "E" for accessing mission board and "Spacebar" / "C" for the game. (Currently only works for 3840x2160, 3840x1080, 3440x1440, 2560x1440, and 1920x1080)<BR><BR>

- Mass Baby Feed<BR>
   - This will automatically upon opening baby Dino inventory refresh the food and close the inventory, allowing you to quickly go around and feed multiple baby Dino's.  Select which food type from drop down to feed the babies when you open inventory.  If "Solo Nanny" is check marked it will allow you to AFK inside a single baby's inventory and refresh the selected food from the dropdown every 1 minute.  Make sure you have appropriate food in your inventory.<BR><BR>

- Auto Grabber<BR>
   - Depending on which function you have selected from the dropdown when you start this feature.  "Air Drop", "Raptor Claus", "Death Bag", or "Empty Crop plots" will quickly grab the items when you open the inventory, taking all instantly, then closing the inventory instantly. "Empty Crop Plots" will automatically put fertilizer back before closing inventory.  Any extra fertilizer in inventory will top the crop plot up.<BR><BR>

- Auto Fishing<BR>
   - Added this feature incase they rework fishing in the future.  Will automatically reel in fish when started.  If on controller checkmark the controller box and it will go off of controller prompts.  Selecting AFK will automatically cast and reel in.<BR><BR>

- Auto Walk / Fly<BR>
   - As name implies, will just automatically move you forward without pressing anything.  Check the "Run Modifier" box to change it to running forward automatically.<BR><BR>

- Magic INI<BR>
   - Currently only one INI setting is added, "Clean Air".  When selected will remove fog and clouds, you can enable / disable this with the dropdown.  Implemented the code to be able to easily add future INI settings.  I have not been in the ARK loop for a little while so my old "No Trees" and "Invisible Ground" no longer work.  If new INI's come out I can quickly add them for future use.<BR><BR>

- Alarm / Timer<BR>
   - Set the HR:MIN:SEC then start the timer for it to count down.  Will play a sound when it reaches zero if the checkbox is selected.<BR><BR>

Troubleshooting
=================================

   - My resolution is not showing correctly:<BR>
        - Make sure you have scaling in windows System >
       Display set to 100%. If that is correct then make
       sure your main display is set to the monitor you
       are using ARK on.<BR><BR>

   - Does in game resolution matter:<BR>
        - The tools function off of your main display
       resolution. Using 2560x1440 main display and
       1920x1080 in game would perform correctly. Make
       sure your in game aspect ratio is the same as
       your main display. (21:9, 16:9, or 16:10)<BR><BR>

   - The program isn't functioning:<BR>
        - Try running the program in Administrator mode and
       relaunch to see if it works. Also a lot of colors in
       game are based off of default gamma 2.2 (Any
       other gamma will break a lot of functionality)<BR><BR>

   - I see (Unsupported) at the bottom:<BR>
        - Currently only resolutions 3840x2160, 3840x1080,
       3440x1440, 2560x1440, 1920x1080, 1920x1200,
       and 1536x864 are supported.<BR><BR>

   - Club ARK is not working for me:<BR>
        - Currently only resolutions 3840x2160, 3840x1080, 3440x1440, 2560x1440, and 1920x1080 are supported.<BR><BR>

   - I keep getting hit in Club ARK:<BR>
        - To achieve the best possible success rate you should copy the video and camera settings each resolution was calibrated for.<BR>
        1. Video Settings:<BR>
         - DLSS: Ultra Performance<BR>
         - Resolution Scaling 80%<BR>
         - Default Gamma: 2.2<BR>
        2. Camera Settings:<BR>
         - 50 FOV (the FOV is critical and can be slightly
           increased to jump slower or decreased to jump
           faster)<BR><BR>

   - I have a different issue not listed:
        - Pleasse head over to <A href="https://github.com/Kexodus1/Ark-Ascended-Tools/issues">issues</A> and submit a new issue.<BR><BR>
     
Changelog
==========================
v4.1.1<BR>
   - Fix for "Auto Join Server" mod screen or connection failed detection<BR><BR>
   
v4.1.0<BR>
   - Added AZERTY support to "Magic INI"<BR>
   - Added support for 3840x2160 and 3840x1080 resolutions to "AFK Club ARK"<BR>
   - Minor fix for 3840x1080 "Auto Join Server"<BR>
   - Further adjustments to 1920x1080 for "AFK Club ARK" (Should be more consistent)<BR>
   - Refactored / labeled coordinates code<BR><BR>
     
v4.0.4<BR>
   - Added support for 3840x1080 resolution<BR><BR>
     
v4.0.3<BR>
   - Minor changes to User Guide<BR>
   - Minor fix to disable debug mode<BR><BR>
     
v4.0.2<BR>
   - Added troubleshooting for "AFK Club ARK"<BR>
   - Added extra menu check for "AFK Club ARK"<BR>
   - Minor adjustments to 1920x1080 for "AFK Club ARK"<BR><BR>

v4.0.1<BR>
   - Fix for "Duck Duck Jump" jumping on red blobs for 2560x1440 and 1920x1080 sometimes<BR><BR>

v4.0.0<BR>
   - New features added "AFK Club ARK", "Auto Fishing", and "Magic INI"<BR>
   - Backend coding for easy additions to "AFK Club ARK" and "Magic INI" in the future<BR>
   - Renamed "Drop Thief" to "Auto Grabber"<BR>
   - Rework of "Auto Grabber" to add "Raptor Claus" and "Death Bag" for PVP<BR>
   - Consolidated "Empty Crop Plots" into "Auto Grabber"<BR>
   - Consolidated "Solo Nanny" into "Mass Baby Feed"<BR>
   - Added mod detection to "Auto Join Server" for futureproofing<BR>
   - Updated "User Guide" to reflect all the changes<BR>
   - A few minor bug fixes with integer conversions<BR>
   - Further code optimization / reduced size<BR>
   - Customized program icon and updated look<BR><BR>
     
v3.6.0<BR>
   - New "Troubleshooting" under help menu<BR>
   - Added run checkbox to "Auto Walk / Fly"<BR>
   - Added support for 3840x2160 resolution<BR>
   - Code organization and optimization<BR><BR>
     
v3.5.1<BR>
   - Minor fix for updater downloading exe not zip<BR><BR>
     
v3.5.0<BR>
   - Minor Fixes to "Anti AFK" stop logic<BR>
   - Adjusted version numbers for updater<BR>
   - New "Check for Updates" in help menu<BR><BR>

v3.4.0<BR>
   - Complete rework of "Anti AFK" code<BR>
   - Added Eat / Drink timer input to "Anti AFK"<BR>
   - Added ability to only Move or Eat / Drink to "Anti AFK" (Should add more functionality)<BR><BR>
      
v3.3.2<BR>
   - Minor fix for "Mass Baby Feed" timings<BR><BR>
     
v3.3.1<BR>
   - Added text input to server number box (for servers with fewer then 4 numbers like arkpoc and conquest)<BR><BR>

v3.3.0<BR>
   - Fixed unintended breakage of "Auto Join Server" when server number was implemented<BR>
   - Refactoring of code to optimize "Auto Join Server" and "Backup Joiner"<BR>
   - Consolidated coordinates for "Auto Join Server" and "Backup Joiner" eliminating duplicates<BR><BR>
       
v3.2.0<BR>
   - New feature added "Auto Drop Items"<BR>
   - Fixed programming to detect if "Disable Menu Transitions" is enabled or disabled automatically<BR><BR>
       
v3.1.0<BR>
   - Fix for "Timer / Alarm" function to perform as intended<BR>
   - "Timer / Alarm" will now play sound when reaching "0" if "Enable Sound" checkbox clicked<BR><BR>
       
v3.0.1<BR>
   - Minor fix for Color IDs not loading properly<BR><BR>
      
v3.0.0<BR>
   - New features "Solo Nanny", "Empty Crop Plots", "Mass Baby Feed", "Drop Thief", "Alarm / Timer" and "Auto Walk / Fly"<BR>
   - Updated user guide for better explaining of each feature<BR>
   - Added server number for Auto Joiner<BR>
   - Added item auto drop for Auto Farmer<BR>
   - Added ASA color chart to menu<BR>
   - First implementation of settings with known hotkeys / transparency slider<BR>
   - Finalized major build with reduced size and files<BR>
   - Project is now "open source" with link in "About" to allow others to add to or fix in the future<BR><BR>

v2.6.0<BR>
   - Added "User Guide" and "Changelog" to help menu<BR>
   - Implemented hotkey "F4" to start and stop<BR>
   - Changed "Auto Clicker" to "Auto Farmer" and removed moving of cursor<BR>
   - Changed a lot of backend code for better optimization / organization<BR><BR>

v2.5.1<BR>
   - Fixed Auto Joiner for 1920x1080 and 1536x864<BR>
   - Added small sleep delay for Backup Joiner<BR><BR>

v2.5.0<BR>
   - Adjusted Auto Joiner / Backup Joiner to compensate for button movement on join screen<BR>
   - Added/Fixed 1536x864 support<BR><BR>

v2.4.0<BR>
   - Added an alternative "Backup Auto Joiner" for users that the original "Auto Join Server" is not working for. This function works like the original; please hit the start button on the main server selection page with the server you want to join at the top of the list.<BR><BR>

v2.3.0<BR>
   - Changed AntiAFK to A & D (Strafe) with X (Prone) in between for better movement control, will continue to monitor (reports of moving too much forward into the wall)<BR>
   - minor fix to AutoJoiner stop logic<BR>
   - minor fix for 3440x1440 / 1920x1200 (small adjustments)<BR><BR>

v2.2.0<BR>
   - Added Eating and Drinking to AntiAFK every 1hr (make sure you have food and drink on 9 and 0, can adjust if too slow)<BR>
   - Added extra logic to immediately stop when stop is clicked (would previously try to finish task then stop)<BR>
   - Increased delay on AutoJoiner from 0.1 to 0.5 seconds between clicks to prevent program from becoming unresponsive.<BR>
   - Adjusted some program padding<BR><BR>

v2.1.0<BR>
   - Fixed 1920x1200 Resolution Scaling<BR>
   - Fixed AntiAFK to press keys longer<BR>
   - Fixed misclick on join screen for people with/without Bob's Tall Tales DLC<BR><BR>

v2.0.0<BR>
   - Added New features AntiAFK and AutoClicker<BR>
   - Fixed code to detect resolution and scale accordingly<BR>
   - Fixed Button to toggle the start and stop process<BR>
   - Added show current user screen resolution for troubleshooting<BR><BR>

v1.0.0<BR>
   - Program created and basic Autojoin (only worked on 3440x1440)<BR><BR>
     
