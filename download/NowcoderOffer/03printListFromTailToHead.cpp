/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   03printListFromTailToHead.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/15
  *Description:  Enter a linked list that returns an ArrayList in order from end to end.
  *Others:  NewCoderOffer3
  *Code List: 
  *History:  
     1.Date: 2019/10/15
       Author: chenyu
       Modification: create

**********************************************************************************/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        stack<int> vstack;

        ListNode *Node = head;
        while(Node != nullptr){
            vstack.push(Node->val);
            Node = Node->next;
        }
         
        while(!vstack.empty()){
            array.push_back(vstack.top());
            vstack.pop();
        }
        return array;    
    }
};
