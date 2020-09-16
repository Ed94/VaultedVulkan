# Guide 1 Introduction: Learn the workspace

This guide will go through all the necessary information regarding the setup used for the guides along with getting started with the provided Utils library and CrossWindow.

## First lets go over the setup being used here for the tutorial:  

So the editor being used for the tutorial is Visual Studio Code, check out these tips and tricks if your new to it:   
[Tips & Tricks](https://code.visualstudio.com/docs/getstarted/tips-and-tricks)

The directories used in all the buildables are _Common and _Thirdparty. 

_Common provides helper implementation for going through the guides more helpful.

_ThirdParty contains all the necessary dependencies with exception to the VaultedThermals library which the cmake automatically gets from the include directory.

The build directory will contain all the cmake packaging files including the binaries for the guides and user space in its bin subdirectory.

Each guide will have a Readme.md file that is intended to be read on the library's github. The Readme will be a walkthrough of how to get to the end state of the implementation provided within the guide. 

## Now that your familiar with the setup lets move on to the guide itself: ##

While completing this guide, use the [UserSpace](https://github.com/Ed94/VaultedThermals/tree/master/guides/UserSpace) to follow along. The guides are designed to build off from each other, so that once directory can be used for the entire set of guides here.

**Now as with all the other guides its good to test to make sure that the guides source builds and runs on your machine so go ahead and do that:**   
![gif](https://i.imgur.com/8clt5Xh.gif)

(You can close the application with ALT-F4)

**You may notice on your directory viewer that a new log file has been dropped:**   
![img](https://i.imgur.com/AK4rT3K.png)

The Utils library provides a Logger that will log to console and to a file with the time of the `LOG(message)` function being called for the first time.

This will be the first thing we setup in your own xmain.

Go ahead and include it right after cross window:   
![img](https://i.imgur.com/QvHD9hg.png)

**Open up your main.cpp now and give yourself a hello world message:**   
![img](https://i.imgur.com/Ug9XuFy.png)

If you run the project now you should see your log pop up to the side with your message:   
![img](https://i.imgur.com/O1ATSca.png)

Once we get through this guide, you will have a console open, however this log can be your fallback just in case the program fails.

## xmain

CrossWindow abstracts away the platform dependent entrypoint for you instead of the platform compiler itself (if you had set it up as a console application). It achieves this by generating a platform dependent entrypoint and then calling xmain from there.

The implementation can be found in its main directory:
![img](https://i.imgur.com/dzAsDkD.png)

## Creating a window

Now to get a window up and running right, three objects are required:   
![img](https://i.imgur.com/bB4gWvo.png)   
- `xwin::EventQueue`: Handles the window's events.
- `xwin::WindowDesc`: Defines the window creation parameters.
- `xwin::Window`: Represents the window object.

Go ahead and fill in the wdesc:   
![img](https://i.imgur.com/9vHInNf.png)

Next for the purposes of these guides, the entire execution from now on will be wrapped in a C++ try-catch:   
![img](https://i.imgur.com/O9xrE0z.png)

Now within the try block, create the window and provide it the wdesc, and eventqueue objects:   
![img](https://i.imgur.com/86mPYdf.png)   
The create function will return if the window creation succeeds so wrap it in an if else as well.

The rest of the code is the engine loop that currently only updates on events and detects when a window should close:   
![img](https://i.imgur.com/tdUT8fS.png)

This is everything required before getting our hands dirty. Next guide is completing a Vulkan application handshake.