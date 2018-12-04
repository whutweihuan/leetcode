/***********************************************
#
#      Filename: 30SubstringwithConcatenationofAllWords.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-12-04 16:24:01
# Last Modified: 2018-12-04 16:24:01
#          Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/ 
#   Description: ---
#     You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
#     
#     Example 1:
#     
#     Input:
#       s = "barfoothefoobarman",
#       words = ["foo","bar"]
#     Output: [0,9]
#     Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
#     The output order does not matter, returning [9,0] is fine too.
#     Example 2:
#     
#     Input:
#       s = "wordgoodstudentgoodword",
#       words = ["word","student"]
#     Output: []
***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;


//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//       if(s == "") {return vector<int>{};}
//       if(words.size() == 0){ return vector<int>{};};
//       map<string,int> m1;
//       vector<int> result;
//       for(string s : words){
//          m1[s]++;
//       }
//       int len = (int) words[0].size();
//       for(int i=0;i<(int)s.size();i++){
//            int left = i;
//            int cnt = words.size();
//            map<string,int> m = m1;
//            int j = 0;
//            for( j=0;j<cnt;j++){
//                if(m.find(s.substr(left,len)) != m.end() && m[s.substr(left,len)] > 0){
//                   m[s.substr(left,len)]--;
//                   left += len;
//                }
//                else{
//                    break;
//                }
//            }
//            if(j==cnt) { result.push_back(i); }
//       }
//       return result;
//    }
//};




// brute force   m =len(words), k = eachwordsize
// Onmkm
// mk
// for mk substring,  check a set   satisified then output.
// scan  0 k 2k 3k first
// then  1 k+1 2k+1   move the window k step to mnimize
// eaxtly once:  map[word]=1  need to be one   existed and == 0 used
class Solution {
public:
  vector<int> findSubstring(const string s, const vector<string>& words) {
    vector<int> res;
    if (words.empty()) return res;

    unordered_map<string, int> dict;   // bool
    for(const auto& w : words) ++dict[w];
    int m = words.size();
    int k = words[0].size();
    int mk = m*k;

    //why here is k loop ?
    for(int i = 0; i < k; ++i) {
      int curr = i;
      int end = curr + mk;
      unordered_map<string, int> dict_rest(dict);
      int match = dict_rest.size(); // == 0 output ok
      while (end <= (int)s.size()) { // use the long s to match 

        if (curr < end){  // add only
          auto w = s.substr(curr, k);
          auto search = dict_rest.find(w);
          if (search != dict_rest.end() /* && search->second > 0*/) {
            --search->second;
            if (search->second == 0) --match;
            else if (search->second == -1) ++match;
          }
          curr += k;
        } else { // check and delete
          if (match == 0) res.push_back(end-mk);
          //What is end - mk means ? 
          auto w = s.substr(end-mk, k);
          auto search = dict_rest.find(w);
          if (search != dict_rest.end() /*&& search->second < dict[w]*/) {

            ++search->second;
            if(search->second == 0) --match;
            else if (search->second == 1) ++match;
          }
          end+=k;
        }

      }
    }
    return res;

  }
};

int main(){
    Solution ss;
    string s = "barfoothefoobarman";
    vector<string> words{"foo","bar" };
    //string s = "";
    //vector<string> words{};
    for(int num : ss.findSubstring(s,words)){
        cout<<num<<"\t";
    }
    
}


