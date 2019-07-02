/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/search-a-2d-matrix/
#         title: 74	Search a 2D Matrix
#   Description: ---
#	  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
#	  
#	  Integers in each row are sorted from left to right.
#	  The first integer of each row is greater than the last integer of the previous row.
#	  Example 1:
#	  
#	  Input:
#	  matrix = [
#	    [1,   3,  5,  7],
#	    [10, 11, 16, 20],
#	    [23, 30, 34, 50]
#	  ]
#	  target = 3
#	  Output: true
#	  Example 2:
#	  
#	  Input:
#	  matrix = [
#	    [1,   3,  5,  7],
#	    [10, 11, 16, 20],
#	    [23, 30, 34, 50]
#	  ]
#	  target = 13
#	  Output: false
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(!matrix.size() || !matrix[0].size()){return false;}
    	int row = matrix.size();
    	int col = matrix[0].size();
        int low = 0,high = row*col-1;
        while(low<=high){
        	int mid = low + (high-low)/2;
        	// cout << mid << endl;
        	if(matrix[mid/col][mid%col] < target){
        		low = mid +1;
        	}else if(matrix[mid/col][mid%col] > target){
        		high = mid - 1;
        	}else { 
        		return true;
        	}
        }
        return false;
    }
};

int main(){
	Solution ss;
	// vector<vector<int>>matrix{ 
 //  		{1,   3,  5,  7},
 //  		{10, 11, 16, 20},
 //  		{23, 30, 34, 50}
 //  	};
	vector<vector<int>>matrix{ 
  		{1, 1},
  	};
  	int target = 2;
  	cout << ss.searchMatrix(matrix,target) <<endl;;
}