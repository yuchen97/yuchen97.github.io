/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   05theQueuewithStack.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/17
  *Description:  Use two stacks to implement a queue and complete the Push and Pop 
                 operations of the queue. The elements in the queue are of type int.
  *Others:  NewCoderOffer5
  *Code List: 
  *History:  
     1.Date: 2019/10/17
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(stack2.empty() && stack1.empty())
            throw exception(); 
 
        else if (stack2.empty() && !stack1.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
        }
        int topval = stack2.top();
        stack2.pop();
        return topval;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};
