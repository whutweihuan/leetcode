/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: 
#         title: 77	Combinations
#   Description: ---
#	  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
#	  
#	  Example:
#	  
#	  Input: n = 4, k = 2
#	  Output:
#	  [
#	    [2,4],
#	    [3,4],
#	    [2,3],
#	    [1,2],
#	    [1,3],
#	    [1,4],
#	  ]
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

// 经典回溯
// 156 ms 使用的是find查找，每个for循环依旧从1开始
// 86 ms 加入start不用判断是否存在，且每一个都比后一个小
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
    	dfs(res,temp,1,n,k);
    	return res;
    }

    void dfs(vector<vector<int>> &res,vector<int> temp ,int start ,const int & n,const int & k){
    	// printVector(temp);
    	if(temp.size() == k){
    		res.push_back(temp);
    		return ;
    	}
    	for(int i=start;i<=n;i++){
    		temp.push_back(i);
    		dfs(res,temp,i+1,n,k);
    		temp.pop_back();
    	}
    }
};

// 8 ms
// class Solution {
// public:
// 	vector<vector<int>> combine(int n, int k) {
// 		vector<vector<int>> result;
// 		int i = 0;
// 		vector<int> p(k, 0);
// 		while (i >= 0) {
// 			p[i]++;
// 			if (p[i] > n) --i;
// 			else if (i == k - 1) result.push_back(p);
// 			else {
// 			    ++i;
// 			    p[i] = p[i - 1];
// 			}
// 		}
// 		return result;
// 	}
// };

int main(int argc, char const *argv[])
{
	int n = 4,k=2;
	Solution ss;
	vector<vector<int>> res = ss.combine(n,k);
	printVector2D(res);
	
	return 0;
}