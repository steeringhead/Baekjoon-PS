#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    
    if (enemy.size() <= k)
        return enemy.size();
    
    int idx = 0;
    
    while(idx < enemy.size())
    {
        pq.push(enemy[idx]);
        n -= enemy[idx];           
        if (n < 0)
        {
            if (k==0)
                return idx;    
            k--;
            n += pq.top();
            pq.pop();              // 4 3 2,2,2,9
        }
        idx++;
    }
    
    return enemy.size();
}