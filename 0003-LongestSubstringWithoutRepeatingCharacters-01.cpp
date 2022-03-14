//
// Created by raner on 2022/3/14.
//
#include <cstdio>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        else {
            // length = j - i + 1
            int maxLength{1};
            for (int i = 0; i < s.size(); ++i) {
                for (int j = i; j < s.size(); ++j) {
                    unordered_set<char> buffer; // int will work OK
                    for (int k = i; k <= j; ++k) {
                        buffer.insert(s[k]);
                    }
                    if (buffer.size() < j - i + 1) {
                        break; // longer substring will not satisfy the condition
                    }
                    else {
                        if (buffer.size() > maxLength) maxLength = buffer.size();
                        else ;
                    }
                }
            }
            return maxLength;
        }
    }
};

int main(){
    Solution sol;
    string s{"abcabcbb"};
    printf("%d",sol.lengthOfLongestSubstring(s));

    return 0;
}
