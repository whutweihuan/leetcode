/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-26 
# Last Modified: 2019-1-26
#          Link: https://leetcode.com/problems/rotate-image/
#         title: 48	Rotate Image
#   Description: ---
#     You are given an n x n 2D matrix representing an image.
#     
#     Rotate the image by 90 degrees (clockwise).
#     
#     Note:
#     
#     You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
#     
#     Example 1:
#     
#     Given input matrix = 
#     [
#       [1,2,3],
#       [4,5,6],
#       [7,8,9]
#     ],
#     
#     rotate the input matrix in-place such that it becomes:
#     [
#       [7,4,1],
#       [8,5,2],
#       [9,6,3]
#     ]
#     Example 2:
#     
#     Given input matrix =
#     [
#       [ 5, 1, 9,11],
#       [ 2, 4, 8,10],
#       [13, 3, 6, 7],
#       [15,14,12,16]
#     ], 
#     
#     rotate the input matrix in-place such that it becomes:
#     [
#       [15,13, 2, 5],
#       [14, 3, 4, 1],
#       [12, 6, 8, 9],
#       [16, 7,10,11]
#     ]
***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
	// void swap4Value(vector<vector<int>>& matrix ,int idx1,int idx2,int idx3,int idx4){
	// 	int size = matrix.size();
	// 	int temp = matrix[idx1/size][idx1%size];
	// 	matrix[idx1/size][idx1%size] = matrix[idx4/size][idx4%size];
	// 	matrix[idx4/size][idx4%size] = matrix[idx3/size][idx3%size];
	// 	matrix[idx3/size][idx3%size] = matrix[idx2/size][idx2%size];
	// 	matrix[idx2/size][idx2%size] = temp;
	// }

// we can also use the function 
// swap4Value(matrix,
// 	row*size+col,
// 	col * size + size - 1 - row,
// 	(size-1 -row) *size + size -1 -col,
// 	(size-1 - col) *size + row
// 	);

public:
    void rotate(vector<vector<int>>& matrix) {
    	int size = matrix.size();
        for(int row =0; row < (matrix.size() + 1)/2;row ++){
        	for(int col = 0;col <matrix.size()/2;col ++){
        		// make the matrix 4 part
        		// from left top  => right top => right bottom => left bottom  
        		int temp = matrix[row][col];
        		// left top = left bottom
        		matrix[row][col] = matrix[size-1-col][row];
        		// left bottom = right bottom
        		matrix[size-1-col][row] = matrix[size-1-row][size-1-col];
        		// right bottom = right top
        		matrix[size-1-row][size-1-col] = matrix[col][size-1-row];
        		// right top = left top
        		matrix[col][size-1-row] = temp;
        	}
        }
    }
};

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	vector<vector<int>> matrix{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
	};
	Solution ss;
	ss.rotate(matrix);
	printVector2D(matrix);

}