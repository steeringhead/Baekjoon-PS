#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> res;

void SoloGame(int idx,vector<int> cards,int count)
{
    int cnt = count;
    int curCnt = 0;
    int curIdx = idx;
    
    while(true)
    {
        int curVal = cards[curIdx];
        
        if (curVal != 0)
        {
            cards[curIdx] = 0;
            curIdx = curVal-1;
            curCnt++;
        }
        else
        {
            break;
        }        
    }
    
    
    
    if (cnt != 0 || curCnt + cnt == cards.size())
    {
        res.push_back(cnt * curCnt);
        return;
    }
        
    
    for (int i=0;i<cards.size();i++)
    {
        if (cards[i] != 0)
            SoloGame(i,cards,curCnt);
    }
    
    
}

int solution(vector<int> cards) {
    
    for (int i=0;i<cards.size();i++)
    {
        SoloGame(i,cards,0);
    }
    sort(res.begin(),res.end());
        
    return res[res.size()-1];
}