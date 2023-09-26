#include <string>
using namespace std;

struct Node
{
    bool u;
    bool d;
    bool l;
    bool r;
    Node()
    {
        u = false;
        d = false;
        l = false;
        r = false;
    }
};

Node visited[11][11];

int solution(string dirs) {
    int answer = 0;
    int x = 0;
    int y = 0;
    int cur = 0;

    while (cur < dirs.length())
    {
        if (dirs[cur] == 'U')
        {
            cur++;
            int tmpX = x;
            int tmpY = y + 1;
            if (tmpX > 5 || tmpX < -5 || tmpY > 5 || tmpY < -5)
                continue;
            if (visited[x + 5][y + 5].u == true)
            {
                x = tmpX;
                y = tmpY;
                continue;
            }
            visited[x+5][y+5].u = true;
            visited[tmpX+5][tmpY+5].d = true;
            x = tmpX;
            y = tmpY;
            answer++;
        }
        else if (dirs[cur] == 'D')
        {
            cur++;
            int tmpX = x;
            int tmpY = y - 1;
            if (tmpX > 5 || tmpX < -5 || tmpY > 5 || tmpY < -5)
                continue;
            if (visited[x + 5][y + 5].d == true)
            {
                x = tmpX;
                y = tmpY;
                continue;
            }
            
            visited[x + 5][y + 5].d = true;
            visited[tmpX+5][tmpY+5].u = true;
            x = tmpX;
            y = tmpY;
            answer++;
        }
        else if (dirs[cur] == 'L')
        {
            cur++;
            int tmpX = x - 1;
            int tmpY = y;
            if (tmpX > 5 || tmpX < -5 || tmpY > 5 || tmpY < -5)
                continue;
            if (visited[x + 5][y + 5].l == true)
            {
                x = tmpX;
                y = tmpY;
                continue;
            }
            
            visited[x + 5][y + 5].l = true;
            visited[tmpX+5][tmpY+5].r = true;
            x = tmpX;
            y = tmpY;
            answer++;
        }
        else // 'R'
        {
            cur++;
            int tmpX = x + 1;
            int tmpY = y;
            if (tmpX > 5 || tmpX < -5 || tmpY > 5 || tmpY < -5)
                continue;
            if (visited[x + 5][y + 5].r == true)
            {
                x = tmpX;
                y = tmpY;
                continue;
            }
            
            visited[x + 5][y + 5].r = true;
            visited[tmpX+5][tmpY+5].l = true;
            x = tmpX;
            y = tmpY;
            answer++;
        }
    }

    return answer;
}