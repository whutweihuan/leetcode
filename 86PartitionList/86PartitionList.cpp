/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-2-3
# Last Modified: 2019-2-3
#          Link: https://leetcode.com/problems/partition-list/
#         title: 86	Partition List
#   Description: ---
#	  Given a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.
#
#	  You should preserve the original relative order of the nodes in each
of the two partitions.
#
#	  Example:
#
#	  Input: head = 1->4->3->2->5->2, x = 3
#	  Output: 1->2->2->4->3->5
***********************************************/
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void printLink(ListNode *head) {
  while (head) {
    cout << head->val << "\t";
    head = head->next;
  }
  cout << endl;
}

ListNode *createList(int a[], int n) {
  ListNode *head = NULL, *p = NULL;
  for (int i = 0; i < n; i++) {
    if (head == NULL) {
      head = p = new ListNode(a[i]);
    } else {
      p->next = new ListNode(a[i]);
      p = p->next;
    }
  }
  return head;
}

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *lessHead = new ListNode(0), *biggerHead = new ListNode(0);
    ListNode *q1 = lessHead, *q2 = biggerHead, *p = head;
    while (p) {
      if (p->val < x) {
        q1->next = p;
        q1 = q1->next;
      } else {
        q2->next = p;
        q2 = q2->next;
      }
      p = p->next;
    }
    q2->next = NULL;
    q1->next = biggerHead->next;
    return lessHead->next;
  }
};

int main() {
  Solution ss;
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  p->next = new ListNode(4);
  p = p->next;
  p->next = new ListNode(3);
  p = p->next;
  p->next = new ListNode(2);
  p = p->next;
  p->next = new ListNode(5);
  p = p->next;
  p->next = new ListNode(2);
  p = p->next;
  printLink(head);
  head = ss.partition(head, 3);
  printLink(head);
}