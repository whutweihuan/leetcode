/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-21 
# Last Modified: 2019-1-21
#          Link: https://leetcode.com/problems/first-missing-positive/
#         title: 41	First Missing Positive
#   Description: ---

#	  Given an unsorted integer array, find the smallest missing positive integer.
#	  Example 1:
#	  
#	  Input: [1,2,0]
#	  Output: 3


#	  Example 2:
#	  
#	  Input: [3,4,-1,1]
#	  Output: 2


#	  Example 3:
#	  
#	  Input: [7,8,9,11,12]
#	  Output: 1
#	  Note:
#	  
#	  Your algorithm should run in O(n) time and uses constant extra space.
***********************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// This way use the sort library 
// In fact we can not use it because it is O(log(n)), and we need a algorithm in O(n) time.
// So we need find another way.
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int res = 1 ;
//         sort(nums.begin(),nums.end(),std::less<int>());
//         auto iter = unique(nums.begin(),nums.end());
//         for(auto iter0 = nums.begin();iter0 != iter;iter0++ ){
//         	if( *iter0 <= 0 ){ continue;}
//         	if(res != *iter0){
//         		break;
//         	}
//         	res++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	// Get max number
    	int maxval =1;
    	for(int i=0;i<nums.size();i++){
    		maxval = std::max(maxval,nums[i]);
    	}

    	// Use index as number
    	// Be careful, maybe you will overflow.
        vector <int> a (maxval+1,0);

        // Set flag
        for(int i=0;i<nums.size();i++){
        	if(nums[i] <= 0){ continue;}
        	a[nums[i]] = 1;
        }

        // Use the flag
        int res = 1;
        int i =1;
        for(i=1;i < maxval+1;i++){
        	if(a[i] == 0 ){ 
        		res = i;
        		break;
        	}
        }

        // Return result
        if(i == maxval+1) {res = maxval+1;}
        return res;
    }
};

int main(){
	Solution ss;
	vector<int> nums {1,2,0};
	cout <<ss.firstMissingPositive(nums)<<endl;
}