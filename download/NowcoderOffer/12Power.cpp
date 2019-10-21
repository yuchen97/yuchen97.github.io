/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   12Power.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/20
  *Description:  Enter an integer and output the number of "1" in the binary representation 
                 of the number. The negative number is represented by the complement.
  *Others:  NewCoderOffer12
  *Code List: 
  *History:  
     1.Date: 2019/10/20
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
class Solution {
public:
    double Power(double base, int exponent) {
        /*****if(base == 0)
            return 0;
        if(exponent == 0)
            return 1;
        bool flag = true;
        int cnt = 0;
        double result = base;
        unsigned int absExponet = (unsigned int) exponent;
        if(exponent < 0){
            absExponet = (unsigned int) (-exponent);
            flag = false;
        }
        for(int i=absExponet; i>1; i=i/2){
            if(i%2 == 1){
                ++cnt;
            } else
                result = result*result;
        }
        if(absExponet%2 == 1){
            //++cnt;
            while(cnt){
                result = base*result;
                --cnt;
            }
        }
        if(flag)
            return result;
        else
            return 1/result;
            *****/
        unsigned int absExponent;
        if(exponent < 0){
            if(base == 0)
                return 0;
            absExponent = -exponent;
        } else {
            absExponent = exponent;
        }
        double result = 1;
        while(absExponent != 0){
            if((absExponent & 1) == 1)
                result *= base;
            base *= base;
            absExponent >>= 1;
        }
        return exponent>0 ? result:1/result;
             
    }
};
