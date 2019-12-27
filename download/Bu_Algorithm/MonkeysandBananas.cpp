/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:  MonkeysAndBananas.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/11/27
  *Description:  Given a 'M','B' string and a range K, find the maximum number of matches
  *Others:  Assignment3_6(Greedy OJ A)
            Time: 66ms,	Memory: 2868kb
            Time complexity:O(NK), Space complexity: O(N)
  *History: 
     1.Date: 2019/11/27
       Author: chenyu
       Modification: create

**********************************************************************************/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

long long int MaxBananasEaten (vector<char> vec, int K) {
    long long int cnt = 0;
    vector<bool> visit(vec.size());
 
    for (long long int index=0; index<vec.size(); ++index) {
        if (visit[index] == true) {
            continue;
        }
        for (long long int i=1; (i<=K) && (index+i < vec.size()); ++i) {    // 在 K 范围内，且没有数组越界
            if ((vec[index] != vec[index+i]) && (visit[index+i] == false)) {    // 不相等说明一个 M 一个 B，false 表示没有配对过
                ++cnt;
                // 配对之后更新标志位
                visit[index+i] = true; // 已配对
                visit[index] = true;
                break;
            }
        }
    }
    return cnt;
}

int main() {
    vector<char> vec;
    string str;
    long long int K;
    char c;
    long long int result = 0;
    
    while ((c = getchar()) != '\n') {
        ungetc(c, stdin);   // 将读到的字符回退到输入流中
        cin >> str;
        cin >> K;
        for (long long int i=0; i<str.length(); ++i) {
            vec.push_back(str[i]);
        }
        if (K > 0) {
            result = MaxBananasEaten (vec, K);
        }
        
    }
 
    cout << result;

    return 0;
}