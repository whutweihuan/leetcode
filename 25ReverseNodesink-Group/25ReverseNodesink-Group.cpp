/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
#         title: 25 Reverse Nodes in k-Group
#   Description: ---
#     Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
#     
#     k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
#     
#     Example:
#     
#     Given this linked list: 1->2->3->4->5
#     
#     For k = 2, you should return: 2->1->4->3->5
#     
#     For k = 3, you should return: 3->2->1->4->5
#     
#     Note:
#     
#     Only constant extra memory is allowed.
#     You may not alter the values in the list's nodes, only nodes itself may be changed.
***********************************************/
#include <iostream>
#include <string>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(k <=0 ) {return head;}
    //     ListNode *p = head;00
    //     //tail
    //     ListNode *q = head;
    //     while(p){
    //         p->next = reverseNode(p);
    //     }


    // }

    // ListNode* reverseNode(ListNode * head){
    //     // No node or one node
    //     if(head == NULL || head->next ==NULL) {return head;}

    //     //Swap last two node 
    //     ListNode * next = reverseNode(head->next);
    //     head->next->next = head;
    //     head ->next = NULL;

    //     return next;
    // }

    ListNode *reverseKGroup(ListNode *head, int k) {

    if (k<=0) return head;
    ListNode fake(0);
    fake.next = head;
    ListNode* p = &fake;

    while(p){
        p->next = reverseList(p->next, k);
        for(int i=0; p && i<k; i++){
            p = p->next;
        }
    }

    return fake.next;
    }

    ListNode *reverseList(ListNode *&head, int k){
        ListNode* pEnd=head;
        while (pEnd && k>0){
            pEnd = pEnd->next;
            k--;
        }
        if (k>0) return head;

        ListNode *pHead=pEnd, *p=head;
        while(p != pEnd){
            ListNode *q = p->next;
            p->next = pHead;
            pHead = p;
            p = q;
        }
        return pHead;
    }
};

int main(){
    ListNode * l1;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1 ->next->next->next->next= new ListNode(5);
    Solution ss;
    int k = 2;
    ListNode * head = ss.reverseKGroup(l1, 2);
    while(head){
        cout<<head->val<<"\t";
        head = head->next;
    }

}