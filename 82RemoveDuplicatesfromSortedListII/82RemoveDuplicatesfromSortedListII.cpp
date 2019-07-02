/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-31 
# Last Modified: 2019-1-31
#          Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
#         title: 82	Remove Duplicates from Sorted List II
#   Description: ---
#	  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
#	  
#	  Example 1:
#	  
#	  Input: 1->2->3->3->4->4->5
#	  Output: 1->2->5
#	  Example 2:
#	  
#	  Input: 1->1->1->2->3
#	  Output: 2->3
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


void printLink (ListNode * head){
	while(head){
		cout << head->val <<"\t";
		head= head->next;
	}
	cout << endl;
}


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	// NULL node or single node retuen directly
        if(!head || ! head->next){return head;}
        ListNode * p = head , *newHead = new ListNode(0),*q = newHead;
        
        int pre = 255 ^ p->val; // remember the val,set first node's pre 

        while(p){
        	// check the node if is a single node
        	if(p->val != pre && ( !p->next || p->next->val != p->val)){
        		q->next = p; 
        		q = q->next;
        	}
        	pre = p->val;
        	p = p->next;
        }
        q -> next = NULL;//makes the tail's next NULL
        return newHead->next;
    }
};


// 利用递归
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (!head) return 0;
//         if (!head->next) return head;
        
//         int val = head->val;
//         // p is next node
//         ListNode* p = head->next;
        
//         // next node isn't equal this node value
//         if (p->val != val) {
//             head->next = deleteDuplicates(p);
//             return head;
//         }

//         // if equal make it unqual
//         else {
//             while (p && p->val == val) p = p->next;
//             return deleteDuplicates(p);
//         }
//     }
// };


int main(){
	Solution ss;
	ListNode * head = new ListNode(1);
	ListNode * p = head;
	// for(int i=0;i<2;i++){
	// 	p->next = new ListNode(1);
	// 	p = p->next;
	// }
	p-> next = new ListNode(2);
	p-> next ->next = new ListNode(2);
	p->next->next ->next = new ListNode(3);
	// p->next->next->next = new ListNode(3);
	head = ss.deleteDuplicates(head);
	
	printLink(head);

}