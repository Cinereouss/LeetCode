#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, end = 1;
    for (int i = 0; i < n; i++) {
        int x = i - 1;
        int y = i + 1;
        while (x >= 0 && y < n && s[x] == s[y]) {
            if (y - x + 1 > end) {
                start = x;
                end = y - x + 1;
            }
            x--, y++;
        }
        x = i;
        y = i + 1;
        while (x >= 0 && y < n && s[x] == s[y]) {
            if (y - x + 1 > end) {
                start = x;
                end = y - x + 1;
            }
            x--, y++;
        }
    }
    string ans;
    for (int i = start; i < start + end; i++) {
        ans.push_back(s[i]);
    }
    return ans;
}

int main() {
    /*
    Given a string s, return the longest palindromic substring in s.

    Example 1:
        Input: s = "babad"
        Output: "bab"
        Note: "aba" is also a valid answer.
    
    Example 2:
        Input: s = "cbbd"
        Output: "bb"
        
    Example 3:
        Input: s = "a"
        Output: "a"
    
    Example 4:
        Input: s = "ac"
        Output: "a"

    Constraints:
        1 <= s.length <= 1000
        s consist of only digits and English letters (lower-case and/or upper-case),
    */
    cout << longestPalindrome("ababd");
    return 0;
}