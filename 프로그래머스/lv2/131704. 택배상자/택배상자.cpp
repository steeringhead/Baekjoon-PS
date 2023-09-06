#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 1;
    
    vector<int> sub;
    vector<int> main;   // 3 1 2 5 4
    
    int start = order[0];
    
    for (int i=order.size();i>=1;i--)
    {
        main.push_back(i);  
    }
    
    for (int i=1;i<start;i++)
    {
        sub.push_back(i);
        main.pop_back();
    }
    
    int idx = 1;
    main.pop_back();
    
    //다시 왔다갔다 하는 과정이 안들어있음.
    // main   2 3 4 5
    // sub   
    // box 1 3 
    while(true)
    {        
        int cur = order[idx];
        bool flag = false;
        
        if (main.size() != 0 && cur == main[main.size()-1])
        {
            answer++;
            idx++;
            flag = true;
            main.pop_back();
            continue;
        }
        
        if (sub.size() != 0 && cur == sub[sub.size()-1])
        {
            answer++;
            idx++;
            flag = true;
            sub.pop_back();
            continue;
        }
        
        if (main.size() != 0  && cur != main[main.size()-1])
        {
            int tmp = main[main.size()-1];
            main.pop_back();
            sub.push_back(tmp);
            continue;
        }
        
        if (flag==false)
            break;
    }
    
    
    return answer;
}