/***********************************************
#
#      Filename: 343IntegerBreak.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 13:34:56
# Last Modified: 2018-11-17 13:34:56
#          Link: 
#   Description: ---
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.


***********************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // As the hint said, checking the n with ranging from 7 to 10 to discover the regularities.
    // n = 7,    3*4 = 12
    // n = 8,  3*3*2 = 18
    // n = 9,  3*3*3 = 27
    // n = 10, 3*3*4 = 36
    // n = 11, 3*3*3*2 = 54
    //
    // we can see we can break the number by 3 if it is greater than 4;
    //

    int integerBreak(int n) {
        if(n==2){ return 1;}
        if(n==3){ return 2;}
        int result = 1;
        while(n>4){
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};


int main(){
    Solution ss;
    vector<int> test;
    test.push_back(2);
    test.push_back(10);

    for(int n:test){
        cout<<n<<":\t"<<ss.integerBreak(n)<<endl;
    }

}






