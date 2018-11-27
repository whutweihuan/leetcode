/***********************************************
#
#      Filename: 336PalindromePairs.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 17:05:06
# Last Modified: 2018-11-17 17:05:06
#          Link: https://leetcode.com/problems/palindrome-pairs/
#   Description: ---
#   Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
#   
#   Example 1:
#   
#   Input: ["abcd","dcba","lls","s","sssll"]
#   Output: [[0,1],[1,0],[3,2],[2,4]]
#   Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
#   Example 2:
#   
#   Input: ["bat","tab","cat"]
#   Output: [[0,1],[1,0]]
#   Explanation: The palindromes are ["battab","tabbat"]
***********************************************/
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<set>
# include<vector>

using namespace std;

//the solution is so low
/*************************************************
//class Solution {
//    private:
//        bool isPalindrome(string & s){
//            int lo =0,hi = s.size()-1;
//            while(lo<hi){
//                if(s[lo] != s[hi]){
//                    return false;
//                }
//                hi--,lo++;
//            }
//            return true;
//        }
//
//public:
//    vector<vector<int>> palindromePairs(vector<string>& words) {
//        vector< vector<int> > res;
//        for(size_t i=0;i<words.size();i++){
//            for(size_t j = 0;j<words.size();j++){
//                if (i==j){continue;}
//                string t = words[i] + words[j];
//                if(isPalindrome(t)){
//                    res.push_back(vector<int>{i,j});
//                } 
//            }
//        }
//        return res;
//    }
//};
***********************************************/


////good example
//class Solution {
//public:
//    bool isPalindrome(string& str) {
//        int left = 0, right = str.size() - 1;
//        while( left < right) {
//            if (str[left++] != str[right--]) return false;
//        }
//        return true;
//    }
//    vector<vector<int>> palindromePairs(vector<string>& words) {
//        unordered_map<string, int> dict;
//        for(int i=0; i<words.size(); i++){
//            string w = words[i];
//            reverse(w.begin(), w.end());
//            dict[w] = i;
//        }
//        
//        
//        vector<vector<int>> result;
//        
//        //egde case: deal with empty string 
//        if ( dict.find("") != dict.end() ) {
//            for(int i=0; i<words.size(); i++) {
//                if ( isPalindrome(words[i]) && dict[""] != i ) {
//                    result.push_back( { dict[""], i } );
//                }
//            }
//        }
//        
//        for(int i=0; i<words.size(); i++) {
//            for (int j=0; j<words[i].size(); j++) {
//                //split the word to 2 parts
//                string left = words[i].substr(0, j);
//                string right = words[i].substr(j, words[i].size() - j);
//                
//                // if the `left` is found, which means there is a words has reversed sequence with it.
//                // then we can check the `right` part is Palindrome or not. 
//                if ( dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i ) {
//                    result.push_back( { i, dict[left] } );
//                }
//                
//                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i ) {
//                    result.push_back( { dict[right], i } );
//                }
//            }
//
//        }
//        
//        return result;
//    }
//    
//};


// This way is stupid also ,especially for ""
class Solution {
    private:
        bool isPalindrome(string & s){
            if(s.size() ==0) return false;
            int lo =0,hi = s.size()-1;
            while(lo<hi){
                if(s[lo] != s[hi]){
                    return false;
                }
                hi--,lo++;
            }
            return true;
        }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int> m;
        set<int> st;
        vector<vector<int>>  res;

        for(int i=0;i<words.size();i++){
            m[words[i]] = i;
            st.insert(words[i].size());
        } 
        for(int i=0;i<words.size();i++){
           int len = words[i].size();
           string str = words[i];
           for(auto iter = st.begin();iter!=st.end() && *iter <= len ;iter++){
                string s1 = str.substr(0,len - *iter); 
                string s2 = str.substr( len- *iter, *iter); 
                if(isPalindrome(s1)) {
                    std::reverse(s2.begin(),s2.end());
                    if(m.find(s2) != m.end()){
                        if( i != m[s2]){
                                res.push_back(vector<int>{m[s2],i});
                                cout<<1<<endl;
                        }
                    }
                }
           }

           for(auto iter = st.begin();iter!=st.end() && *iter < len ;iter++){
                string s1 = str.substr(*iter,len - *iter); 
                string s2 = str.substr(0,*iter); 
                if(isPalindrome(s1)) {
                    std::reverse(s2.begin(),s2.end());
                    if(m.find(s2) != m.end()){
                        if(i != m[s2]){
                               res.push_back(vector<int>{i,m[s2]});
                               cout<<2<<endl;
                        }
                    }
                }
           }
        }
       return res; 

    }
};



int main(){
    Solution ss;
    vector<string> test ={"a",""};
    //vector<string> test ={"abcd","dcba","lls","s","sssll",""};
    //vector<string> test ={"lls","s"};
    for(vector<int> v: ss.palindromePairs(test)){
        cout<<"[ ";
        for(auto c :v){
            cout<<c<<"\t";
        }
        cout<<"]\t";
    }
    getchar();
}


















