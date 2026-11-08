#include <iostream>
#include <clocale>
using namespace std;

int main() {
    // Set the locale to support Russian language settings.
    setlocale(LC_ALL, "Russian");

    // Initialize the array size and the starting element index.
    const int n = 8;
    int k;

    // Declare an array to store the ring elements.
    int arr[100];

    // Input the array elements.
    cout << "Enter " << n << " array elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the starting element number.
    cout << "Enter K (from 1 to " << n << "): ";
    cin >> k;

    // Convert the element number into an array index.
    k--;

    // Check whether the entered index is valid.
    if (k < 0 || k >= n) {
        cout << "Invalid K value!" << endl;
        return 1;
    }

    // Print the array starting from the K-th element and moving left.
    cout << "\nArray moving left: ";
    for (int i = 0; i < n; i++) {
        // Calculate the current index using circular movement.
        int index = (k - i + n) % n;

        // Print the current array element.
        cout << arr[index] << " ";
    }
    cout << endl;

    // Save the original first element.
    int first = arr[0];

    // Add the first element to the end of the ring.
    arr[n] = first;

    // Add the last three original elements to the ring.
    arr[n + 1] = arr[n - 3];
    arr[n + 2] = arr[n - 2];
    arr[n + 3] = arr[n - 1];

    // Update the number of elements in the ring.
    const int newN = n + 4;

    // Print the modified array starting from the K-th element and moving right.
    cout << "\nModified array moving right: ";
    for (int i = 0; i < newN; i++) {
        // Calculate the current index using circular movement.
        int index = (k + i) % newN;

        // Print the current array element.
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}