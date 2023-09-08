#include <string>
#include <vector>
#include <queue>

using namespace std;

int solve(long long val, queue<int> q1, queue<int> q2, long long q1sum, long long q2sum)
{
    //일단 큰놈에서 작은놈으로 옮기자
    long long cur1 = q1sum;
    long long cur2 = q2sum;
    int size = q1.size()*10;
    int cnt = 0;

    //한개이하로 줄지 않고 계속 왔다갔다 하는경우 ? -> 이때는 결국 -1리턴이겠네.
    while (true) // 3 3 3 3   /  3 3 21 3
    {
        // if (q1.size() == 1 || q2.size() == 1)
        // {
        //     if (cur1 != cur2)
        //     {
        //         return -1;
        //     }
        // }
        
        if (cnt > size)
        {
            return -1;
        }

        if (cur1 < cur2)
        {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            cur1 += tmp;
            cur2 -= tmp;
        }
        else if (cur1 > cur2)
        {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            cur1 -= tmp;
            cur2 += tmp;
        }
        else
        {
            break;
        }

        cnt++;
    }

    return cnt;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<int> q1;
    queue<int> q2;
    long long total = 0;
    long long q1sum = 0, q2sum = 0;

    for (int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        total += queue1[i];
        q1sum += queue1[i];
    }

    for (int i = 0; i < queue2.size(); i++)
    {
        q2.push(queue2[i]);
        total += queue2[i];
        q2sum += queue2[i];
    }

    if (total % 2 != 0)
        return -1;
    if (q1sum == q2sum)
        return 0;

    long long goal = total / 2;


    return solve(goal, q1, q2, q1sum, q2sum);
}
