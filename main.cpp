#include <iostream>
#include "standard_bench.h"
#include "App.h"
#include <libqhullcpp/Qhull.h>



// Bench from standard test
BENCHMARK(BM_empty);


int main(int argc, char** argv) {

    App app;
    orgQhull::Qhull qh;



    // Hi !
    std::cout << "Hello, World!" << std::endl;

    // Run benchmarks
    /*
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) {
        std::cout << "ReportUnrecognizedArguments" << std::endl;
        return 1;
    }
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::Shutdown();
    */

    App application;
    if(application.Init()) {
        //application.Run();
    } else {
        std::cout << "Couldn't initialize SDL2. Goodbye." << std::endl;
    }
    application.Run();

    return 0;
}
