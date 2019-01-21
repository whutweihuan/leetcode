/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-24 
# Last Modified: 2018-12-24 
#          Link: https://leetcode.com/problems/combination-sum-ii/
#         title: 40CombinationSumII
#   Description: ---
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
	set<vector<int>> res;
    int cnt =0;
public:
    vector<vector<int>> combinationSum2n(vector<int>& candidates, int target) {
    	vector<int> aleadySel;
    	sort(candidates.begin(),candidates.end());
    	dfs(candidates,target,aleadySel,0);
        // printf("The count of all plan is %d\n", cnt);

        vector<vector<int>> res2(res.begin(),res.end());
        return res2;
    }

    bool dfs(vector<int> & candidates,int target,vector<int> & aleadySel,int i){
    	if(target < 0) {return false;}
    	if(target == 0 ) { res.insert(aleadySel); cnt++; return true; }
    	if(i>= candidates.size()) {return false;}

    	aleadySel.push_back(candidates[i]);
    	dfs(candidates,target-candidates[i],aleadySel,i+1);

    	aleadySel.pop_back();
    	dfs(candidates,target,aleadySel,i+1);
    	return false;
    }
};

int main(){
	// vector<int> candidates{10,1,2,7,6,5,1};
	vector<int> candidates{2,5,2,1,2};
	int target = 5;
	Solution ss;
	vector<vector<int>> result = ss.combinationSum(candidates,target);
	for(vector<int> com:result){
		for(int n:com){
			cout<<n<<"\t";
		}
		cout<<endl;
	}
}