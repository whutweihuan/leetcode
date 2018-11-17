/***********************************************
#
#      Filename: 371SumofTwoIntegers.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-16 23:10:29
# Last Modified: 2018-11-16 23:10:29
#         Link : 2018-11-16 23:10:29
#   Description: ---
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
***********************************************/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        double a = sqrt(num);    
        int b = int(a);
        return a==b;

    }
};

int main(){
   Solution ss;
    cout<<"16:\t"<<ss.isPerfectSquare(16)<<endl;
    cout<<"17:\t"<<ss.isPerfectSquare(17)<<endl;

    getchar();
}










