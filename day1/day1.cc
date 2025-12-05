#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main () {
    freopen("input.txt", "r", stdin);

    int pos = 50; 
    int zero_count = 0;

    std::string line;

    int ctr = 0;
    while (cin >> line) {
        bool dir = line[0] == 'L' ? true : false;
        int times = stoi(line.substr(1, line.size()));

        if (dir) {
            pos -= times;
        } else {
            pos += times;
        }
        pos = pos % 100;
        if (pos < 0) {
            pos = 100+pos;
        }


        cout << "Read line: " << line << " times " << times <<  " New Pos: " << pos << endl;

        if (pos == 0) zero_count++;

    }    

    cout << "Zero Count: " << zero_count << endl;
}