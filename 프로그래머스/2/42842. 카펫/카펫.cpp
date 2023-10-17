#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    
    for (int i=3;i<total;i++)
    {
        if (total%i == 0)
        {
            int width = total/i;
            if (width < i)
                break;
            int widthY = width - 2;
            int heightY = i-2;
            if (widthY*heightY == yellow)
            {
                answer.push_back(width);
                answer.push_back(i);
                break;
            }
        }
    }
    
    
    return answer;
}