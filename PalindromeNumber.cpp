#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;

    string str = to_string(x);
    int strSize = str.size();

    for (int i = 0; i <= strSize / 2; ++i) {
        if (str[i] != str[strSize - 1 - i]) return false;
    }

    return true;
}

bool isPalindrome2(int x) {
    if (x < 0) return false;

    long reversed = 0, localNum = x;

    while (localNum) {
        reversed = 10 * reversed + localNum % 10;
        localNum = localNum / 10;
    }

    return (reversed == x);
}

int main() {
    /*
    Given an integer x, return true if x is palindrome integer.
    An integer is a palindrome when it reads the same backward as forward. For
    example, 121 is palindrome while 123 is not.

    Example 1:
        Input: x = 121
        Output: true

    Example 2:
        Input: x = -121
        Output: false
        Explanation: From left to right, it reads -121. From right to left, it
    becomes 121-. Therefore it is not a palindrome.

    Example 3:
        Input: x = 10
        Output: false
        Explanation: Reads 01 from right to left. Therefore it is not a
    palindrome.

    Example 4:
        Input: x = -101
        Output: false


    Constraints:
        -231 <= x <= 231 - 1
    */

    isPalindrome(1221);
    isPalindrome2(1221); // don't using string !

    return 0;
}