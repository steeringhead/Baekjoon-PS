#include <string>
#include <vector>

using namespace std;

int map[1000][1000];

struct Node
{
    int x;
    int y;
    int val;
    int cnt;
    Node(int a, int b, int c, int d)
    {
        x = a;
        y = b;
        val = c;
        cnt = d;
    }
};

Node leftBottom(int x, int y, int val, int cnt)
{
    int tmp = cnt - 1;
    while (cnt > 0)
    {
        cnt--;
        if (map[x][y] == 0)
        {
            map[x][y] = val++;
            x++;
        }
    }

    return Node(x-1, y+1, val, tmp);
}

Node rightTop(int x, int y, int val, int cnt)
{
    int tmp = cnt - 1;
    while (cnt > 0)
    {
        cnt--;
        if (map[x][y] == 0)
        {
            map[x][y] = val++;
            y--;
            x--;
        }
    }
    return Node(x + 2,y + 1, val, tmp);
}

Node right(int x, int y, int val, int cnt)
{
    int tmp = cnt - 1;
    while (cnt > 0)
    {
        cnt--;
        if (map[x][y] == 0)
        {
            map[x][y] = val++;
            y++;
        }
    }
    return Node(x-1, y-2, val, tmp);
}


vector<int> solution(int n) {
    vector<int> answer;
    int cnt = 0;
    auto init = Node(0, 0, 1, n);

    while (cnt < n)
    {
        auto cur1 = leftBottom(init.x, init.y, init.val, init.cnt);
        cnt++;
        auto cur2 = right(cur1.x, cur1.y, cur1.val, cur1.cnt);
        cnt++;
        auto cur3 = rightTop(cur2.x, cur2.y, cur2.val, cur2.cnt);
        init = Node(cur3.x, cur3.y, cur3.val, cur3.cnt);
        cnt++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] != 0)
                answer.push_back(map[i][j]);
            else
                break;

        }
    }

    return answer;
}