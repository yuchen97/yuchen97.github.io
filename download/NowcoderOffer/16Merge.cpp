/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   16Merge.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/24
  *Description:  Input a linked list, and after inverting the linked list, 
                 output the header of the new linked list.
  *Others:  NewCoderOffer16
  *Code List: 
  *History:  
     1.Date: 2019/10/24
       Author: chenyu
       Modification: create

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        /***** method 1 Recurrence
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;
        ListNode* p1 = pHead2;
        ListNode* p2 = pHead1;
        ListNode* ptmp = nullptr;
        if(pHead1->val <= pHead2->val){
            p1 = pHead1;
            p2 = pHead2;
        }
        while(p1 != nullptr){
            if((p1->next!=nullptr) && (p1->next->val < p2->val))
                p1 = p1->next;
            else {
                ptmp = p2;
                p2 = p2->next;
                ptmp->next = p1->next;
                p1->next = ptmp;
                p1 = p1->next;
            }
            if(p2 == nullptr)
                break;
        }
        return pHead1==nullptr ? pHead2:pHead1;
        *****/
        ///***** method 2 Recursive
        if(pHead1 == nullptr)  return pHead2;
        if(pHead2 == nullptr)  return pHead1;
         
        ListNode* phead = nullptr;
        if(pHead1->val <= pHead2->val){
            phead = pHead1;
            phead->next = Merge(pHead1->next, pHead2);
        } else {
            phead = pHead2;
            phead->next = Merge(pHead1, pHead2->next);
        }
 
        return phead;
    }
};