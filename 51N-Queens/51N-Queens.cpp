/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-27 
# Last Modified: 2019-1-27
#          Link: https://leetcode.com/problems/n-queens/
#         title: 51	N-Queens
#   Description: ---
# 	  The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
# 	  
# 	  
# 	  
# 	  Given an integer n, return all distinct solutions to the n-queens puzzle.
# 	  
# 	  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
# 	  
# 	  Example:
# 	  
# 	  Input: 4
# 	  Output: [
# 	   [".Q..",  // Solution 1
# 	    "...Q",
# 	    "Q...",
# 	    "..Q."],
# 	  
# 	   ["..Q.",  // Solution 2
# 	    "Q...",
# 	    "...Q",
# 	    ".Q.."]
# 	  ]
# 	  Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void printVector2D(vector<vector<string>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\n";
		}
		cout<<"\n"<<endl;
	}
}

class Solution {
public:
	int size ;
	int count_kind;
	bool ok(const vector<string> & temp,int row ,int col){
		//valify the col, i means row
		for(int i=0;i<size;i++){
			if(i == row){ continue; }
			if(temp[i][col] == 'Q'){
				return false;
			}
		}

		//valify the x
		int dir[4][2]={
			{-1,-1},
			{-1,1},
			{1,-1},
			{1,1}
		};

		for(int i=0;i<4;i++){
			int row_temp = row;
			int col_temp = col;
			while(1){
				row_temp += dir[i][0];
			    col_temp += dir[i][1];
			    if(row_temp<0 || row_temp>=size || col_temp<0 || col_temp>= size){
			    	break;
			    }
			    if(temp[row_temp][col_temp] == 'Q'){
			    	return false;
			    }
			}
		}
		return true;
	}

	// void backtrack(vector<vector<string>> & result, vector<string> & temp,int count,int pos){
	// 	if(count == size ){ 
	// 		result.push_back(temp); 
	// 		count_kind++; 
	// 		return;
	// 	}

	// 	for(int i=pos;i<size *size;i++){
	// 		temp[i/size][i%size] = 'Q';
	// 		int row = i/size;
	// 		if(ok(temp,i)){
	// 			backtrack(result,temp,count+1,i+1);
	// 		}
	// 		temp[i/size][i%size] = '.';
	// 	}
	// }

	void backtrack(vector<vector<string>> & result, vector<string> & temp,int count,int current_row){	
		if(count == size ){ 
			result.push_back(temp); 
			count_kind++; 
			return;
		}

		if(current_row >= size){return ;}

		for(int i=0;i<size;i++){
			temp[current_row][i] = 'Q';
			if(ok(temp,current_row,i) ){
				backtrack(result,temp,count+1,current_row+1);
			}
			temp[current_row][i] = '.';
		}
	}

public:
    vector<vector<string>> solveNQueens(int n) {
    	size = n;
    	count_kind = 0;
    	vector<vector<string>> result;
    	vector<string>  temp(n,string(n,'.'));
        backtrack(result,temp,0,0);
        
        return result;
    }
};

vector< vector<string> > solveNQueens(int n) {
    vector< vector<string> > result;
    vector<int> solution(n);

    solveNQueensRecursive(n, 0, solution, result);

    return result;    
}

// //The following recursion is easy to understand. Nothing's tricky.
// //  1) recursively find all of possible columns row by row.
// //  2) solution[] array only stores the columns index. `solution[row] = col;` 
// void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result) {
//     //if no more row need to do, shape the result
//     if (currentRow == n){
//         vector<string> s;
//         for (int row = 0; row < n; row++) {
//             string sRow;
//             for (int col = 0; col < n; col++) {
//                 sRow = sRow + (solution[row] == col ? "Q" :"." );
//             }
//             s.push_back(sRow);
//         }
//         result.push_back(s);
//         return;
//     }

//     //for each column
//     for (int col = 0; col < n; col++) {
//         //if the current column is valid
//         if (isValid(col, currentRow, solution) ) {
//             //place the Queue
//             solution[currentRow] = col;
//             //recursively put the Queen in next row
//             solveNQueensRecursive(n, currentRow+1, solution, result);
//         }
//     } 
// }

// //Attempting to put the Queen into [row, col], check it is valid or not
// //Notes: 
// //  1) we just checking the Column not Row, because the row cannot be conflicted
// //  2) to check the diagonal, we just check |x'-x| == |y'-y|, (x',y') is a Queen will be placed
// bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn) {

//     for(int i=0; i<attemptedRow; i++) {
//         if (attemptedColumn == queenInColumn[i]  || 
//             abs(attemptedColumn - queenInColumn[i]) == abs(attemptedRow - i)) {
//             return false;
//         } 
//     }
//     return true;
// }

int main(){
	Solution ss;
	vector<vector<string>> result = ss.solveNQueens(7);
	printVector2D(result);
	cout<< "数目为\t" << ss.count_kind <<endl;
}