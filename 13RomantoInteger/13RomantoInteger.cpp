/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-27 
# Last Modified: 2018-11-27 
#          Link: https://leetcode.com/problems/roman-to-integer/
#         title: 13 Roman to Integer
#   Description: ---
#	   Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
#	   
#	   Symbol       Value
#	   I             1
#	   V             5
#	   X             10
#	   L             50
#	   C             100
#	   D             500
#	   M             1000
#	   For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
#	   
#	   Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
#	   
#	   I can be placed before V (5) and X (10) to make 4 and 9. 
#	   X can be placed before L (50) and C (100) to make 40 and 90. 
#	   C can be placed before D (500) and M (1000) to make 400 and 900.
#	   Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
#	   
#	   Example 1:
#	   
#	   Input: "III"
#	   Output: 3
#	   Example 2:
#	   
#	   Input: "IV"
#	   Output: 4
#	   Example 3:
#	   
#	   Input: "IX"
#	   Output: 9
#	   Example 4:
#	   
#	   Input: "LVIII"
#	   Output: 58
#	   Explanation: L = 50, V= 5, III = 3.
#	   Example 5:
#	   
#	   Input: "MCMXCIV"
#	   Output: 1994
#	   Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        std::vector<int> v = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        std::vector<string> ch = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        map<string,int> m;
        for(int i=0;i<v.size();i++){
        	m[ch[i]] = v[i];
        }
        int res = 0;

        for(int i=0;i<s.size();i++){
        	if(m.find(s.substr(i,2)) != m.end()){
        		// cout<<i<<endl;
        		// cout<<s.substr(i,2)<<endl;
        		// cout<<"Yes"<<endl;
        		res += m[s.substr(i,2)];
        		i++;
        	}
        	else{
        		// cout<<s.substr(i,1)<<endl;
        		res += m[s.substr(i,1)];
        	}
        }
        return res;
    }
};

int main(){
	Solution ss;
	cout<<ss.romanToInt("IX")<<endl;
	cout<<ss.romanToInt("LVIII")<<endl;
}