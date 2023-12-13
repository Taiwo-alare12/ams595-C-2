
#define PI_APPROX2_H


#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES
#include <cmath>

struct PiResults {
    double approx;
    double error;
};

PiResults pi_approx(double max_error) {
    int N = 1;  // Start with a small number of intervals

    double result, absolute_error;
    do {
        double sum = 0.0;
        double delta_x = 1.0 / N;

        for (int k = 1; k <= N; ++k) {
            double x_k = (double)k / N;
            double f_x_k = 1.0 / (1.0 + x_k * x_k);
            double f_x_k_minus_1 = 1.0 / (1.0 + (x_k - delta_x) * (x_k - delta_x));

            sum += (f_x_k + f_x_k_minus_1) / 2.0;
        }

        result = sum * delta_x;

        // Calculate the absolute error
        double pi_value = M_PI;
        absolute_error = std::abs(result - pi_value);

        // Double the number of intervals for the next iteration
        N *= 2;

    } while (absolute_error > max_error);

    return {result, absolute_error};
}

int main() {
    double max_error;

    // Get the maximum acceptable error from the user
    std::cout << "Enter the maximum acceptable error: ";
    std::cin >> max_error;

    // Call the pi_approx function
    PiResults results = pi_approx(max_error);

    // Print the results
    std::cout << "Approximated value of pi: " << results.approx << std::endl;
    std::cout << "Absolute error: " << results.error << std::endl;

    return 0;
}
