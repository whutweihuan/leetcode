/***********************************************
#
#      Filename: 2AddTwoNumbers.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-22 15:58:06
# Last Modified: 2018-11-22 15:58:06
#          Link: https://leetcode.com/problems/add-two-numbers/
#   Description: ---
#     You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
#     
#     You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#     
#     Example:
#     
#     Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#     Output: 7 -> 0 -> 8
#     Explanation: 342 + 465 = 807.
***********************************************/
#include<iostream>
#include<cmath>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//  class Solution {
//  public:
//      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//          long long int number = 0;
//          long long int n1 =0,n2=0;
//          int iter = 0;
//          while(l1){
//              n1+=  pow (10,iter++)* (l1->val);
//              l1 = l1->next;
//          }
//          cout<<n1<<endl;
//          iter =0;
//          while(l2){
//              n2+= pow (10,iter++)* (l2->val);
//              l2 = l2->next;
//          }
//          cout<<n2<<endl;
//          number = n1+n2;
//          cout<<number<<endl;
//          ListNode * res = new ListNode(number % 10);
//          number /= 10;
//          ListNode *tail = res;
//          while(number){
//             tail->next = new ListNode( number %10);
//             tail = tail->next;
//             number/=10;
//          }
//         return res; 
//      }
//  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //The head is no meaning but need to flag it
        ListNode * res = new ListNode(0) ;

        //for carrry flag
        int flag = 0;

        ListNode *tail = res;
        while(l1 || l2){
            int number = flag;
            //get the first val about l1
            if(l1){
                number+= l1->val;
                l1=l1->next;
            }
            //get the second val about l2
            if(l2){
                number+= l2->val;
                l2=l2->next;
            }
            flag = number/10;
           tail ->next = new ListNode(number%10);
           tail = tail->next;
        }
        if(flag){
            tail->next = new ListNode(1);
            tail = tail ->next;
        }
        return res->next;
    }
};

int main(){
    Solution ss;

    ListNode *l1;
    ListNode *l2;
    
     l1 = new ListNode(9);
     l2 = new ListNode(1);
      
     ListNode *tail = l2;
     for(int i=0;i<9;i++){
         tail->next = new ListNode(9);
         tail = tail->next;
     }
     //l1 = new ListNode(2);
     //l1 ->next= new ListNode(4);
     //l1 ->next->next= new ListNode(3);
     
     //l2 = new ListNode(5);
     //l2->next = new ListNode(6);
     //l2->next->next = new ListNode(4);

    ListNode *head = ss.addTwoNumbers(l1,l2);
    while(head){
        cout<<head->val<<"\t";
        head = head->next;
    }
}














