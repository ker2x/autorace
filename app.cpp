//
// Created by ker on 01/10/2021.
//

#pragma ide diagnostic ignored "clion-misra-cpp2008-4-5-2"
#pragma ide diagnostic ignored "clion-misra-cpp2008-4-10-2"
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-0-4"
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-0-6"
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-2-12"
#pragma ide diagnostic ignored "clion-misra-cpp2008-7-4-3"

#include "app.h"
#include "hull.h"

app::app()
    : window(nullptr, SDL_DestroyWindow)
    , renderer(nullptr, SDL_DestroyRenderer)

{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS|SDL_INIT_TIMER) < 0) {
        throw std::runtime_error{std::string("Couldn't initialize SDL: ") + SDL_GetError()};
    }
}

void app::createGraphicContext(int width, int height, bool fullscreen) noexcept {

    const auto windowFlag = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;

    window.reset(SDL_CreateWindow("Autorace", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlag));
    SDL_assert_release(static_cast<bool>(window)); // NOLINT(clion-misra-cpp2008-5-0-13)

    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    SDL_assert_release(static_cast<bool>(renderer)); // NOLINT(clion-misra-cpp2008-5-0-13)

    (void) SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    (void) SDL_SetHint(SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES, "0");
}


/***
 * Main Loop
 */
void app::run() {
    std::cout << "Entering run()" << std::endl;
    std::vector<float> vecX, vecY;
    hull h;

    while(keepRunning) {
        handleEvent();
        (void) SDL_SetRenderDrawColor(renderer.get(), 96, 150, 96, 255);
        (void) SDL_RenderClear(renderer.get());
        (void) SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);

        auto cloud = h.generateRandomPointcloud<float>(25000,0.0,0.0, 1024.0, 768.0);
        for(auto p: cloud) {
            (void) SDL_RenderDrawPointF(renderer.get(), p.x(), p.y());
        }

        SDL_RenderPresent(renderer.get());

        //test
//        std::vector<hull::point2D<float>> lmp = h.convexHullFromPoint2D<float>(cloud);
    }
    std::cout << "Exiting run()" << std::endl;
}
/***
 * Handle SDL Event
 */
void app::handleEvent() noexcept {
    while (static_cast<bool>(SDL_PollEvent(&event))) // NOLINT(clion-misra-cpp2008-5-0-13)
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
