/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-26 
# Last Modified: 2019-1-26
#   Description: ---
		common function
***********************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
}

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	vector<vector<int>> matrix{
		{1,2,3},
		{1,2,3}
	};
	printVector2D(matrix);
}