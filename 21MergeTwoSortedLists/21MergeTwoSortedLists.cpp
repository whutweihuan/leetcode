/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/merge-two-sorted-lists/
#         title: 21 Merge Two Sorted Lists
#   Description: ---
#     Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#     Example:

#     Input: 1->2->4, 1->3->4
#     Output: 1->1->2->3->4->4

***********************************************/
#include <iostream>
#include <vector>

using namespace std;

 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){return l2;}
        if(l2==NULL){return l1;}
        ListNode *p1 = l1, *p2 = l2;
        ListNode  * newhead;
        if(l1->val < l2->val){
            newhead = l1;
            p1 = p1->next;
        }
        else{
            newhead = l2;
            p2 = p2->next;
        }
        ListNode * q = newhead;
        while(p1 || p2){
            if(p1 && p2 && p1->val < p2->val){
                q->next = p1;
                p1 = p1->next;
            }
            else if(p1 && p2 && p1->val >= p2->val){
                q->next = p2;
                p2 = p2->next;
            }
            else if(p1){
                q->next = p1;
                p1 = p1->next;
            }
            else if(p2){
                q->next = p2;
                p2 = p2->next;
            }
            q = q->next;
        }
        return newhead;
    }
};

int main(){
    ListNode * l1;
    ListNode * l2;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution ss;
    ListNode *result = ss.mergeTwoLists(l1,l2);
    while(result){
        cout<<result->val<<"\t";
        result = result->next;
    } 

}