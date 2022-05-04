#include "benchmark.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <cstdio>

template<typename Func, typename... Args>
void Benchmark::start(int newIterCount, Func func, Args... args) {
    if (newIterCount <= 0) {
        return;
    }
    std::vector<double> elapsedTimes;
    for (int i = 0; i < newIterCount; ++i) {
        clock_t start = clock();
        func(args...);
        double diff = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        elapsedTimes.push_back(diff);
    }

    double max = *std::max_element(elapsedTimes.begin(), elapsedTimes.end());
    double min = *std::min_element(elapsedTimes.begin(), elapsedTimes.end());
    double sum = std::accumulate(elapsedTimes.begin(), elapsedTimes.end(), 0.);
    double avg = sum / newIterCount;

    puts("======================================");
    printf("\t\tMAX:\t%f\n\t\tMIN:\t%f\n\t\tAVG:\t%f\n", max, min, avg);
    puts("======================================");
}

template<typename Func, typename... Args>
void Benchmark::start(Func func, Args... args) {
    start(iterCount, func, args...);
}
