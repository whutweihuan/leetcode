/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-3 
# Last Modified: 2018-12-3 
#          Link: https://leetcode.com/problems/implement-strstr/
#         title: 28    Implement strStr()
#   Description: ---
#      Implement strStr().
#      
#      Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#      
#      Example 1:
#      
#      Input: haystack = "hello", needle = "ll"
#      Output: 2
#      Example 2:
#      
#      Input: haystack = "aaaaa", needle = "bba"
#      Output: -1
***********************************************/
#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return  0;
        }
    
        int start = 0,end = needle.size()-1;
        while(end< haystack.size()){
            int i =0;
            for( i=0;i<needle.size();i++){
                if(haystack[start+i] != needle[i]){break;}
            }
            if(i == needle.size()){return start;}
            start++;
            end++;
        }
        return -1;
    }
};

int main(){
    Solution ss;
    string haystack = "hello";
    string needle = "ll";

    cout << ss.strStr(haystack,needle)<<endl;
}
