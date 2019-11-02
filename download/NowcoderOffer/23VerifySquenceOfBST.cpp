/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   23VerifySquenceOfBST.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/11/01
  *Description:  Input an array of integers to determine if the array is the result 
                 of a subsequent traversal of a binary search tree. If yes, output Yes, 
                 otherwise output No. Assume that any two numbers in the input array 
                 are different from each other.
  *Others:  NewCoderOffer23
  *Code List: 
  *History:  
     1.Date: 2019/11/01
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len == 0) return false;
        if(len <= 2) return true;
        int i = 0;
        vector<int> leftseq, rightseq;
        for(; i<len-1; ++i){
            if(sequence[i] > sequence[len-1])
                break;
            else
                leftseq.push_back(sequence[i]);
        }
        if(leftseq.size()==0) // solve 5,4,3,2,1
            leftseq.push_back(1);
        for(; i<len-1; ++i){
            if(sequence[i]<sequence[len-1])
                return false;
            else
                rightseq.push_back(sequence[i]);
        }
        if(rightseq.size()==0) // solve 1,2,3,4,5
            rightseq.push_back(1);
        return VerifySquenceOfBST(leftseq) && VerifySquenceOfBST(rightseq);
    }
};