/***********************************************
#
#      Filename: 9PalindromeNumber.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 23:17:30
# Last Modified: 2018-11-22 23:17:30
#          Link: https://leetcode.com/problems/palindrome-number/
#   Description: ---
#     Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
#     
#     Example 1:
#     
#     Input: 121
#     Output: true
#     Example 2:
#     
#     Input: -121
#     Output: false
#     Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
#     Example 3:
#     
#     Input: 10
#     Output: false
#     Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
***********************************************/
#include<iostream>
#include<string>

using namespace std;



class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if (x == 0) return true;
        string s = std::to_string(x);
        int low = 0,high = s.size()-1;
        while(low<high){
            if(s[low] != s[high]) return false;
            low++,high--;
        }
        return true;
    }
};

int main(){
    Solution ss;
    cout<<ss.isPalindrome(121)<<endl;

}















