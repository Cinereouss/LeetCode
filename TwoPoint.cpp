#include <iostream>
#include <vector>

using namespace std;

int slove(vector<int> &nums, int maxSum) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        int temp = 0;
        int j;
        for (j = i; j < nums.size(); j++) {
            temp += nums[j];
            if (temp >= maxSum) break;
        }
        res += nums.size() - j;
    }
    return res;
}

int slove2(vector<int> &nums, int maxSum) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        int temp = 0;
        int j;
        for (j = i; j < nums.size(); j++) {
            temp += nums[j];
            if (temp >= maxSum) break;
        }
        res += nums.size() - j;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 5, 4, 2};
    cout << slove(nums, 8) << endl;

    return 0;
}