/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   11NumberOf1.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/20
  *Description:  Enter an integer and output the number of "1" in the binary representation 
                 of the number. The negative number is represented by the complement.
  *Others:  NewCoderOffer11
  *Code List: 
  *History:  
     1.Date: 2019/10/20
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
class Solution {
public:
     int  NumberOf1(int n) {
         ///*****法一
         int cnt = 0;
         int flag = 1;
         while(flag){
             if((n & flag) != 0)
                 ++cnt;
             flag = flag << 1;
         }
         return cnt;
         //*****/
         /***** 法二
         int cnt = 0;
         while(n){
             ++cnt;
             n = (n-1)&n;
         }
         return cnt;
         *****/
     }
};