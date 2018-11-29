/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/generate-parentheses/
#         title: 22 Generate Parentheses
#   Description: ---
#     
#     Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#     
#     For example, given n = 3, a solution set is:
#     
#     [
#       "((()))",
#       "(()())",
#       "(())()",
#       "()(())",
#       "()()()"
#     ]

***********************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
     vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        if (n==0 ){return vector<string> {};}
        //string temp ="(";
        
        dfs(n,n,"");
        cout<<cnt<<endl;

        return result;
    }
    void dfs(int a,int b,string ans){

        if(a<0 || b<0 ){return ;}
        if(a > b){return ;}
        if( a==0 ) {
            for(int i=0;i<b;i++){
                ans+=")";
            }
            result.push_back(ans);          
            return ;
        }
        dfs(a-1,b,ans+"(");
        dfs(a,b-1,ans+")");
    }
};

int main(){
    Solution ss;
    int n = 8;
    for(string s: ss.generateParenthesis(n)){
        cout<<s<<"\n";
    }
}