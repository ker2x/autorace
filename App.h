//
// Created by ker on 01/10/2021.
//

#ifndef AUTORACE_APP_H
#define AUTORACE_APP_H

#include <SDL.h>
#include <iostream>

class App {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    bool keepRunning;

public:
    App();
    virtual ~App();

    bool Init();
    bool CreateWindow(int width, int height);
    bool CreateRenderer();
    void HandleEvent();
    void Run();

};


#endif //AUTORACE_APP_H
