#include <string>
#include <vector>

using namespace std;


string ToBinary(int val)
{
    vector<int> v;
    while(val!=0)
    {
        v.push_back(val % 2);
        val = val/2;
    }
    string tmp = "";
    for (int i=v.size()-1;i>=0;i--)
    {
        tmp += to_string(v[i]);
    }
    
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCnt = 0;
    string curString = s;
    int curVal = 0;
    int totalCnt = 0;
    
    while(true)
    {
        totalCnt++;
        for (int i=0;i<curString.length();i++)
        {
            if (curString[i] == '0')
                zeroCnt++;
            else
                curVal++;    
        }
        
        curString = ToBinary(curVal);
        if (curString == "1")
            break;
        else
            curVal = 0;
        
    }
    
    answer.push_back(totalCnt);
    answer.push_back(zeroCnt);
    return answer;
}