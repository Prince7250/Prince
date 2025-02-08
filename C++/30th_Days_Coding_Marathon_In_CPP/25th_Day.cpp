//1) Capitalize First Letter of every Word in a File bookmark_border
// Write a function as below, which given two filenames in parameters, change the first letter of every word in first file to uppercase of that character if it is a lower case character and store it in the second file.

// Sample Input
// Capital1.txt
// output.txt

// #include <iostream>
// #include <fstream>
// #include <cctype>
// #include <cstring>

// using namespace std;

// void capitalizeWords(char source[20], char dest[20]) {
//     ifstream inputFile(source);
//     ofstream outputFile(dest);

//     if (!inputFile || !outputFile) {
//         cout << "Error opening file.";
//         return;
//     }

//     string line;
//     while (getline(inputFile, line)) {
//         bool isNewWord = true;

//         for (char &c : line) {
//             if (isNewWord && isalpha(c)) {
//                 c = toupper(c);
//             }
//             isNewWord = !isalpha(c);
//         }

//         outputFile << line << endl;
//     }

//     inputFile.close();
//     outputFile.close();
// }

// int main() {
//     char source[20] = "Capital1.txt";
//     char dest[20] = "output.txt";

//     capitalizeWords(source, dest);

//     cout << "Processing completed. Check output.txt";

//     return 0;
// }

// 2) Reverse the Content of File and Print it bookmark_border
// Given a text file in current directory, print its contents backwards from last word of last line back to the first word of first line.

// Input
// You have been provided a text file name in input. 
// Output
// Print the contents of file in backward manner.
// Sample Input
// file1.txt

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    char filename[20];
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file.\n";
        return 1;
    }

    vector<string> lines, words;
    string line, word;

    while (getline(file, line))
        lines.push_back(line);

    file.close();

    for (int i = lines.size() - 1; i >= 0; i--) {
        stringstream ss(lines[i]);
        while (ss >> word)
            words.push_back(word);

        for (int j = words.size() - 1; j >= 0; j--)
            cout << words[j] << (j > 0 ? " " : "");
        
        cout << endl;
        words.clear();
    }

    return 0;
}




