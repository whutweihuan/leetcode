/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-31 
# Last Modified: 2019-1-31
#          Link: https://leetcode.com/problems/maximal-rectangle/
#         title: 85	Maximal Rectangle
#   Description: ---
#	  Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
#	  
#	  Example:
#	  
#	  Input:
#	  [
#	    ["1","0","1","0","0"],
#	    ["1","0","1","1","1"],
#	    ["1","1","1","1","1"],
#	    ["1","0","0","1","0"]
#	  ]
#	  Output: 6
***********************************************/
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <char> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}

void printVector2D(vector<vector<char>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

// the question is base in before
class Solution {
public:
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
  }
};


// way II, use the code before 
// This way is easy to understand
int largestRectangleArea(vector<int> &height) {

    if (height.size()<=0) return 0;

    height.push_back(0);
    vector<int> stack;
    int maxArea=0;

    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {

    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row, vector<int>(col));

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if (matrix[i][j]=='1'){
                heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
            }
        }
        int area = largestRectangleArea(heights[i]);
        if (area > maxArea){
            maxArea = area;
        }
    }
    return maxArea;
}

int main(){
	Solution ss;
	vector<vector<char>> matrix{
        {"1","0","1","0","0"},
        {"1","0","1","1","1"},
        {"1","1","1","1","1"},
        {"1","0","0","1","0"}
	};
	cout << ss.maximalRectangle(matrix) << endl;
}