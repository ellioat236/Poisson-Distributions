#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double exponential(double mean) {
    double randomU = rand() / (RAND_MAX + 1.0);
    return -mean * log(1 - randomU);
}

int main() {
    srand(time(0));

    const int processes = 1000;
    const double arrivalR = 2.0;
    const double serviceR = 1.0;

    double arrivalTsum = 0.0;
    double serviceTsum = 0.0;
    double cTime = 0.0;

    for (int i = 1; i <= processes; i++) {
        double betweenArrivalT = exponential(1.0 / arrivalR);
        cTime += betweenArrivalT;

        double serviceTime = exponential(serviceR);
        serviceTsum += serviceTime;

        std::cout << "(" << i << ", " << cTime
                  << ", " << serviceTime << ")" << std::endl;

        if (i == processes) {
            arrivalTsum = cTime;
        }
    }

    double averageArrivalR = processes / arrivalTsum;
    double averageServiceT = serviceTsum / processes;

    std::cout << "Average Arrival Rate: " << averageArrivalR << " processes/second" << std::endl;
    std::cout << "Average Service Time: " << averageServiceT << " seconds" << std::endl;

    return 0;
}


