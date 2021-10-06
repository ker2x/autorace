//
// Created by ker on 30/09/2021.
//

#ifndef SIMPLE_QUEUE_STANDARD_BENCH_H
#define SIMPLE_QUEUE_STANDARD_BENCH_H

#include <benchmark/benchmark.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/random.hpp>
#include <random>

void BM_empty(benchmark::State& state);
void BM_loop(benchmark::State& state);
void BM_sum32(benchmark::State& state);
void BM_sum64(benchmark::State& state);
void BM_mt19937(benchmark::State& state);
void BM_stdmt19937(benchmark::State& state);
void BM_rndFloat(benchmark::State& state);

void cacheBench(benchmark::State &state);


#endif //SIMPLE_QUEUE_STANDARD_BENCH_H
