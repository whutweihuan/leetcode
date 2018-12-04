/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/swap-nodes-in-pairs/
#         title: 24 Swap Nodes in Pairs
#   Description: ---
#     
#     Given a linked list, swap every two adjacent nodes and return its head.
#     
#     Example:
#     
#     Given 1->2->3->4, you should return the list as 2->1->4->3.
#     Note:
#     
#     Your algorithm should use only constant extra space.
#     You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode * swapPairs(ListNode* head) {
        auto p = head;
        //no node
        if (p == NULL) { return p; }

        //swap first two nodes
        if (p&&p->next) {
            auto next = p->next;
            p->next = p->next->next;
            next->next = p;
            head = next;//change head node
        }
        //only one node
        else {
            return p;
        }

        //swap rest nodes;
        auto prev = head->next;
        p = head->next->next;
        while (p&&p->next){
            auto next = p->next;
            p->next = p->next->next;
            next->next = p;
            prev->next = next;
            prev = p;
            p = p->next;
        }
        return head;
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);

    Solution ss;
    ListNode *head = ss.swapPairs(l1);
    while(head){
        cout<<head->val<<"\t";
        head = head->next;
    }
}