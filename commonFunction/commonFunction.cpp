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
	cout << endl;
}

void printVector2D(vector<vector<int>> vec){
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void printLink (ListNode * head){
	while(head){
		cout << head->val <<"\t";
		head= head->next;
	}
	cout << endl;
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

vector<string> & split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main(){
	vector<vector<int>> matrix{
		{1,2,3},
		{1,2,3}
	};
	printVector2D(matrix);
}