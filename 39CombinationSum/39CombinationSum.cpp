/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-11 
# Last Modified: 2018-12-11 
#          Link: https://leetcode.com/problems/combination-sum/
#         title: 39	Combination Sum
#   Description: ---
#	  Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
#	  
#	  The same repeated number may be chosen from candidates unlimited number of times.
#	  
#	  Note:
#	  
#	  All numbers (including target) will be positive integers.
#	  The solution set must not contain duplicate combinations.
#	  Example 1:
#	  
#	  Input: candidates = [2,3,6,7], target = 7,
#	  A solution set is:
#	  [
#	    [7],
#	    [2,2,3]
#	  ]
#	  Example 2:
#	  
#	  Input: candidates = [2,3,5], target = 8,
#	  A solution set is:
#	  [
#	    [2,2,2,2],
#	    [2,3,3],
#	    [3,5]
#      ]
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int> subresult;
//         helper(result, 0, target, candidates, subresult);
        
//         return result;
//     }
    
//     // start is used to make sure always go right, not go back and repeatedly use the current one
//     // if it is i + 1, then no repeat
//     void helper(vector<vector<int>>& result, int start, int target, vector<int>& candidates, vector<int>& subresult) {
        
//         if (target <= 0) {
//             if (target == 0) {
//                 result.push_back(subresult);
//             }
//             return;
//         }
        
//         for(int i = start; i < candidates.size(); i++) {
//             subresult.push_back(candidates[i]);
//             helper(result, i, target - candidates[i], candidates, subresult);
//             subresult.pop_back();
//         }
//     }
// };


class Solution {
private:
	vector<vector<int>> res;
    int cnt =0;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<int> aleadySel;
    	dfs(candidates,target,aleadySel,0);
        printf("The count of all plan is %d\n", cnt);
        return res;
    }

    bool dfs(vector<int> & candidates,int target,vector<int> & aleadySel,int i){
    	if(target < 0) {return false;}
    	if(target == 0 ) { res.push_back(aleadySel); cnt++; return true; }
    	if(i>= candidates.size()) {return false;}

    	aleadySel.push_back(candidates[i]);
    	dfs(candidates,target-candidates[i],aleadySel,i);

    	aleadySel.pop_back();
    	dfs(candidates,target,aleadySel,i+1);
    	return false;
    }
};

int main(){
	vector<int> candidates{6,5,4,3,9};
	int target = 20;
	Solution ss;
	vector<vector<int>> result = ss.combinationSum(candidates,target);
	for(vector<int> com:result){
		for(int n:com){
			cout<<n<<"\t";
		}
		cout<<endl;
	}
}
