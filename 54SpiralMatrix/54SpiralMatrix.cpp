/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://leetcode.com/problems/spiral-matrix/
#         title: 54	Spiral Matrix
#   Description: ---
# 	  Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
# 	  
# 	  Example 1:
# 	  
# 	  Input:
# 	  [
# 	   [ 1, 2, 3 ],
# 	   [ 4, 5, 6 ],
# 	   [ 7, 8, 9 ]
# 	  ]
# 	  Output: [1,2,3,6,9,8,7,4,5]
# 	  Example 2:
# 	  
# 	  Input:
# 	  [
# 	    [1, 2, 3, 4],
# 	    [5, 6, 7, 8],
# 	    [9,10,11,12]
# 	  ]
# 	  Output: [1,2,3,4,8,12,11,10,9,5,6,7]
# 	  
***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	if(matrix.size() == 0){return vector<int>();}
        vector<int> result;
        vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),0));
        int row = 0,col=0;
        int count = 1;
        int dir[4][2]={
			{0,1},// to right
			{1,0},// to down
			{0,-1},// to left
			{-1,0}  //to up
		};
		result.push_back(matrix[0][0]);
		visited[0][0] = 1;
		int current_dir = 0;
        while(count < matrix.size()*matrix[0].size()){
        	cout<< row <<", "<< col<<endl;
        	int temp_row = row;
        	int temp_col = col;
        	temp_row += dir[current_dir][0];
        	temp_col += dir[current_dir][1];
        	if(temp_row<0 || temp_row>=matrix.size() || temp_col<0 || temp_col>=matrix[0].size() 
        		|| visited[temp_row][temp_col] == 1 ){
        		current_dir = (current_dir+1)%4;
        	}
        	else{
        		row = temp_row;
        		col = temp_col;
        		count++;
        		visited[row][col] = 1;
        		result.push_back(matrix[row][col]);
        	}
        }
    	return result;
    }

};


int main(){
	Solution ss;
	// vector<vector<int>> matrix{
	// 	 {1, 2, 3 },
	// 	 {4, 5, 6 },
	// 	 {7, 8, 9 }
	// };
	vector<vector<int>> matrix{
		 // {1, 2, 3, 4},
		 // {5, 6 ,7, 8},
		 // {9, 10, 11 ,12}
	};
	vector<int> result = ss.spiralOrder(matrix);
	printVector(result);
}