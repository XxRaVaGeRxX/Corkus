# </> Corkus </> -- Pop the cork on your mods! 
### ©2026 RavagerStudio > License: GPL-3.0
>A straightforward tool for creating ModInfo.xml files for 7 Days to Die Modlets, developed in C++.
> 
> Now in version 1.2.2, Prepare for v2.0 Everyone the app will create whole mod folders ready for any dev to make a modlet
>
>Time to pop the cork on your mod workflow
## Overview
>Wiki with more detailed instructions/changelog coming soon. 
>
> Free use ModInfo.xml Generator
> 
> Enjoy the simplicity of a one click file generation app - Set up after first run with `corkus.config`
>
> Corkus will auto-detect and generate a .config if you delete your original copy
>
> Turn off Auto Generation to "save" your config. Otherwise Corkus will overwrite every run.
## Features
>Friendly CLI interface
> 
>Quick and easy file generation
> 
>Cross-platform compatibility with CMake
>
>Now has corkus.config for setting defaults

## Usage
>Clone the repository
>
>Build with CMake for your platform, instructions below.
>
>Run the executable and follow the terminal prompts to generate your ModInfo.xml file

## Linux
##### CMake
>Ensure you have a recent CMake
>
>Clone the repo
>
>     git clone https://github.com/XxRaVaGeRxX/Corkus.git
>
> `cd` into the repo location
> 
> Then `cd /Build-Scripts/Linux`
>
>Run this command in the same directory - Gives permission to execute
>
>     chmod +x build.sh
>
>Then run this command - CMake Build Script for Linux
>
>     ./build.sh
>
>Then run the program still in the repo directory and it should run in the terminal
>
>     ./build/Corkus

##### Pre-Compiled Executable 

>Or try the pre-compiled executable in the build folder
>
>Download linux executable in the [build folder](https://github.com/XxRaVaGeRxX/Corkus/tree/master/Build-Scripts/Linux/build)
>
>Give it permission to run with `chmod +x ./Corkus` in appropriate directory
>
>Then run the executable with `./Corkus`
>
>`OR CLICK THE EXE in the path you want to create!!`

## Windows
>Please Note: Windows is not officially supported yet. I do not own a Windows machine to test on. 
> 
> If any windows user wants to help out, please feel free to submit a pull request.
> 
>Ensure you have a recent CMake
> 
>Start by cloning the repo
>
>`cd` into the repo directory
>
>`cd /Build-Scripts/Windows`
>
>Run the build.bat file
>
> `cd` into the repo directory
>
> `cd /build`
>
> `Corkus.exe`
