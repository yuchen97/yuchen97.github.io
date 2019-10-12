/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   CountInversion.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/09/11
  *Description:  count the number of the inversions, and ai > 3aj
  *Others:  test0 (OJ2)
  *Code List: 
     1. Divide and Conquer
  *History:  
     1.Date: 2019/09/09
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
#include<iostream>
using namespace std;
long long int Merge(int* data, int* tmp_data, int left, int mid, int right) // Conquer
{
    int i = mid;
    int j = right;
    long long int cnt = 0;
    while(i >= left && j >= mid + 1)    // 计算满足要求的逆序对数
    {
        if(data[i] - data[j] > data[j] + data[j])   // 将data[i]>3data[j]改成左边形式可以节省空间 
        {
            cnt += j - mid;     // 如果是满足要求的逆序对，计数+j-mid，因为left和right都是递增排序的
            i--;                // i 指向上一个数组元素
        }    
        else
            j--;                // j 指向上一个元素
    }

    i = mid;
    j = right;    
    int tmp_right = right;
    while(i >= left && j >= mid + 1)  // 将 left 和 right 两边的递增序列重新组合成一个新的递增序列
    {
        if(data[i] > data[j])
        {
            tmp_data[tmp_right--] = data[i--];
        }    
        else
            tmp_data[tmp_right--] = data[j--];
    }


    while (i >= left)       // 将其余未比较的元素也附加上
       tmp_data[tmp_right--] = data[i--];
    while (j >= mid + 1) 
       tmp_data[tmp_right--] = data[j--];
 
    for(int i=left; i <= right; ++i)   // tmp_data 与 data 交换
        data[i] = tmp_data[i];
   
    
    for(int i=0; i<6; ++i)
        cout << data[i] << " ";
    cout << endl; 
    return cnt;
}


long long int InversePairs(int* data, int* tmp_data, int left, int right)   // Divide
{
    long long int cnt = 0;
    
    if(left < right)    // left >= right 时结束递归
    {
        int mid = (left + right)/2;
        cnt += InversePairs(data, tmp_data, left, mid); 
        cnt += InversePairs(data, tmp_data, mid + 1, right);
        cnt += Merge(data, tmp_data, left, mid, right);  
    }
    return cnt;
}


int main()
{
    ios::sync_with_stdio(false);   // 提速 
	int len;
    int data[100010];

    cin >> len;
    for(int i=0; i < len; ++i)
        cin >> data[i];
    
    int* tmp_data = new int[len];
    long long int cnt = InversePairs(data, tmp_data, 0, len - 1);
    delete[] tmp_data;

    cout << cnt;
    return 0;
}