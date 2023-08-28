#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N,M;
int visited[100][100];
int dist = 0;

void DFS(int x,int y,vector<string>& maps)
{
    visited[x][y] = 1;
    dist += maps[x][y]-'0';
    
    for (int i=0;i<4;i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];        
        
        if (nX < 0 || nX >= N || nY < 0 || nY >= M || maps[nX][nY] == 'X')
            continue;
        if (visited[nX][nY] == 1)
            continue;       
        
        DFS(nX,nY,maps);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = maps.size();
    M = maps[0].length();
    
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            if (maps[i][j] != 'X' && visited[i][j] == 0)
            {
                DFS(i,j,maps);
                answer.push_back(dist);
                dist = 0;
            }   
        }
    }
    
    sort(answer.begin(),answer.end());
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
        
    return answer;
}