#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;



int day1_part1() {
    if (!freopen("input.txt", "r", stdin)) {
        cerr << "Error opening file" << endl;
        return -1;
    }

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
        if (pos == 0) zero_count++;

    }

    fclose(stdin);
    return zero_count;    
}

int day1_part2() {
    // 1. CLEAR THE FLAGS from the previous run
    cin.clear(); 

    // 2. Re-open the file
    if (!freopen("input.txt", "r", stdin)) {
        cerr << "Error opening file" << endl;
        return -1;
    }
    int pos = 50; 
    int zero_count = 0;
    std::string line;

    while (cin >> line) {
        int times = stoi(line.substr(1, line.size()));
        zero_count += std::abs(times / 100);
        times = times % 100;

        line[0] == 'L' ? pos -= times : pos += times;

        if (pos == 0 || pos == 100 || pos == -100) {
            zero_count++;
            pos = 0;
        } else if (pos < 0) {
            zero_count++;
            pos = 100+pos;
        } else if (pos > 100) {
            zero_count++;
            pos = pos % 100;
        }
    }    

    cout << "Zero Count: " << zero_count << endl;
    fclose(stdin);
    return zero_count;
}

int main () {
    int day1_part1_out = day1_part1();
    cout << "Day 1 part 1: " << day1_part1_out << endl;

    int day1_part2_out = day1_part2();
    cout << "Day 1 part 2: " << day1_part2_out << endl;
}