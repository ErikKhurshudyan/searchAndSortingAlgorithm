#include "headers/Vector.hpp"
#include "headers/function.hpp"

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

    for (; state.KeepRunning();)
    {
        mergeSort(v);
    }
}
BENCHMARK(BM_Vector_LinearSearch);


BENCHMARK_MAIN();

