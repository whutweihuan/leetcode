/***********************************************
#
#      Filename: 7ReverseInteger.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 20:34:35
# Last Modified: 2018-11-22 20:34:35
#          Link:  https://leetcode.com/problems/reverse-integer/
#   Description: ---
#     Given a 32-bit signed integer, reverse digits of an integer.
#     
#     Example 1:
#     
#     Input: 123
#     Output: 321
#     Example 2:
#     
#     Input: -123
#     Output: -321
#     Example 3:
#     
#     Input: 120
#     Output: 21
#     Note:
#     Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 ***********************************************/
#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
       long long sum =0;
       while(x){
            sum = sum *10 + (x %10);
            x/=10;
       }
       if (sum > INT_MAX || sum < INT_MIN) {return 0;}
       return sum;
    }
};

int main(){
    //int x1 = 123;
    //int x2= -123;
    //int x3= 1534236469;
    int x4= -2147483648;
    Solution ss;
    cout<<ss.reverse(x4)<<endl;
}















