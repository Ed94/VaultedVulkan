#include "CrossWindow/CrossWindow.h"
#include "Renderer.hpp"



void xmain(int argc, const char** argv)
{
    // 🖼 Create Window
    xwin::WindowDesc wdesc;
    wdesc.title = "VT Guide: Hello Triangle";
    wdesc.name = "MainWindow";
    wdesc.visible = true;
    wdesc.width = 640;
    wdesc.height = 64;
    wdesc.fullscreen = false;

    xwin::Window window;
    xwin::EventQueue eventQueue;

    if (!window.create(wdesc, eventQueue))
    { return; }

    // Engine Loop
    bool isRunning = true;

    while (isRunning)
    {
        // bool shouldRender = true;

        eventQueue.update();

        while (!eventQueue.empty())
        {
            const xwin::Event& event = eventQueue.front();

            if (event.type == xwin::EventType::Resize)
            {
                const xwin::ResizeData data = event.data.resize;

                // renderer.resize(data.width, data.height);

                // shouldRender = false;                
            }

            if (event.type == xwin::EventType::Close)
            {
                window.close();

                // shouldRender = false;

                isRunning = false;
            }

            eventQueue.pop();
        }        
    }
}