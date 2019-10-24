/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   14FindKthToTail.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/23
  *Description:  Enter a linked list and output the kth node from the bottom of the list.
  *Others:  NewCoderOffer14
  *Code List: 
  *History:  
     1.Date: 2019/10/23
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        /***** method 1
        if(pListHead==nullptr|| k<1)
            return nullptr;
        ListNode* pfront = pListHead;
        ListNode* pbehind = pListHead;
        for(int i=0; i<k-1; ++i){
            pfront = pfront->next;
            if(pfront == nullptr)
                return nullptr;
        }
        while(pfront->next != nullptr){
            pfront = pfront->next;
            pbehind = pbehind->next;
        }
        return pbehind;
        *****/
       ///***** method 2 more simpler
        ListNode* pfront = pListHead;
        ListNode* pbehind = pListHead;
        int i=0;
        for (; pfront != nullptr; i++) {
            if (i >= k)
                pbehind = pbehind->next;
            pfront = pfront->next;
        }
        return i < k ? nullptr : pbehind;
        //****/
    }
};