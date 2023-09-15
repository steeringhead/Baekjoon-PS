#include <string>
#include <vector>

using namespace std;

string start[5] ={"A","E","I","O","U"};

vector<string> ans;

void MakeDict(string tmp)
{
    ans.push_back(tmp);
        
    if (tmp.length() == 5)
        return;
    
    for (int i=0;i<5;i++)
    {
        tmp += start[i];        
        MakeDict(tmp);
        tmp.pop_back();
    }
    
}

int solution(string word) {
    int answer = 0;
    
    for (int i=0;i<5;i++)
    {
        MakeDict(start[i]);
    }
    
    for(int i=0;i<ans.size();i++)
    {
        if (ans[i] == word)
            answer = i+1;
    }
    
    return answer;
}