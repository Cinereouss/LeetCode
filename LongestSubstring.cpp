#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int res = 0;
    int temp = 0;
    int beginWindown = 0;
    int endWindown = 0;
    set<char> substring;

    while (beginWindown < s.length() && endWindown < s.length()) {
        temp = substring.size();
        substring.insert(s[endWindown]);
        if (temp < substring.size()) {
            res = max(res, endWindown - beginWindown + 1);
            endWindown++;
        } else {
            substring.erase(s[beginWindown]);
            beginWindown++;
        }
    }
    return res;
}

int main() {
    /*
        Given a string s, find the length of the longest substring without
       repeating characters. Example 1: Input: s = "abcabcbb" Output: 3
            Explanation: The answer is "abc", with the length of 3.

        Example 2:
            Input: s = "bbbbb"
            Output: 1
            Explanation: The answer is "b", with the length of 1.

        Example 3:
            Input: s = "pwwkew"
            Output: 3
            Explanation: The answer is "wke", with the length of 3.
            Notice that the answer must be a substring, "pwke" is a subsequence
       and not a substring.

        Example 4:
            Input: s = ""
            Output: 0

        Constraints:
            0 <= s.length <= 5 * 104
            s consists of English letters, digits, symbols and spaces.
    */

    string str = "abcabcbb";
    lengthOfLongestSubstring(str);

    return 0;
}