/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/sort-colors/
#         title: 75	Sort Colors
#   Description: ---
#	  Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
#	  
#	  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
#	  
#	  Note: You are not suppose to use the library's sort function for this problem.
#	  
#	  Example:
#	  
#	  Input: [2,0,2,1,1,0]
#	  Output: [0,0,1,1,2,2]
#	  Follow up:
#	  
#	  A rather straight forward solution is a two-pass algorithm using counting sort.
#	  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
#	  Could you come up with a one-pass algorithm using only constant space?
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//     	map<int,int> m;
//     	for(int i=0;i<nums.size();i++){
//     		m[nums[i]]++;
//     	}
//     	int idx=0;
//     	for(auto iter = m.begin();iter != m.end();iter++){
//     		while(iter->second--){
//     			nums[idx++] = iter->first;
//     		}
//     	}
//     }
// };

void sortColors(int a[], int n) {
    int zero=0, two=n-1;
    for(int i=0; i<=two; i++ ){
        if (a[i]==0){
            swap(&a[zero], &a[i]);
            zero++;
        }
        if (a[i]==2){
            swap(&a[two], &a[i]);
            two--; 
            i--;
        }
    }
}

int main(){
	Solution ss;
	vector <int> nums {2,0,2,1,1,0} ;
	ss.sortColors(nums);
	printVector(nums);

}