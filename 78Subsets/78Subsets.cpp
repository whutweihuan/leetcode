/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/subsets/
#         title: 78	Subsets
#   Description: ---
#	  Given a set of distinct integers, nums, return all possible subsets (the power set).
#	  
#	  Note: The solution set must not contain duplicate subsets.
#	  
#	  Example:
#	  
#	  Input: nums = [1,2,3]
#	  Output:
#	  [
#	    [3],
#	    [1],
#	    [2],
#	    [1,2,3],
#	    [1,3],
#	    [2,3],
#	    [1,2],
#	    []
#	  ]
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(res,ans,0,nums);
        return res;
    }

    void dfs(vector<vector<int>>&res,vector<int> ans ,int start,const vector<int>& nums){
    	if(start >= nums.size()) {
    		res.push_back(ans);
    		return ;
    	}
    	dfs(res,ans,start+1,nums);
    	ans.push_back(nums[start]);
    	dfs(res,ans,start+1,nums);
    }
};

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> set;
//         vector<int> subset;
//         int start = 0;
//         backtrack(nums,start,set,subset);
        
//         return set;
//     }
//     void backtrack(vector<int>& nums,int start,vector<vector<int>>& set,vector<int>& subset){
//         set.push_back(subset);
//         for(int i = start;i< nums.size();i++){
//             subset.push_back(nums[i]);    
//             backtrack(nums,i+1,set,subset);       
//             subset.pop_back();        
//         }
//     } 
// };

int main(){
	Solution ss;
	vector<int> nums{1,2,3};
	vector<vector<int>> res = ss.subsets(nums);
	printVector2D(res);
}