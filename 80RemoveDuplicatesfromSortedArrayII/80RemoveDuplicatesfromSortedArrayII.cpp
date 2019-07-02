/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-31 
# Last Modified: 2019-1-31
#          Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
#         title: 80	Remove Duplicates from Sorted Array II
#   Description: ---
#	   Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
#	   
#	   Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
#	   
#	   Example 1:
#	   
#	   Given nums = [1,1,1,2,2,3],
#	   
#	   Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
#	   
#	   It doesn't matter what you leave beyond the returned length.
#	   Example 2:
#	   
#	   Given nums = [0,0,1,1,1,1,2,3,3],
#	   
#	   Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
#	   
#	   It doesn't matter what values are set beyond the returned length.
#	   Clarification:
#	   
#	   Confused why the returned value is an integer but your answer is an array?
#	   
#	   Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
#	   
#	   Internally you can think of this:
#	   
#	   // nums is passed in by reference. (i.e., without making a copy)
#	   int len = removeDuplicates(nums);
#	   
#	   // any modification to nums in your function would be known by the caller.
#	   // using the length returned by your function, it prints the first len elements.
#	   for (int i = 0; i < len; i++) {
#	       print(nums[i]);
#	   }
***********************************************/
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//     	if(nums.empty()){return 0;}
//     	int len = 1;
//     	int cnt = 1; //cnt == 1 equals there is single  number
//     	int pre = nums[0];
//     	for(int i=1;i<nums.size();i++){
//     		// cout << cnt <<endl;
//     		if(nums[i] == pre ){
//     			if(cnt +1 < 3){
//     			  	 len++;cnt++;
//     			 }
//     			 else{
//     			 	nums.erase(nums.begin()+i);
//     			 	i--;
//     			 }	 
//     		}else{
//     			pre = nums[i];
//     			cnt = 1;
//     			len++;
//     		} 		
//     	}
//         return len;
//     }
// };

// It is a good solution
class Solution {
public:
    // maintain the first part (return part) to be correct
    // we can compare nums[i] to nums[i-2] to see if they are the same
    // if nums[i] == nums[i - 2 - counter], we make it the swap point
    // [0,0,1,1,1,3,3,3]
    // i = 2, nums[i] != nums[i - 2 - 0], continue
    // i = 3, nums[i] != nums[i - 2 - 0], continue
    // i = 4, nums[i] == nums[i - 2 - 0], counter++
    // i = 5, nums[i] != nums[i - 2 - 1], nums[i - 1] = nums[i]
    //    get [0,0,1,1,3,1,3,3]
    // i = 6, nums[i] != nums[i - 2 - 1]
    //    get [0,0,1,1,3,3,1,3]
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() < 2) return nums.size();
      int n = nums.size(), count = 0;
      for (int i = 2; i < n; i++) {
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
      }
      return n - count;
    }
};

// pretty good !
// int removeDuplicates(vector<int>& nums) {
//     int i = 0;
//     for (int n : nums)
//         if (i < 2 || n > nums[i-2])
//             nums[i++] = n;
//     return i;
// }

int main(){
	Solution ss;
	// vector<int> nums{1,1,1,2,2,3};
	vector<int> nums{0,0,1,1,1,1,2,3,3};
	cout << ss.removeDuplicates(nums) << endl;
	printVector(nums);
}