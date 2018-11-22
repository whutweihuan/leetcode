/***********************************************
#
#      Filename: 316RemoveDuplicateLetters.cpp
#

#        Create: 2018-11-20 20:18:31
# Last Modified: 2018-11-20 20:18:31
#          Link: https://leetcode.com/problems/remove-duplicate-letters/
#   Description: ---
#    Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
#    
#    Example 1:
#    
#    Input: "bcabc"
#    Output: "abc"
#    Example 2:
#    
#    Input: "cbacdcbc"
#    Output: "acdb"
***********************************************/
#include<iostream>
#include<string> 
#include<vector> 
#include<algorithm>
#include<string.h>

using namespace std; 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counter[256];
        int visited[256];
        memset(counter,0,sizeof(counter));
        memset(visited,0,sizeof(visited));
        for(auto c:s){
             counter[c]++; 
        }
        string result ="";
        for(char c:s){
            counter[c]--;
            if(visited[c]) {continue;}
            
            //if the current char is smaller than the last char of the result 
            //and there is still duplicated char ,we pop the last char of result
            while( !result.empty() && counter[result.back()] >0 && c <= result.back())
            {
                visited[result.back()] = 0;
                result.pop_back();
            }

            result.push_back(c);
            visited[c] = 1;
        }
        return result;
    }
};

int main(){
    Solution ss;
    cout<<ss.removeDuplicateLetters("cbacdcbc");
}


