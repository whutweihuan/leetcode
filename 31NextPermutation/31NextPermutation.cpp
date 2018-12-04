/***********************************************
#
#      Filename: 31NextPermutation.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-04 17:39:43
# Last Modified: 2018-12-04 17:39:43
#          Link: https://leetcode.com/problems/next-permutation/
#   Description: ---
#     Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
#     
#     If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
#     
#     The replacement must be in-place and use only constant extra memory.
#     
#     Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
#     
#     1,2,3 → 1,3,2
#     3,2,1 → 1,2,3
#     1,1,5 → 1,5,1
***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

 class Solution {
 public:
     void nextPermutation(vector<int>& nums) {
         if(nums.size()<=1) {return;}
         if(is_sorted(nums.begin(),nums.end(),std::greater<int>())){
            reverse(nums.begin(),nums.end()); 
         }
         else{
             rec(nums,1);
         }
     }
 
     bool rec(vector<int>& nums,int start){
         if(is_sorted(nums.begin()+start,nums.end(),std::greater<int>())){
             sort(nums.begin()+start,nums.end());
             //binary search is faster than o(n)
             int index = upper_bound(nums.begin()+start,nums.end(),nums[start-1]) - nums.begin();
             swap(nums[start-1],nums[index]);
             return true;
          }
         else rec(nums,start+1);
         return false;
      }
         
 };

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int i = n - 1;
//         for (; i >= 1; i--) {
//             if (nums[i] > nums[i - 1])
//                 break;
//         }
//         if (i == 0) {
//             reverse(nums.begin(), nums.end());
//         }
//         else {
//             int smallest_index = i;
//             for(;smallest_index < n; smallest_index ++) {
//                 if (nums[smallest_index] <= nums[i - 1]) {
//                     break;
//                 }
//             }
//             smallest_index --;
//             swap(nums[smallest_index], nums[i - 1]);
//             reverse(nums.begin() + i, nums.end());
//         }
//     }
// };

int main(){
   vector<int> nums {1,3,2};
   //vector<int> nums {3,2,1};
   Solution ss;
   ss.nextPermutation(nums);
   for(int n:nums){
        cout<<n<<"\t";
   }
//    if(std::is_sorted(nums.begin(),nums.end(),std::greater<int>())){
//         cout<<"It is sorted!"<<endl;
//    }
//    else{
//         cout<<"It is not sorted!"<<endl;
//    }

}















