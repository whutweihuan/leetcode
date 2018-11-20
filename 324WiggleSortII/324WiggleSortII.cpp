/***********************************************
#
#      Filename: 324WiggleSortII.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-20 15:04:03
# Last Modified: 2018-11-20 15:04:03
#          Link: https://leetcode.com/problems/wiggle-sort-ii/
#   Description: ---
#    Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
#    
#    Example 1:
#    
#    Input: nums = [1, 5, 1, 1, 6, 4]
#    Output: One possible answer is [1, 4, 1, 5, 1, 6].
#    Example 2:
#    
#    Input: nums = [1, 3, 2, 2, 3, 1]
#    Output: One possible answer is [2, 3, 1, 3, 1, 2].
***********************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // if erase ,the index will change.
    // also we need consider the odd and even.
    // and we choose the n.size()-1  mod 2  or n.size() mod 2 ?
    // consider how many number we need to change.
    void wiggleSort(vector<int>& nums) {
       int midIdx = nums.size()/2;
       //do you know why we need sort by decent ? 
       sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
       // think why here is '< midInx' ?
       for(int i = 0;i < midIdx;i++){
            int val = nums[midIdx + i];
            // we need to erase first ,once intsert the index will change
            nums.erase(nums.begin() + midIdx + i);
            nums.insert(nums.begin() + i*2 ,val);
       } 
    }

};

int main(){
    Solution ss;
    //vector<int >test {1, 5, 1, 1, 6, 4};
    vector<int >test {1,3,2,2,3,1};


    ss.wiggleSort(test);
    for(auto each : test){
        cout<<each<<"\t";
    }
}
















