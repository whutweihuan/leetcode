/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-27 
# Last Modified: 2018-11-27 
#          Link: https://leetcode.com/problems/integer-to-roman/
#         title: 12 Integer to Roman
#   Description: ---
#     Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
#     
#     Symbol       Value
#     I             1
#     V             5
#     X             10
#     L             50
#     C             100
#     D             500
#     M             1000
#     For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
#     
#     Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
#     
#     I can be placed before V (5) and X (10) to make 4 and 9. 
#     X can be placed before L (50) and C (100) to make 40 and 90. 
#     C can be placed before D (500) and M (1000) to make 400 and 900.
#     Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
#     
#     Example 1:
#     
#     Input: 3
#     Output: "III"
#     Example 2:
#     
#     Input: 4
#     Output: "IV"
#     Example 3:
#     
#     Input: 9
#     Output: "IX"
#     Example 4:
#     
#     Input: 58
#     Output: "LVIII"
#     Explanation: L = 50, V = 5, III = 3.
#     Example 5:
#     
#     Input: 1994
#     Output: "MCMXCIV"
#     Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
#
***********************************************/
#include<iostream>
#include<vector>
#include<map>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> v = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        std::vector<string> ch = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
       
        string res = "";
        int len = v.size();
        
        for(int i=0;num!=0;i++){
            while(num >= v[i]){
                int count = num /v[i] ;
                num -= count*v[i];
                while(count){
                    res += ch[i];
                    count--;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution ss;
    cout<<ss.intToRoman(9)<<endl;
    // cout<<ss.intToRoman(900)<<endl;
    // cout<<ss.intToRoman(10)<<endl;
}