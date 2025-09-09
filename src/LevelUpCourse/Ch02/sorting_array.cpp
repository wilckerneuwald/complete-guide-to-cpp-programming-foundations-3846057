// Sort an array in ascending oder using low level containers and no STL algorithm

#include <iostream>

void sort_array(int* input_array, const size_t size) {
    // Bubble sorting algorithm
    int temp;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size - 1; i++) {
            if (input_array[i] > input_array[i + 1]) {
                temp = input_array[i];
                input_array[i] = input_array[i + 1];
                input_array[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

int main() {
    int my_array[] = {7, 5, 7, 3, 5, 0};
    const size_t size = sizeof(my_array) / sizeof(my_array[0]);
    sort_array(my_array, size);
    for (int i = 0; i < size; i++) {
        std::cout << "Array[ " << i << " ] -> " << my_array + i << ": ";
        std::cout << *(my_array + i) << std::endl << std::endl;
    }

    return 0;
}