/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-31 
# Last Modified: 2019-1-31
#          Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#         title: 83	Remove Duplicates from Sorted List
#   Description: ---
#	  Given a sorted linked list, delete all duplicates such that each element appear only once.
#	  
#	  Example 1:
#	  
#	  Input: 1->1->2
#	  Output: 1->2
#	  Example 2:
#	  
#	  Input: 1->1->2->3->3
#	  Output: 1->2->3
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
        	if(p->val != pre ){
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

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {    
//         ListNode* cur = head;
//         while(cur){
//             while(cur->next && cur->next->val == cur->val)
//                 cur->next = cur->next->next;
//             cur = cur->next;
//         }
//         return head;          
//     }
// };


//Java code use recursive
// public ListNode deleteDuplicates(ListNode head) {
//         if(head == null || head.next == null)return head;
//         head.next = deleteDuplicates(head.next);
//         return head.val == head.next.val ? head.next : head;
// }


// C++ code  bad version
// if (h && (h->next = deleteDuplicates(h->next)) && h->next->val == h->val) delete h, h = h->next; return h;

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
	p->next->next ->next->next = new ListNode(3);
	// p->next->next->next = new ListNode(3);
	head = ss.deleteDuplicates(head);
	
	printLink(head);

}