/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-26 
# Last Modified: 2019-1-26
#          Link: https://leetcode.com/problems/permutations-ii/
#         title: 47	Permutations II
#   Description: ---
#     Given a collection of numbers that might contain duplicates, return all possible unique permutations.
#     
#     Example:
#     
#     Input: [1,1,2]
#     Output:
#     [
#       [1,1,2],
#       [1,2,1],
#       [2,1,1]
#     ]
***********************************************/
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

// 92 ms
// Now we need consider the same number ,we can store the index the identify the same number
// and we can use set to emmurate the duplicate anwser.
// class Solution {
// private:
// 	void backtrack(vector<int> &nums,set<vector<int>> & result ,vector<int> temp,vector<int> &pos){
// 		if(temp.size() == nums.size()){ 
// 			result.insert(temp);
// 			return;
// 		}
// 		for(int i=0;i<nums.size();i++){
// 			if(find(pos.begin(),pos.end(),i) == pos.end()){
// 				pos.push_back(i);
// 				temp.push_back(nums[i]);
// 				backtrack(nums,result,temp,pos);
// 				temp.pop_back();
// 				pos.pop_back();
// 			}
// 		}

// 	}

// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         set<vector<int>> res;
//         vector <int> temp;
//         vector <int> pos;
//         backtrack(nums,res,temp,pos);
//         return vector<vector<int>>(res.begin(),res.end());
//     }
// };


// 16 ms
// At first we can get anwser by swap two number and use the index
// when there is duplicate number in an array, we can use a set to skip the number
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        dfs(nums, res, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> uset;
        for (int i = index; i < nums.size(); ++i) {
            if (uset.find(nums[i]) == uset.end()) {
                uset.insert(nums[i]);
                swap(nums[i], nums[index]);
                dfs(nums, res, index + 1);
                swap(nums[i], nums[index]);
            }
        }
    }
};


int main(){
	vector <int> nums {1,2,3};
	Solution ss;
	vector<vector<int>> res = ss.permuteUnique(nums);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<"\t";
		}
		cout<<endl;
	}
}