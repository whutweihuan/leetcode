/***********************************************
#
#      Filename: 5LongestPalindromicSubstring.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 18:03:55
# Last Modified: 2018-11-22 18:03:55
#          Link: https://oj.leetcode.com/problems/longest-palindromic-substring/
#   Description: ---
#     Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
#     
#     Example 1:
#     
#     Input: "babad"
#     Output: "bab"
#     Note: "aba" is also a valid answer.
#     Example 2:
#     
#     Input: "cbbd"
#     Output: "bb"
***********************************************/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;


// class Solution {
//     bool valid(string s){
//         int low = 0, high = s.size()-1;
//         while(low<high){
//             if(s[low] != s[high]){
//                 return false;
//             }
//             low++,high--;
//         }
//         return true;
//     }
// public:
//     string longestPalindrome(string s) {
//         if(s.size()==0){ return "";}
//         map<int,string> m;
//        for(int i=0;i<(int)s.size();i++){
//             for(int j=1;j<=(int)s.size()-i;j++){
//                 string sub = s.substr(i,j);     
//                 cout<<sub<<endl;
//                 if(valid(sub)){
//                     //cout<<sub.size()<<endl;;
//                    m[sub.size()] = sub; 
//                 }
//             }
//        } 
//        return ( --m.end()  )->second;
//     }
// };


//Good papers, https://segmentfault.com/a/1190000003914228
class Solution {
public:
    string longestPalindrome(string s) {
        string t ="#";
        for(int i=0;i<(int)s.size();i++){
            t+=s[i];
            t+= "#";
        }
        //cout<<t<<endl;
        int idx = 0;
        vector<int> RL (t.size(),0);
        int maxRight = 0;
        int pos = 0;
        int MaxLen = 0;
        for(int i=0;i<(int)t.size();i++){
            if(i<maxRight){
                RL[i] = min(RL[2*pos -i],maxRight-i);
            }
            else{
                RL[i] = 1;
            }
            while( i-RL[i]>=0 && i+RL[i]<(int)t.size() && t[i-RL[i]] == t[i+RL[i]]){
                RL[i] +=1;
            }
            if (RL[i]+i-1 > maxRight){
                maxRight = RL[i] +i-1;
                pos = i;
            }
            MaxLen = max(MaxLen,RL[i]);
            if(MaxLen == RL[i]){idx =i;}
        }

        //The Maxlen -1 is the length of longest of substring .
        //Now we need to get the string.
        string res = "";
        for(int i= idx -(MaxLen-1);i<=idx+MaxLen -1;i++){
            res += t[i]; 
        }
        //cout<<res<<endl;
        string res2 ="";
        for(int i=0;i<(int)res.size();i++){
            if(res[i]!='#'){
                res2 += res[i];
            }
        }
        
        return res2;
    }
};


int main(){
    Solution ss;
    string s1 = "babab";
    string s2 = "cbbd";
    string s3 = "a";

    cout<<ss.longestPalindrome(s3);
}









