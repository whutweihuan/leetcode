/***********************************************
#
#      Filename: 4MedianofTwoSortedArrays.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 17:44:54
# Last Modified: 2018-11-22 17:44:54
#          Link: https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
#   Description: ---
#     There are two sorted arrays nums1 and nums2 of size m and n respectively.
#     
#     Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#     
#     You may assume nums1 and nums2 cannot be both empty.
#     
#     Example 1:
#     
#     nums1 = [1, 3]
#     nums2 = [2]
#     
#     The median is 2.0
#     Example 2:
#     
#     nums1 = [1, 2]
#     nums2 = [3, 4]
#     
#     The median is (2 + 3)/2 = 2.5
#     
***********************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> dv;
        for(int i=0;i<(int)nums1.size();i++){dv.push_back(nums1[i]);}
        for(int i=0;i<(int)nums2.size();i++){dv.push_back(nums2[i]);}
        sort(dv.begin(),dv.end());
        if((dv.size() & 1) != 0){
            return dv[ int(dv.size()/2) ];
        } 
        int mid = dv.size()/2;
        return (dv[mid-1]+dv[mid])/2.0;
    }
};

int main(){
    Solution ss;
    vector<int>nums1{1,2};
    vector<int>nums2{3,4};

    cout<<ss.findMedianSortedArrays(nums1,nums2);
}













