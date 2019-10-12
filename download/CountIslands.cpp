/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   CountIslands.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/11
  *Description:  the question of water and land, and count the number of the island
                (only consider horizontally or vertically)
  *Others:  Assignment1_8(OJ)
  *Code List: 
     1. dfs
     2. bfs with visit
     3. bfs
  *History:  
     1.Date: 2019/10/11
       Author: chenyu
       Modification: create
     2.…………

**********************************************************************************/
/***** dfs
#include <cstdio>
bool map[1010][1010];

void SelectDirection(bool (*map)[1010], int row, int col, int m, int n)
{
    if(row < 0 || row > m-1 || col < 0 || col > n - 1) 
        return;
    if(map[row][col] == 1)
        map[row][col] = 0;
    else
        return;

    SelectDirection(map, row-1, col, m, n);
    SelectDirection(map, row+1, col, m, n);
    SelectDirection(map, row, col-1, m, n);
    SelectDirection(map, row, col+1, m, n);

}

int FindIslandAndCount(bool (*map)[1010], int row, int col)
{
    int cnt = 0;
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            if(map[i][j] == 1)
            {
                SelectDirection(map, i, j, row, col);
                ++cnt;
            }    
    return cnt;
}
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            scanf("%d", &map[i][j]);

    int cnt = FindIslandAndCount(map, row, col);
    printf("%d", cnt);
}
*****/

/*****
// bfs
// Vs = Vsource 起点
// Vn = Vnow 当前点
// Va = Vadjacent 当前点的相邻点
// dir = direction 四个方向


// bfs 用 visit
#include <cstdio>
#include <queue>
using namespace std;
struct Node{
    int x, y;
};

bool visit[1010][1010];
bool grid[1010][1010];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 四个方向

void BFS(Node Vs, bool (*visit)[1010], int row, int col)
{
    Node Vn, Va;
    queue<Node> q;
    q.push(Vs);
    visit[Vs.x][Vs.y] = true;
    
    while (!q.empty())
    {
        Vn = q.front();
        q.pop();
        for(int i=0; i<4; ++i)
        {
            Va = Node({Vn.x + dir[i][0], Vn.y + dir[i][1]});

            if(Va.x < 0 || Va.x > row-1 || Va.y < 0 || Va.y > col -1)
                continue;
            if(grid[Va.x][Va.y] == 0)
                continue;

            if(grid[Va.x][Va.y] == 1 && visit[Va.x][Va.y] == false)
            {
                q.push(Va);
                visit[Va.x][Va.y] = true;
            }
        }
    }
}
int FindIslandAndCount(bool (*grid)[1010], bool (*visit)[1010], int row, int col)
{
    int cnt = 0;
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            if(grid[i][j] == 1 && visit[i][j] == false)
            {
                BFS({i, j}, visit, row, col);
                ++cnt;
            }    
    return cnt;
}
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            visit[i][j] = false;
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            scanf("%d", &grid[i][j]);

    int cnt = FindIslandAndCount(grid, visit, row, col);
    printf("%d", cnt);
}
*****/
// bfs 不用 visit
#include <cstdio>
#include <queue>
using namespace std;
struct Node{
    int x, y;
};

bool grid[1010][1010];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 四个方向
void BFS(Node Vs, int row, int col)
{
    Node Vn, Va;
    queue<Node> q;
    q.push(Vs);
    
    while (!q.empty())
    {
        Vn = q.front();
        q.pop();
        for(int i=0; i<4; ++i)
        {
            Va = Node({Vn.x + dir[i][0], Vn.y + dir[i][1]});

            if(Va.x < 0 || Va.x > row-1 || Va.y < 0 || Va.y > col -1)
                continue;

            if(grid[Va.x][Va.y] == 1)
            {
                q.push(Va);
                grid[Va.x][Va.y] = 0;
            }
            else
                continue;
        }
    }
}
int FindIslandAndCount(bool (*grid)[1010], int row, int col)
{
    int cnt = 0;
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            if(grid[i][j] == 1)
            {
                BFS({i, j}, row, col);
                ++cnt;
            }    
    return cnt;
}
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            scanf("%d", &grid[i][j]);

    int cnt = FindIslandAndCount(grid, row, col);
    printf("%d", cnt);
}
