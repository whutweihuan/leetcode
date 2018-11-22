/***********************************************
#
#      Filename: 312BurstBalloons.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-21 20:37:57
# Last Modified: 2018-11-21 20:37:57
#          Link: https://leetcode.com/problems/burst-balloons/
#   Description: ---
#     Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
#     
#     Find the maximum coins you can collect by bursting the balloons wisely.
#     
#     Note:
#     
#     You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
#     0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
#     Example:
#     
#     Input: [3,1,5,8]
#     Output: 167
#     Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
***********************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

// the DFS ways .
// It can not pass the exam for its lowly speed.
//class Solution {
//    map <vector<int>,int> m;
 // public:
//      int dfs(vector<int> nums){
//          int ans = 0;
//          if (m.find(nums) != m.end()){
//              return m[nums];
//          }
//          if( 1 == (int)nums.size()){
//              m[nums] = nums[0];
//              return nums[0];
//          }
//  
//          for(int i=0;i<(int)nums.size();i++){
//              vector<int > t = nums;
//              t.erase(t.begin()+i);
//  
//              if( i== 0 ){
//                  ans = max(ans,dfs(t) + 1 * nums[i] * nums[i+1]);
//              }
//              else if (i == (int)nums.size()-1){
//                  ans = max(ans,dfs(t) + nums[i-1] * nums[i] * 1);
//              }
//              else{
//                  ans = max(ans,dfs(t) + nums[i-1] * nums[i] * nums[i+1]);
//              }
//            } 
//            m[nums] = ans;
//            return ans;
//      }
//  
//      int maxCoins(vector<int>& nums) {
//          int ans = 0;
//          ans = dfs(nums);
//          return ans;
//      }
//  };

// use divide and conquer
// it not so faste
class Solution {
public:
    // so when a list divided by index i, how to figure between it ,
    // will it combine ?
    int divede(vector<int> nums,int low ,int high,vector< vector<int> > & dp){
        // careful here is return zero not other.
        if( low == high-1){
            dp[low][high] =  0;
        } 

        if(dp[low][high] != 0){ return dp[low][high];}
        int ans = 0;
        for(int i= low+1;i<high;i++){
            //careful here is not i-1 and i+1
            ans = max (ans, nums[low] * nums[i] * nums[high] + divede(nums,low,i,dp) + divede(nums,i,high,dp));
        }
        // ans = max (ans,divede(nums,low+1,high,dp) + nums[low] );
        // ans = max (ans,divede(nums,low,high-1,dp) + nums[high] );
        dp[low][high] = ans;
        return ans;
    }

    int maxCoins(vector<int>& nums) {
        //remove all zero item
        nums.erase(remove_if(nums.begin(),nums.end(),[](int n){ return n==0;}),nums.end());

        //add 1 for head and tail
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector< vector<int> > dp (nums.size(),vector<int>(nums.size(),0));
        int ans = divede(nums,0,(int)nums.size()-1,dp);

        return ans;
    }
};

// use dp ,it faster.
// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
//         int n = nums.size();
//         vector<vector<int> > dp(n, vector<int>(n, 0));
//         for (int len=0; len<=n-2; len++) {
//             for (int j=1; j+len<n-1; j++) {
//                 for (int k=j; k<=j+len; k++) {
//                     dp[j][j+len] = max(dp[j][j+len], dp[j][k-1] + dp[k+1][j+len] + nums[j-1] * nums[k] * nums[j+len+1]);
//                 }
//                 //cout << j << ", " << j+len << ": " << dp[j][j+len] << endl;
//             }
//         }
//         return dp[1][n-2];
//     }
// };

int main(){
   Solution ss;
    vector<int > nums{3,1,5,8};
    //vector<int > nums{9,76,64,21,97,60,5};
    //vector<int > nums{8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2,5};
    cout<<ss.maxCoins(nums)<<endl;
   
}


