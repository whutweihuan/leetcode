/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-31 
# Last Modified: 2019-1-31
#          Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#         title: 81	Search in Rotated Sorted Array II
#   Description: ---
#	  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#	  
#	  (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
#	  
#	  You are given a target value to search. If found in the array return true, otherwise return false.
#	  
#	  Example 1:
#	  
#	  Input: nums = [2,5,6,0,0,1,2], target = 0
#	  Output: true
#	  Example 2:
#	  
#	  Input: nums = [2,5,6,0,0,1,2], target = 3
#	  Output: false
#	  Follow up:
#	  
#	  This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
#	  Would this affect the run-time complexity? How and why?
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// 调用两次二分查找
// class Solution {
// 	bool binSearch(vector<int>& nums, int target,int start,int end){
// 		while(start <= end){
// 			int mid = start + (end-start)/2;
// 			if(target > nums[mid]){
// 				start = mid+1;
// 			}else if(target < nums[mid]){
// 				end = mid -1;
// 			}else{
// 				return true;
// 			}
// 		}
// 		return false;
// 	}

// public:
//     bool search(vector<int>& nums, int target) {
//     	if(nums.empty()) {return false;}
//         int firstEnd = 0;
//         for(int i=0;i<nums.size()-1;i++){
//         	if(nums[i] > nums[i+1]){
//         		firstEnd = i;break;
//         	}
//         }
//         return binSearch(nums,target,0,firstEnd) || 
//         	   binSearch(nums,target,firstEnd+1,nums.size()-1);
//     }
// };

// 
//                /
//               /
//				/
//       	   		  /
//	  				 /			  
//					/
//
// 一定在这两条递增的曲线上分类讨论一些就可以了

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        
        while(left<=right)
        {
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;

            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

            else if(nums[left] <= nums[mid])
            {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else
            {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};

int main(){
	Solution ss;
	vector<int> nums{2,5,6,0,0,1,2};
	int target = 3;
	cout << ss.search(nums,target) <<endl;
}