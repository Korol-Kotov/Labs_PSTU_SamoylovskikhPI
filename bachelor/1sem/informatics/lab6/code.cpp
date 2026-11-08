#include <iostream>
#include <clocale>
using namespace std;

int main() {
    // Set the locale to support Russian language settings.
    setlocale(LC_ALL, "Russian");

    // Declare a character array to store the input string.
    char s[256];

    // Read the input string.
    cout << "Enter a string: ";
    cin.getline(s, 256);

    // Initialize the index for processing the string.
    int i = 0;

    // Create an array to store the resulting string.
    char result[256];

    // Initialize the index for the resulting string.
    int j = 0;

    // Process the string until the terminating period is found.
    while (s[i] != '.' && s[i] != '\0') {
        // Skip one or more spaces between words.
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

        // Check whether the word is an identifier.
        bool isIdentifier = true;

        // Check the first character of the word.
        if (!((s[start] >= 'a' && s[start] <= 'z') ||
              (s[start] >= 'A' && s[start] <= 'Z') ||
              s[start] == '_')) {
            isIdentifier = false;
        }

        // Check the remaining characters of the word.
        for (int k = 1; k < len; k++) {
            if (!((s[start + k] >= 'a' && s[start + k] <= 'z') ||
                  (s[start + k] >= 'A' && s[start + k] <= 'Z') ||
                  (s[start + k] >= '0' && s[start + k] <= '9') ||
                  s[start + k] == '_')) {
                // Mark the word as an invalid identifier.
                isIdentifier = false;
                break;
            }
        }

        // Copy the word to the resulting string if it is a valid identifier.
        if (isIdentifier && len > 0) {
            // Add a space before the word if it is not the first word.
            if (j > 0) {
                result[j] = ' ';
                j++;
            }

            // Copy all characters of the current word.
            for (int k = 0; k < len; k++) {
                result[j] = s[start + k];
                j++;
            }
        }
    }

    // Add the terminating period and null character.
    result[j] = '.';
    result[j + 1] = '\0';

    // Display the resulting string.
    cout << "Result: " << result << endl;

    return 0;
}