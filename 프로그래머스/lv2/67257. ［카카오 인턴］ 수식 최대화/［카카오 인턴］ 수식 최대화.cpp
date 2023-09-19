#include <string>
#include <vector>
#include <queue> //100-60000-520

using namespace std;

//완탐
//벡터 두개 - > 연산자 벡터 , 계산값 벡터
//큐 한개

string opr[6] = { "+*-","+-*","-+*","-*+","*+-","*-+" };
long long maxVal = -100000;

void calcul(int idx, string exp)
{
    string cur = opr[idx];
    vector<string> val;
    vector<char> op;

    string frag = "";
    for (int i = 0; i < exp.length(); i++)
    {
        if (i == exp.length() - 1)
        {
            frag += exp[i];
            val.push_back(frag);
        }
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
        {
            val.push_back(frag);
            frag = "";
            op.push_back(exp[i]);
        }
        else
        {
            frag += exp[i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        char tmp = cur[i];
        int size = op.size();
        for (int i = 0; i < size; i++)
        {
            if (i >= op.size())
            {
                break;
            }
            if (tmp == op[i])
            {
                if (tmp == '-')
                {
                    long long tmp2 = stoull(val[i]) - stoull(val[i + 1]);
                    val[i] = to_string(tmp2);
                    val.erase(val.begin() + i + 1);
                    op.erase(op.begin() + i);
                    i--;
                }
                else if (tmp == '+')
                {
                    long long tmp2 = stoull(val[i]) + stoull(val[i + 1]);
                    val[i] = to_string(tmp2);
                    val.erase(val.begin() + i + 1);
                    op.erase(op.begin() + i);
                    i--;
                }
                else
                {
                    long long tmp2 = stoull(val[i]) * stoull(val[i + 1]);
                    val[i] = to_string(tmp2);
                    val.erase(val.begin() + i + 1);
                    op.erase(op.begin() + i);
                    i--;
                }
            }
        }

    }
    
    long long maxSub = stoull(val[0]);
    if (maxSub < 0)
        maxSub *= -1;
    if (maxSub > maxVal)
        maxVal = maxSub;
}

long long solution(string expression) {
    
    for (int i = 0; i < 6; i++)
    {
        calcul(i, expression);
    }

    return maxVal;
}