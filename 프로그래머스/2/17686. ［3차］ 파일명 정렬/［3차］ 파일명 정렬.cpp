#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    int idx;
    string HEAD;
    int NUMBER;
    info(int a, string b, int c)
    {
        idx = a;
        HEAD = b;
        NUMBER = c;
    }

    bool operator<(const info& other) const
    {
        if (HEAD == other.HEAD)
        {
            if (NUMBER == other.NUMBER)
                return idx < other.idx;
            else
                return NUMBER < other.NUMBER;
        }
        else
            return HEAD < other.HEAD;
    }
};

vector<info> v;

void analyze(string s, int index)
{
    string head = "";
    string num = "";
    
    int cur = 0;
    
    while(cur < s.length())
    {
        if (s[cur] >= '0' && s[cur] <='9')
        {
            break;
        }            
        head += tolower(s[cur]);
        cur++;
    }
    
    while(cur < s.length())
    {
        if (s[cur] < '0' || s[cur] > '9')
            break;
        
        num += s[cur];
        cur++;
    } 
    
    v.push_back({index,head,stoi(num)});
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    for (int i = 0; i < files.size(); i++)
    {
        analyze(files[i], i);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(files[v[i].idx]);
    }


    return answer;
}
