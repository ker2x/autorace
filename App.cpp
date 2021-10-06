//
// Created by ker on 01/10/2021.
//

#include "App.h"

App::App()
    : window(nullptr, SDL_DestroyWindow)
    , renderer(nullptr, SDL_DestroyRenderer)

{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS|SDL_INIT_TIMER) < 0)
        throw std::runtime_error {std::string("Couldn't initialize SDL: ") + SDL_GetError()};
}

void App::CreateGraphicContext(int width, int height, bool fullscreen) noexcept {

    const auto windowflag = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;

    window.reset(SDL_CreateWindow( "Autorace",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowflag));
    SDL_assert_release(window);

    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    SDL_assert_release(renderer);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_SetHint(SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES, "0");
}


/***
 * Main Loop
 */
void App::Run() {
    std::cout << "Entering Run()" << std::endl;
    while(keepRunning) {
        HandleEvent();
        SDL_SetRenderDrawColor(renderer.get(), 96, 150, 96, 255);
        SDL_RenderClear(renderer.get());
        SDL_RenderPresent(renderer.get());
    }
    std::cout << "Exiting Run()" << std::endl;
}

/***
 * Handle SDL Event
 */
void App::HandleEvent() noexcept {
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                keepRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        keepRunning = false;
                        break;
                    default:
                        std::cout << "KEYDOWN : " <<  event.key.keysym.scancode << std::endl;
                        break;
                }
                break;
            default:
                break;
        }
    }
}


