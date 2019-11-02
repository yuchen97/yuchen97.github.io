/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   20min.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/29
  *Description:  Define the data structure of the stack, implement a min function 
                 in this type that can get the smallest element contained in the 
                 stack (time complexity should be O(1)).
  *Others:  NewCoderOffer20
  *Code List: 
  *History:  
     1.Date: 2019/10/29
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    stack<int> stack1;
    stack<int> stack2;
    void push(int value) {
        stack1.push(value);
        if(stack2.empty() || value<stack2.top())
            stack2.push(value);
        else
            stack2.push(stack2.top());
    }
    void pop() {
        if(!stack1.empty() && !stack2.empty()){
            stack1.pop();
            stack2.pop();
        }
    }
    int top() {
        if(!stack1.empty() && !stack2.empty()){
            return stack2.top();
        }
    }
    int min() {
        if(!stack2.empty())
            return stack2.top();
    }
};
