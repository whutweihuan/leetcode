/***********************************************
#
#      Filename: 1TwoSum.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 15:22:12
# Last Modified: 2018-11-22 15:22:12
#          Link: https://leetcode.com/problems/two-sum/
#   Description: ---
#     Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#     
#     You may assume that each input would have exactly one solution, and you may not use the same element twice.
#     
#     Example:
#     
#     Given nums = [2, 7, 11, 15], target = 9,
#     
#     Because nums[0] + nums[1] = 2 + 7 = 9,
#     return [0, 1].
***********************************************/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

// It is so silly and it time is O(n^2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res;
//         for(int i=0;i<(int)nums.size();i++){
//             for(int j=i+1;j<(int)nums.size();j++){
//                 if(nums[i] + nums[j] == target){
//                     res.push_back(i);
//                     res.push_back(j);
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int ,int> m;
        for(int i=0;i<(int)nums.size();i++){
            if(m.find(target - nums[i]) != m.end()){
                return vector<int>{ i,m[target-nums[i]]};
            }
            m[nums[i] ] = i;
        }
    }
};
int main(){
    Solution ss;
    vector<int> nums{2,2};
    //vector<int> nums{2,7,11,15};
    int target = 4;
    for( auto n : ss.twoSum(nums,target)){
        cout<<n<<"\t";
    }
}















