#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int res = INT_MAX;
int visited[100][100];

struct Node
{
    int x;
    int y;
    int cnt;
        
    Node(int a,int b,int c)
    {
        x = a;
        y = b;
        cnt = c; 
    }
};

void BFS(int x,int y,vector<string>& map)
{
    queue<Node> Q;
    Q.push(Node(x,y,0));
    visited[x][y] = 1;
    
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (map[cur.x][cur.y] == 'G')
        {
            res = min(cur.cnt,res);
        }
        
        for (int i=0;i<4;i++)
        {
            int nX = cur.x + dx[i];
            int nY = cur.y + dy[i];
            int cnt = cur.cnt;
            
            if ((nX < 0 || map.size() <= nX || nY < 0 || map[0].length() <= nY) || map[nX][nY] == 'D') continue;                     
            
            while (true) {
                nX += dx[i];
                nY += dy[i];
                
                if ((nX < 0 || map.size() <= nX || nY < 0 || map[0].length() <= nY) || map[nX][nY] == 'D') 
                {
                    nX -= dx[i];
                    nY -= dy[i];
                    break;
                }
            }
           
            if (visited[nX][nY] == 1) continue;
            
            Q.push(Node(nX,nY,cnt+1));
            visited[nX][nY] = 1;
            
        }
    }
}

int solution(vector<string> board) {   
    
    for (int i=0;i<board.size();i++)
    {
        for (int j=0;j<board[0].length();j++)
        {
            if (board[i][j] == 'R')
            {
                BFS(i,j,board);                
            }
        }
    }
    
    if (res != INT_MAX)
    {
        return res;
    }
    
    else
    {
        return -1;
    }
    
}