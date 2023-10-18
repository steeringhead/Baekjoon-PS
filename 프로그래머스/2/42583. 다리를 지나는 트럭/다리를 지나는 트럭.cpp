#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int idx = 0;
    int sum = 0;
    
    while(true)
    {
        if (idx == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        int curWeight = truck_weights[idx];
        answer++;
        
        if (q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
            
        }
                
        if (sum + curWeight <= weight && q.size() < bridge_length)
        {
            sum += curWeight;
            q.push(curWeight);
            idx++;
        }
        else
            q.push(0);               
    }
    
    return answer;
}