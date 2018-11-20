/***********************************************
#
#      filename: 322coinchange.cpp
#
#        author: weihuan -whutweihuan@163.com
#        create: 2018-11-20 16:34:01
# last modified: 2018-11-20 16:34:01
#          link: https://leetcode.com/problems/coin-change/
#   description: ---
#    you are given coins of different denominations and a total amount of money amount. write a function to compute the fewest number of coins that you need to make up that amount. if that amount of money cannot be made up by any combination of the coins, return -1.
#    
#    example 1:
#    
#    input: coins = [1, 2, 5], amount = 11
#    output: 3
#    explanation: 11 = 5 + 5 + 1
#    example 2:
#    
#    input: coins = [2], amount = 3
#    output: -1
#    
***********************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class solution {
//public:
//    // gready way
//    // it can not simply like gready
//    // 
//    int coinchange(vector<int>& coins, int amount) {
//        vector<int> dp (amount+1,amount+1);
//        dp[0] = 0;
//        for(int i=1; i <= amount; i++){
//            for(int j=0;j<coins.size();j++){
//                if(i >= coins[j]){
//                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
//                }
//            }
//        }
//        if (dp[amount] == amount+1) { return -1;};
//        return dp[amount];
//    }
//};

class solution {
public:
    // gready way
    // it can not simply like gready
    // 
    int coinchange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1,amount+1);
        dp[0] = 0;

        for(int i=0; i < coins.size(); i++){
            for(int j= coins[i] ;j<= amount;j++){
                dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if (dp[amount] == amount+1) { return -1;};
        return dp[amount];
    }
};

int main(){
    solution ss;
    vector<int> coins {186,419,83,408};
    int amount = 6249;
    cout << ss.coinchange(coins,amount);
}






















