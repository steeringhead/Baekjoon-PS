#include <string>
#include <vector>

using namespace std;

int last;
int goal;
int answer = 0;

void calcul(int val,int curIdx,vector<int>& numbers)
{
    if (curIdx >= last)
    {
        if (val == goal)
        {
            answer++;
            return;
        }            
        else
            return;
    }
    else
    {
        calcul(val+numbers[curIdx+1],curIdx+1,numbers);
        calcul(val-numbers[curIdx+1],curIdx+1,numbers);
    }
}

int solution(vector<int> numbers, int target) {
    
    int size = numbers.size();
    last = size-1;
    goal = target;
    
    calcul(0+numbers[0],0,numbers);
    calcul(0-numbers[0],0,numbers);
    
    return answer;
}