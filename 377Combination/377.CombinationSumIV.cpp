/**********************************************
 * author: weihuan
 * link: https://leetcode.com/problems/combination-sum-iv/description/
 * date: 2018-11-16
 * title: combination-sum-iv/description
 * descrition:
 * Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7
 *
 *

 ********************************************  */
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums,int target){
        int a [target+1];
        memset(a,0,sizeof(a));
        a[0] =1;// 构成0只有一种情况，全部不选
        for(int  i=1;i<=target;i++){
            for(size_t j=0;j<nums.size();j++){
                if(i >= nums[j]){
                   a[i] +=  a[i-nums[j]]; 
                }
            }
        }
      return a[target];
    }
};

class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        
        int ans(0);
        int len = nums.size();
        
        //if(len==0) return 0; 
        
        vector<int> m(target+1,-1);
        
        m[0]=1;        
        ans= dfs(nums,m,target);
        
        
        return ans;        
    }
    
    int dfs(vector<int> &nums, vector<int> &m, int curval){
        if(curval<0) return 0 ; 
        if(m[curval]!=-1) return m[curval];
        
        int sum(0); 
        
        for(int i=0,len=nums.size(); i<len;i++){
            sum+=dfs(nums,m,curval-nums[i]);
        }     
        
        m[curval] = sum;
        
        return m[curval];
        
    }
};

int main(){
    Solution ss;
   vector<int> nums {1,2};
   
   int target = 10;
    std::cout<<ss.combinationSum4(nums,target)<<endl;

    getchar();
}

























