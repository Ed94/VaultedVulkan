// Cross platform window managing library.
#include "CrossWindow/CrossWindow.h"

// Helper implementation
#include "Utils.hpp"



// This is cross-window's main function, it called on the platform dependent entrypoint.
void xmain(int argc, const char** argv)
{
    LOG("Entered CrossWindow execution: xmain");

    xwin::EventQueue eventQueue;   // Window event queue.
    xwin::WindowDesc wdesc     ;   // Window description.
    xwin::Window     window    ;   // Window object.

    // Setup the window creation parameters. 
    wdesc.title      = "Hello Cross Window!";
    wdesc.name       = "MainWindow";
    wdesc.visible    = true;
    wdesc.width      = 640;
    wdesc.height     = 64;
    wdesc.fullscreen = false;

    try
    {
        // 🖼 Create Window
        if (!window.create(wdesc, eventQueue))
            return;   // Exit if window fails to create.
        else LOG("Window created.");

        LOG("Entering engine loop.");

        bool isRunning = true;   // Sentinel for engine loop.

        while (isRunning)
        {
            // Update the event queue for the window.
            eventQueue.update();   

            // Process events.
            while (!eventQueue.empty())   
            {
                // Get the latest event.
                const xwin::Event& event = eventQueue.front();   

                // Handle window closing.
                if (event.type == xwin::EventType::Close)
                {
                    window.close();

                    isRunning = false;
                }

                // Remove the event from the queue.
                eventQueue.pop();
            }   
        }

        LOG("Exiting: xmain");
    }
    catch(const std::exception& e)
    {
        LOG(std::string("Error: ") + std::string(e.what()));
    }
}