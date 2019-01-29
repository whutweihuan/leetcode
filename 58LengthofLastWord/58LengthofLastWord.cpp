/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://leetcode.com/problems/length-of-last-word/
#         title: 58	Length of Last Word
#   Description: ---
#     Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
#     
#     If the last word does not exist, return 0.
#     
#     Note: A word is defined as a character sequence consists of non-space characters only.
#     
#     Example:
#     
#     Input: "Hello World"
#     Output: 5
#     
***********************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i=s.size()-1;i>=0;i--){
        	// there is blank in the last maybe! 
        	if(s[i] ==' ' ){
        		if(len){ return len; }
        		continue;
        	}
        	else{ len++;}
        }
        return len;
    }
};

int main(int argc, char const *argv[])
{
	Solution ss;
	cout << ss.lengthOfLastWord("Hello World ");

	return 0;
}