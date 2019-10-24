/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   15ReverseList.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/24
  *Description:  Input a linked list, and after inverting the linked list, 
                 output the header of the new linked list.
  *Others:  NewCoderOffer15
  *Code List: 
  *History:  
     1.Date: 2019/10/24
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;
        ListNode* pReversehead = pHead;
        ListNode* pTail = nullptr;
        ListNode* pNode = nullptr;
        while(pReversehead != nullptr){
            pNode = pReversehead;
            pReversehead = pReversehead->next;
            pNode->next = pTail;
            pTail = pNode;
        }
        return pNode;
    }
};
