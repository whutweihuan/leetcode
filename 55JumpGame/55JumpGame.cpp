/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://oj.leetcode.com/problems/jump-game/
#         title: 55	Jump Game
#   Description: ---
#	  
#	  Given an array of non-negative integers, you are initially positioned at the first index of the array.
#	  
#	  Each element in the array represents your maximum jump length at that position.
#	  
#	  Determine if you are able to reach the last index.
#	  
#	  Example 1:
#	  
#	  Input: [2,3,1,1,4]
#	  Output: true
#	  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
#	  Example 2:
#	  
#	  Input: [3,2,1,0,4]
#	  Output: false
#	  Explanation: You will always arrive at index 3 no matter what. Its maximum
#	               jump length is 0, which makes it impossible to reach the last index.
#	  
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxPos = 0;
//         for(int i=0;i<nums.size();i++){
//         	maxPos = std::max(maxPos,nums[i]+i);
//         	if(nums[maxPos] == 0 && i>=maxPos && i !=nums.size()-1){
//         		return false;
//         	}
//         }
//         return maxPos >= nums.size() -1;
//     }
// };

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         vector<int> dp(nums.size(), 0);
//         dp[0]=nums[0];
//         for(int i=1;i<nums.size();i++){
//             dp[i]=max(dp[i - 1], nums[i - 1]) - 1;
//             if(dp[i]<0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for(int i=0;i<nums.size();i++){
        	maxPos = std::max(maxPos,nums[i]+i);
        	if(maxPos >= nums.size()-1){
        		return true;
        	}
        }
        return false;
    }
};

int main(){
	Solution ss;
	// vector<int> nums{0,2,3};
	// vector<int> nums{3,2,1,0,4};
	// vector<int> nums{2,3,1,1,4};
	vector<int> nums{2,0,0};
	cout << ss.canJump(nums)<<endl;
}