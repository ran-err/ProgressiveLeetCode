//
// Created by raner on 2022/8/5.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (int(prices.size()) <= 0) return 0;
        vector<int> variations(prices.size());
        variations[0] = 0;
        for (int i {1}; i < int(prices.size()); ++i) {
            variations[i] = prices[i] - prices[i - 1];
        }
        // for (auto i: variations) cout << i << " "; cout << endl;
        return maxp(variations, 1, int(variations.size()) - 1);
    }
private:
    int maxp(vector<int> const & variations, int left, int right) {
        if (left > right) return 0;
        if (left == right) return variations[left] > 0 ? variations[left]: 0;
        int mid = (left + right) / 2;
        int left_max = maxp(variations, left, mid);
        int right_max = maxp(variations, mid + 1, right);

        int sum {0};
        int left_part {variations[mid]};
        for (int i {mid - 1}; i >= left; --i) {
            sum += variations[i];
            if (sum > left_part) left_part = sum;
        }  // error caused by lacking unit test

        sum = 0;
        int right_part {variations[mid + 1]};
        for (int i {mid + 2}; i <= right; ++i) {
            sum += variations[i];
            if (sum > right_part) right_part = sum;
        }

        int cross_max = left_part + right_part;

        if (left_max > right_max && left_max > cross_max) return left_max;
        else if (right_max > left_max && right_max > cross_max) return right_max;
        else return cross_max;
    }
};

int main() {
    vector<int> a {7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(a);

    return 0;
}
