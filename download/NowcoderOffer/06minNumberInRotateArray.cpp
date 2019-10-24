/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   06minNumberInRotateArray.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/18
  *Description:  Find the min number in a rotate array(Non-decreasing sorted array).
  *Others:  NewCoderOffer6
  *Code List: 
  *History:  
     1.Date: 2019/10/18
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int end = rotateArray.size() - 1;
        int start = 0;
        int mid;
        
        while( rotateArray[start] >= rotateArray[end]){
            if( end-start == 1){
                start = end;
                break;
            }
            mid = (start + end)/2;
            if( rotateArray[start]==rotateArray[end] && rotateArray[mid]==rotateArray[end] ){
                int result = rotateArray[start];
                for(int i=start+1; i<=end; ++i){
                    if( rotateArray[i] < result )
                        result = rotateArray[i];
                }
                return result;
            }
             
            if(rotateArray[start] > rotateArray[mid])
                end = mid;
            else
                start = mid;
        }
        return rotateArray[start];
    }
};