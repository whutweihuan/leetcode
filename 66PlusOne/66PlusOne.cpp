/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/plus-one/
#         title: 66	Plus One
#   Description: ---
#	  Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
#	  
#	  The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
#	  
#	  You may assume the integer does not contain any leading zero, except the number 0 itself.
#	  
#	  Example 1:
#	  
#	  Input: [1,2,3]
#	  Output: [1,2,4]
#	  Explanation: The array represents the integer 123.
#	  Example 2:
#	  
#	  Input: [4,3,2,1]
#	  Output: [4,3,2,2]
#	  Explanation: The array represents the integer 4321.
***********************************************/
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
        	if(!carry){break;}
        	int temp = digits[i] + carry ;
        	carry = temp /10;
        	digits[i] = temp%10;
        	printVector(digits);
        }
        if(carry){digits.insert(digits.begin(),carry);}
        return digits;
    }
};

int main(int argc, char const *argv[])
{
	Solution ss;
	vector<int> digits {9,9,9};
	vector<int> res = ss.plusOne(digits);
	printVector(res);
	return 0;
}