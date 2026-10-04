#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_LEN = 200;
    char sentence[MAX_LEN];

    cout << "Enter a sentence: ";
    cin.getline(sentence, MAX_LEN);

    char *ptr = sentence;

    int upperCount = 0, lowerCount = 0, spaceCount = 0;

    while (*ptr != '\0') {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            upperCount++;
        } else if (*ptr >= 'a' && *ptr <= 'z') {
            lowerCount++;
        } else if (*ptr == ' ') {
            spaceCount++;
        }
        ptr++; 
    }

    cout << "Uppercase letters: " << upperCount << endl;
    cout << "Lowercase letters: " << lowerCount << endl;
    cout << "Spaces:            " << spaceCount << endl;

    return 0;
}