/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://oj.leetcode.com/problems/permutation-sequence/
#         title: 60	Permutation Sequence
#   Description: ---
#	  The set [1,2,3,...,n] contains a total of n! unique permutations.
#	  
#	  By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
#	  
#	  "123"
#	  "132"
#	  "213"
#	  "231"
#	  "312"
#	  "321"
#	  Given n and k, return the kth permutation sequence.
#	  
#	  Note:
#	  
#	  Given n will be between 1 and 9 inclusive.
#	  Given k will be between 1 and n! inclusive.
#	  Example 1:
#	  
#	  Input: n = 3, k = 3
#	  Output: "213"
#	  Example 2:
#	  
#	  Input: n = 4, k = 9
#	  Output: "2314"
#	  
***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printVector(vector <string> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;

}

// class Solution {
// public:
// 	static bool cmp(const string &a,const string & b){
// 		for(int i=0;i<a.size();i++){
// 			if(a[i] == b[i]){ continue;}
// 			return a[i] < b[i];
// 		}
// 		return a[0] < b[0];
// 	}

//     string getPermutation(int n, int k) {
//         vector<string> res;
//         string s ="";
//         for(int i=1;i<=n;i++){
//         	s += i+'0';
//         }
//         // cout<< "s\t" << s <<endl;
//         backtarck(res,s,0);
//         sort(res.begin(),res.end(),cmp);
//         // printVector(res);
//         return res[k-1];
//     }

//     void backtarck(vector<string> & res,string & s,int pos){
//     	// cout << "s\t" << s <<endl;
//     	if(pos == s.size()){ res.push_back(s); return ;}
//     	for(int i= pos;i<s.size();i++){
//     		swap(s[i],s[pos]);
//     		backtarck(res,s,pos+1);
//     		swap(s[i],s[pos]);
//     	}
//     }
// };
class Solution {
	int count ;
public:
    string getPermutation(int n, int k) {
        string res="";
        count = 0;
        string s ="";
        for(int i=1;i<=n;i++){
        	s += i+'0';
        }
        string temp ="";
        backtarck(res,s,temp, k);
        return res;
    }

    void backtarck(string & res,const string  &s, string temp,const int & k){
    	if(res != ""){return ;}
    	if(temp.size() == s.size()){
    	    count++;
    	    if(count == k){ res = temp; } 
    		return ;
    	}
    	for(int i= 0;i<s.size();i++){
    		if(temp.find(s[i]) == temp.npos){
    			 temp.push_back(s[i]);
    		     backtarck(res,s,temp,k);
    		     temp.pop_back();
    		}	
    	}
    }
};

// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         vector<int> factorial(n,1);
//         string num = "123456789";
//         string res;
//         for(int i = 1; i< n; ++i) factorial[i] = factorial[i-1]*i;
//         --k;
//         for(int i = n; i>=1; --i){
//             int j = k/factorial[i-1];
//             res.push_back(num[j]); //string也可以用push_back
//             k = k % factorial[i-1];
//             num.erase(j,1); //很重要，用过一次后面的permutation就不能再出现了  
//         }
//         return res;
//     }
// };

int main(){
	Solution ss;
	int n = 3,k=3;
	cout << ss.getPermutation(9,2)<<endl;
}