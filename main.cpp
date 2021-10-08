#include <iostream>
//#include "standard_bench.h"
#include "app.h"

//BENCHMARK(BM_empty);
//BENCHMARK(BM_mt19937);
//BENCHMARK(BM_rndFloat);

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {

    /*
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) {
        std::cout << "ReportUnrecognizedArguments" << std::endl;
        return 1;
    }
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::Shutdown();
*/

    if(atexit(SDL_Quit) != 0) {
        BOOST_LOG_TRIVIAL(fatal) << "atexit error : " << strerror(errno);
        return errno;
    }

    app application;
    application.createGraphicContext(1024, 768, false);
    application.run();

    return 0;
}
