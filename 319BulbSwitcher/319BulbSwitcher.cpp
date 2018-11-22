/***********************************************
#
#      Filename: 319BulbSwitcher.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-20 18:30:41
# Last Modified: 2018-11-20 18:30:41
#          Link: 
#   Description: ---
# There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
# 
# Example:
# 
# Input: 3
# Output: 1
# Explanation:
# At first, the three bulbs are [off, off, off].
# After first round, the three bulbs are [on, on, on].
# After second round, the three bulbs are [on, off, on].
# After third round, the three bulbs are [on, off, off].`
# So you should return 1, because there is only one bulb is on.

//  two click equals no clik
//  So we need find numbers that can be decomposed ,can the number of factors is Odd
//  finally we need to  find the squred number, it only had Odd facors;
//  

*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {

public:
    int bulbSwitch(int n) {
       return sqrt(n); 
    }
};

int main(){

    
}









































