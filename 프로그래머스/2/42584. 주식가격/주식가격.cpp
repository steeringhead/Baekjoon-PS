#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    vector<int> answer;
    for (int i=0;i<N;i++)
    {
        answer.push_back(0);
    }
    
    //일단 당연히 2중포문은 시간초과가 날것같음
    for (int i=0;i<N;i++)
    {
        int cur = prices[i];
        for (int j=i+1;j<N;j++)
        {
            int tmp = prices[j];
            if (tmp >= cur)
                answer[i]++;
            else
            {
                answer[i]++;
                break;
            }
                
        }
    }
    
    return answer;
}