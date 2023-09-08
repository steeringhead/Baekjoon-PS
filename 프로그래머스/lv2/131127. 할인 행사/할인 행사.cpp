#include <string>
#include <vector>
#include <map>

using namespace std;

//완탐이냐 아니냐.

int answer = 0;

void check(int idx,vector<string>& discount,map<string,int> buy)
{
    int curIdx = idx;
    
    for (int i=0;i<10;i++)
    {
        if (curIdx >= discount.size())
            return;
        
        string tmp = discount[curIdx];
        buy[tmp]--;
        curIdx++;
    }
    
    bool flag = true;
    for(auto it=buy.begin();it != buy.end();it++)
    {
        if (it->second > 0)
        {
            flag = false;
            break;
        }
    }
    
    if (flag == true)
        answer++;    
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    
    map<string,int> buy;
    
    for (int i=0;i<want.size();i++)
    {
        buy[want[i]] = number[i];
    }
    
    for (int i=0;i<discount.size();i++)
    {   
        check(i,discount,buy);
    }
    
    return answer;
}