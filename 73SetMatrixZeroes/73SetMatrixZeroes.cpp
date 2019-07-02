/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/set-matrix-zeroes/
#         title: 73	Set Matrix Zeroes
#   Description: ---
#	  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
#	  
#	  Example 1:
#	  
#	  Input: 
#	  [
#	    [1,1,1],
#	    [1,0,1],
#	    [1,1,1]
#	  ]
#	  Output: 
#	  [
#	    [1,0,1],
#	    [0,0,0],
#	    [1,0,1]
#	  ]
#	  Example 2:
#	  
#	  Input: 
#	  [
#	    [0,1,2,0],
#	    [3,4,5,2],
#	    [1,3,1,5]
#	  ]
#	  Output: 
#	  [
#	    [0,0,0,0],
#	    [0,4,5,0],
#	    [0,3,1,0]
#	  ]
#	  Follow up:
#	  
#	  A straight forward solution using O(mn) space is probably a bad idea.
#	  A simple improvement uses O(m + n) space, but still not the best solution.
#	  Could you devise a constant space solution?
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

// O(m*n) space
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//     	// For each row
//     	vector<vector<int>> matrix1 = matrix;
//         for(int i=0;i<matrix.size();i++){
//         	if(find(matrix[i].begin(),matrix[i].end(),0) != matrix[i].end()){
//         		for(int j=0;j<matrix[0].size();j++){matrix[i][j] = 0;}
//         	}
//         }
//         // For each col
//         for(int i=0;i<matrix[0].size();i++){
//         	int hava = 0;
//         	for(int j=0;j<matrix.size();j++){
//         		if(matrix1[j][i]==0){ hava =1;break;}
//         	}
//         	if(hava){
//         		for(int j=0;j<matrix.size();j++){matrix[j][i] = 0;}
//         	}
//         }        
//     }
// };

// O(m+n) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        
        vector<bool> zeroRows(matrix.size(), false);
        vector<bool> zeroCols(matrix[0].size(), false);
        
        for (int rows = 0; rows < matrix.size(); rows++) {
            for (int cols = 0; cols < matrix[0].size(); cols++) {
                if (matrix[rows][cols] == 0) {
                    zeroRows[rows] = true;
                    zeroCols[cols] = true;
                }
            }
        }
        
        for (int rows = 0; rows < matrix.size(); rows++) {
            for (int cols = 0; cols < matrix[0].size(); cols++) {
                if (zeroRows[rows] || zeroCols[cols]) matrix[rows][cols] = 0;
            }
        }
    }
};

// O (1) space
// class Solution {
// public:
//     Solution(){
//         srand(time(NULL));
//     }
//     void setZeroes(vector<vector<int> > &matrix) {
//         if(random()%2){
//             setZeroes1(matrix);
//         }
//         setZeroes2(matrix);
//     }
    
//     void setZeroes1(vector<vector<int> > &matrix) {
        
//         int bRow = false, bCol=false;
        
//         for (int r=0; r<matrix.size(); r++){
//             for(int c=0; c<matrix[r].size(); c++){
//                 if (matrix[r][c]==0){
//                     if (r==0) bRow = true;
//                     if (c==0) bCol = true;
//                     matrix[0][c] = matrix[r][0] = 0;
//                 }
//             }
//         }
        
//         for (int r=1; r<matrix.size(); r++){
//             for(int c=1; c<matrix[r].size(); c++){
//                 if (matrix[0][c]==0 || matrix[r][0]==0) {
//                     matrix[r][c]=0;
//                 }
//             }
//         }
//         if (bRow){
//             for(int c=0; c<matrix[0].size(); c++) matrix[0][c] = 0;
//         }
//         if (bCol){
//             for(int r=0; r<matrix.size(); r++) matrix[r][0] = 0;
//         }

//     }

int main(){
	Solution ss;
	vector<vector<int>> matrix{	
  		{0,1,2,0},
  		{3,4,5,2},
  		{1,3,1,5}
	};
	ss.setZeroes(matrix);
	printVector2D(matrix);
}