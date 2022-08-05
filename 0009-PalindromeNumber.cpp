//
// Created by raner on 2022/7/17.
//
#include <array>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome_string(int x) {
        if (x < 0) return false;
        string s{to_string(x)};
        for (int l{0}, r{int(s.size()) - 1}; l < r; ++l, --r) {
            if (s[l] != s[r]) return false;
        }
        return true;
    }

    bool isPalindrome_digit(int x) {
        if (x < 0) return false;
        int divisor{1};
        for (; x / divisor >= 10; divisor *= 10);
        for (; divisor >= 10; x = (x % divisor) / 10, divisor /= 100) {
            // divisor>0的话最后一位也会被拿去比较，每个奇数位的数字浪费一次时间，divisor>=10的话把这些时间节约下来了
            // 这里换成x>0也可以，但是如果最后中间一位是0或者提前剩下好多0，则提前退出比较，而最后中间一位不是0则要被左右再拿一次，很乱
            if (x / divisor != x % 10) return false;
        }
        return true;
    }

    bool isPalindrome_revert(int x) {
        if (x < 0 || (x % 10 == 0 && x / 10 != 0)) return false;
        int r{0};
        for (; r < x; r = r * 10 + (x % 10), x /= 10);
        if (r == x || r - x * 10 == r % 10) return true;
        else return false;
    }
};

void print_bool(bool b) {
    if (b) printf("true");
    else printf("false");
}

int main() {
    vector<int> v{121, // true：正例，短
                  -121, // 负例
                  -0,
                  1122,
                  10001,
                  1000021,
                  int(0x80000000)};
    Solution s;
    for (auto i: v) {
        print_bool(s.isPalindrome_string(i));
        printf(" ");
        print_bool(s.isPalindrome_digit(i));
        printf(" ");
        print_bool(s.isPalindrome_revert(i));
        printf("\n");
    }

    return 0;
}
