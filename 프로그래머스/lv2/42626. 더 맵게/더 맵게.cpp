#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Info
{
    int val;
    Info(int a)
    {
        val = a;
    }
    
    bool operator<(const Info& other) const
    {
        return val > other.val;
    }
};

priority_queue<Info> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i=0;i<scoville.size();i++)
    {
        pq.push(Info(scoville[i]));
    }
    
    while(true)
    {
        Info tmp = pq.top();
        if (tmp.val >= K)
            break;
        if (pq.size() == 1)
            return -1;
        
        Info cur1 = pq.top();
        pq.pop();
        Info cur2 = pq.top();
        pq.pop();
        int nV = cur1.val + cur2.val*2;
        pq.push(Info(nV));
        answer++;
    }
    
    return answer;
}