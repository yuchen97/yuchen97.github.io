/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:  VolunteerRecruitment.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/12/22
  *Description:   Get the most from the least money (Linear programming)
  *Others:  Assignment4_4(LP OJ A)
            Time: 164ms,	Memory: 8412kb
  *History: 
     1.Date: 2019/12/22
       Author: chenyu
       Modification: create

**********************************************************************************/
#include <iostream>
#include <cmath>
#define N 1010
#define M 10100
using namespace std;
const double INF = 1e10;
const double eps = 1e-7;
int n, m;
double A[M][N], b[M], c[N], v;
void Pivot(int l, int e)
{
	b[l] /= A[l][e];
	for (int i = 1; i <= n; i++)
		if (i != e)
			A[l][i] /= A[l][e];
	A[l][e] /= A[l][e];

	for (int i = 1; i <= m; i++)
		if (i != l && fabs(A[i][e])>eps)
		{
			b[i] -= A[i][e] * b[l];
			for (int j = 1; j <= n; j++)
				if (j != e)
					A[i][j] -= A[i][e] * A[l][j];
			A[i][e] =- A[i][e] * A[l][e];
            // cout << "----------" << endl;
            // cout << A[i][e];
            // cout << "----------" << endl;
		}

	v += c[e] * b[l];   // v = -z,, -z = -z - c[e]b[l]
	for (int i = 1; i <= n; i++)
		if (i != e)
			c[i] -= c[e] * A[l][i];
	c[e] =- c[e] * A[l][e];
}
double Simplex()
{
	int i, l, e;
	while (true)
	{
		for (i = 1; i <= n; i++)
			if (c[i]>eps) break;
		if ((e = i) == n + 1) return v;
		double tmp = INF;
		for (i = 1; i <= m; i++)
			if (A[i][e]>eps && b[i] / A[i][e]<tmp)
				tmp = b[i] / A[i][e], l = i;
		if (tmp == INF) return INF;
		Pivot(l, e);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin>>c[i];
	for (int i = 1, x, y; i <= m; i++)
	{
		cin>>x>>y>>b[i];
		for (int j = x; j <= y; j++)
			A[i][j] = 1;
	}
	double ans = Simplex();

	cout<< int(ans + 0.5);
	return 0;
}