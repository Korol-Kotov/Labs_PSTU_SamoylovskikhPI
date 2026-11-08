#include <iostream>
#include <clocale>
using namespace std;

// Function to count negative elements in an integer array.
int count(int a[], int n) {
    // Initialize the counter.
    int result = 0;

    // Check all array elements.
    for (int i = 0; i < n; i++) {
        // Check whether the current element is negative.
        if (a[i] < 0) {
            result++;
        }
    }

    // Return the number of negative elements.
    return result;
}

// Overloaded function to count words
// that start and end with the same letter.
int count(char s[]) {
    // Initialize the counter.
    int result = 0;

    // Initialize the index for processing the string.
    int i = 0;

    // Process the string until the terminating period or null character.
    while (s[i] != '.' && s[i] != '\0') {
        // Skip spaces between words.
        while (s[i] == ' ') {
            i++;
        }

        // Save the beginning of the current word.
        int start = i;

        // Find the end of the current word.
        while (s[i] != ' ' && s[i] != '.' && s[i] != '\0') {
            i++;
        }

        // Calculate the length of the current word.
        int len = i - start;

        // Check whether the word is not empty.
        if (len > 0) {
            // Compare the first and last letters.
            if (s[start] == s[start + len - 1]) {
                result++;
            }
        }
    }

    // Return the number of matching words.
    return result;
}

int main() {
    // Set the locale to support Russian language settings.
    setlocale(LC_ALL, "Russian");

    // Declare the size of the integer array.
    int n;

    // Read the array size.
    cout << "Enter array size: ";
    cin >> n;

    // Declare an integer array.
    int a[256];

    // Read array elements.
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Display the number of negative elements.
    cout << "Number of negative elements: " << count(a, n) << endl;

    // Clear the input buffer.
    cin.ignore(1000, '\n');

    // Declare a character array to store the input string.
    char s[256];

    // Read the input string.
    cout << "Enter a string: ";
    cin.getline(s, 256);

    // Display the number of words with matching first and last letters.
    cout << "Number of matching words: " << count(s) << endl;

    return 0;
}