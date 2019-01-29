/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://leetcode.com/problems/maximum-subarray/
#         title: 53	Maximum Subarray
#   Description: ---
#     Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
#     
#     Example:
#     
#     Input: [-2,1,-3,4,-1,2,1,-5,4],
#     Output: 6
#     Explanation: [4,-1,2,1] has the largest sum = 6.
#     Follow up:
#     
#     If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
#     
#     Accepted

***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){
        	sum = std::max(nums[i],sum+nums[i]);
        	max = std::max(max,sum);
        }
        return max;
    }
};

int main(){
	Solution ss;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

	cout << ss.maxSubArray(nums) <<endl;
}