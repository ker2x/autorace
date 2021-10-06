//
// Created by ker on 01/10/2021.
//

#ifndef AUTORACE_APP_H
#define AUTORACE_APP_H

#include <SDL.h>
//#include <SDL/SDL_opengl.h>
#include <iostream>

class App {

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
    bool keepRunning = true;
    SDL_Event event {};

    void HandleEvent() noexcept;

public:
    App();

    void CreateGraphicContext(int width, int height, bool fullscreen) noexcept;
    void Run();

};


#endif //AUTORACE_APP_H
