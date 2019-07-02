/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-30 
# Last Modified: 2019-1-30
#          Link: https://leetcode.com/problems/minimum-window-substring/
#         title: 76	Minimum Window Substring
#   Description: ---
#	  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
#	  
#	  Example:
#	  
#	  Input: S = "ADOBECODEBANC", T = "ABC"
#	  Output: "BANC"
#	  Note:
#	  
#	  If there is no such window in S that covers all characters in T, return the empty string "".
#	  If there is such window, you are guaranteed that there will always be only one unique minimum window in S
***********************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// // This is template for substring question
// int findSubstring(string s){
//         vector<int> map(128,0);
//         int counter; // check whether the substring is valid
//         int begin=0, end=0; //two pointers, one point to tail and one  head
//         int d; //the length of substring

//         for() { /* initialize the hash map here */ }

//         while(end<s.size()){

//             if(map[s[end++]]-- ?){   modify counter here  }

//             while(/* counter condition */){ 
                 
//                  /* update d here if finding minimum*/

//                 //increase begin to make it invalid/valid again
                
//                 if(map[s[begin++]]++ ?){ /*modify counter here*/ }
//             }  

//             /* update d here if finding maximum*/
//         }
//         return d;
//   }


//My wrong code
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int start = 0,end = 0;
//         int ok = 0;
//         string temp=""; 
//         queue <int> q;
//         for(int i=0;i<s.size();i++){
//         	if(!ok){
//         		if(t.find(s[i]) != t.npos ){
//         			if(temp.find(s[i]) == temp.npos){
//         				temp += s[i];
//         				q.push(i);
//         			}
//         			// else{
//         			// 	temp.erase(temp.begin());
//         			// 	temp += s[i];
//         			// 	q.pop();
//         			// 	q.push(i);
//         			// }
//         		}
//         	}else{
//         		temp.erase(temp.begin());
//         		temp += s[i];
//         		q.pop();
//         		q.push(i);        		
//         	}
//         }
//         if(!ok){return "";}
//     }
// };

void printVector(vector <int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\t";
	}
	cout << endl;
}


class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0,end = 0,head = 0; // head tail, Two pointer
        int count = t.size();// make sure the substring is valid
        int maxLen = INT_MAX;
        vector<int> maps (128,0);
        for(auto c:t) maps[c]++;
        while(end<s.size()){
        	if(maps[s[end++]]-- >0){count--;}  // s[i] is in t
        	while(count==0){ //the substring is valid now
        		if(end-start < maxLen) maxLen = end - (head=start) ;
        		if(maps[s[start++]]++ ==0) count++; //make it invalid
        	}
        }
        return maxLen == INT_MAX?"":s.substr(head,maxLen);
    }
};

int main(){
	Solution ss;
	string S = "KKADOBECODEBANC", T = "ABC" ;
	cout << ss.minWindow(S,T) << endl; 
}