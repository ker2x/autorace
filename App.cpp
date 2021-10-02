//
// Created by ker on 01/10/2021.
//

#include "App.h"

App::App() {
}

App::~App() {
    std::cout << "Destroying App" << std::endl;
    SDL_Quit();
}

/***
 * Initialize SDL
 * @return is SDL initialized ?
 */
bool App::Init() {
    std::cout << "SDL2 Init : ";

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Couldn't initialize SDL: %s\n" << SDL_GetError() << std::endl;
        return false;
    }

    if(CreateWindow(800,600)) {
        CreateRenderer();
    }

    std::cout << "Done !" << std::endl;
    return true;
}

/***
 * Main Loop
 */
void App::Run() {
    std::cout << "Entering Run()" << std::endl;
    keepRunning = true;
    while(keepRunning) {
        HandleEvent();
        SDL_SetRenderDrawColor(renderer, 96, 150, 96, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    std::cout << "Exiting Run()" << std::endl;
}

/***
 * Handle SDL Event
 */
void App::HandleEvent() {
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                keepRunning = false;
                break;

            default:
                break;
        }
    }
}

/***
 * Create SDL Renderer
 * @return
 */
bool App::CreateRenderer() {
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "\"Failed to create renderer : " << SDL_GetError();
        return false;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    return true;
}

/***
 * Create SDL Window
 * @param screen width
 * @param screen height
 * @return is window created ?
 */
bool App::CreateWindow(int width, int height) {
    window = SDL_CreateWindow(
            "Autorace",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height, 0);

    if (!window) {
        std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}
