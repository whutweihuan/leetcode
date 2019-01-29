/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://leetcode.com/problems/spiral-matrix-ii/
#         title: 59	Spiral Matrix II
#   Description: ---
#	  Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
#	  
#	  Example:
#	  
#	  Input: 3
#	  Output:
#	  [
#	   [ 1, 2, 3 ],
#	   [ 8, 9, 4 ],
#	   [ 7, 6, 5 ]
#	  ]
#	  
***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0){  return vector<vector<int>>();}
        vector<vector<int>> result(n,vector<int>(n,0));
        int row = 0,col=0;
        int count = 1;
        int dir[4][2]={
			{0,1},// to right
			{1,0},// to down
			{0,-1},// to left
			{-1,0}  //to up
		};
		result[0][0] = count;
		int current_dir = 0;
        while(count < n*n){
        	// cout<< row <<", "<< col<<endl;
        	int temp_row = row;
        	int temp_col = col;
        	temp_row += dir[current_dir][0];
        	temp_col += dir[current_dir][1];
        	if(temp_row<0 || temp_row>=n || temp_col<0 || temp_col>= n 
        		|| result[temp_row][temp_col] != 0 ){
        		current_dir = (current_dir+1)%4;
        	}
        	else{
        		row = temp_row;
        		col = temp_col;
        		count++;
        		result[row][col] = count;
        	}
        }
        return result;
    }
};

int main(){
	Solution ss;
	vector<vector<int>> res = ss.generateMatrix(10);
	printVector2D(res);
}

