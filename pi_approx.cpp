#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES  // I define this to make sure M_PI is available
#include <cmath>

// I define a struct to store results
struct PiResults {
    double approx;
    double error;
};

// I write a function to approximate pi and calculate the error
PiResults pi_approx(int N) {
    double sum = 0.0;
    double delta_x = 1.0 / N;

    for (int k = 1; k <= N; ++k) {
        double x_k = (double)k / N;
        double f_x_k = 1.0 / (1.0 + x_k * x_k);
        double f_x_k_minus_1 = 1.0 / (1.0 + (x_k - delta_x) * (x_k - delta_x));

        sum += (f_x_k + f_x_k_minus_1) / 2.0;
    }

    double result = sum * delta_x;

    // I calculate the absolute error
    double pi_value = M_PI;
    double absolute_error = std::abs(result - pi_value);

    // I create and return a PiResults struct
    return {result, absolute_error};
}

int main() {
    int N = 1000;

    // I call the pi_approx function
    PiResults results = pi_approx(N);

    // I print the results
    std::cout << "Approximated value of pi: " << results.approx << std::endl;
    std::cout << "Absolute error: " << results.error << std::endl;

    return 0;
}
