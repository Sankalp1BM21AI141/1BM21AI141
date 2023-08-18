#include <iostream>
#include <chrono>
#include <cstdlib> // For generating random numbers
#include <ctime>   // For seeding random number generator

class InsertionSort {
public:
    static void sort(int arr[], int size) {
        for (int i = 1; i < size; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = key;
        }
    }
};

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Test for different values of n
    for (int n = 1000; n <= 10000; n += 1000) {
        int* arr = new int[n];

        // Fill the array with random integers
        for (int i = 0; i < n; ++i) {
            arr[i] = std::rand();
        }

        // Measure the time taken to sort
        auto start = std::chrono::high_resolution_clock::now();
        InsertionSort::sort(arr, n);
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate the duration in milliseconds
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        std::cout << "Time taken to sort " << n << " elements: " << duration << " milliseconds" << std::endl;

        delete[] arr;
    }

    return 0;
}
