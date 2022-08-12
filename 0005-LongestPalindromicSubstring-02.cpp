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
        //int max_length {numeric_limits<int>::lowest()};  // due to base case minimal value
        int max_length {1};
        int left {0}, right {0};
        vector<vector<int>> m(s.size(), vector<int>(s.size()));
        // base cases
        for (int i {0}; i < int(s.size()); ++i) {
            m[i][i] = 1;
        }  // unit test一开始可以先把一些很长的用来测边界的用例先注释掉
        for (int i {0}; i < int(s.size()) - 1; ++i) {
            // m[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;  // ※※※动态规划中更新最大值是从base case开始的，测试时多考虑测base case
            if (s[i] == s[i + 1]) {
                m[i][i + 1] = 2;
                max_length = 2;
                left = i;
                right = i + 1;
            }
        }  // 如果测试用例不够unit test的（即反应不出测试效果），就立即加一些用例
        for (int l {3}; l <= int(s.size()); ++l) {
            for (int i {0}; i <= int(s.size()) - l; ++i) {
                int j {i + l - 1};  // 临时变量可以减少错误
                if (s[i] == s[i + l - 1] && m[i + 1][i + l - 2] == l - 2) {  // arst1331arst
                    // if (j - i < 3)  // 可以将长度为2融入计算
                    m[i][i + l - 1] = m[i + 1][i + l - 2] + 2;
                } else {
                    m[i][i + l - 1] = max(m[i + 1][i + l - 1], m[i][i + l - 2]);
                }

                if (m[i][i + l - 1] > max_length) {
                    max_length = m[i][i + l - 1];
                    left = i;
                    right = i + l - 1;
                }
            }
        }

        //printMatrix(m);

        return string(s.begin() + left, s.begin() + right + 1);  // s.substr
    }
private:
    static void printMatrix(vector<vector<int>> const & m) {
        for (auto & v: m) {  // pass by ref?
            for (auto i: v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
//    vector<string> pa_test_cases {
//        "a",  // 1
//        "bb",  // 1
//        "121",  // 1
//        string(1000, 'h'),  // 1
//        "ab",  // 0
//        "abc",  // 0
//        "ababc"  // 0
//    };
//    for (auto t: pa_test_cases) {
//        cout << s.isPalindrome(t, 0, int(t.size()) - 1) << " ";
//    }
    vector<string> test_cases {
//            "a",  // a
//            "bb",  // bb
//            "121",  // 121
//            "babad",  // bab
//            "dabab",  // aba
//            //string(1000, 'h'),  // 1000 h
//            "arst1331arst",  // 1331
//            "arstb165",  // a
//            // leetcode cases
            "cbbd",
            // more test cases for base cases, important for dp
            "bbcd",
            "cdbb",
    };
    for (auto t: test_cases) {
        cout << s.longestPalindrome(t) << "\n";
    }

    return 0;
}
