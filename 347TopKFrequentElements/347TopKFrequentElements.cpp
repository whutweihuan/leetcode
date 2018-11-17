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
#include<unordered_map>
#include<queue>

using namespace std;

/*************First Solution ***************
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return nums;
        unordered_map<int, int> m;
        pair<int, int> tmp;
        priority_queue<pair<int, int>, vector<pair<int, int>> ,cmp> q;
        for(int i = 0; i < nums.size();i ++) {
            m[nums[i]] ++;
        }
        unordered_map<int, int>::iterator iter = m.begin();
        for(int i = 0; i < m.size();i ++) {
            tmp.first = iter->first;
            tmp.second = iter->second;
            q.push(tmp);
            iter ++;
        }
            
        
        vector<int> res;
        int i = 0;
        while(!q.empty() && i < k) {
            tmp = q.top();
            res.push_back(tmp.first);
            q.pop();
            i ++;
            
        }
        return res;
    }
    
    struct cmp {
        bool operator() (const pair<int, int> p, const pair<int, int> q) {
            return p.second < q.second;
            
        }
            
    };
};
*******************************************/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {        
        unordered_map<int, int> mp;
        for (int ii = 0; ii < nums.size(); ++ii) {
            if (!mp[nums[ii]]) {
                mp[nums[ii]] = 1;
            }
            else {
                mp[nums[ii]]++;
            }
        }
        
        priority_queue<pair<int, int>> pq;

        for (auto ii = mp.begin(); ii != mp.end(); ++ii) {
            pq.push(make_pair(ii->second, ii->first));
        }
        vector<int> res;
        for (int ii = 0; ii < k; ++ii) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main(){
    Solution ss;
    //vector<int> nums{1,1,1,2,2,3};
    //int k = 2;
    vector<int> nums{4,1,-1,2,-1,2,3};
    int k = 2;
    for(auto each:ss.topKFrequent(nums,k)){
        cout<<each<<"\t";    
    }

}






























