//
// Created by raner on 2022/8/4.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int n_1 {2}, n_2 {1}, now {0};
        for (int i {2}; i < n; ++i) {
            now = n_1 + n_2;
            // n_2, n_1, now
            n_2 = n_1;
            n_1 = now;
        }
        return now;
    }
};

int main() {
    Solution s;
    for (int i {1}; i < 10; ++i) {
        cout << s.climbStairs(i) << endl;
    }


    return 0;
}
