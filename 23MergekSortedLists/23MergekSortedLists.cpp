/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/merge-k-sorted-lists/
#         title: 23 Merge k Sorted Lists
#   Description: ---
#     Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
#     
#     Example:
#     
#     Input:
#     [
#       1->4->5,
#       1->3->4,
#       2->6
#     ]
#     Output: 1->1->2->3->4->4->5->6
#     
***********************************************/
#include <vector>
#include <iostream>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        
        for(int i=0;i<lists.size();i++){
            head = mergeTwoLists(head,lists[i]);
        }
        return head;

    }

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
    Solution ss;
    ListNode * l1;
    ListNode * l2;
    ListNode * l3;

    l1= new ListNode(1);
    l1->next= new ListNode(3);
    l1->next->next= new ListNode(4);

    l2= new ListNode(1);
    l2->next= new ListNode(4);
    l2->next->next= new ListNode(5);

    l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    vector<ListNode*> lists{l1,l2,l3};
    ListNode * newhead = ss.mergeKLists(lists);
    while(newhead){
        cout<<newhead->val<<"\t";
        newhead = newhead->next;
    }

}