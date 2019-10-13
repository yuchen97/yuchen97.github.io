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
    while(i >= left && j >= mid + 1)    // count the number of inverison
    {
        if(data[i] - data[j] > data[j] + data[j])   // use ai-aj>aj+aj can save some memory instead of ai>3aj 
        {
            cnt += j - mid;     // if it satisfies the requirement, cnt=cnt+j-mid. Because left and right sequences are increment
            i--;                // i point to the previous array element
        }    
        else
            j--;                // j point to the previous array element
    }

    i = mid;
    j = right;    
    int tmp_right = right;
    while(i >= left && j >= mid + 1)  // Reassemble the incremental sequences on both left and right into a new incremental sequence
    {
        if(data[i] > data[j])
        {
            tmp_data[tmp_right--] = data[i--];
        }    
        else
            tmp_data[tmp_right--] = data[j--];
    }


    while (i >= left)       // Attach the remaining uncompared elements
       tmp_data[tmp_right--] = data[i--];
    while (j >= mid + 1) 
       tmp_data[tmp_right--] = data[j--];
 
    for(int i=left; i <= right; ++i)   // tmp_data changes with data
        data[i] = tmp_data[i];
   
    
    for(int i=0; i<6; ++i)
        cout << data[i] << " ";
    cout << endl; 
    return cnt;
}


long long int InversePairs(int* data, int* tmp_data, int left, int right)   // Divide
{
    long long int cnt = 0;
    
    if(left < right)    // when left >= right end recursion
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
    ios::sync_with_stdio(false);   // Speed up 
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