/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: 
#         title: 61	Rotate List
#   Description: ---
#	  Given a linked list, rotate the list to the right by k places, where k is non-negative.
#	  
#	  Example 1:
#	  
#	  Input: 1->2->3->4->5->NULL, k = 2
#	  Output: 4->5->1->2->3->NULL
#	  Explanation:
#	  rotate 1 steps to the right: 5->1->2->3->4->NULL
#	  rotate 2 steps to the right: 4->5->1->2->3->NULL
#	  Example 2:
#	  
#	  Input: 0->1->2->NULL, k = 4
#	  Output: 2->0->1->NULL
#	  Explanation:
#	  rotate 1 steps to the right: 2->0->1->NULL
#	  rotate 2 steps to the right: 1->2->0->NULL
#	  rotate 3 steps to the right: 0->1->2->NULL
#	  rotate 4 steps to the right: 2->0->1->NULL
#	  
***********************************************/
#include <algorithm>
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
    ListNode* rotateRight(ListNode* head, int k) {
    	// for NULL list
    	if(!head){return head;}
    	// the len of list
    	int len = 1;
    	// get the tail node of the list
    	ListNode * tail = head;
    	ListNode * p = head;
    	while(tail->next){ tail = tail->next; len++;}
    	// connect the tail and head 
    	tail -> next = head;
    	// think about 3 node about 1 2 3
    	// 1 2 3   1 2 3   1 2 3
    	// 0 1 2   3 4 5   6 7 8
    	// supose we are at in index 3, and now k = 2
    	// we can just left move to index = 3-2 = 1
    	// also we can right move len - k = 3-2 = 1 ,and move 1 ,new we are in index = index+1 = 4 
    	k = len - k%len;  // this is for k > len
    	while(k--){ p=p->next;}
    	head = p;  // we found the new head
    	len--;
    	while(len--){p=p->next;}// we found the new tail
    	p->next = NULL; 
        return head;
    }
};

int main(){
	Solution ss;
	int k  = 2;
	ListNode * head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next -> next = new ListNode(3);
	// head -> next -> next -> next = new ListNode(4);
	// head -> next -> next -> next ->next = new ListNode(5);

	head = ss.rotateRight(head,k);
	while(head){
		cout<< head->val<<"\t";
		head = head->next;
	}
}