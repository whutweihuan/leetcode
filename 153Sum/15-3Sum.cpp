/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-28
# Last Modified: 2018-11-28 
#          Link: https://leetcode.com/problems/3sum/
#         title: 3sum
#   Description: ---
#     Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
#     
#     Note:
#     
#     The solution set must not contain duplicate triplets.
#     
#     Example:
#     
#     Given array nums = [-1, 0, 1, 2, -1, -4],
#     
#     A solution set is:
#     [
#       [-1, 0, 1],
#       [-1, -1, 2]
#     ]
#     
***********************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         // auto iter = unique(nums.begin(),nums.end());
//         set<vector<int>> res ;
//         // set<int> used;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 for(int k= j+1;k<nums.size();k++){
//                     if(nums[i]+nums[j]+nums[k] == 0){
//                         res.insert(vector<int>{nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> res2; 
//         for(auto iter =res.begin();iter!=res.end();iter++){
//           res2.push_back(*iter);
//         }
//         return res2;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //Use set to remove the duplicate
        set<vector<int> > result;

        int len = nums.size();
  
        for(int i=0;i<len-2;i++){
            int start = i+1;
            int end = len-1;
            int a = nums[i];
            while(start<end){
                 int b = nums[start];
                 int c = nums[end];
                if(a+b+c == 0){
                    result.insert(vector<int>{a,b,c});
                    end--;
                }
                else if(a+b+c>0){
                    end--;
                }
                else{
                    start++;
                }
            }
        }

        vector<vector<int> > res;
        res.assign(result.begin(),result.end());

        return res;
    }
};

int main(){
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution ss;
    for(auto num :ss.threeSum(nums)){
        for(auto c:num){
            cout<<c<<"\t";
        }
        cout<<endl;
    }
}















