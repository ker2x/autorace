//
// Created by ker on 01/10/2021.
//

#ifndef AUTORACE_APP_H
#define AUTORACE_APP_H

#include <SDL.h>
#include <iostream>
#include <memory>

#include <boost/log/trivial.hpp>

class app {

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window {nullptr, &SDL_DestroyWindow};
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer {nullptr, &SDL_DestroyRenderer};
    bool keepRunning = true;
    SDL_Event event {};

    void handleEvent() noexcept;

public:
    app() noexcept;

    void createGraphicContext(int width, int height, bool fullscreen) noexcept;
    void run();

};


#endif //AUTORACE_APP_H
