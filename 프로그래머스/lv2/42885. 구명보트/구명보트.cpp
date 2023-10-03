#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),cmp);
    //투포인터로 하면 시간초과 안날거같음.
    
    int left = 0;
    int right = people.size()-1;
    //50 50 60 70 80
    while(left<=right)
    {
        int tmp = people[left] + people[right];
        
        if (tmp <= limit)
        {
            left++;
            right--;
            answer++;
        }
        else
        {
            right--;
            answer++;
        }
    }
    
    return answer;
}