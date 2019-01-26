/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-25 
# Last Modified: 2019-1-25
#          Link: https://leetcode.com/problems/jump-game-ii/
#         title: 45	Jump Game II
#   Description: ---
#	Given an array of non-negative integers, you are initially positioned at the first index of the array.
#
#	Each element in the array represents your maximum jump length at that position.
#	
#	Your goal is to reach the last index in the minimum number of jumps.
#	
#	Example:
#	
#	Input: [2,3,1,1,4]
#	Output: 2
#	Explanation: The minimum number of jumps to reach the last index is 2.
#	    Jump 1 step from index 0 to 1, then 3 steps to the last index.


***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 568 ms
// class Solution {
// private:
// 	vector<int> dp;
// public:
//     int jump(vector<int>& nums) {
//     	for(int i=0;i<nums.size();i++){
//     		dp.push_back(-1);
//     	}
//     	int res = 0;
//         return dfs(nums,0);
//     }

//     int dfs(vector<int> & nums,int index){
//     	if (dp[index] != -1){return dp[index];}
//     	if (index >= nums.size()-1 ){ return 0;}
//     	int min_val = 1<<30;
//     	for(int i= nums[index] ;i>0;i--){
//     		if(i + index < nums.size()){
//     			min_val = std::min(dfs(nums,index+i)+1,min_val);
//     		}
//     	}
//     	return dp[index] = min_val;
//     }
// };


// 8 ms
class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0, maxReach=0, res=0;
        for(int i=0; i<nums.size(); ++i) {   
            if(reach<i) {
                reach=maxReach;
                ++res;
            }
            maxReach=max(maxReach, i+nums[i]);
        }
        return res;
    }
};

int main(){
	Solution ss;
	vector <int> nums {2,3,1,1,4};
	// vector <int> nums {1,4};
	cout << ss.jump(nums) <<endl;
}


	