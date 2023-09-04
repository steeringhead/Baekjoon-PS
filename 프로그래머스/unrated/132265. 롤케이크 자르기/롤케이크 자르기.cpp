#include <string>
#include <vector>
#include <map>

using namespace std;

//완탐은 시간초과



int solution(vector<int> topping) {
    int answer = 0;
    
    map<int,int> lm;
    map<int,int> rm;
    lm[topping[0]]++;
    for (int i=1;i<topping.size();i++)
    {
        rm[topping[i]]++;
    }
    
    int idx=0;
    while(idx<topping.size())
    {
        if (lm.size() == rm.size())
            answer++;
        idx++;
        lm[topping[idx]]++;
        rm[topping[idx]]--;
        if (rm[topping[idx]] == 0)
        {
            rm.erase(topping[idx]);
        }
    }
    
    
    return answer;
}