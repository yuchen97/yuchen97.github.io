/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   21IsPopOrder.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/30
  *Description:  Input two sequences of integers. The first sequence indicates the 
                 push order of the stack. Please determine if the second sequence is 
                 the pop-up order of the stack. Assume that all numbers pushed onto 
                 the stack are not equal. (Note: the length of the two sequences is equal)
                 For example:
                    pushV = 1, 2, 3, 4, 5    popV = 4, 5, 3, 2, 1 (√)
                    pushV = 1, 2, 3, 4, 5    popV = 4, 3, 5, 2, 2 (√) 
  *Others:  NewCoderOffer21
  *Code List: 
  *History:  
     1.Date: 2019/10/30
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty())  return false;
         
        stack<int> st;
        int indexpop = 0, indexpush = 0;
        int len = popV.size();
        st.push(pushV[indexpush]);
         
        while(indexpop<len && indexpush<len){
            if(st.top() != popV[indexpop]){
                    st.push(pushV[++indexpush]);
            } else {
                st.pop();
                ++indexpop;
            }
        }
        return st.empty();
    }
};
