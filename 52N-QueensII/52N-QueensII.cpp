/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://leetcode.com/problems/n-queens-ii/
#         title: 52	N-Queens II
#   Description: ---
		返回次数

***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
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
    int totalNQueens(int n) {
        size = n;
    	count_kind = 0;
    	vector<vector<string>> result;
    	vector<string>  temp(n,string(n,'.'));
        backtrack(result,temp,0,0);
        
        return count_kind;
    }
};




int main(){
	Solution ss;
	int result = ss.totalNQueens(8);
	cout<< "数目为\t" << result <<endl;
}