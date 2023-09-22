#include <string>
#include <vector>
#include <map>
using namespace std;

//map쓰면 될거같음

vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> info;
    int maxVal = 0;
    
    string frag ="";
    for (int i=0;i<s.length();i++)
    {
        
        if (s[i] == ',' || i == s.length()-1)
        {
            int tmp = stoi(frag);
            info[tmp]++;
            frag="";
            
            if (info[tmp] > maxVal)
                maxVal = info[tmp];
        }
        
        else if (s[i] == '{' || s[i] == '}')
            continue;       
        
        else
            frag += s[i];
        
    }
    
    
    while(maxVal>0)
    {
        for (auto iter=info.begin();iter!=info.end();iter++)
        {
            if (iter->second == maxVal)
                answer.push_back(iter->first);
        }
        maxVal--;
    }
    
    
    return answer;
}