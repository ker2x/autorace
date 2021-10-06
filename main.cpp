#include <iostream>
#include "standard_bench.h"
#include "app.h"


//Bench from standard test
//BENCHMARK(BM_empty);
//BENCHMARK(BM_mt19937);
//BENCHMARK(BM_rndFloat);

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {

    /*
    // run benchmarks
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) {
        std::cout << "ReportUnrecognizedArguments" << std::endl;
        return 1;
    }
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::Shutdown();
*/

    atexit(SDL_Quit);

    app application;
    application.createGraphicContext(1024, 768, false);
    application.run();
    return 0;
}
