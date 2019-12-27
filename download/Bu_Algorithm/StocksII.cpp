/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:  StocksII.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/11/28
  *Description:   Best Time to Buy and Sell Stock II
                  buy one and sell one share of the stock multiple times.
  *Others:  Assignment3_5(Greedy OJ B)
            Time: 2947ms,	Memory: 2764kb
            Time complexity:O(NK), Space complexity: O(N)
  *History: 
     1.Date: 2019/11/28
       Author: chenyu
       Modification: create

**********************************************************************************/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/**
 * Method one
 * Time 3174ms	Memory 10352kb
**/
/*
long long int FindMaxProfit (vector<int> stocks) {
    if (stocks.empty()) {
        return 0;
    }
    long long int profit = 0;

    for (int i=0; i<stocks.size()-1; ++i) {
        if (stocks[i] < stocks[i+1]) {
            profit += stocks[i+1] - stocks[i];
        } 
    }
    return profit;
}


int main() {
    long long int stock, res = 0;
    vector<int> stocks;
    char c;
    while (true) {
        if ((c = cin.get()) == '\n') {    // 如果放到前面它会 cin 一个值，这样最后就会少最前面的值
            break;
        }
        ungetc(c, stdin);
        cin >> stock;
        stocks.push_back(stock);

    }
    res = FindMaxProfit(stocks);
    cout << res;
    return 0;
}
*/

/**
 * Method one
**/
int main() {
    long int stock, res = 0;
    queue<long int> q;
    vector<int> stocks;
    char c;
    while (true) {
//        if ((c = cin.get()) == '\n') Time 3196ms 	Memory 2828kb
        if ((c = getchar()) == '\n') {  // Time 2947ms	Memory 2764kb
            break;
        }
        ungetc(c, stdin);
        cin >> stock;   // 4 5 11 12

        q.push(stock);
        if (q.size() == 2) {    // 4 5 --- 5 11 --- 11 12
            if (q.back() > q.front()) {
                res += q.back() - q.front();
            }
            q.pop(); // 5 ---11 ---12 
        }
    }

    cout << res;
    return 0;
}

/*
int main() {
    long long int stock, stock2 = 0, res = 0;
    vector<int> stocks;
    char c;

    do {
        cin >> stock;
        stocks.push_back(stock);
    } while (cin.get() != '\n');

    if (scanf("%d",&stock)) {
        long long stock1 = stock;
        while (scanf("%d",&stock)) {
            stock2 = stock;
            if (stock2 > stock1) {
                res += stock2 - stock1;
            }
            stock1 = stock2;
            stocks.push_back(stock);
                if (c == '\n') {
                break;
            }
        }
    }

    cout << res;
    return 0;
}
*/