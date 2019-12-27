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
        for (long long int i=1; (i<=K) && (index+i < vec.size()); ++i) {    // In the K range and no array out of bounds
            if ((vec[index] != vec[index+i]) && (visit[index+i] == false)) {    // Not equal means one M and one B, false means no pairing
                ++cnt;
                // Update flag bit after pairing
                visit[index+i] = true; // Paired
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
        ungetc(c, stdin);   // Roll back the characters read to the input stream
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