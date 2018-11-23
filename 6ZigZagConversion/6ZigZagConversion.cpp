/***********************************************
#
#      Filename: 6ZigZagConversion.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 19:40:51
# Last Modified: 2018-11-22 19:40:51
#          Link: https://leetcode.com/problems/zigzag-conversion/
#   Description: ---
#     The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
#     
#     P   A   H   N
#     A P L S I I G
#     Y   I   R
#     And then read line by line: "PAHNAPLSIIGYIR"
#     
#     Write the code that will take a string and make this conversion given a number of rows:
#     
#     string convert(string s, int numRows);
#     Example 1:
#     
#     Input: s = "PAYPALISHIRING", numRows = 3
#     Output: "PAHNAPLSIIGYIR"
#     Example 2:
#     
#     Input: s = "PAYPALISHIRING", numRows = 4
#     Output: "PINALSIGYAHRPI"
#     Explanation:
#     
#     P     I    N
#     A   L S  I G
#     Y A   H R
#     P     I
***********************************************/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//This way is used a 2-d array
//store it and finally read it.
//It is not fast .
// class Solution {
// public:
//     string convert(string s, int numRows) {
//        if (numRows ==1){return s;}
//        vector< vector<char> >  v (numRows,vector<char>(s.size(),'#'));
//        int row = 0; 
//        int col = 0; 
//        int flag = 0;//0:down  1:right and up  
//        for(int i=0;i<(int)s.size();i++){
//             v [row][col] = s[i];
//             if(row ==numRows- 1){
//                 flag = 1;
//             }
//             else if(row ==0){
//                 flag = 0;
//             }
//             if(flag == 0){
//                 row++;
//             }
//             else if(flag ==1){
//                 row --;
//                 col++;
//             }
//        }
//        //cout<<"ok";
//        string res="";
//        for(int i=0;i<numRows;i++){
//          for(int j=0;j<(int)s.size();j++){
//             if(v[i][j] != '#'){
//                 res.push_back(v[i][j]);
//             }
//          }
//        }
//        return res;
//     }
// };


// in fact ,the move is just down and up,
// You just need nlows string to store it.
class Solution {
public:
    string convert(string s, int numRows) {
       if (numRows ==1){return s;}
       vector<string> v(numRows,"");
       int pos = 0;
       int flag = -1;//means we need go down ,if it equals -1 means it will go up
       for(int i=0;i<(int)s.size();i++){
            v[pos] += s[i];
            if(pos == numRows-1){flag = -1;}
            else if(pos == 0){flag = 1;}
            pos += flag;
       }
       string res = "";
       for(int i=0;i<numRows;i++){
            res += v[i]; 
       }

       return res;
    }
};


int main(){
    string s1= "PAYPALISHIRING";
    string s2= "AB";
    int numRows = 3;
    Solution ss;
    cout<<ss.convert(s1,numRows);

}













