/***********************************************
#
#      Filename: 341FlattenNestedListIterator.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 15:10:50
# Last Modified: 2018-11-17 15:10:50
#          Link: 
#   Description: ---
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,4,6].
***********************************************/


#include<iostream>
#include<vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    void dfs(vector<NestedInteger> & nestedList){
        for(size_t i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()){
               result.push_back(nestedList[i].getInteger()); 
            }
            else{
                vector<NestedInteger> nt = nestedList[i].getList();
                   dfs(nt);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        st = 0;
    }

    int next() {
        return result[st++];
    }

    bool hasNext() {
        if(st <= result.size()-1){
            return false;
        }
        else{
            return true;
        }
    }
private:
    vector<int> result;
    int st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){

}













