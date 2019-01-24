/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-24 
# Last Modified: 2019-1-24
#          Link: https://leetcode.com/problems/multiply-strings/
#         title: 43	Multiply Strings
#   Description: ---
#	  Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
#	  
#	  Example 1:
#	  
#	  Input: num1 = "2", num2 = "3"
#	  Output: "6"
#	  Example 2:
#	  
#	  Input: num1 = "123", num2 = "456"
#	  Output: "56088"
#	  Note:
#	  
#	  The length of both num1 and num2 is < 110.
#	  Both num1 and num2 contain only digits 0-9.
#	  Both num1 and num2 do not contain any leading zero, except the number 0 itself.
#	  You must not use any built-in BigInteger library or convert the inputs to integer directly.
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 100 ms
// class Solution {
// public:
//     string multiply(string num1, string num2) {
//     	if( num1== "0" || num2 == "0" ) { return "0" ;}
//     	string result = "0";//保存结果

//     	// Use each number of num1 to calculate the string num2
//     	for(int i=num1.size()-1;i>=0;i--){
//     		string multOne = multiplyOne(num2,num1[i]-'0',num1.size()-1 -i);
//     		cout << "multOne\t" << multOne <<endl;
//     		result = add(result,multOne);
//     		cout << "add\t" << result <<endl;
//     	}
        	
//         return result;
    	
//     }

//     // Add string num1 and num2;
//     string add(string num1, string num2) {
//     	int carry = 0;
//     	string result ="";
//     	int i=num1.size()-1 ,j = num2.size()-1 ;
//     	while( i>=0 && j>=0){
//     		int tempAdd = num1[i]-'0' + num2[j] -'0';
//     		tempAdd += carry;
//     		carry = tempAdd / 10;
//     		result = to_string(tempAdd %10) +result;
//     		i--,j--;
//     	}
    	
//     	while(j>=0){
//     		int temp = num2[j] -'0' + carry;
//     		carry = temp /10;
//     		result = to_string(temp%10) + result;
//     		j--;
//     	}

//     	while(i>=0){
//     		int temp = num1[i] -'0' + carry;
//     		carry = temp /10;
//     		result = to_string(temp%10) + result;
//     		i--;
//     	}
//     	if(carry){ result = to_string(carry) + result; }
//     	return result;
//     }

//     // Get result when calculate the string num and single intger n
//     string multiplyOne(string num,int n,int count){
//     	int carry = 0;
//     	string result = "";
//     	for(int i= num.size()-1;i>=0;i--){
//     		int multiTemp = n * (num[i]-'0') + carry;
//     		carry = multiTemp /10;
//     		result = to_string(multiTemp%10)+result;
//     	}
//     	if(carry){ result = to_string(carry) + result; }
//     	while(count > 0) {
//     		result += "0";
//     		count--;
//     	}
//     	return result;
//     }
// };



// 4ms
class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(),'0');
        // cout << result <<endl;
        reverse(begin(num1),end(num1));
        reverse(begin(num2),end(num2));
        
        int carry = 0;
        for(int i = 0; i < num1.size(); ++i){
            for(int j = 0; j < num2.size(); ++j){
                int temp = (result[i + j] - '0') + carry + ((num1[i] - '0')*(num2[j] - '0'));
                result[i + j] = (temp % 10) + '0';
                carry = (temp / 10);
            }
            
            if(carry){
                int temp = (result[i + num2.size()] - '0') + carry;
                result[i+ num2.size()] = (temp%10) + '0';
                carry = temp/10;
            }
        }
        
        if(carry){
            result[num1.size() + num2.size() - 1] += ((result[num1.size() + num2.size() - 1] - '0') + carry) + '0';
        }
        
        reverse(begin(result),end(result));
        int zi = 0;
        for(;zi != result.size() && result[zi] == '0'; zi++);
        if(zi == result.size()){
            return "0";
        }
        
        return result.substr(zi);
    }
};






int main(){
	string num1 = "999";
	string num2 = "999";

	Solution ss;
	// cout << ss.add("8991","89910")<<endl;
	cout << ss.multiply(num1,num2) <<endl;
	// cout << ss.multiplyOne("123",4);
	// cout<<ss.multiply(num1,num2)<<endl;
}
