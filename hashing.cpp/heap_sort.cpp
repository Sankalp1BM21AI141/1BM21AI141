#include <iostream>
#include <ctime>
using namespace std;
class HeapSort {
public:
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
        
        if (right < n && arr[right] > arr[largest])
            largest = right;
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void sort(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort heapSort;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    clock_t start_time = clock();
    heapSort.sort(arr, n);
    clock_t end_time = clock();

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    cout << endl;

    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Execution time: " << execution_time << " seconds" << endl;

    return 0;
}
