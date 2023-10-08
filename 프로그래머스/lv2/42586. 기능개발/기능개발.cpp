#include <string>
#include <vector>

using namespace std;



vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0;
    while(idx < progresses.size())
    {
        int cnt = 0;
        for (int i=0;i<progresses.size();i++)
        {
            if (progresses[i] < 100)
            {
                progresses[i] += speeds[i];
            }
        }
        
        if (progresses[idx] >= 100)
        {            
            int tmp = idx;
            cnt++;
            while(true)
            {
                if (tmp+1 >= progresses.size())
                {
                    idx = tmp+1;
                    break;
                }
                    
                
                if (progresses[tmp+1] >= 100)
                {
                    cnt++;
                    tmp++;
                }
                else
                {
                    idx = tmp+1;
                    break;
                }
                    
            }
            
            answer.push_back(cnt);
        }
        
        
        
    }
    return answer;
}