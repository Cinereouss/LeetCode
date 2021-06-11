#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size())
        return findMedianSortedArrays(nums2,nums1);

    int x = nums1.size();
    int y = nums2.size();
    int high = x;
    int low = 0;

    while(low<=high){
        int divideX = low + (high - low)/2;
        int divideY = (x + y + 1)/2 - divideX;
        
        double maxLeftX = (divideX == 0 ? INT_MIN : nums1[divideX-1]);
        double minRightX = (divideX == x ? INT_MAX : nums1[divideX]);
        
        double maxLeftY = (divideY == 0 ? INT_MIN : nums2[divideY-1]);
        double minRightY = (divideY == y ? INT_MAX : nums2[divideY]);
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX){
            return (x + y) % 2 == 0 ? (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0 :  max(maxLeftX, maxLeftY);
        }else if(maxLeftX>minRightY){
            high = divideX-1;
        }else{
            low = divideX +1;
        }
    }

    return 0;
}

int main(){
    /*
        Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
        The overall run time complexity should be O(log (m+n)).

        Example 1:
            Input: nums1 = [1,3], nums2 = [2]
            Output: 2.00000
            Explanation: merged array = [1,2,3] and median is 2.
        
        Example 2:
            Input: nums1 = [1,2], nums2 = [3,4]
            Output: 2.50000
            Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
        
        Example 3:
            Input: nums1 = [0,0], nums2 = [0,0]
            Output: 0.00000
      
        Example 4:
            Input: nums1 = [], nums2 = [1]
            Output: 1.00000
        
        Example 5:
            Input: nums1 = [2], nums2 = []
            Output: 2.00000
        
        Constraints:
            nums1.length == m
            nums2.length == n
            0 <= m <= 1000
            0 <= n <= 1000
            1 <= m + n <= 2000
            -106 <= nums1[i], nums2[i] <= 106
    */

    vector <int> nums1 = {1,2};
    vector <int> nums2 = {1,2,3};

    cout << findMedianSortedArrays(nums1, nums2);
    
    return 0;
}