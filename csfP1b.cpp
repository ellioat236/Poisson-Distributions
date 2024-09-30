#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

double exponential(double mean) {
    double randomU = rand() / (RAND_MAX + 1.0);
    return -mean * log(1 - randomU);
}

int main() {
    srand(time(0));

    const double MTBF = 500.0;
    const double restorationT = 10.0;
    const double eTime = 20 * 365 * 24;

    double sumTime = 0.0;
    int failures = 0;

    double s1Failure = exponential(MTBF);
    double s1Restore = s1Failure + restorationT;

    double s2Failure = exponential(MTBF);
    double s2Restore = s2Failure + restorationT;

    std::cout << "Data for Server 1 and Server 2 over 20 years:\n";
    std::cout << std::setw(12) << "Time" 
              << std::setw(20) << "Server 1"
              << std::setw(20) << "Server 2" << std::endl;

    while (sumTime < eTime) {
        if (s1Failure < s2Restore && s2Failure < s1Restore) {
            failures++;
        }

        if (s1Failure < s2Failure) {
            sumTime = s1Failure;

            std::cout << std::setw(12) << sumTime
                      << std::setw(20) << "Server 1 Failed"
                      << std::setw(20) << "" << std::endl;

            std::cout << std::setw(12) << s1Restore
                      << std::setw(20) << "Server 1 Restored"
                      << std::setw(20) << "" << std::endl;

            s1Failure += exponential(MTBF);
            s1Restore = s1Failure + restorationT;
        } else {
            sumTime = s2Failure;

            std::cout << std::setw(12) << sumTime
                      << std::setw(20) << ""
                      << std::setw(20) << "Server 2 Failed" << std::endl;

            std::cout << std::setw(12) << s2Restore
                      << std::setw(20) << ""
                      << std::setw(20) << "Server 2 Restored" << std::endl;

            s2Failure += exponential(MTBF);
            s2Restore = s2Failure + restorationT;
        }
    }

    std::cout << "\nTotal system failures in 20 years: " << failures << std::endl;
    return 0;
}

