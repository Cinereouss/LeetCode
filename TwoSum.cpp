#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        if (m.find(target - nums[i]) != m.end()) {
            res.push_back(m.find(target - nums[i])->second);
            res.push_back(i);
            return res;
        } else {
            m[nums[i]] = i;
        }
    }
    return res;
}

int main() {
    /*
        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Output: Because nums[0] + nums[1] == 9, we return [0, 1].
    */

    vector<int> inp = {2, 7, 11, 5};
    int target = 9;

    twoSum(inp, target);

    return 0;
}