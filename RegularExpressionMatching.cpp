#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p) {
    int n = p.size();
    int m = s.size();
    s = "0" + s;
    p = "0" + p;

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (p[i] == s[j] || p[i] == '.') {
                if (j > 0) dp[i][j] |= dp[i - 1][j - 1];
            } else if (p[i] == '*') {
                dp[i][j] |= dp[i - 2][j];  // use 0 times
                dp[i][j] |= dp[i - 1][j];  // use 1 times
                if (s[j] == p[i - 1] || p[i - 1] == '.')
                    if (j > 0) dp[i][j] |= dp[i][j - 1];  // use multiple times
            }
        }
    }

    return dp[n][m];
}

int main() {
    /*
        Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 
            '.' Matches any single character.​​​​
            '*' Matches zero or more of the preceding element.
            The matching should cover the entire input string (not partial).

        Example 1:
            Input: s = "aa", p = "a"
            Output: false
            Explanation: "a" does not match the entire string "aa".
   
        Example 2:
            Input: s = "aa", p = "a*"
            Output: true
            Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
    
        Example 3:
            Input: s = "ab", p = ".*"
            Output: true
            Explanation: ".*" means "zero or more (*) of any character (.)".
        
        Example 4:
            Input: s = "aab", p = "c*a*b"
            Output: true
            Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
        
        Example 5:
            Input: s = "mississippi", p = "mis*is*p*."
            Output: false

        Constraints:
            0 <= s.length <= 20
            0 <= p.length <= 30
            s contains only lowercase English letters.
            p contains only lowercase English letters, '.', and '*'.
            It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
    */
    isMatch("", ".*");
    return 0;
}