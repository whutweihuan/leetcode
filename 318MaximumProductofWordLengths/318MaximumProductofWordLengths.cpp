/***********************************************
#
#      Filename: 318MaximumProductofWordLengths.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-20 18:57:42
# Last Modified: 2018-11-20 18:57:42
#          Link: https://leetcode.com/problems/maximum-product-of-word-lengths/
#   Description: ---
#     Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
#     
#     Example 1:
#     
#     Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
#     Output: 16
#     Explanation: The two words can be "abcw", "xtfn".
#     Example 2:
#     
#     Input: ["a","ab","abc","d","cd","bcd","abcd"]
#     Output: 4
#     Explanation: The two words can be "ab", "cd".
#     Example 3:
#     
#     Input: ["a","aa","aaa","aaaa"]
#     Output: 0
#     Explanation: No such pair of words.
***********************************************/
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
       map<int,int> m;

        for(auto w :words){
            int mask = 0;
            for(auto c:w){
               mask = mask | 1 <<( c -'a'); 
            }
            if(m.find(mask) == m.end() || m[mask] < w.size()){
                m[mask] = w.size();
            }
        }
        
        int imax = 0;
        for(auto a :m){
            for(auto b:m){
                if( (a.first & b.first)) {
                    continue;
                } 
                imax = std::max(imax,a.second * b.second); 
            }
        }
        return imax;
    }
};

int main(){
    Solution ss;
    //vector<string> test {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> test{"aa","aa"};
    cout<<ss.maxProduct(test);

}

























