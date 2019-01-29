/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/minimum-path-sum/
#         title: 64	Minimum Path Sum
#   Description: ---
#	  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
#	  
#	  Note: You can only move either down or right at any point in time.
#	  
#	  Example:
#	  
#	  Input:
#	  [
#	    [1,3,1],
#	    [1,5,1],
#	    [4,2,1]
#	  ]
#	  Output: 7
#	  Explanation: Because the path 1→3→1→1→1 minimizes the sum.
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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if(i>0 && j>0){
        			dp[i][j] = std::min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        		}
        		else if(i>0){
        			dp[i][j] = dp[i-1][j] + grid[i][j];
        		}
        		else if(j>0){
        			dp[i][j] = dp[i][j-1] + grid[i][j];
        		}
        		else{
        			dp[i][j] = grid[i][j];
        		}
        	}
        }
        // printVector2D(dp);
        return dp[row-1][col-1];
    }
};

// int minPathSum(vector<vector<int> > &grid) {
//     if (grid.size()<=0){
//         return 0;
//     }
//     int i, j;
//     for(i=0; i<grid.size(); i++){
//         for(j=0; j<grid[i].size(); j++){
//             int top = i-1<0 ? INT_MAX : grid[i-1][j] ;
//             int left = j-1<0 ? INT_MAX : grid[i][j-1];
//             if (top==INT_MAX && left==INT_MAX){
//                 continue;
//             }
//             grid[i][j] += (top < left? top: left);

//         }
//     }

//     return grid[grid.size()-1][grid[0].size()-1];
// }

int main(int argc, char const *argv[])
{
	Solution ss;
	// vector<vector<int>> grid{
	// 	  {1,3,1},
 // 		  {1,5,1},
 //  		  {4,2,1}
	// };
	vector<vector<int>> grid{
		  {0,1},
 		  {1,0},
	};
	cout << ss.minPathSum(grid)<<endl;
	return 0;
}