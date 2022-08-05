# LeetCode 1. Two Sum (Easy)

[LeetCode 1. Two Sum (Easy) 原题链接](https://leetcode-cn.com/problems/two-sum/)

[LeetCode渐近式题解目录](https://www.jianshu.com/p/69538b766975)

## 题目内容

**English:**

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**中文：**

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**Example 1:**

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

**Example 2:**

Input: nums = [3,2,4], target = 6
Output: [1,2]

**Example 3:**

Input: nums = [3,3], target = 6
Output: [0,1]

**Constraints:**

- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

## 解

为行文简洁只给出了程序主体，如需完整程序可访问[GitHub链接](https://github.com/ran-err/ApproachingLeetCode)下载。

**方法一（通过）：**

55 / 57 个通过测试用例

直接遍历所有“两数之和”，时间O(n^2)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        for(auto it {nums.begin()}; it != nums.end(); ++it){
            for(auto jt {it + 1}; jt != nums.end(); ++jt){
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
```

**优化思路：**

只看题干很容易陷入“因为题目要求找‘两数相加和为`target`’所以需要遍历所有的两数组合”的误区，导致解空间一开始就是$n^2$大小。运算主要集中在两个循环，内层循环是一个查找，可以使用哈希表来降低查找操作的时间复杂度。对于其他“双循环内层查找”的程序也可以考虑这种优化思路。

C++中`unordered_map`的用法可以参考[cppreference](https://en.cppreference.com/w/cpp/container/unordered_map)

**方法二（通过）：**

57 / 57 个通过测试用例

内层查找改用{数字，下标}的映射来做。程序平均时间复杂度为线性

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i {0}; i < int(nums.size()); ++i) {
            if (index.find(target - nums[i]) != index.end())
                return {index[target - nums[i]], i};
            else
                index[nums[i]] = i;
        }
        return {};
    }
};
```
