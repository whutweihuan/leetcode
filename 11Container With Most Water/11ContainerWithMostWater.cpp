/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-27 
# Last Modified: 2018-11-27 
#          Link: https://leetcode.com/problems/container-with-most-water/
#         title: 11. Container With Most Water
#   Description: ---
#	 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
#	 
#	 Note: You may not slant the container and n is at least 2.

***********************************************/

#include<vector>
#include <iostream>
#include<algorithm>

using namespace std;

//Just use the silly way ,O(n^2)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxv = 0;
//         for(int i=0;i<height.size();i++){
//         	for(int j=i+1;j<height.size();j++){
//         		maxv = std::max(maxv,std::min(height[i],height[j])*(j-i));
//         	}
//         }
//         return maxv;
//     }
// };


//Can use double pointer, one from left and another from right
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxv = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
        	maxv = std::max(std::min(height[left],height[right])*(right-left) ,maxv);
        	if(height[left] > height[right]){
        		right--;
        	}
        	else{
        		left++;
        	}
        }

        return maxv;
    }
};

int main(){
	Solution ss;
	std::vector<int> height {1,8,6,2,5,4,8,3,7};
	cout <<ss.maxArea(height)<<endl;
}