/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/4sum/
#         title: 18. 4Sum
#   Description: ---
#	  Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
#	  
#	  Note:
#	  
#	  The solution set must not contain duplicate quadruplets.
#	  
#	  Example:
#	  
#	  Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
#	  
#	  A solution set is:
#	  [
#	    [-1,  0, 0, 1],
#	    [-2, -1, 1, 2],
#	    [-2,  0, 0, 2]
#	  ]

***********************************************/
#include <vector>
#include<iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int len = nums.size();
  
        for(int i=0;i<len-3;i++){
        	for(int j=i+1;j<len-2;j++){
            	int start = j+1;
            	int end = len-1;
            	int a = nums[i];
            	int d = nums[j];
            	while(start<end){
            	     int b = nums[start];
            	     int c = nums[end];
            	    if(a+b+c +d== target){
            	        result.push_back(vector<int>{a,d,b,c});
            	        end--;
            	    }
            	    else if(a+b+c+d> target){
            	        end--;
            	    }
            	    else{
            	        start++;
            	    }
            	}
            }
        }
        set<vector<int> > cleardup(result.begin(),result.end());
        result.assign(cleardup.begin(),cleardup.end());

        return result;
    }
};

int main(){
	Solution ss;
	vector<int> nums {0,0,0,0};
	// vector<int> nums {1, 0, -1, 0, -2, 2};
	int target = 0;
	for(auto num:ss.fourSum(nums,target)){
		for(auto n:num){
			cout<<n<<"\t";
		}
		cout<<endl;
	}
}