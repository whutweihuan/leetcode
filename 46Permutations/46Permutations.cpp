/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-25 
# Last Modified: 2019-1-25
#          Link: https://leetcode.com/problems/permutations/
#         title: 46	Permutations
#   Description: ---
#	  
#	  Given a collection of distinct integers, return all possible permutations.
#	  
#	  Example:
#	  
#	  Input: [1,2,3]
#	  Output:
#	  [
#	    [1,2,3],
#	    [1,3,2],
#	    [2,1,3],
#	    [2,3,1],
#	    [3,1,2],
#	    [3,2,1]
#	  ]

***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 0ms
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         sort(nums.begin(),nums.end());
//         res.push_back(nums);
//         int i = 0;
//         while(!is_sorted(nums.begin(),nums.end(),std::greater<int>())){
//         	i++;
//         	nextPermutation(nums);
//         	res.push_back(nums);
//         }
//         cout << "i\t" <<i <<endl;
//         return res;

//     }

//      void nextPermutation(vector<int>& nums) {
//          if(nums.size()<=1) {return;}
//          if(is_sorted(nums.begin(),nums.end(),std::greater<int>())){
//             reverse(nums.begin(),nums.end()); 
//          }
//          else{
//              rec(nums,1);
//          }
//      }
 
//      bool rec(vector<int>& nums,int start){
//          if(is_sorted(nums.begin()+start,nums.end(),std::greater<int>())){
//              sort(nums.begin()+start,nums.end());
//              //binary search is faster than o(n)
//              int index = upper_bound(nums.begin()+start,nums.end(),nums[start-1]) - nums.begin();
//              swap(nums[start-1],nums[index]);
//              return true;
//           }
//          else rec(nums,start+1);
//          return false;
//       }
// };

/*
 *    The algroithm - Take each element in array to the first place.
 *
 *    For example: 
 *    
 *         0) initalization 
 * 
 *             pos = 0
 *             [1, 2, 3]   
 *
 *         1) take each element into the first place, 
 *
 *             pos = 1
 *             [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2] 
 *
 *             then we have total 3 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2] 
 *            
 *         2) take each element into the "first place" -- pos 
 *
 *             pos = 2
 *             [1, 2, 3]  ==>  [1, 3, 2]
 *             [2, 1, 3]  ==>  [2, 3, 1]
 *             [3, 1, 2]  ==>  [3, 2, 1] 
 *
 *             then we have total 6 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
 *
 *          3) pos = 3 which greater than length of array, return.
 *
 */
// vector<vector<int> > permute(vector<int> &num) {
    
//     vector<vector<int> > vv;
//     vv.push_back(num);

//     if (num.size() <2){
//         return vv;
//     }
        
//     int pos=0;
//     while(pos<num.size()-1){
//         int size = vv.size();
//         for(int i=0; i<size; i++){
//             //take each number to the first place
//             for (int j=pos+1; j<vv[i].size(); j++) {
//                 vector<int> v = vv[i];
//                 int t = v[j]; 
//                 v[j] = v[pos];
//                 v[pos] = t;
//                 vv.push_back(v);
//             }
//         }
//         pos++;
//     }
//     return vv;
// }

// 8ms
//经典回溯
class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmpVec){
        if (tmpVec.size()==nums.size()){
            ans.push_back(tmpVec);
            return;
        }
        for(auto n: nums){
            if (find(tmpVec.begin(), tmpVec.end(), n)==tmpVec.end()){
                tmpVec.push_back(n);
                backtrack(nums, ans, tmpVec);
                tmpVec.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(nums, ans, tmp);
        return ans;
    }
};

int main(){
	vector <int> nums {1,2,3};
	Solution ss;
	vector<vector<int>> res = ss.permute(nums);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<"\t";
		}
		cout<<endl;
	}
}


