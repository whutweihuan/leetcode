/***********************************************
#
#      Filename: 349IntersectionofTwoArrays.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 00:27:37
# Last Modified: 2018-11-17 00:27:37
#         Link : https://leetcode.com/problems/intersection-of-two-arrays/ 
#   Description: ---
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
***********************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res;
        
        vector <int>& shortnums = nums1.size()>nums2.size()?nums2:nums1;
        vector <int> & longnums  = nums1.size()>nums2.size()?nums1:nums2;
        for(size_t i=0;i<shortnums.size() ;i++){
        auto iter = find(longnums.begin(),longnums.end(),shortnums[i]); 
            if(iter != longnums.end() && find(res.begin(),res.end(),shortnums[i]) == res.end()){
                res.push_back(shortnums[i]);
                longnums.erase(iter);
            }
            
        }
       return res;
    }
};

int main(){
    Solution ss;
    vector<int> a{1,2,3,4};
    vector<int> b{2,2,3,3};
    for(auto each: ss.intersection(a,b)){
        cout<<each<<"\t";
    }

}
