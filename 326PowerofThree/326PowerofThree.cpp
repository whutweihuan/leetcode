/***********************************************
#
#      Filename: 326PowerofThree.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-20 14:57:14
# Last Modified: 2018-11-20 14:57:14
#          Link: https://leetcode.com/problems/power-of-three/
#   Description: ---
#         you need to write a function to determin a number is power of three;
***********************************************/

#include<iostream>
#include<cmath>

using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n)/log10(3);
        return res == int(res);
    }
};

int main(){
    Solution ss;
    cout<<  ss.isPowerOfThree(9);
}

