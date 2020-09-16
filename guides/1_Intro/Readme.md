# Guide 1 Introduction: Learn the workspace

This guide will go through all the necessary information reguarding the setup used for the guides along with getting started with the provided Utils library and CrossWindow.

**First lets go over the setup being used here for the tutorial:**   

The directories used in all the buildables are _Common and _Thirdparty. 

_Common provides helper implementation for going through the guides more helpful.

_ThirdParty contains all the necessary dependencies with exception to the VaultedThermals library which the cmake automatically gets from the include directory.

The build directory will contain all the cmake packaging files including the binaries for the guides and user space in its bin subdirectory.

Each guide will have a Readme.md file that is intended to be read on the library's github. The Readme will be a walkthrough of how to get to the end state of the implementation provided within the guide. 

**Now that your familiar with the setup lets move on to the guide itself:**   

While completing this guide, use the [UserSpace](NeedsLink] to follow along. The guides are designed to build off from each other, so that once directory can be used for the entire set of guides here.

**Now as with all the other guides its good to test to make sure that the guides source builds and runs on your machine so go ahead and do that:**   
[gif](https://i.imgur.com/8clt5Xh.gif)

**You may notice on your directory viewer that a new log file has been dropped:**   
[img](https://i.imgur.com/AK4rT3K.png)

The Utils library provides a Logger that will log to console and to a file with the time of the LOG function being called for the first time.

Go ahead and include it right after cross window:
[img](https://i.imgur.com/QvHD9hg.png)

This will be the first thing we setup in your own xmain.

**Open up your main.cpp now and give yourself a hello world message:**   
[img](https://i.imgur.com/Ug9XuFy.png)

If you run the project now you should see your log pop up to the side with your message:   
[img](https://i.imgur.com/O1ATSca.png)

Once we get through this guide, you will have a console open, however this log can your fallback just in case the program fails.