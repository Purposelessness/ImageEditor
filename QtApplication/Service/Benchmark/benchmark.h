#ifndef IMAGEEDITOR_BENCHMARK_H
#define IMAGEEDITOR_BENCHMARK_H


class Benchmark {
public:
    template<typename Func, typename... Args>
    static void start(int iterCount, Func func, Args... args);

    template<typename Func, typename... Args>
    static void start(Func func, Args... args);

private:
    static const int iterCount = 30;
};


#include "benchmark.inl"


#endif //IMAGEEDITOR_BENCHMARK_H
