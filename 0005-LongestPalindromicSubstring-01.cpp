//
// Created by raner on 2022/8/10.
//
#define private public
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_length {numeric_limits<int>::lowest()};
        int left {0}, right {0};
        for (int i {0}; i < int(s.size()); ++i) {
            for (int j {i}; j < int(s.size()); ++j) {
                if (isPalindrome(s, i, j)) {
                    int sub_length = j - i + 1;
                    if (sub_length > max_length) {
                        max_length = sub_length;
                        left = i;
                        right = j;
                    }
                }
            }
        }
        string res(s.begin() + left, s.begin() + right + 1);
        return res;
    }
private:
    bool isPalindrome(string const & s, int i, int j) {
        for (; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> pa_test_cases {
        "a",  // 1
        "bb",  // 1
        "121",  // 1
        string(1000, 'h'),  // 1
        "ab",  // 0
        "abc",  // 0
        "ababc"  // 0
    };
    for (auto t: pa_test_cases) {
        cout << s.isPalindrome(t, 0, int(t.size()) - 1) << " ";
    }
    vector<string> test_cases {
            "a",  // a
            "bb",  // bb
            "121",  // 121
            "babad",  // bab
            "dabab",  // aba
            string(1000, 'h'),  // 1000 h
            "arst1331arst",  // 1331
            "arstb165"  // a
    };
    for (auto t: test_cases) {
        cout << s.longestPalindrome(t) << "\n";
    }

    return 0;
}
