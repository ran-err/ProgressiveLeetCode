//
// Created by raner on 2021/8/26.
//
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        for(auto it = nums.begin(); it != nums.end(); ++it){
            for(auto jt = it + 1; jt != nums.end(); ++jt){
                if (*it + *jt == target){
                    indexes.push_back(it - nums.begin());
                    indexes.push_back(jt - nums.begin());
                    return indexes;
                }
            }
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
