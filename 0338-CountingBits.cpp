//
// Created by raner on 2022/8/7.
//

#include <bitset>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);  // memory leak caused by size = n
        vector<int> digits(20, 1);
        for (int i {0}; i < int(digits.size()); ++i) {
            digits[i] <<= i;
            //cout << digits[i] <<endl;
        }
        for (int num {0}; num <= n; ++num) {
            for (int i {0}; i <= 16; ++i) {
                if (digits[i] > num) break;
                else if ((num & digits[i]) != 0) {
                    result[num] += 1;
                }
            }
        }
        // for (auto i: result) cout << i << endl;

        return result;
    }
};

// iomanip hex oct bitset<20>(number)
int main() {
    vector<int> test_cases {
        0,  // boundary value + all zero bits
        //100000,  // boundary value
        1,  // 0 1
        2,  // 0 1 1
        5,  // 0 1 1 2 1 2
        8,  // 0 1 1 2 1 2 2 3 1
        16
    };
    Solution s;
    for (auto n: test_cases) {
        vector<int> result = s.countBits(n);
        for (auto i: result) cout << i << " ";
        cout << endl;
    }

    return 0;
}
