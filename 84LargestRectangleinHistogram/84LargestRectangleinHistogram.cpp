/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-31 
# Last Modified: 2019-1-31
#          Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
#         title: 84	Largest Rectangle in Histogram
#   Description: ---
# * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
# * find the area of largest rectangle in the histogram.
# * 
# *                    6          
# *                  +---+        
# *               5  |   |        
# *              +---+   |        
# *              |   |   |        
# *              |   |   |        
# *              |   |   |     3  
# *              |   |   |   +---+
# *        2     |   |   | 2 |   |
# *      +---+   |   |   +---+   |
# *      |   | 1 |   |   |   |   |
# *      |   +---+   |   |   |   |
# *      |   |   |   |   |   |   |
# *      +---+---+---+---+---+---+
# *      
# * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
# *      
# *      
# *                    6          
# *                  +---+        
# *               5  |   |        
# *              +-------|        
# *              |-------|        
# *              |-------|        
# *              |-------|     3  
# *              |-------|   +---+
# *        2     |-------| 2 |   |
# *      +---+   |-------|---+   |
# *      |   | 1 |-------|   |   |
# *      |   +---|-------|   |   |
# *      |   |   |-------|   |   |
# *      +---+---+---+---+---+---+
# *      
# * 
# * The largest rectangle is shown in the shaded area, which has area = 10 unit.
# * 
# * For example,
# * Given height = [2,1,5,6,2,3],
# * return 10.
# * 
# *   
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

// dfs 超时
// So awful, How stupid !
// Who guys write so so bad code ? Yes his name is shuaihuan.
// class Solution {
// 	int findMin(vector<int>& heights,int begin,int end){
// 		if(heights.empty()) return 0;
// 		int maxval = heights[begin];
// 		for(int i=begin;i<=end;i++){
// 		  maxval = min(maxval,heights[i]);
// 		}
// 		return maxval;
// 	}

// 	int dfs(vector<int>& heights,int left,int right){
// 		if(left > right ){return 0;}
// 		if(left == right) {return heights[left];}
// 		int maxval = findMin(heights,left,right) * (right-left+1);
// 		// cout << maxval <<endl;
// 		return max(maxval,max(dfs(heights,left+1,right) ,dfs(heights,left,right-1)));
// 	}
// public:
//     int largestRectangleArea(vector<int>& heights) {
    	
//         return dfs(heights,0,heights.size()-1);
//     }
// };


// So clever ! nice.
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int res = 0;
        
//         for (int i = 0; i < n; i ++) {
//             if (i + 1 < n && heights[i + 1] >= heights[i]) {
//                 continue;   
//             }
//             int minH = heights[i];
//             for (int j = i; j >= 0; j --) {
//                 minH = min(minH, heights[j]);
//                 res = max(res, (i - j + 1) * minH);
//             }
//         }
        
//         return res;    
//     }
// };
/*
          3     
		+---+      
		|	|	  2
		|   |   +---+
		|	| 1 |   |
		|	+---+   |
		|	|   |	|
		+---+---+---+ 
				^
				|
		如果我们能求出这个地方最左和最右大于它的边界，那么就很好就可以用这个地方的高度来乘上宽度了


*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int size = heights.size();
    	vector<int> leftBound(size,0);
    	vector<int> rightBound(size,0);
    	leftBound[0] = -1;
    	rightBound[size-1] = size;
    	// 查找每一列大于它的最左边界，保存在leftbound数组里面
    	for(int i=1;i<size;i++){
    		int idx = i-1;//上一个地方
    		// 发现能够拓展
    		while(idx>=0 && heights[idx] >= heights[i]){
    			idx = leftBound[idx];
    		}
    		leftBound[i] = idx;
    	}
    	//同理，对每一列右边界处理
    	for(int i=size-2;i>=0;i--){
    		int idx = i+1;
    		while(idx<size && heights[idx] >= heights[i]){
    			idx = rightBound[idx];
    		}
    		rightBound[i] = idx;
    	}

    	int maxArea = 0;
    	for(int i = 0;i<size;i++) {
    		maxArea = max(maxArea,heights[i]*(rightBound[i] - leftBound[i]-1));
    	}
    	return maxArea;      
    }
};
int main(){
	Solution ss;
	vector<int>heights{2,1,5,6,2,3};
	cout << ss.largestRectangleArea(heights)<<endl;
}