/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-29 
# Last Modified: 2018-11-29 
#          Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#         title: 19 Remove Nth Node From End of List
#   Description: ---
#	  Given a linked list, remove the n-th node from the end of list and return its head.
#	  
#	  Example:
#	  
#	  Given linked list: 1->2->3->4->5, and n = 2.
#	  
#	  After removing the second node from the end, the linked list becomes 1->2->3->5.
#	  Note:
#	  
#	  Given n will always be valid.

***********************************************/
#include <iostream>
#include <vector>

using namespace std;

// Use the double pointer to locate the position
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *slow = head, *fast = head;
//         if (slow->next == NULL){
//             return NULL;
//         }
//         for (int i=0; i < n; i++){
//             fast = fast->next;
//         }
//         if (fast == NULL){
//             return head->next;
//         }
//         while (fast->next != NULL){
//             fast = fast->next;
//             slow = slow->next;
//         }
        
//         slow->next = slow->next->next;
//         return head;
//     }
// };


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p = head;
        int len = 0;
        //Count the length of link
        while(p){
        	len++;
        	p=p->next;
        }
        //Remove head node
        if(len == n) {return head->next;}
        p = head;
        for(int i=0;i<len-n-1;i++){
        	p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};

int main(){
	Solution ss;
	ListNode * head = new ListNode(1);
	ListNode * p = head;
	for(int i=2;i<=5;i++){
		p->next = new ListNode(i);
		p = p->next;
	}

	//ListNode * q = head;

	// while(q){
	// 	cout<<q->val<<"\t";
	// 	q = q->next;
	// } 
	// cout<<endl;

	int n = 4;

	ListNode * newHead = ss.removeNthFromEnd(head,n);
	while(newHead){
		cout<<newHead->val<<"\t";
		newHead = newHead->next;
	} 
}