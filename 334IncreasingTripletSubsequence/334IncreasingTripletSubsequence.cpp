/***********************************************
#
#      Filename: 334IncreasingTripletSubsequence.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 22:25:21
# Last Modified: 2018-11-17 22:25:21
#          Link: https://leetcode.com/problems/increasing-triplet-subsequence/
#   Description: ---
//  Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//  
//  Formally the function should:
//  
//  Return true if there exists i, j, k
//  such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//  Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
//  
//  Example 1:
//  
//  Input: [1,2,3,4,5]
//  Output: true
//  Example 2:
//  
//  Input: [5,4,3,2,1]
//  Output: false`
***********************************************/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// O(n^2) learned from <bianchengzhimei>
//class Solution {
//public:
//    bool increasingTriplet(vector<int>& nums) {
//      vector<int> a(nums.size(),1);
//      for(int i= 1 ;i<nums.size();i++){
//          for(int j=0;j<i;j++){
//            if(nums[i] > nums[j] && a[i] < a[j] + 1){
//                a[i] = a[j] +1;
//                if(a[i] >= 3){return true;}
//            }
//          }
//      }
//      return false;
//    }
//};

// so clever!
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int s1 = INT_MAX, s2 = INT_MAX;
      for (int curr : nums) {
        if (curr <= s1) s1 = curr;
        else if (curr <= s2) s2 = curr;
        else return true;
      }
      return false;
    }
};

int main(){
    Solution ss;
    //vector<int> test{1,2,3,4,5};
    vector<int> test{5,1,5,5,2,5,4};
    cout<<ss.increasingTriplet(test)<<endl;

}
