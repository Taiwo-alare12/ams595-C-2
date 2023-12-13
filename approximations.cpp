#include <iostream>
#include <cmath>
#include <vector>

// I define a struct to store results
struct PiResults {
    double approx;  // Approximated value of pi
    double error;   // Absolute error compared to built-in value of pi
};

// I  write function to approximate pi and calculate the error
PiResults pi_approx(int N) {
    double sum = 0.0;
    double delta_x = 1.0 / N;

    // I use the trapezoidal rule to approximate the integral
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

// I write function to compute approximations for each input value
PiResults* approximations(const std::vector<int>& intervals) {
    // Allocate memory for results array
    PiResults* results = new PiResults[intervals.size()];

    // I compute approximations for each interval
    for (size_t i = 0; i < intervals.size(); ++i) {
        results[i] = pi_approx(intervals[i]);
    }

    return results;
}

int main() {
    // Example usage
    std::vector<int> interval_values = {1000, 2000, 5000};
    PiResults* approx_results = approximations(interval_values);

    // Access and use the results as needed
    for (size_t i = 0; i < interval_values.size(); ++i) {
        std::cout << "Approximation for " << interval_values[i] << " intervals: " << approx_results[i].approx << std::endl;
    }

    // I free the allocated memory
    delete[] approx_results;

    return 0;
}
