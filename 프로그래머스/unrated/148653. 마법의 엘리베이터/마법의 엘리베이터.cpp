#include <string>
#include <vector>

using namespace std;

//일반적인 BFS와는 다른느낌.

int solution(int storey) {
    int answer = 0;
    
    string s = to_string(storey);
    int tmp = s.length() - 1;
    
    while(tmp >= 0)
    {
        int cur = s[tmp] - '0';
        if (tmp == 0)
        {
            if (cur > 5)
            {
                answer += 10-cur+1;
                break;
            }
            else
            {
                answer += cur-0;
                break;
            }
        }
        if (cur > 5)
        {
            answer += 10 - cur;
            s[tmp-1] = (char)(s[tmp-1] -'0'+1+48);
            tmp--;
        }
        if (cur < 5)
        {
            answer += cur - 0;
            tmp--;
        }
        if (cur == 5)
        {
            int check = tmp-1;
            
            if (s[check]-'0' >= 5)
            {
                answer += 10 - 5;
                s[check] = (char)(s[check] -'0'+1+48);
                tmp--;
            }            
            if (s[check]-'0' < 5)
            {
                answer += cur - 0;
                tmp--;
            }
        }
    }
    
    return answer;
}