#include "benchmark.h"

#include <QElapsedTimer>
#include <QDebug>
#include <QVector>

template<typename Func, typename... Args>
void Benchmark::start(int newIterCount, Func func, Args... args) {
    if (newIterCount <= 0) {
        return;
    }
    QVector<int> elapsedTimes;
    for (int i = 0; i < newIterCount; ++i) {
        QElapsedTimer time;
        time.start();
        func(args...);
        elapsedTimes << static_cast<int>(time.elapsed());
    }

    double max = *std::max_element(elapsedTimes.constBegin(), elapsedTimes.constEnd()) / 1000.0;
    double min = *std::min_element(elapsedTimes.constBegin(), elapsedTimes.constEnd()) / 1000.0;
    int sum = std::accumulate(elapsedTimes.constBegin(), elapsedTimes.constEnd(), 0);
    double avg = sum / (newIterCount * 1000.0);

    qDebug() << "    MAX: " << max << '\n' <<
                "    MIN: " << min << '\n' <<
                "    AVG: " << avg << '\n' <<
                "************************************************************";
}

template<typename Func, typename... Args>
void Benchmark::start(Func func, Args... args) {
    start(iterCount, func, args...);
}
