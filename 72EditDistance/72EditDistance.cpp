/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/edit-distance/
#         title: 72	Edit Distance
#   Description: ---
#	  Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
#	  
#	  You have the following 3 operations permitted on a word:
#	  
#	  Insert a character
#	  Delete a character
#	  Replace a character
#	  Example 1:
#	  
#	  Input: word1 = "horse", word2 = "ros"
#	  Output: 3
#	  Explanation: 
#	  horse -> rorse (replace 'h' with 'r')
#	  rorse -> rose (remove 'r')
#	  rose -> ros (remove 'e')
#	  Example 2:
#	  
#	  Input: word1 = "intention", word2 = "execution"
#	  Output: 5
#	  Explanation: 
#	  intention -> inention (remove 't')
#	  inention -> enention (replace 'i' with 'e')
#	  enention -> exention (replace 'n' with 'x')
#	  exention -> exection (replace 'n' with 'c')
#	  exection -> execution (insert 'u')
***********************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//*    For Example:
//*
//*        word1="abb", word2="abccb"
//*
//*        1) Initialize the DP matrix as below:
//*
//*               "" a b c c b
//*            "" 0  1 2 3 4 5
//*            a  1
//*            b  2
//*            b  3
//*
//*        2) Dynamic Programming
//*
//*               "" a b c c b
//*            ""  0 1 2 3 4 5
//*            a   1 0 1 2 3 4 
//*            b   2 1 0 1 2 3
//*            b   3 2 1 1 2 2
class Solution { 
public:
    int minDistance(string word1, string word2) { 
        int m = word1.length(), n = word2.length();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;  
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
        return dp[m][n];
    }
};

// class Solution { 
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.length(), n = word2.length();
//         vector<int> cur(m + 1, 0);
//         for (int i = 1; i <= m; i++)
//             cur[i] = i;
//         for (int j = 1; j <= n; j++) {
//             int pre = cur[0];
//             cur[0] = j;
//             for (int i = 1; i <= m; i++) {
//                 int temp = cur[i];
//                 if (word1[i - 1] == word2[j - 1])
//                     cur[i] = pre;
//                 else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
//                 pre = temp;
//             }
//         }
//         return cur[m]; 
//     }
// }; 

int main(int argc, char const *argv[])
{
	Solution ss;
	string word1 = "horse", word2 = "ros";
	cout << ss.minDistance(word1,word2) << endl;	
	return 0;
}