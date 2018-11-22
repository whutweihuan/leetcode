/***********************************************
#
#      Filename: 315CountofSmallerNumbersAfterSelf.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-21 10:07:52
# Last Modified: 2018-11-21 10:07:52
#          Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#   Description: ---
#    You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
#    
#    Example:
#    
#    Input: [5,2,6,1]
#    Output: [2,1,1,0]
#    Explanation:
#    To the right of 5 there are 2 smaller elements (2 and 1).
#    To the right of 2 there is only 1 smaller element (1).
#    To the right of 6 there is 1 smaller element (1).
#    To the right of 1 there is 0 smaller element.
***********************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// this way is too silly, but it is so easy.
//  class Solution {
//  public:
//      vector<int> countSmaller(vector<int>& nums) {
//          vector<int> result (nums.size(),0);
//          for(int i = nums.size()-1 ; i>=0 ;i--){
//              for(int j = i+1;j<nums.size();j++){
//                  if(nums[i] > nums[j]){
//                      result[i] ++;
//                  }
//              }
//          }
//          return result;
//      }
//  };

// this way use bit (Binary Index Tree)
// can learn from https://zh.wikipedia.org/zh-hans/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84
// and http://www.hawstein.com/posts/binary-indexed-trees.html
// it is nice to read.
//

 class BIT{
     vector<int> tree;
     
 public:
     BIT(int size){
        tree = vector<int>(size,0);
     }

     //return the sum from 1 to idx 
     int read(int idx){
         int sum =0;
         while(idx>0){
             sum += tree[idx];
             idx -= (idx & -idx);
         }
         return sum;
     }
     
     // return the val in this index ,
     // origin value
     int readSingle(int idx){
         int sum = tree[idx];
         if(idx > 0){
             int z = idx - (idx & -idx);
             idx--;
             while(idx != z){
                 sum -= tree[idx];
                 idx -= (idx & -idx);
             }
         }
         return sum;
     }
    
     void update(int idx,int val){
         while(idx <= (int)tree.size()-1){
             tree[idx] += val;
             idx += (idx & -idx);
         }
     }
 
 };
typedef struct P{
    int val;
    int pos;
}P ;

int cmp(const void * a,const void *b){
    return (*(P*)a).val - (*(P*)b).val;
}

 class Solution {
 public:
     vector<int> countSmaller(vector<int>& nums) {
         struct P * s =  (struct P *) malloc(sizeof(struct P)* (nums.size())); 
         for(int i=1;i<=(int)nums.size();i++){
            s[i].pos  = i; 
            s[i].val = nums[i-1];
         }
         qsort(s+1,nums.size(),sizeof(s[0]),cmp);
        
         vector<int> ds(nums.size()+1,0);
         for(int i=1;i<= (int)nums.size();i++){
            ds[s[i].pos] = i;
         }
         vector<int> res(nums.size(),0);
         BIT bit(nums.size()+1);
        for(int i= nums.size();i>=1;i--){
           res[i-1] = bit.read(ds[i]);
           bit.update(ds[i],1);
        }
        return res;
     }

 };


/*
 * the following idea is based on BIT 'Binary index tree'
 * code from leedcode after  update you old slow code
 */

// #include<unordered_map>
// class BIT {
// protected:
//   int size_;
//   vector<int> data_;
// 
// public:
//   BIT(int size) : size_(size), data_(size + 1, 0) {}
//   void add(int i, int val) {
//     for (int x = i; x <= size_; x += x & (-x)) {
//       data_[x] += val;
//     }
//   }
//   int querySum(int i) {
//     int retval = 0;
//     for (int x = i; 1 <= x; x -= x & (-x)) {
//       retval += data_[x];
//     }
//     return retval;
//   }
// };
// 
// 
// 
// class Solution {
// public:
//   vector<int> countSmaller(vector<int>& nums) {
//     if (nums.size() == 0) return {};
//     vector<int> sortedNums(nums);
//     sort(sortedNums.begin(), sortedNums.end());
//     unordered_map<int, int> m;
//     int cnt = 0;
//     for (int i = 0; i < (int)sortedNums.size(); i++) {
//       if (m.find(sortedNums[i]) == m.end()) {
//         cnt++;
//         m[sortedNums[i]] = cnt;
//       }
//     }
// 
//     vector<int> ans(nums.size(), 0);
//     BIT bit(cnt);
//     for (int i = nums.size() - 1; i >= 0; i--) {
//       ans[i] = bit.querySum(m[nums[i]] - 1);
//       cout<<ans[i]<<"\t";
//       bit.add(m[nums[i]], 1);
//     }
//     cout<<endl;
//     return ans;
//   }
// };


/*
 * the following way is using binary search to solve it 
 */
//   class Solution {
//   public:
//       vector<int> countSmaller(vector<int>& nums) {
//           int n = nums.size();
//           vector<int> t, res (n);
//   
//           for (int i = n - 1; i >= 0; --i) {
//               int left = 0, right = t.size();
//   
//               while(left < right) {
//                   int mid = left + (right - left) / 2;
//                   if (t[mid] >= nums[i]) right = mid;
//                   else left = mid + 1;
//               }
//   
//               res[i] = right;
//               t.insert(t.begin() + right, nums[i]);
//           }
//   
//           return res;
//       }
//   };

int main(){
    vector<int > test {5,2,6,1};
    //vector<int > test {2,0,1};
    Solution ss;
    for(auto c:ss.countSmaller(test)){
        cout<<c<<"\t";
    }
}

































