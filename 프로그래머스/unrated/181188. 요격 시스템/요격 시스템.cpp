#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    
    int answer = 0;
    int idx = 1;
    sort(targets.begin(),targets.end(),cmp);
    
    int end = targets[0][1] ;
    answer++;
    while(idx < targets.size())
    {
        if (targets[idx][0] < end)
        {
            idx++;            
        }
        else
        {
            end = targets[idx][1];
            answer++;
        }
        
    }
    
    
    return answer;
}