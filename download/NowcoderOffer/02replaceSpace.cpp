/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   02replaceSpace.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/14
  *Description:  Replace each space in a string with "%20".
                 We Are Happy ---> We%20Are%20Happy
  *Others:  NewCoderOffer2
  *Code List: 
  *History:  
     1.Date: 2019/10/14
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0)
            return;
        int cnt = 0;
        for(int i=0; i<length; ++i){
            if(str[i] == ' ')
                ++cnt;
        }
        int newlength = length + 2*cnt;
 
        for(int i=length-1; i>=0; --i){
            if(str[i] == ' '){
                str[--newlength] = '0';
                str[--newlength] = '2';
                str[--newlength] = '%';
            }
            else{
                str[--newlength] = str[i];
            }
 
        }
    }
};