#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m; //크기,갯수
    
    for (int i=0;i<tangerine.size();i++)
    {
        m[tangerine[i]]++;
    }
    
    vector<pair<int,int>> v; //(map.begin(), map.end())
    for (auto& it : m)
    {
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),cmp);
        
    int idx = 0;
    while(k>0)
    {
        k -= v[idx].second;
        idx++;
    }
    
    return idx;
}