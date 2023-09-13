#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[8];
vector<int> ans;

void Search(int k,int size,int cnt,vector<vector<int>>& dungeons)
{
    for (int i=0;i<size;i++)
    {
        if (visited[i] == 0 && dungeons[i][0] <= k)
        {
            visited[i] = 1;
            Search(k-dungeons[i][1],size,cnt+1,dungeons);
            visited[i] = 0;
                
        }
    }
    ans.push_back(cnt);    
}

int solution(int k, vector<vector<int>> dungeons) {
        
    for (int i=0;i<dungeons.size();i++)
    {
        if (dungeons[i][0] <= k)
        {
            visited[i] = 1;
            Search(k-dungeons[i][1],dungeons.size(),1,dungeons);
            visited[i] = 0;
        }
        
    }
    sort(ans.begin(),ans.end());
    
    return ans.back();
}