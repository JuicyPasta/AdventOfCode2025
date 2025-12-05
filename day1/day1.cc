#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;



int day1_part1() {
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
        if (pos == 0) zero_count++;

    }

    fclose(stdin);
    return zero_count;    
}

int day1_part2() {
    freopen("input.txt", "r", stdin);

    int pos = 50; 
    int zero_count = 0;
    std::string line;

    while (cin >> line) {
        int times = stoi(line.substr(1, line.size()));
        line[0] == 'L' ? pos -= times : pos += times;

        zero_count += pos / 100;

        pos = pos % 100;
        if (pos < 0) {
            pos = 100+pos;
        }
        cout << "Read line: " << line << " times " << times <<  " New Pos: " << pos << endl;

        if (pos == 0) zero_count++;

    }    

    cout << "Zero Count: " << zero_count << endl;
    fclose(stdin);
    return zero_count;
}

int main () {
    //int day1_part1_out = day1_part1();
    //cout << "Day 1 part 1: " << day1_part1_out << endl;

    int day1_part2_out = day1_part2();
    cout << "Day 1 part 2: " << day1_part2_out << endl;
}