/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   13reOrderArray.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/22
  *Description:  Adjust the order of the numbers in the array, put all the odd numbers 
                 in the first half of the array, all the even numbers in the second half, 
                 and ensure that the relative positions between odd and odd, even and even 
                 are unchanged.
  *Others:  NewCoderOffer13
  *Code List: 
  *History:  
     1.Date: 2019/10/22
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return ;
        int cnt = 0;
        int len = array.size();
        vector<int> array_temp(len);
        for(int i=0, j=len, k=0; i<len; ++i){
            if(array[i] & 1){ // odd number
                array_temp[k++] = array[i];
                ++cnt;
            } else
                array_temp[--j] = array[i];
        }
  
        for(int i=cnt,j=len; i<(cnt+len)/2; ++i){
            int temp = array_temp[i];
            array_temp[i] = array_temp[--j];
            array_temp[j] = temp;
        }
        for(int i=0; i<len; ++i){
           array[i] = array_temp[i];
        }
    }
};