/***********************************************
#
#      Filename: 3LongestSubstringWithoutRepeatingCharacters.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 16:48:09
# Last Modified: 2018-11-22 16:48:09
#          Link: https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
#   Description: ---
#     Given a string, find the length of the longest substring without repeating characters.
#     
#     Example 1:
#     
#     Input: "abcabcbb"
#     Output: 3
#     Explanation: The answer is "abc", with the length of 3.
#     Example 2:
#     
#     Input: "bbbbb"
#     Output: 1
#     Explanation: The answer is "b", with the length of 1.
#     Example 3:
#     
#     Input: "pwwkew"
#     Output: 3
#     Explanation: The answer is "wke", with the length of 3.
#                  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
***********************************************/
#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

// It is so slow !!!
// Better than 1.82% !
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//        int sum = 0;  
// 
//        for(int i=0;i<(int)s.size();i++){
//            map<char,int> m;
//            int temp = 0;
//            for(int j=i;j<(int)s.size();j++){
//                if(m.find(s[j]) != m.end()){
//                   break;
//                } 
//                temp++;
//                m[s[j]] = 1;
//             }  
//                sum = max(sum,temp);
//        }
//        
//        return sum;
//     }
//     
// };

// So clever
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v (256,-1);
        int start = -1;
        int ans = 0;
        for(int i=0;i<(int)s.size();i++){
            //Jump to the last index.
            if(v[s[i]] > start){
                start = v[s[i]];
            } 
            v[s[i]] = i;
            ans = max(ans,i-start);
        }
        return ans;
    }
};

int main(){
    Solution ss;
    //string test="abcabcbb";
    //string test=" ";
    string test="dvdf";
    //string test="bbbbb";
    //string test="pwwkew";
    cout<<ss.lengthOfLongestSubstring(test);
}











