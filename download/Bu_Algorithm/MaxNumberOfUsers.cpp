/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:  Maxnumberofusers.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/11/05
  *Description:  There is a server which has the disk space of M and the memory of N. 
                 Given some tasks, the i-th task needs the disk space of Xi and the 
                 memory of Yi, and it can serve Ui users. Design an algorithm and 
                 implement it to find out the maximum number of users that this server
                 can serve simultaneously.
  *Others:  Assignment2_7(Dynamic-Programming OJ B)
  *Code List:  
     1. QuickSort->n/2 and O(nlogn)
     2. Topk and O(n)
     3. Using array features and O(n)
  *History:  
     1.Date: 2019/10/11
       Author: chenyu
       Modification: create

**********************************************************************************/
#include<cstdio>
int dp[1010][1010] = {0};
int m[1010], n[1010], v[1010];

int Maxnumberofusers(int* param, int* m, int* n, int *v){
    if(m == nullptr || n == nullptr || v == nullptr)
        return 0;

    int M = param[0], N = param[1], K = param[2];
    for(int k=1; k<=K; ++k){
        for(int i=M; i>=m[k]; --i){
            for(int j=N; j>=n[k]; --j){
                dp[i][j] = dp[i][j] > dp[i-m[k]][j-n[k]]+v[k] ? dp[i][j] : dp[i-m[k]][j-n[k]]+v[k];
            }
        }
    }
    return dp[M][N];

}
int main(){
    int param[2];
    scanf("%d %d %d", &param[0], &param[1], &param[2]); // M N K

    for(int i=1; i<=param[2]; ++i)
        scanf("%d %d %d", &m[i], &n[i], &v[i]);
    int maxpeople = Maxnumberofusers(param, m, n, v);
    printf("%d", maxpeople);
    return 0;
}
