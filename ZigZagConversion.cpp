#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows) {
    string res;
    int strLength = s.length();

    if (numRows == 1) return s;

    for (int row = 0; row < numRows; ++row) {
        int point = row;

        while (point < strLength) {
            res += s[point];
            point += 2 * numRows - 2;
            if (point - row * 2 < strLength && row != 0 && row != numRows - 1) {
                res += s[point - row * 2];
            }
        }
    }

    return res;
}

int main() {
    /*
        The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
        (you may want to display this pattern in a fixed font for better legibility)
       
        P   A   H   N
        A P L S I I G
        Y   I   R
       
        And then read line by line: "PAHNAPLSIIGYIR"
        Write the code that will take a string and make this conversion given a number of rows:
        string convert(string s, int numRows);
        
        Example 1:
            Input: s = "PAYPALISHIRING", numRows = 3
            Output: "PAHNAPLSIIGYIR"
        
        Example 2:
            Input: s = "PAYPALISHIRING", numRows = 4
            Output: "PINALSIGYAHRPI"
        
        Explanation:
            P     I    N
            A   L S  I G
            Y A   H R
            P     I
        
        Example 3:
            Input: s = "A", numRows = 1
            Output: "A"

        Constraints:
            1 <= s.length <= 1000
            s consists of English letters (lower-case and upper-case), ',' and '.'.
            1 <= numRows <= 1000
    */

    cout << convert("ABC", 3);
    return 0;
}