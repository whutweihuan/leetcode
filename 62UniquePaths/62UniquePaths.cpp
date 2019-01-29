/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/unique-paths/
#         title: 62	Unique Paths
#   Description: ---
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *    
 *    
 *    start                                                  
 *    +---------+----+----+----+----+----+                   
 *    |----|    |    |    |    |    |    |                   
 *    |----|    |    |    |    |    |    |                   
 *    +----------------------------------+                   
 *    |    |    |    |    |    |    |    |                   
 *    |    |    |    |    |    |    |    |                   
 *    +----------------------------------+                   
 *    |    |    |    |    |    |    |----|                   
 *    |    |    |    |    |    |    |----|                   
 *    +----+----+----+----+----+---------+                   
 *                                   finish                  
 *    
 * 
 * How many possible unique paths are there?
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 *               
***********************************************/
#include <iostream>
#include <string>
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

// (m+n-2)! / ((m-1)! * (n-1)!)

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//     	m--,n--;
//     	int bigger = m > n?m:n;
//     	int small = m <= n?m:n;

//     	long long res = 1;
//     	for(int i=bigger+1;i<= bigger+small;i++){
//     		res *= i; 		
//     	}
//     	// cout << res <<endl;
//     	long long  temp = 1;
//     	for(int i=1;i<=small;i++){
//     		temp *= i;		
//     	}
//     	return res / temp;
//     }
// };

// class Solution {
// public:
//     long long uniquePaths(long long k, long long  n) {
//        int m = n;
//         n = k+n-2;
//         if(m<k)
//             k=m;
//         k--;
//         long long a = 1;
//        // cout<<n<<k;
//         for(int i =1;i<=k;i++)
//             a = (a*(n-i+1))/i;//, cout<<a;
//         return a;
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int>> dp(m,vector<int>(n,1));
    	for(int i=1;i<m;i++){
    		for(int j=1;j<n;j++){
    			dp[i][j] = dp[i-1][j] + dp[i][j-1];
    		}
    	}
    	return dp[m-1][n-1];
    }
};


int main(){
	int m = 40,n = 6;
	Solution ss;
	cout <<  ss.uniquePaths(m,n) <<endl;
}