//
// Created by raner on 2022/8/12.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        // size > 1
        if (nums[0] == 0) return false;
        for (int i {int(nums.size()) - 2}; i > 0; --i) {
            if (nums[i] == 0) {
                int c{1};
                bool flag{false};
                for (int j{i - 1}; j >= 0; --j, ++c) {
                    if (nums[j] > c) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) return flag;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> test_cases {
        {2, 3, 1, 1, 4},  // 1
        {3, 2, 1, 0, 4},  // 0
        {0},  // 1
        {1},  // 1
        {0, 1},  // 0 for i > 0
        {4, 3, 2, 1, 0, 3, 2, 1, 0, 5},  // 0
        {1, 2, 1, 2, 0, 1, 1},  // 1
        {1, 1, 0, 2, 0, 1, 1},  // 0
        // leetcode cases
        {2, 0, 0},  // 1
    };
    for (auto t: test_cases) {
        cout << s.canJump(t) << endl;
    }
    
    return 0;
}
