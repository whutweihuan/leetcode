/***********************************************
#
#      Filename: 331VerifyPreorderSerializationofaBinaryTree.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-18 00:25:09
# Last Modified: 2018-11-18 00:25:09
#          Link: 
#   Description: ---
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: "1,#"
Output: false
Example 3:

Input: "9,#,#,1"
Output: false
***********************************************/

