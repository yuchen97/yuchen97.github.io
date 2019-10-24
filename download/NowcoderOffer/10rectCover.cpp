/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   10rectCover.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/18
  *Description:  We can cover a larger rectangle with a 2*1 small rectangle horizontally 
                 or vertically. 
                 How many methods are there to cover a 2*n large rectangle with n 2*1 
                 small rectangles without overlapping?
  *Others:  NewCoderOffer10
  *Code List: 
  *History:  
     1.Date: 2019/10/18
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    int rectCover(int number) {
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