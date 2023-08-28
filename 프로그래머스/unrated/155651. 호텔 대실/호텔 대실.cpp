#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//정렬부터

struct Task
{
    string sT;
    string eT;
    Task (string x,string y)
    {
        sT = x;
        eT = y;
    }
    
    bool operator<(const Task& other) const
    {   
        if (stoi(sT.substr(0,2)) != stoi(other.sT.substr(0,2)))
            return stoi(sT.substr(0,2)) < stoi(other.sT.substr(0,2));
        else
            return stoi(sT.substr(3,5)) < stoi(other.sT.substr(3,5));
    }
};

bool cmp(const pair<int,string>& x,const pair<int,string>& y)
{
    if (stoi(x.second.substr(0,2)) != stoi(y.second.substr(0,2)))
            return stoi(x.second.substr(0,2)) < stoi(y.second.substr(0,2));
    else
        return stoi(x.second.substr(3,5)) < stoi(y.second.substr(3,5));
}

int solution(vector<vector<string>> book_time) {
    vector<Task> v;
    for (int i = 0; i < book_time.size(); i++)
    {
        v.push_back(Task(book_time[i][0], book_time[i][1]));
    }
    sort(v.begin(), v.end());

    vector<pair<int, string>> sub;

    for (int i = 0; i < v.size(); i++)
    {
        if (sub.empty())
        {
            sub.push_back({ 1,v[i].eT });
        }
        else
        {
            for (int j = 0; j < sub.size(); j++)
            {
                int sTmp = stoi(v[i].sT.substr(0, 2)) * 60 + stoi(v[i].sT.substr(3, 5));
                int eTmp = stoi(sub[j].second.substr(0, 2)) * 60 + stoi(sub[j].second.substr(3, 5));
                if (eTmp + 10 > sTmp)
                {
                    sub.push_back({ sub.size() + 1,v[i].eT });
                    break;
                }
                else
                {
                    sub[j].second = v[i].eT;
                    break;
                }
            }
            sort(sub.begin(), sub.end(), cmp);
        }
        
    }

    return sub.size();
}