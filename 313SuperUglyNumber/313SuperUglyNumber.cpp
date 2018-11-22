/***********************************************
#
#      Filename: 313SuperUglyNumber.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-21 19:26:09
# Last Modified: 2018-11-21 19:26:09
#          Link: https://leetcode.com/problems/super-ugly-number/
#   Description: ---
#     Write a program to find the nth super ugly number.
#     
#     Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
#     
#     Example:
#     
#     Input: n = 12, primes = [2,7,13,19]
#     Output: 32 
#     Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
#                  super ugly numbers given primes = [2,7,13,19] of size 4.
#     Note:
#     
#     1 is a super ugly number for any given primes.
#     The given numbers in primes are in ascending order.
#     0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
#     The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
***********************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// this coment from https://github.com/haoel/leetcode/blob/master/algorithms/cpp/superUglyNumber/SuperUglyNumber.cpp
// It is intersting.
// ********************************************************************************
// As the solution we have for the ugly number II problem
//
//    int nthUglyNumber(int n) {
//
//        int i=0, j=0, k=0;
//        vector<int> ugly(1,1);
//
//        while(ugly.size() < n){
//            int next = min(ugly[i]*2, ugly[j]*3, ugly[k]*5);
//            if (next == ugly[i]*2) i++;
//            if (next == ugly[j]*3) j++;
//            if (next == ugly[k]*5) k++;
//            ugly.push_back(next);
//        }
//        return ugly.back();
//    }
//
// The logic of solution is exacly same for both., except that instead of 3 numbers you have k numbers to consider.
//
//
//**********************************************************************

#include<climits>
class Solution {
public:
    //only contain prime number
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       int len = (int)primes.size();
       vector<int> pos(len,0);
       vector<int> result {1};
       while((int)result.size() < n){
            int _min =  INT_MAX;
            for(int i=0;i<len;i++){
                _min = min(_min,primes[i]*result[pos[i]]); 
            }
            for(int i=0;i<len;i++){
                if(_min == result[pos[i]] * primes[i]){
                   pos[i]++; 
                }
            }
            result.push_back(_min);
       }
       return result.back();
    }
};

int main(){
    Solution ss;
    int n = 12;
    vector<int> primes { 2,7,13,19 };
    cout<<ss.nthSuperUglyNumber(n,primes);
}



























