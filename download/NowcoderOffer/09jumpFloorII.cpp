/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   09jumpFloorII.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/18
  *Description:  A frog can jump to 1 step at a time, or jump to level 2... It can 
                 also jump to level n. The frog to jump on an n-level step in total.
                 How many kinds of jumps are there. 
  *Others:  NewCoderOffer9
  *Code List: 
  *History:  
     1.Date: 2019/10/18
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    int jumpFloorII(int number) {
        /***** method 1
        if(number < 1)
            return 0;
         
        int value_dic[number+1];
        for (int i=0; i<number+1; ++i){
            value_dic[i] = 0;
        }
         
        if(number == 1){
            return 1;
        }
        int ans = 0;
        for(int i=1; i<number; ++i){
            if(value_dic[i] == 0)
                value_dic[i] = jumpFloorII(i);
            ans += value_dic[i];
        }
         
        return ans += 1;
        *****/
        /***** method 2
        if(number < 1)
            return 0;
        if(number == 1)
            return 1;
        return 2*jumpFloorII(number-1);
        *****/
        ///***** method 3
        if(number < 1)
            return 0;
        return 1 << (number-1);
        //*****/
    }
};