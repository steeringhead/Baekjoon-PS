#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//구조체랑 스택이용해서
//남은시간 스택에 저장해두고 꺼내서 완료하는 방식

struct Task
{
    string name;
    string startTime;
    string needTime;
    
    Task(string a,string b,string c)
    {
        name = a;
        startTime = b;
        needTime = c;
    }
    
    bool operator<(const Task& other) const
    {
        return stoi(startTime.substr(0,2) + startTime.substr(3,5))
            < stoi(other.startTime.substr(0,2) + other.startTime.substr(3,5));
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<Task> pL;
    for (int i = 0; i < plans.size(); i++)
    {
        pL.push_back(Task(plans[i][0], plans[i][1], plans[i][2]));
    }
    sort(pL.begin(), pL.end());

    vector<pair<string, int>> v;
    vector<string> ans;
    //일단 여기까지는 야무지게 잘들어옴 . 이 뒤 로직만 잘짜면 답나올듯

    int time = 0;

    for (Task T : pL)
    {
        int nTime = stoi(T.startTime.substr(0, 3)) * 60 + stoi(T.startTime.substr(3, 5));
        while (time < nTime)
        {
            if (v.size() > 0)
            {
                v.back().second--;
                if (v.back().second == 0)
                {
                    ans.push_back(v.back().first);
                    v.pop_back();
                }
            }
            time++;
        }
        v.push_back({ T.name , stoi(T.needTime)});
    }
    
    while (v.size() > 0)
    {
        ans.push_back(v.back().first);
        v.pop_back();
    }
    return ans;
}