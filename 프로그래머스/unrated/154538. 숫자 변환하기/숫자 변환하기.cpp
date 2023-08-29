#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

bool flag = false;
int total = INT_MAX;
int visited[1000001];

void BFS(int a, int b, int n)
{
    int dx[3] = {2,3,n};
    int start = a;
    queue<pair<int,int>> Q;
    Q.push({start,0});
    visited[start] = 1;
    
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        if (cur.first == b)
        {
            flag = true;
            if (cur.second < total)
                total = cur.second;
        }
        
        for (int i=0;i<3;i++)
        {
            int next;
            if (i==2)
                next = cur.first + dx[i];
            else
                next = cur.first * dx[i];
            
            if (next > b || visited[next] == 1)
                continue;
            
            visited[next] = 1;
            Q.push({next,cur.second+1});
        }
    }
    
}

int solution(int x, int y, int n) {
    BFS(x,y,n);
    if (flag == false)
        return -1;
    
    return total;
}