#include <iostream>
#include <clocale>
using namespace std;

// Define the array dimensions.
const int ROWS = 3;
const int COLS = 4;

// Function to find the maximum repeating element in a two-dimensional array.
int findMaxRepeated(int arr[ROWS][COLS]) {
    // Initialize the maximum repeating element.
    int maxRepeated = 0;

    // Check each element of the array.
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count the number of occurrences of the current element.
            int count = 0;

            for (int k = 0; k < ROWS; k++) {
                for (int l = 0; l < COLS; l++) {
                    // Compare the current element with all array elements.
                    if (arr[i][j] == arr[k][l]) {
                        count++;
                    }
                }
            }

            // Check whether the element occurs more than once.
            if (count > 1) {
                // Update the maximum repeating element.
                if (count > 1 && (maxRepeated == 0 || arr[i][j] > maxRepeated)) {
                    maxRepeated = arr[i][j];
                }
            }
        }
    }

    return maxRepeated;
}

int main() {
    // Set the locale to support Russian language settings.
    setlocale(LC_ALL, "Russian");

    // Declare and initialize the two-dimensional array.
    int arr[ROWS][COLS] = {
        { 5, 12, 7, 3 },
        { 12, 8, 15, 7 },
        { 4, 9, 15, 2 }
    };

    // Print the two-dimensional array.
    cout << "Исходный массив:" << endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // Find the maximum repeating element using the function.
    int result = findMaxRepeated(arr);

    // Print the result.
    if (result != 0) {
        cout << "Максимальный из повторяющихся элементов: " << result << endl;
    }
    else {
        cout << "Повторяющихся элементов нет." << endl;
    }

    return 0;
}