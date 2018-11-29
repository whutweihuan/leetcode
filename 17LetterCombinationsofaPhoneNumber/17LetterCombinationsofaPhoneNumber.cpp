/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#         title: 17 letter combinations of a phone number
#   Description: ---

#	  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
#	  
#	  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
#	  
#	  //手机九键
#	  
#	  Example:
#	  
#	  Input: "23"
#	  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#
***********************************************/
#include<iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
	// This places can replace the char to string
	// vector<string> is better.
	// careful the first key of map is not digital,it is charcter.
	map<char,vector<char>> m{
        	{'2',{'a','b','c'}},
        	{'3',{'d','e','f'}},
        	{'4',{'g','h','i'}},
        	{'5',{'j','k','l'}},
        	{'6',{'m','n','o'}},
        	{'7',{'p','q','r','s'}},
        	{'8',{'t','u','v'}},
        	{'9',{'w','x','y','z'}}
        };
        vector<string> result;

public:
    vector<string> letterCombinations(string digits) {

        dfs(digits,"");

        return result;
    }


    void dfs(string s,string ans){
    	if(s.size() == 1){
    		for(int i=0;i< m[s[0]].size();i++){
    			result.push_back(ans+m[s[0]][i]);
    		}
    		return;
    	}
    	for(int i=0;i<m[s[0]].size();i++){

    		dfs(s.substr(1),ans+m[s[0]][i]);
    	}
    	return;
    }
};

int main(){
	Solution ss;
	string digits = "23";
	for(string s:ss.letterCombinations(digits)){
		cout<<s<<"\t";
	}
}