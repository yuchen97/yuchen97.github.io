/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   07Fibonacci.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/18
  *Description:  Please output the nth item of the Fibonacci sequence 
                 (starting at 0, the 0th item is 0).
  *Others:  NewCoderOffer7
  *Code List: 
  *History:  
     1.Date: 2019/10/18
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
class Solution {
public:
    int Fibonacci(int n) {
        if(n <1)
            return 0;
        if(n <= 2)
            return 1;
 
        int first = 1;
        int second = 1;
        int result;
        for(int i=3; i<=n; ++i){
            result = first + second;
            second = first;
            first = result;
        }
        return result;
    }
};