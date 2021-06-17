#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    int res = 0, mark = 1;
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
            if (res > (INT_MAX-(s[i]-'0'))/10) {
                if (mark == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            res = res * 10 + (int)s[i] - 48;
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