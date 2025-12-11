// #include<iostream>
// using namespace std;
// int main()
// {
//     while(true){
//         cout<<"This is an infinite loop. Press Ctrl+C to stop it.\n This is my new laptop sdfiefbsisufhsiuc  euwhfuiehfuids cwehgfuiebfui efeuwghfui"<<endl;
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <string>
// #include <chrono>
// #include <cstdlib>  // for rand()
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cout << "Starting stress test (no threads)... Press Ctrl+C to stop.\n";

//     vector<string> memoryHog;
//     string chunk(10 * 1024 * 1024, 'A'); // 10 MB block

//     long long counter = 0;

//     while (true) {
//         // Heavy CPU math load
//         volatile long long x = 1;
//         for (int i = 1; i < 500000; ++i)
//             x = (x * i) % 999983;

//         // Gradually eat memory
//         if (counter % 50 == 0) { // every few loops
//             memoryHog.push_back(chunk);
//             cout << "Allocated " << memoryHog.size() * 10 << " MB RAM so far...\n";
//         }

//         counter++;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << "Starting 8 GB stress test... Press Ctrl+C to stop.\n";

    const int RAM_GB = 1;      // ⚙️ amount of RAM to use (half of your total)
    const int CHUNK_MB = 10;   // each block = 10 MB
    const int BLOCKS = (RAM_GB * 1024) / CHUNK_MB;

    cout << "Allocating approximately " << RAM_GB << " GB RAM (" << BLOCKS << " blocks)...\n";

    vector<string> memoryHog;
    string chunk(CHUNK_MB * 1024 * 1024, 'A');

    for (int i = 0; i < BLOCKS; ++i)
        memoryHog.push_back(chunk);

    cout << "Memory allocation complete. Beginning infinite CPU loop...\n";

    long long counter = 0;

    while (true) {
        // 🧮 CPU-heavy math
        volatile long long x = 1;
        for (int i = 1; i < 1000000; ++i)
            x = (x * i) % 999983;

        // ♻️ Keep RAM active
        memoryHog[counter % memoryHog.size()][0] = 'B';
        counter++;

        if (counter % 200 == 0)
            cout << "Running... CPU and memory stress active.\n";
    }

    return 0;
}
