/***********************************************
#
#      Filename: 344ReverseString.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 13:25:01
# Last Modified: 2018-11-17 13:25:01
#          Link: 
#   Description: ---
Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
***********************************************/

#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
       if(s.size()==0){ return "";}
       int lo =0 , hi = s.size()-1;
       while(lo<hi){
            swap(s[lo],s[hi]);
            lo++,hi--;
       }
       return s;
    }
};

int main()
{
    Solution ss;
    string s = "weihuan";
    std::cout<<ss.reverseString(s)<<endl;
}



