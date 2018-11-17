/***********************************************
#
#      Filename: 350IntersectionofTwoArraysII.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-16 23:46:29
# Last Modified: 2018-11-16 23:46:29
#         Link : 2018-11-16 23:46:29
#   Description: ---
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
***********************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res;
        vector <int>& shortnums = nums1.size()>nums2.size()?nums2:nums1;
        vector <int> & longnums  = nums1.size()>nums2.size()?nums1:nums2;
        for(size_t i=0;i<shortnums.size() ;i++){
        auto iter = find(longnums.begin(),longnums.end(),shortnums[i]); 
            if(iter != longnums.end()){
                res.push_back(shortnums[i]);
                longnums.erase(iter);
            }
            
        }
       return res;
    }
};

int main(){
    Solution ss;
    vector<int> a {1,2,2,1};
    vector<int> b {2,2};

    for(auto each:ss.intersect(a,b)){
        cout<<each<<"\t";
    }
}














