//
// Created by raner on 2022/7/23.
// CLRS 4.1
//
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return findMaxSubarray(nums, 0, int(nums.size()) - 1);
    }
private:
    int findMaxCrossingSubarray(vector<int> const & nums, int left, int mid, int right){
        int sum {0};
        int left_sum {numeric_limits<int>::min()};  // 负无穷
        for (int i {mid}; i >= left; --i) {
            sum += nums[i];
            if (sum > left_sum) left_sum = sum;
        }

        sum = 0;
        int right_sum {numeric_limits<int>::min()};
        for (int i {mid + 1}; i <= right; ++i) {
            sum += nums[i];
            if (sum > right_sum) right_sum = sum;
        }
        return left_sum + right_sum;
    }

    int findMaxSubarray(vector<int> const & nums, int left, int right){
        if (left == right) return nums[left];

        int mid {(left + right) / 2};

        int left_max_sum {findMaxSubarray(nums, left, mid)};
        int right_max_sum {findMaxSubarray(nums, mid + 1, right)};

        int crossing_max_sum {findMaxCrossingSubarray(nums, left, mid, right)};
        if (left_max_sum >= right_max_sum && left_max_sum >= crossing_max_sum) return left_max_sum;
        else if (right_max_sum >= left_max_sum && right_max_sum >= crossing_max_sum) return right_max_sum;
        else return crossing_max_sum;
    }
};

int getMaxWhiteBox(int left_max_sum, int right_max_sum, int crossing_max_sum) {
    if (left_max_sum >= right_max_sum && left_max_sum >= crossing_max_sum) return left_max_sum;
    else if (right_max_sum >= left_max_sum && right_max_sum >= crossing_max_sum) return right_max_sum;
    else return crossing_max_sum;
}

int main(){
    vector<vector<int>> test_cases {
            {0},  // 0
            {10},  // 10
            {-10},  // -10
            {-1, -2, -3, -4, -5},  // -1
            {-4, -5, -6, -1, -2, -3},  // -1
            {1, 2, 3},  // 6
            {4, 2, 1, 3},  // 10
            {-4, -5, -10, -1, 4, -1, 2, 1},  // 6
            {4, -1, 2, 1, -4, -5, -10, -1},  // 6
            {-2, 1, -3, 4, -1, 2, 1, -5, 4},  // 6
            {-2, 1, -3, 4, -1, 2, 1, -5, 4, -1},  // 6
            vector<int>(100000, 10000),  // 1 000 000 000
            vector<int>(100000, -10000)  // -10 000
    };
    Solution s;

    for (vector<int> & v : test_cases) {
        cout << s.maxSubArray(v) << "\n";
    }

    vector<vector<int>> max_test_cases {
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 1, 2},
            {3, 2, 1}
    };
    cout << "test max:\n";
    for (auto const & v : max_test_cases) {
        cout << getMaxWhiteBox(v[0], v[1], v[2]);
    }

    return 0;
}
