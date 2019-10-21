/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   08jumpFloor.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/18
  *Description:  A frog can jump to the first step or jump to the second level. The 
                 frog to jump on an n-level step. 
                 How many kinds of jumps are there. 
  *Others:  NewCoderOffer8
  *Code List: 
  *History:  
     1.Date: 2019/10/18
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
class Solution {
public:
    int jumpFloor(int number) {
        if(number < 1)
            return 0;
        if(number <= 2)
            return number;
 
        int first = 1;
        int second = 2;
        int result;
        for(int i=3; i<=number; ++i){
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};
