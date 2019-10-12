/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:  FindtheMajorityElement.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/08
  *Description:  The majority element is the element that appears more than 
                \lfloor n/2 \rfloor times.
  *Others:  Assignment1_7(OJ)
  *Code List:  //主要函数列表，每条记录应包含函数名及功能简要说明
     1. QuickSort->n/2 and O(nlogn)
     2. Topk and O(n)
     3. Using array features and O(n)
  *History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
     1.Date: 2019/10/11
       Author: chenyu
       Modification: create

**********************************************************************************/
#include<cstdio>
int arr[5000010];

/*****
// Easy thinking and complexity O(nlogn)
#include<algorithm> 
using namespace std;
int Partition(int* arr, int start, int end)
{
    sort(arr, n);
    return arr[n/2];
}
*****/
/*****
// QuickSort thinking and complexity O(n)
int Partition(int* arr, int start, int end)
{
    int small = start-1;
    for(int index=start; index<end-1; ++index)
    {
        if(arr[index] < arr[end-1])
        {
            ++small;
            if(small != index)
            {
                int temp = arr[index];
                arr[index] = arr[small];
                arr[small] = temp; 
            }
        }
    }

    int temp = arr[end-1];
    arr[end-1] = arr[++small];
    arr[small] = temp;
    return small; 
}
int FindtheMajorElement(int* arr, int n)
{
    int mid = n >> 1;
    int start = 0;
    int end = n;
    int index = Partition(arr, start, end); // O(n)
    while(index != mid) // T(n/2)
    {
        if(index < mid)
        {
            start = index+1;
            index = Partition(arr, start, end);
        }
        else
        {
            end = index-1;
            index = Partition(arr, start, end);  
        }
    }
    int result = arr[index];
    return result;
}
*****/

// Easy and complexity O(n)
int FindtheMajorElement(int* arr, int n)
{
    int majorelement;
    int times = 0;
    for(int i=0; i<n; ++i)    // majority element占一半以上，所以先加后减完最后剩的肯定是 majorelement
    {
        //printf("test %d",arr[i]);
        if(times==0)
        {
            majorelement = arr[i];
            times = 1; 
        }
        else if(majorelement==arr[i])
        {
            ++times;    // majorelement与下一个相同就加，否则就减
        } else {
            --times;
        }
    }
    return majorelement;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &arr[i]);
    int majorelement = FindtheMajorElement(arr, n);
    printf("%d", majorelement);
    return 0;
}