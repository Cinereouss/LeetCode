#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    long long res = 0, mark = 1;
    bool markBool = true, hadNum = false;
    int strLength = s.length();

    for (int i = 0; i < strLength; ++i) {
        if (s[i] == '-' && markBool && hadNum == false) {
            mark = -1;
            markBool = false;
            continue;
        }

        if (s[i] == '+' && markBool && hadNum == false) {
            mark = +1;
            markBool = false;
            continue;
        }

        if (s[i] == ' ' && hadNum == false && markBool == true) continue;

        if (s[i] < '0' || s[i] > '9' && hadNum == false) break;

        if (s[i] >= '0' && s[i] <= '9') {
            hadNum = true;
            res = res * 10 + (int)s[i] - 48;
            if (res >= 2147483648) {
                if (mark == 1) {
                    return 2147483647;
                } else {
                    return -2147483648;
                }
            }
        } else if (hadNum) {
            break;
        }
    }

    return mark * res;
}

int main() {
    cout << myAtoi("-91283472332");
    return 0;
}