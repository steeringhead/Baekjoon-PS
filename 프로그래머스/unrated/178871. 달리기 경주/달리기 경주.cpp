#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {  
    //map을 사용하는 아이디어 OK -> 어떻게 이렇게 생각했나 ?
    //이중포문은 시간초과있음. 그렇기 때문에 map을 사용해야겠다 생각.
    //map을 두개 사용해야함. 다른 문제들도 그렇고
    //투포인터처럼 두개를 사용해야 쉽게 풀리는 문제들이 존재한다는걸 항상 인지.
    vector<string> res;
    
    map<string,int> m1;
    map<int,string> m2;
    
    for (int i=0;i<players.size();i++)
    {
        m1.insert(make_pair(players[i],i));
        m2.insert(make_pair(i,players[i]));
    }
    
    for (int i=0;i<callings.size();i++)
    {
        int tmp = m1[callings[i]];
        string s = m2[tmp - 1];
        m1[callings[i]] = tmp - 1;
        m1[s] = tmp;
        m2[tmp] = s;
        m2[tmp -1] = callings[i];
    }
    
    for (auto t : m2)
        res.push_back(t.second);
    return res;
}