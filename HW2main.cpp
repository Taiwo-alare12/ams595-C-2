#include <iostream>
#include <vector>
#include "approximations.h"
#include "pi_approx.h"

int main() {
    // Q1: Print the approximation and error for N = 10000 using Q1
    int N_q1 = 10000;
    PiResults result_q1 = pi_approx(N_q1);
    std::cout << "Q1 - Approximation for N = " << N_q1 << ": " << result_q1.approx << std::endl;
    std::cout << "Q1 - Absolute error: " << result_q1.error << std::endl;

    // Q2: Create a vector with elements {101, 102, 107} as an input
    std::vector<int> intervals_q2 = {101, 102, 107};
    // Print out the elements of the array from Q2 using this vector
    PiResults* results_q2 = approximations(intervals_q2);
    for (size_t i = 0; i < intervals_q2.size(); ++i) {
        std::cout << "Q2 - Approximation for N = " << intervals_q2[i] << ": " << results_q2[i].approx << std::endl;
    }

    // Don't forget to free the allocated memory
    delete[] results_q2;

    return 0;
}

