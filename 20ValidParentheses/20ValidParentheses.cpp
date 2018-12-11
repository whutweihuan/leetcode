/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/valid-parentheses/
#         title: 20    Valid Parentheses
#   Description: ---
#      Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#      
#      An input string is valid if:
#      
#      Open brackets must be closed by the same type of brackets.
#      Open brackets must be closed in the correct order.
#      Note that an empty string is also considered valid.
#      Example 1:
#      
#      Input: "()"
#      Output: true
#      Example 2:
#      
#      Input: "()[]{}"
#      Output: true
#      Example 3:
#      
#      Input: "(]"
#      Output: false
#      Example 4:
#      
#      Input: "([)]"
#      Output: false
#      Example 5:
#      
#      Input: "{[]}"
#      Output: true
***********************************************/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {     
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){ stk.push('(');}
            else if(s[i] == '['){ stk.push('[');}
            else if(s[i] == '{'){ stk.push('{');}

            else if(s[i] == ')'){ 
                if(stk.empty() || stk.top()!='(' ){return false;}
                stk.pop();
            }  
            else if(s[i] == ']'){ 
                if(stk.empty() ||stk.top()!='['){return false;}
                stk.pop();
            } 
            else if(s[i] == '}'){ 
                if(stk.empty() ||stk.top()!='{' ){return false;}
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution ss;
    string s ="}]}()){{)[{[(]";
    // string s = "{[]}";
    cout<<ss.isValid(s)<<endl;
}