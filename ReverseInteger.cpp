#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
    int res = 0;

    while (x) {
        if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = res * 10 + x % 10;
        x = x / 10;
    }
    return res;
}

int main() {
    /*
    Given a signed 32-bit integer x, return x with its digits reversed. 
    If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    Example 1:
        Input: x = 123
        Output: 321
    
    Example 2:
        Input: x = -123
        Output: -321
    
    Example 3:
        Input: x = 120
        Output: 21
    
    Example 4:
        Input: x = 0
        Output: 0
    
    Constraints:
        -231 <= x <= 231 - 1

    */

    cout << reverse(-123);
    return 0;
}