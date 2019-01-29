/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/simplify-path/
#         title: 71	Simplify Path
#   Description: ---
#  	  Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
#  	  
#  	  In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
#  	  
#  	  Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
#  	  
#  	   
#  	  
#  	  Example 1:
#  	  
#  	  Input: "/home/"
#  	  Output: "/home"
#  	  Explanation: Note that there is no trailing slash after the last directory name.
#  	  Example 2:
#  	  
#  	  Input: "/../"
#  	  Output: "/"
#  	  Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
#  	  Example 3:
#  	  
#  	  Input: "/home//foo/"
#  	  Output: "/home/foo"
#  	  Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
#  	  Example 4:
#  	  
#  	  Input: "/a/./b/../../c/"
#  	  Output: "/c"
#  	  Example 5:
#  	  
#  	  Input: "/a/../../b/../c//.//"
#  	  Output: "/c"
#  	  Example 6:
#  	  
#  	  Input: "/a//b////c/d//././/.."
#  	  Output: "/a/b/c"
***********************************************/
#include<iostream>
#include <string>
#include <stack>

using namespace std;

// My wrong code
// You should handle "..", other than "."
// You should store the "/" int the stack
// You need't to know the charcter is a alpha or not, Just care about if it is . or /
// You need more careful.
// The result /... should output /... instead of /
// class Solution {
// 	bool isalpha(char ch){
// 		return  'a'<= ch && ch<='z';
// 	}
// public:
//     string simplifyPath(string path) {
//         stack<string> stk;
//         for(int i=0;i<path.size();i++){
//         	string s ="";
//         	bool alpha = false;
//         	while(isalpha(path[i])){
//         		alpha = true;
//         		s+= path[i];
//         		i++;
//         	}
//         	if(alpha){
//         		stk.push(s);
//         	}
//         	if(path[i] == '.'){
//         		stk.push(".");
//         	}
//         	else if(path[i]=='/'){
//         		if(stk.empty() || isalpha(stk.top()[0]) ){
//         			stk.push("/");
//         		}
//         		else if(stk.top() == "/"){ continue;}
//         		int cnt = 0;
//         		while(!stk.empty() && stk.top() == "."){
//         			stk.pop();
//         			cnt++;
//         		}
//         		if(cnt == 2){
//         			while(!stk.empty() && cnt--){
//         				stk.pop();
//         			}
//         			if(stk.empty()){stk.push("/");}
//         		}
//         	}

//         }
//         int cnt = 0;
//         while(!stk.empty() && stk.top() == "."){
//             stk.pop();
//         	cnt++;
//         }

//         if(cnt == 2){
//         while(!stk.empty() && cnt--){
//         		stk.pop();
//         	}
//         }
//         if(!stk.empty() && stk.top()=="/"){
//         	stk.pop();
//         }
//         if(stk.empty()){
//         	return "/";
//         }

//         string res ="";
//         while(!stk.empty()){
//         	res = stk.top() + res;
//         	stk.pop();
//         }

//         return res;
//     }
// };

// good example
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}

// Java code
// string simplifyPath(string path) {
// 	vector<string>   nameVect;
// 	string name;
	
// 	path.push_back('/');
// 	for(int i=0;i<path.size();i++){
// 		if(path[i]=='/'){
// 			if(name.size()==0)continue;
// 			if(name==".."){		//special case 1：double dot，pop dir
// 			     if(nameVect.size()>0)nameVect.pop_back();
// 			}else if(name=="."){//special case 2:singel dot，don`t push
// 			}else{			
// 				nameVect.push_back(name);
// 			}
// 			name.clear();
// 		}else{
// 			name.push_back(path[i]);//record the name
// 		}
// 	}

// 	string result;
// 	if(nameVect.empty())return "/";
// 	for(int i=0;i<nameVect.size();i++){
// 		result.append("/"+nameVect[i]);
// 	}
// 	return result;
// }


// The following way use deque,also java code
// public class Solution {
//     public String simplifyPath(String path) {
//         if (path==null||path.length()==0) return "";
//         String[] paths = path.split("/+");
//         Deque<String> queue = new LinkedList<String>();
        
//         for (String s:paths){

//         	if (s.equals("..")){
//         		if (!queue.isEmpty())
//         			queue.pollLast();
//         	}
//         	else if (s.equals(".")||s.equals(""))
//         		continue;
//         	else queue.offer(s);
//         }
//         StringBuilder result=new StringBuilder("");
//         if (queue.isEmpty()) result.append("/");
//         while (!queue.isEmpty()){
        	
//         		result.append("/").append(queue.poll());//Faster than string manipulation. 
//         }
//         return result.toString();
//     }
// }

// Python code, use spilt way.
// class Solution:
//     def simplifyPath(self, path):
//         """
//         :type path: str
//         :rtype: str
//         """
//         stack,vars = [],path.split("/")
//         for var in vars:
//             if var!='':
//                 if var == '.':
//                     continue
//                 elif var == '..':
//                     if len(stack)>0:
//                         stack.pop()
//                 else:
//                     stack.append(var)
//         return '/'+'/'.join(stack)



int main(){
	Solution ss;
	// string path = "/a//b////c/d//././/..";
	string path = "/...";
	cout << ss.simplifyPath(path) <<endl;
}