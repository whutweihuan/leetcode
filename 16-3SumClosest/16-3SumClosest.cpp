/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-28 
# Last Modified: 2018-11-28 
#          Link: https://leetcode.com/problems/3sum-closest/
#         title: 3 sum closest
#   Description: ---
#     Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
#     
#     Example:
#     
#     Given array nums = [-1, 2, 1, -4], and target = 1.
#     
#     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
     int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int maxdiff = INT_MAX;
        int res = 0;
        int len = nums.size();

        for(int i=0;i<len-2;i++){
            int start = i+1;
            int end = len-1;
         
            while(start<end){
                 int threeSum = nums[i] + nums[start] + nums[end];
                 int tempdiff = threeSum - target; 
                if(tempdiff == 0){
                    return threeSum;
                }
                else if(abs(tempdiff) < maxdiff){
                    maxdiff = abs(tempdiff);
                    res = threeSum;               
                }
                if(threeSum > target){
                    end--;
                }
                else if(threeSum < target){
                    start++;
                }
            }
        }
        return res;
    }
};

int main(){
   // vector<int> nums{0,2,1,-3};
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    Solution ss;
    cout<<ss.threeSumClosest(nums,target)<<endl;

}