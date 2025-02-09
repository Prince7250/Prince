//1) Print the lines from file bookmark_border
// Access a text file from current folder and print its contents in odd-even manner i.e. print all the odd lines first then print the even lines.
// Input Format:
// You have been provided a text file path in input.
// Output Format:
// Print the file contents in odd-even manner.
// Sample Input
// file1.txt

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filePath;
    cin >> filePath;
    
    ifstream file(filePath);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    
    string oddLines[1000], evenLines[1000];
    string line;
    int oddIndex = 0, evenIndex = 0, lineNumber = 1;
    
    while (getline(file, line)) {
        if (lineNumber % 2 == 1) {
            oddLines[oddIndex++] = line;
        } else {
            evenLines[evenIndex++] = line;
        }
        lineNumber++;
    }
    file.close();
    
    for (int i = 0; i < oddIndex; i++) {
        cout << oddLines[i] << endl;
    }
    
    for (int i = 0; i < evenIndex; i++) {
        cout << evenLines[i] << endl;
    }
    
    return 0;
}



//2)Count the unique words from a file bookmark_border
// Write a function named countUniqueWords() that accepts a file name as a parameter and returns a count of the number of unique words in the file.

// #include <iostream>
// #include <fstream>
// #include <cctype>
// #include <string>
// using namespace std;

// int countUniqueWords(string filename) {
//     ifstream file(filename);
//     if (!file) { // Check if the file exists
//         cout << "Error: Unable to open file " << filename << endl;
//         return 0;
//     }
    
//     string uniqueWords[10000]; // Array to store unique words
//     int uniqueCount = 0; // Counter for unique words
//     string line, wordBuffer;
    
//     cout << "Processing file: " << filename << endl;
    
//     while (getline(file, line)) { // Read the file line by line
//         cout << "Reading line: " << line << endl;
//         wordBuffer = "";
//         for (char c : line) { // Process each character in the line
//             if (isalnum(c)) { // If the character is alphanumeric, add it to the wordBuffer
//                 wordBuffer += tolower(c);
//             } else if (!wordBuffer.empty()) { // If a non-alphanumeric character is found, process the word
//                 cout << "Processing word: " << wordBuffer << endl;
//                 bool found = false;
//                 for (int i = 0; i < uniqueCount; i++) { // Check if the word is already in the array
//                     if (uniqueWords[i] == wordBuffer) {
//                         found = true;
//                         break;
//                     }
//                 }
//                 if (!found && uniqueCount < 10000) { // If not found, add to unique words array
//                     uniqueWords[uniqueCount++] = wordBuffer;
//                     cout << "Added unique word: " << wordBuffer << endl;
//                 }
//                 wordBuffer = ""; // Reset the word buffer for the next word
//             }
//         }
//         if (!wordBuffer.empty()) { // Process the last word in the line if any
//             cout << "Processing last word in line: " << wordBuffer << endl;
//             bool found = false;
//             for (int i = 0; i < uniqueCount; i++) {
//                 if (uniqueWords[i] == wordBuffer) {
//                     found = true;
//                     break;
//                 }
//             }
//             if (!found && uniqueCount < 10000) {
//                 uniqueWords[uniqueCount++] = wordBuffer;
//                 cout << "Added unique word: " << wordBuffer << endl;
//             }
//         }
//     }
    
//     file.close(); // Close the file
//     cout << "Total unique words found: " << uniqueCount << endl;
//     return uniqueCount; // Return the count of unique words
// }

// int main() {
//     string filename;
//     cout << "Enter filename: ";
//     cin >> filename; // Read the file name from input
//     int result = countUniqueWords(filename);
//     cout << "Unique word count: " << result << endl; // Output the count of unique words
//     return 0;
// }
