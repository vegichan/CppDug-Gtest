#ifndef PROJECT_GOOGLETESTDEMO_H
#define PROJECT_GOOGLETESTDEMO_H

#include <random>

bool getTrue() { return true; }

void throwEx(int param) {
    if (param < 0) throw std::invalid_argument("param smaller than 0");
}

int getFive() { return 5; }

void failInpredictably() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> dist(1.0, 100.0);

    double randVal = dist(generator);
    if (randVal < 5.0) {
        throw std::runtime_error("random failure happened");
    }
}

#endif //PROJECT_GOOGLETESTDEMO_H
