/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-10 
# Last Modified: 2018-12-10 
#          Link: 
#         title: Valid Sudoku
#   Description: ---
#      Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#      
#      Each row must contain the digits 1-9 without repetition.
#      Each column must contain the digits 1-9 without repetition.
#      Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
# 
***********************************************/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<81;i++){
            int row = i/9;
            int col = i%9;
            //Skip the .
            if(board[row][col] =='.'){continue;}

            //Valid the row
            for(int j=col+1;j<9;j++){
                if(board[row][j] == board[row][col]) {   return false;}
            }
            //Valid the col
            for(int j=row+1;j<9;j++){
                if(board[j][col] == board[row][col]) {  return false;}
            }
            //Valid the box
            //First we should known which box it is
            int box_row = (row/3)*3;
            int box_col = (col/3)*3;
            for(int ii=box_row;ii<box_row+3;ii++){
                for(int jj=box_col;jj<box_col+3;jj++){
                    if (ii==row && jj == col) { continue;}
                    if(board[ii][jj] == board[row][col]){  return false;}
                }
            }
        }
        return true;
    }
};

int main(){
    Solution ss;
    // vector <vector<char>> board{
    //       {'5','3','.','.','7','.','.','.','.'},
 //            {'6','.','.','1','9','5','.','.','.'},
 //            {'.','9','8','.','.','.','.','6','.'},
 //            {'8','.','.','.','6','.','.','.','3'},
 //            {'4','.','.','8','.','3','.','.','1'},
 //            {'7','.','.','.','2','.','.','.','6'},
 //            {'.','6','.','.','.','.','2','8','.'},
 //            {'.','.','.','4','1','9','.','.','5'},
 //            {'.','.','.','.','8','.','.','7','9'}
    //     };
        // vector<vector<char>> board{        
  //             {'8','3','.','.','7','.','.','.','.'},
  //             {'6','.','.','1','9','5','.','.','.'},
  //             {'.','9','8','.','.','.','.','6','.'},
  //             {'8','.','.','.','6','.','.','.','3'},
  //             {'4','.','.','8','.','3','.','.','1'},
  //             {'7','.','.','.','2','.','.','.','6'},
  //             {'.','6','.','.','.','.','2','8','.'},
  //             {'.','.','.','4','1','9','.','.','5'},
  //             {'.','.','.','.','8','.','.','7','9'}
        // };

        vector<vector<char>> board{    
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}
        };

        cout<<ss.isValidSudoku(board)<<endl;

}