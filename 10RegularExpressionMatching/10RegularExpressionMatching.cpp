/***********************************************
#
#      Filename: 10RegularExpressionMatching.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 23:26:06
# Last Modified: 2018-11-22 23:26:06
#          Link: https://leetcode.com/problems/regular-expression-matching/
#   Description: ---
#     Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
#     
#     '.' Matches any single character.
#     '*' Matches zero or more of the preceding element.
#     The matching should cover the entire input string (not partial).
#     
#     Note:
#     
#     s could be empty and contains only lowercase letters a-z.
#     p could be empty and contains only lowercase letters a-z, and characters like . or *.
#     Example 1:
#     
#     Input:
#     s = "aa"
#     p = "a"
#     Output: false
#     Explanation: "a" does not match the entire string "aa".
#     Example 2:
#     
#     Input:
#     s = "aa"
#     p = "a*"
#     Output: true
#     Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
#     Example 3:
#     
#     Input:
#     s = "ab"
#     p = ".*"
#     Output: true
#     Explanation: ".*" means "zero or more (*) of any character (.)".
#     Example 4:
#     
#     Input:
#     s = "aab"
#     p = "c*a*b"
#     Output: true
#     Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
#     Example 5:
#     
#     Input:
#     s = "mississippi"
#     p = "mis*is*p*."
#     Output: false
***********************************************/
#include<iostream>
#include<string>

using namespace std;

//  --------------------- 
//  作者：shiter 
//  来源：CSDN 
//  原文：https://blog.csdn.net/wangyaninglm/article/details/55827721 
//  
//  class Solution {
//   public:
//    bool isMatch(const char *s, const char *p)
//    {
//        if (*p == '\0') return *s == '\0';
//        // next char is not '*', then must match current character
//        if (*(p + 1) != '*')
//  
//        {
//            if (*p == *s || (*p == '.' && *s != '\0'))
//                return isMatch(s + 1, p + 1);
//            else
//                return false;
//  
//        }
//        else
//        { // next char is '*'
//            while (*p == *s || (*p == '.' && *s != '\0'))
//            {
//                //not use * to replace
//                if (isMatch(s, p + 2))
//                    return true;
//                //Now we must use * to replace
//                s++;
//            }
//            return isMatch(s, p + 2);
//        }
//    }
//  };


// C++ solution.
// The idea same as c int the last one.
//  class Solution {
//  public:
//      bool isMatch(string s, string p) {
//          if (p.empty())    return s.empty();
//  
//          if ('*' == p[1])
//              // x* matches empty string or at least one character: x* -> xx*
//              // *s is to ensure s is non-empty
//              return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
//          else
//              return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
//      }
//  };


class Solution {
public:
    bool isMatch(string s, string p) {
        
        return s == p;
    }
};

int main(){
    string s1 = "aab";
    string t1 = "c*a*b";

    Solution ss;
    cout<<ss.isMatch(s1,t1)<<endl;
}













