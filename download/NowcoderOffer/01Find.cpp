/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   Find.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/14
  *Description:  Enter an integer to determine if  if it is in a two-dimensional(nxn)
                 array. The array, each row and column, is in ascending order.
  *Others:  NewCoderOffer1
  *Code List: 
  *History:  
     1.Date: 2019/10/14
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        if( array[0].empty() || array[0][0] > target || array[row-1][col-1] < target)
            return false;
        
        for(int j=0; row-1>=0 && j<col;){
            if(target == array[row-1][j])
                return true;
            else if(target > array[row-1][j])
                ++j;
            else
                --row;
        }
        return false;
    }
};