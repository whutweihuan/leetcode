/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/word-search/
#         title: 79	Word Search
#   Description: ---
#	  Given a 2D board and a word, find if the word exists in the grid.
#	  
#	  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
#	  
#	  Example:
#	  
#	  board =
#	  [
#	    ['A','B','C','E'],
#	    ['S','F','C','S'],
#	    ['A','D','E','E']
#	  ]
#	  
#	  Given word = "ABCCED", return true.
#	  Given word = "SEE", return true.
#	  Given word = "ABCB", return false.
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

void printVector2D(vector<vector<char>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout << endl;
}


// vector<vector<char>>& board is 16 ms
// vector<vector<char>>  board is 152 ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
         if(!board.size() || !board[0].size()) {return false;}
         int row = board.size();
         int col = board[0].size();
         for(int i=0;i<row;i++){
         	for(int j=0;j<col;j++){
         		if(word[0] == board[i][j]){
         			if(dfs(board,word,i,j)){
         				return true;
         			}
         		}
         	}
         }
         return false;
    }

    bool dfs(vector<vector<char>> & board, string word,int row,int col){
    	if(word.empty()){return true;}
    	if(row<0 || row >= board.size() || col<0 || col >= board[0].size() || board[row][col] != word[0]){
    		return false;
    	}
    	
    	board[row][col] = '#';
    	printVector2D(board);
    	bool done = dfs(board,word.substr(1),row-1,col) ||     //up
    		       dfs(board,word.substr(1),row,col+1) ||      //right
    			   dfs(board,word.substr(1),row+1,col) ||	   //down
    			   dfs(board,word.substr(1),row,col-1);		   //left
    	board[row][col] = word[0];
    	return done;
    }
};

int main(){
	Solution ss;
	vector<vector<char>> board{
  	  	{'A','B','C','E'},
  	  	{'S','F','C','S'},
  	  	{'A','D','E','E'}		
	};
	string word = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";
	cout << ss.exist(board,word3) <<endl;
}