/***********************************************
#
#      Filename: 347TopKFrequentElements.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 00:43:26
# Last Modified: 2018-11-17 00:43:26
#          Link: 
#   Description: ---
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
***********************************************/

#include<vector>
#include<iostream>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> m;
        set<int> sets;
        for(size_t i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int i=0;
        while(sets.size()<k){
            sets.insert(nums[i++]);
        }
        for(size_t i =0;i<nums.size();i++){
            if(sets.find(nums[i]) ==sets.end() && m[nums[i]] > *sets.begin()){
                sets.erase(sets.begin());
                sets.insert(nums[i]);
            }
        }
        for(auto iter = sets.begin();iter!=sets.end();iter++){
            res.push_back(*iter);
        }
        return res;
    }
};

int main(){
    Solution ss;
    //vector<int> nums{1,1,1,2,2,3};
    //int k = 2;
    vector<int> nums{3,0,1,0};
    int k = 1;
    for(auto each:ss.topKFrequent(nums,k)){
        cout<<each<<"\t";    
    }

}






























