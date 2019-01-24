/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-24 
# Last Modified: 2019-1-24
#          Link: https://leetcode.com/problems/wildcard-matching/
#         title: 44	Wildcard Matching
#   Description: ---
#		Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
#		
#		'?' Matches any single character.
#		'*' Matches any sequence of characters (including the empty sequence).
#		The matching should cover the entire input string (not partial).
#		
#		Note:
#		
#		s could be empty and contains only lowercase letters a-z.
#		p could be empty and contains only lowercase letters a-z, and characters like ? or *.
#		Example 1:
#		
#		Input:
#		s = "aa"
#		p = "a"
#		Output: false
#		Explanation: "a" does not match the entire string "aa".
#		Example 2:
#		
#		Input:
#		s = "aa"
#		p = "*"
#		Output: true
#		Explanation: '*' matches any sequence.
#		Example 3:
#		
#		Input:
#		s = "cb"
#		p = "?a"
#		Output: false
#		Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
#		Example 4:
#		
#		Input:
#		s = "adceb"
#		p = "*a*b"
#		Output: true
#		Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
#		Example 5:
#		
#		Input:
#		s = "acdcb"
#		p = "a*c?b"
#		Output: false
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {

// public:


//     bool isMatch(string s, string p){
//     	 if (p.empty())    return s.empty();
//          if (s.empty()){
//          	for(int i=0;i<p.size();i++){
//          		if(p[i]!= '*') { return false;}
//          	}
//          	return true;
//          }
//          cout << p[0]<<endl;
//  		 if(p[0] == '*'){
//  		 	return isMatch(s,p.substr(1)) ||  isMatch(s.substr(1),p);
//  		 }
//  		 else if(p[0] == '?' || p[0] == s[0]){
//  		 	return isMatch(s.substr(1),p.substr(1));
//  		 }
//          else  {
//          	return false;
//          }	   

//     }
// };

class Solution {

public:
    bool isMatch(string s, string p){
    	int sIdxLast = -1, pIdxLast= -1;
    	int sIdx=0,pIdx=0;
    	while(sIdx != s.size()){
    		//Skip this * 
    		if(p[pIdx] == '*'){
    			pIdx++;
    			if(pIdx==p.size()){ return true;}
    			// Store the index 
    			// So we can back
    			sIdxLast = sIdx;
    			pIdxLast = pIdx;
    		}
    		else if(p[pIdx] == '?' || p[pIdx] == s[sIdx]){
    			pIdx++;sIdx++;
    		}
    		else if(sIdxLast != -1){
    			// back
    			sIdx = ++sIdxLast;
    			pIdx = pIdxLast;
    		}
    		else{
    			return false;
    		}
    	}
    	while(p[pIdx]== '*' ){pIdx++;}
    	return pIdx == p.size();
    }
};



int test(string s,string p,bool ans){
	Solution ss;
	cout << s <<"  MATCH  "<< p <<"\t"; 
	if(ss.isMatch(s,p) == ans){
		cout<< "Yes"<<endl;
	}
	else{
		cout << "No" <<endl;
	}
}


int main(){
	Solution ss;

	test("adceb","*a*b",1);

	test("acdcb","a*c?b",0);
	test("aa","*",1);
	test("abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab","*aabb***aa**a******aa*",1);
	test("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba","*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*",1);
	test("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb","**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb",1);
	test("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba","a*******b",1);
}
