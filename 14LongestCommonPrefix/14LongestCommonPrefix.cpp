/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-27 
# Last Modified: 2018-11-27 
#          Link: https://leetcode.com/problems/longest-common-prefix/
#         title: 14    Longest Common Prefix
#   Description: ---
#      
#      Write a function to find the longest common prefix string amongst an array of strings.
#      
#      If there is no common prefix, return an empty string "".
#      
#      Example 1:
#      
#      Input: ["flower","flow","flight"]
#      Output: "fl"
#      Example 2:
#      
#      Input: ["dog","racecar","car"]
#      Output: ""
#      Explanation: There is no common prefix among the input strings.

***********************************************/
#include <iostream>
#include<string>
#include <vector>
#include <climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size()== 0){return "";}
        if(strs.size()== 1){return strs[0];}

        int minlen = INT_MAX;
        for(int i=0;i<strs.size();i++){
            minlen = std::min(minlen,(int)strs[i].size());
        }

        for(int i=0;i<minlen;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != strs[j-1][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }

        return res;
    }
};


int main(){
    // vector<string> strs{"flower","flow","flight"};
    vector<string> strs{""};
    Solution ss;
    cout<<ss.longestCommonPrefix(strs)<<endl;
}





