/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:  LongestComSubseq.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/08
  *Description:  Given two sequences, find the length of the longest common subsequence (LCS). 
                 A subsequence is different from a substring, for the former need NOT be 
                 consecutive of the original sequence. For example, for “ABCD" and “AEFC", 
                 the longest common subsequence is “AC", and the length of it is 2.
  *Others:  Assignment2_6(Dynamic-Programming OJ B)
  *History: 
     1.Date: 2019/11/06
       Author: chenyu
       Modification: create

**********************************************************************************/
#include<cstdio>
int dp[1010][1010] = {0};
int num;
int len1[110], len2[110];
char seq1[110][1010], seq2[110][1010];
int cnt[110] = {0};

int* LongestComSubseq(int* len1, int* len2, char (*seq1)[1010], char (*seq2)[1010], int N){
    // if it is defined in a function, it is a local variable, it will be released 
    // when the function ends, so the return value will be wrong.
    //int cnt[N+1] = {0}; Either defined in main and passed in, or define global variables
    if(N <= 0)
        return cnt;

    for(int t=1; t<=N; ++t){
        for(int i=1; i<=len1[t]; ++i){
            for(int j=1; j<=len2[t]; ++j){
                if(seq1[t][i-1] == seq2[t][j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }
        cnt[t-1] = dp[len1[t]][len2[t]]; // cnt starts with subscript 0
    }

    return cnt;
}

int main(){
    int N;
    scanf("%d", &N); // N pairs

    for(int i=1; i<=N; ++i){
        scanf("%d %d", &len1[i], &len2[i]); // length of seq
        scanf("%s %s", seq1[i], seq2[i]); // the contains of seq
    }

    int* p = LongestComSubseq(len1, len2, seq1, seq2, N);

    for(int i=0; i<N; ++i){
        printf("%d\n", p[i]);
    }
    
    return 0;
}
