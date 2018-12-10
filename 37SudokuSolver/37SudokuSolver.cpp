/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-10 
# Last Modified: 2018-12-10 
#          Link: https://leetcode.com/problems/sudoku-solver/
#         title: 37 Sudoku Solver
#   Description: ---
#     
#     Write a program to solve a Sudoku puzzle by filling the empty cells.
#     
#     A sudoku solution must satisfy all of the following rules:
#     
#     Each of the digits 1-9 must occur exactly once in each row.
#     Each of the digits 1-9 must occur exactly once in each column.
#     Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#     Empty cells are indicated by the character '.'.
#     
***********************************************/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<char>> result;
    int ok = 0;
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0);
        if(ok){
            board = result;
        }
        else{
            printf("没有解！\n");
        }
      
    }

    bool dfs(vector<vector<char> >board,int index){
        if(index > 80) {
            ok = true;
            result = board;
            return true;
        }

        int row = index/9;
        int col = index%9;
        if(board[row][col] != '.'){
            if(index ==80){
                 ok = true;
                 result = board;
                 return true;
            }
            else{
                return dfs(board,index+1);
            }
        }

        for(int x = '1';x<='9';x++){
            board[row][col] = x;
            if(isValidSudoku(board,index)){
                if(dfs(board,index+1)){
                    return true;
                }
            }
        }
        return false;
    }


    bool isValidSudoku(vector<vector<char>>& board ,int index) {
            int row = index / 9;
            int col = index % 9;
            //Valid the row
            for(int j=0;j<9;j++){
                if(j == col) {continue;}
                if(board[row][j] == board[row][col]) {   return false;}
            }
            //Valid the col
            for(int j=0;j<9;j++){
                if(j == row) {continue;}
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
        
        return true;
    }
};

int main(){
    Solution ss;
    // vector <vector<char>> board{
    //        {'5','3','.','.','7','.','.','.','.'},
    //        {'6','.','.','1','9','5','.','.','.'},
    //        {'.','9','8','.','.','.','.','6','.'},
    //        {'8','.','.','.','6','.','.','.','3'},
    //        {'4','.','.','8','.','3','.','.','1'},
    //        {'7','.','.','.','2','.','.','.','6'},
    //        {'.','6','.','.','.','.','2','8','.'},
    //        {'.','.','.','4','1','9','.','.','5'},
    //        {'.','.','.','.','8','.','.','7','9'}
    //  };
     vector <vector<char>> board{
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','1','.','.'}
    };

     ss.solveSudoku(board);

     for (int i = 0; i < 9; ++i)
     {
        for (int j = 0; j < 9; ++j)
        {
            // printf('%c\t', board[i][j]);
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
     }

}