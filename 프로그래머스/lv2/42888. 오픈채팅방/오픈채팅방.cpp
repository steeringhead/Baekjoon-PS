#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> result, state;
    map<string,string> m;
    
    for(int i=0;i<record.size();i++)
    {
        stringstream ss(record[i]);
        string str[3];
        string tmp;
        int idx = 0;
        while(ss >> tmp)
          str[idx++] = tmp;
        
        if (str[0] == "Enter")
        {
            state.push_back("들어왔습니다.");
            result.push_back(str[1]);
            m[str[1]] = str[2];
        }
        else if (str[0] == "Leave")
        {
            state.push_back("나갔습니다.");
            result.push_back(str[1]);
        }
        else
        {
            m[str[1]] = str[2];
        }
    }
    
    for (int i=0;i<result.size();i++)
    {
        result[i] = m[result[i]] + "님이 " + state[i];
    }
    
    return result;
}