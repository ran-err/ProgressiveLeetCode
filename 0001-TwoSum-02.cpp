//
// Created by raner on 2022/3/18.
//
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); ++i) {
            if (index.find(target - nums[i]) != index.end())
                return {index[target - nums[i]], i};
            else
                index[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    // Example 1
    vector<int> nums{2,7,11,15};
    int target{9};
    // Example 2
//    vector<int> nums{3,2,4};
//    int target{6};
    // Example 3
//    vector<int> nums{2,7,11,15};
//    int target{9};
    for (auto i: s.twoSum(nums, target)) {
        printf("%d ", i);
    }
    return 0;
}
