/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/unique-paths-ii/
#         title: 63	Unique Paths II
#   Description: ---
		有障碍物
***********************************************/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int max3num(const int &a,const int &b,const int &c){
		int temp = max(a,b);
		return max(temp,c);
	}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int row = obstacleGrid.size();
    	int col = obstacleGrid[0].size();
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if(obstacleGrid[i][j] == 1){
        			obstacleGrid[i][j] = -1;
        		}
        	}
        }
        if(obstacleGrid[0][0] == -1){return 0;}
        obstacleGrid[0][0] = 1;
        for(int i=0;i<row;i++){
        	for(int j=0;j<col;j++){
        		if(obstacleGrid[i][j] == -1){continue;}
        		if(i==0 && j==0){continue;}
        		if(i==0){
        			obstacleGrid[i][j] = max(obstacleGrid[i][j-1],0);
        		}
        		else if(j==0){
        			obstacleGrid[i][j] = max(obstacleGrid[i-1][j],0);
        		}
        		else {
        			obstacleGrid[i][j] = max3num(obstacleGrid[i-1][j],obstacleGrid[i][j-1],
        			obstacleGrid[i-1][j] + obstacleGrid[i][j-1]);
        		}

        	}
        }
        return obstacleGrid[row-1][col-1] == -1 ? 
        			0:obstacleGrid[row-1][col-1];
    }
};

int main(){
	Solution ss;
	vector<vector<int>> obstacleGrid{
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	// vector<vector<int>> obstacleGrid{
	// 	{1,0}
	// };
	cout << ss.uniquePathsWithObstacles(obstacleGrid)<<endl;
}