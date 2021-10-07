//
// Created by ker on 30/09/2021.
//

#include "standard_bench.h"
/*
void BM_empty(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(state.iterations());
    }
    state.SetItemsProcessed(state.iterations());
}

void BM_loop(benchmark::State& state) {
    for (auto _ : state) {
        for(uint i = 0; i < state.range(0); ++i)
            benchmark::DoNotOptimize(i);
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
}

void BM_sum32(benchmark::State& state) {
    for (auto _ : state) {
        uint32_t sum = 0;
        uint32_t size = state.range(0);
        for(uint32_t i = 0; i < size; ++i) {
            benchmark::DoNotOptimize(sum++);
        }
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(uint32_t));

}

void BM_sum64(benchmark::State& state) {
    for (auto _ : state) {
        uint64_t sum = 0;
        uint64_t size = state.range(0);
        for(uint64_t i = 0; i < size; ++i) {
//            sum++;
            benchmark::DoNotOptimize(sum++);
        }
    }
    state.SetItemsProcessed(state.iterations() * state.range(0));
    state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(uint64_t));
}

void BM_mt19937(benchmark::State& state) {
    boost::random::mt19937 gen;
    for(auto _ : state) {
        benchmark::DoNotOptimize(gen());
    }
    state.SetItemsProcessed(state.iterations());
    state.SetBytesProcessed(state.iterations() * sizeof(int));
}

void BM_stdmt19937(benchmark::State& state) {
    std::mt19937 gen;
    for(auto _ : state) {
        benchmark::DoNotOptimize(gen());
    }
    state.SetItemsProcessed(state.iterations());
    state.SetBytesProcessed(state.iterations() * sizeof(int));
}

void BM_rndFloat(benchmark::State &state) {
    boost::random::mt19937 gen;
    boost::random::uniform_real_distribution<double> doubleRand(-0.5, 0.5);
    for(auto _ : state) {
        benchmark::DoNotOptimize(doubleRand(gen));
    }
    state.SetItemsProcessed(state.iterations());
    state.SetBytesProcessed(state.iterations() * sizeof(double));

}


void cacheBench(benchmark::State &state)
{
    int bytes = 1 << state.range(0);
    int size = ( bytes / sizeof(int) ) / 2;

    std::vector<int> data;
    data.reserve(size);
    std::vector<int> indices;
    indices.reserve(size);

    // rng for the data and indices
    std::default_random_engine random_engine (
            std::chrono::steady_clock::now().time_since_epoch().count()
    );
    std::uniform_int_distribution<int> data_dist {
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max()
    };
    std::uniform_int_distribution<int> idx_dist {0, size};

    // insert random data into the vector and random indexes to the index array
    for (auto i = 0; i < size; ++i)
        data.push_back(data_dist(random_engine));

    // now pick random indices and insert into index array
    for (auto i = 0; i < size; ++i)
        indices.push_back(idx_dist(random_engine));

    // thrash all cache!!
    while (state.KeepRunning())
    {
        auto sum = 0LL;
        for (auto i : indices)
            sum += data[i];

        benchmark::DoNotOptimize(sum);
        __asm__ volatile
        ("" : : "g"(sum) : "memory");
    }

    state.SetItemsProcessed(state.iterations());
    state.SetBytesProcessed(long(state.iterations()) * long(bytes));
    state.SetLabel(std::to_string(bytes / 1024) + "kb");
}

*/
