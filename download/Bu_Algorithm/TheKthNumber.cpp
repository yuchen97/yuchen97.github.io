/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   TheKthNumber.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/09/08
  *Description:  the kth largest number in an unsort array
  *Others:  test0 (OJ1)
  *Code List: 
     1. topk
  *History:  
     1.Date: 2019/09/09
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
#include<cstdio>
int data[5000010];

int Partition(int data[], int length, int start, int end)
{
    int index = 0;
    int large = start - 1;
    for(index = start; index < end; ++index)
    {
        if(data[index] > data[end])
        {
            ++large;
            if(large != index)
            {
                int tmp;
                tmp = data[large];
                data[large] = data[index];
                data[index] = tmp;
            }
        }
    }
    ++large;
    int tmp;
    tmp = data[large];
    data[large] = data[end];    
    data[end] = tmp;
    return large;
}

int main()
{
    int length, k;

    scanf("%d", &length);
    scanf("%d", &k);
    for(int i = 0; i < length; ++i)
        scanf("%d", &data[i]);

    int start = 0;
    int end = length - 1;
    while (true)
    {
        int pos = Partition(data, length, start, end);
        if(k - 1 == pos)
        {
            printf("%d",data[pos]);
            break;
        }
        if(k - 1 > pos)
            start = pos + 1;
        else
            end = pos - 1;
    }
    
    return 0;
}