#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int score;
    string target;
    Node(int a, string b)
    {
        score = a;
        target = b;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<Node> q;
    vector<int> v;
    
    for (int i=0;i<priorities.size();i++)
    {
        if (i == location)
        {
            q.push(Node(priorities[i],"YES"));
        }
        else
            q.push(Node(priorities[i],"NO"));
        
        v.push_back(priorities[i]);
    }
    
    int left = 0;
    int right = priorities.size()-1;
    
    while(true)
    {
        Node cur = q.front();
        bool flag = true;
        for (int i=left;i<=right;i++)
        {
            if (cur.score < v[i])
            {
                flag = false;
                break;
            }
        }
        
        if (flag == false)
        {
            q.push(cur);
            q.pop();
            v.push_back(cur.score);            
            left++;
            right++;
        }
        else
        {
            if (cur.target == "YES")
                return ++answer;
            else
            {
                q.pop();
                left++;
                answer++;
            }
        }
        
    }      
    
}