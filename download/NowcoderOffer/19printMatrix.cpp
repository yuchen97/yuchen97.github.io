/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   19printMatrix.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/28
  *Description:  Input a matrix and print each number in a clockwise order from the 
                 outside to the inside.
                 For example, if you input the following: 
                    4 X 4 matrix: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
                 Then print out the numbers:
                    1 X 16 matrix: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
  *Others:  NewCoderOffer19
  *Code List: 
  *History:  
     1.Date: 2019/10/28
       Author: chenyu
       Modification: create

**********************************************************************************/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
         
        int cols = matrix[0].size();
        int rows = matrix.size();
        //if(cols < 1 && rows < 1)
        //    return nullptr;
        int start_x = 0;
        int end_x = cols - 1;
        int start_y = 0;
        int end_y = rows - 1;
        vector<int> arr;
        while(start_x<=end_x && start_y<=end_y){
            for(int col=start_x; col<=end_x; ++col)
                arr.push_back(matrix[start_y][col]);
            ++start_y;
             
            for(int row=start_y; row<=end_y; ++row)
                arr.push_back(matrix[row][end_x]);
            --end_x;
             
            if(start_y <= end_y){    // 避免输入只有单行
                for(int col=end_x; col>=start_x; --col)
                    arr.push_back(matrix[end_y][col]);
                --end_y;
            }
             
            if(start_x<=end_x){      // 避免输入只有单列
                for(int row=end_y; row>=start_y; --row)
                    arr.push_back(matrix[row][start_x]);
                ++start_x;
            }
        }
        return arr;
    }
};