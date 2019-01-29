/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/add-binary/
#         title: 67	Add Binary
#   Description: ---
#	  Given two binary strings, return their sum (also a binary string).
#	  
#	  The input strings are both non-empty and contains only characters 1 or 0.
#	  
#	  Example 1:
#	  
#	  Input: a = "11", b = "1"
#	  Output: "100"
#	  Example 2:
#	  
#	  Input: a = "1010", b = "1011"
#	  Output: "10101"
***********************************************/
#include <iostream>
#include <string>

using namespace std;

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int aIdx=a.size()-1;
//         int bIdx=b.size()-1;
//         int carry=0;
//         string s="";
//         while(aIdx>=0 || bIdx>=0 || carry)
//         {
//             carry+= aIdx>=0 ? a[aIdx--]-'0' : 0;
//             carry+= bIdx>=0 ? b[bIdx--]-'0' : 0;
//             s=char((carry%2)+'0')+s;
//             carry = carry/2;
//         }
//         return s;
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string & longStr = a.size() > b.size()?a:b;
        string & shortStr = a.size() <= b.size()?a:b;
        string res ="";
        for(int i=longStr.size()-1,j=shortStr.size()-1;i>=0;i--,j--){
        	int temp;
        	if(j>=0){      		
        		temp = longStr[i] -'0' + shortStr[j]-'0' + carry;
        	}
        	else{
        		temp = longStr[i] -'0' + + carry; 		
        	}
        	carry = temp/2;
        	res = char(temp%2+'0')+res;
        }
        if(carry){ res = '1'+res;}
        return res;
    }
};

int main(){
	Solution ss;
	string a = "1010111";
	string b = "1011";
	cout << ss.addBinary(a,b)<<endl;
}