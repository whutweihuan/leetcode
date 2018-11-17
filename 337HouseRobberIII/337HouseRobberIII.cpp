/***********************************************
#
#      Filename: 337HouseRobberIII.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 16:31:15
# Last Modified: 2018-11-17 16:31:15
#          Link: https://leetcode.com/problems/house-robber-iii/
#   Description: ---
#   
#   The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
#   
#   Determine the maximum amount of money the thief can rob tonight without alerting the police.
#   
#   Example 1:
#   
#   Input: [3,2,3,null,3,null,1]
#   
#        3
#       / \
#      2   3
#       \   \
#        3   1
#   
#   Output: 7
#   Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
#   Example 2:
#   
#   Input: [3,4,5,1,3,null,1]
#   
#        3
#       / \
#      4   5
#     / \   \
#    1   3   1
#   
#   Output: 9
#   Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
***********************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 1160 ms
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL){
            return 0;
        } 

        int selsef = root->val;
        if(root->left){
            selsef += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
             selsef += rob(root->right->left) + rob(root->right->right);
        }
        return std::max(selsef,rob(root->left)+ rob(root->right));
    }
};

int main(){
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    Solution ss;
    int val = ss.rob(root);
    cout<<val<<endl;
    
}




























