#include<iostream>

#include<vector>

using namespace std;

void printv(vector<int> v){
	for(auto c :v){
		cout<<c<<"\t";
	}
}

int main(){
	std::vector<int> v{1,2,3,4};
	printv(v);
	getchar();
}