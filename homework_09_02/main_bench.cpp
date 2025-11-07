#include "headers/Vector.hpp"

#include <benchmark/benchmark.h>

const int SIZE = 1 << 15; // 32768 elements

// ---- Vector ----
static void BM_Vector_LinearSearch(benchmark::State& state)
{
    Vector<int> v;
    for (int i = 0; i < SIZE; ++i)
    {
        v.push_back(i);
    }
    int key = SIZE - 1;

    for (; state.KeepRunning();)
    {
        bool found = v.binarySearch(key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_Vector_LinearSearch);


BENCHMARK_MAIN();

