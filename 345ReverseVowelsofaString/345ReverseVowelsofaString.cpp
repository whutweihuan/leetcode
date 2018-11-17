/***********************************************
#
#      Filename: 345ReverseVowelsofaString.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 12:44:36
# Last Modified: 2018-11-17 12:44:36
#          Link: 
#   Description: ---
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

ideas:
1. use stack
2. can use swap,two pointer ,one from head ,and another one from tail.

***********************************************/



#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<string.h>

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
       set<char> st = {'i','u','o','e','a','A','I','U','E','O'};          
       stack<char> stk;
        for(auto c: s){
            if(st.find(c)!=st.end()){
               stk.push(c); 
            }
        }
        
        for(auto & c: s){
            if(st.find(c)!=st.end()){
                c = stk.top();
                stk.pop();
            }
        }
        return s;
    }
};

// Author: Hao Chen
// 1) preset a dictionary table to look up vowels
// 2) we have two pointer, the `left` one search vowels from the beginning to then end, the `right` one search from the end to the beginning.
// 3) swap the left one and the right one until left >= right.
class Solution2 {
private:
   bool vowelsTable[256];
public:
    Solution2(){
        memset(vowelsTable, 0, sizeof(vowelsTable));
        vowelsTable['a']=true;
        vowelsTable['e']=true;
        vowelsTable['i']=true;
        vowelsTable['o']=true;
        vowelsTable['u']=true;

        vowelsTable['A']=true;
        vowelsTable['E']=true;
        vowelsTable['I']=true;
        vowelsTable['O']=true;
        vowelsTable['U']=true;
    }
    bool isVowels(char ch) {
        return vowelsTable[ch];
    }
    string reverseVowels(string s) {
        int left=0, right=s.size()-1;
        while ( left < right ) {
            while( !isVowels( s[left]) ) left++;
            while( !isVowels( s[right] ) ) right--;
            if (left >= right) break;
            swap(s[left], s[right]);
            left++; right--;
        }
        return s;
    }
};


int main(){
    Solution ss;
    string s="hello";
    string s2="Unglad, I tar a tidal gnu.";
    std::cout<<s+":\t"<<ss.reverseVowels(s)<<endl;
    std::cout<<s2+":\t"<<ss.reverseVowels(s2)<<endl;
}








