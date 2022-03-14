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
            unordered_set<char> buffer; // int will work OK
            int i{0}, j{0};
            while (j != s.size()) {
                if (buffer.find(s[j]) == buffer.end()) {
                    // not repeat
                    buffer.insert(s[j]);
                    j += 1;
                } else {
                    buffer.erase(s[i]);
                    i += 1;
                }
                if (j - i > maxLength) maxLength = j - i;
            }
            return maxLength;
        }
    }
};

int main(){
    Solution sol;
    string s{"pwwkew"};
    printf("%d",sol.lengthOfLongestSubstring(s));

    return 0;
}
