/***********************************************
#
#      Filename: 338CountingBits.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 16:00:01
# Last Modified: 2018-11-17 16:00:01
#          Link: https://leetcode.com/problems/counting-bits/
#   Description: ---
#   Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
#   
#   Example 1:
#   
#   Input: 2
#   Output: [0,1,1]
#   Example 2:
#   
#   Input: 5
#   Output: [0,1,1,2,1,2]
#   Follow up:
#   
#   It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
#   Space complexity should be O(n).
#   Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
***********************************************/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int counts(int n){
        int sum = 0 ;
        while(n){
            sum++;
            n = n&(n-1);
        }
        return sum;
    }
public:
    vector<int> countBits(int num) {
       vector<int> res;
       for(int i=0;i<=num;i++){
            res.push_back(counts(i)); 
       }
       return res;
    }
};

/*
*  class Solution {
*   public:
*    vector<int> countBits(int num) {
*        vector<int> ans;
*        ans.push_back(0);
*        for(int i = 1; i <= num; ++i) {
*            ans.push_back(ans[i >> 1] + (i & 1));
*        }
*        return ans;
*    }
*};
**/


int main(){
    Solution ss;
    vector<int> test;
    test.push_back(2);
    test.push_back(5);
    for(int n : test){
        cout<<n<<":\t";
        for(int bit : ss.countBits(n)){
            cout<<bit<<"\t";
        }
        cout<<endl;
    }
    

}

















