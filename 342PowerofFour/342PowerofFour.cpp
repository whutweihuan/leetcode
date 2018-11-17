/***********************************************
#
#      Filename: 342PowerofFour.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 14:16:25
# Last Modified: 2018-11-17 14:16:25
#          Link: 
#   Description: ---
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
***********************************************/

#include<vector>
#include<iostream>
#include<algorithm>

using  namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
       vector<int> nums;
       int t = 1;
       nums.push_back(1);
       for(int i=0;i<15;i++){
         t = t<<2;
         nums.push_back(t);
       }
       if(find(nums.begin(),nums.end(),num) != nums.end()){
            return true;
        }
        return false;
    }
};

/*
 class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        if(num&(num-1))
            return false;
        //0101 0101 0101 0101 0101 0101 0101 0101
        if(num&0x55555555)
            return true;
        return false;
    }
};
*/

/*
 class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        if ((num >=0) && (num < 4)) return false;
        else if (num < 0) return false;
        while (num %4 ==0) {
            num /= 4;
        }
        
        return num == 1;
    }
};
*/

int main(){
    Solution ss;
    vector<int> test;
    test.push_back(16);
    test.push_back(20);
    test.push_back(28);
    test.push_back(22);
    test.push_back(23);
    test.push_back(25);
    test.push_back(-2147483648);
    for(auto n:test){
        cout<<n<<":\t"<<ss.isPowerOfFour(n)<<endl;
    }
}


























