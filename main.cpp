#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#define long long ll
using namespace std;
string input = "", tmp = "";
vector<string> list_num;
vector<char> num;
float _tmp;
bool is_number(string &s)
{
    float v;
    try
    {
        v = stof(s);
    }
    catch (const exception &e)
    {
        return false;
    }
    return true;

    // isdigit(s.c_str());

    // int cnt=0;
    // for (char c : s) {
    //     if(c=='.') cnt++;
    //     if ((!isdigit(c)&&c!='.')||cnt>1) {
    //         return false;
    //     }
    // }
    // return true;
}
float calc(string &func_type, string &param)
{
    float val;
    // func = list_num[i].substr(0, 3);
    // func_param = list_num[i].substr(4, list_num[i].length() - 5);
    if (func_type == "sin")
    {
        val = sin(stof(param) * (M_PI / 180));
    }
    else if (func_type == "cos")
    {
        val = cos(stof(param) * (M_PI / 180));
    }
    else if (func_type == "tan")
    {
        val = tan(stof(param) * (M_PI / 180));
    }
    else if (func_type == "num")
    {
        val = stof(param);
    }
    else
    {
        cerr << "Error:Please use cos,tan or num.";
        return 0x7fffffff;
    }

    return val;
}

float count()
{
    string func, func_param;
    if (is_number(list_num[0]))
    {
        func = "num";
        func_param = list_num[0];
    }
    else
    {
        func = list_num[0].substr(0, 3);
        func_param = list_num[0].substr(4, list_num[0].length() - 5);
    }
    float func_val = calc(func, func_param);
    for (int i = 1; i < list_num.size(); i++)
    {
        if (is_number(list_num[i]))
        {
            func = "num";
            func_param = list_num[i];
        }
        else
        {
            func = list_num[i].substr(0, 3);
            func_param = list_num[i].substr(4, list_num[i].length() - 5);
        }
        float func_val_temp = calc(func, func_param);
        switch (num[i - 1])
        {
        case '*':
            func_val *= func_val_temp;
            break;
        case '+':
            func_val += func_val_temp;
            break;
        case '-':
            func_val -= func_val_temp;
            break;
        case '/':
            func_val /= func_val_temp;
            break;
        }
    }
    return func_val;
}
void split(string &data)
{   
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/')
        {
            if(tmp==""&&data[i]=='-'){
                tmp+=data[i];
                continue;
            }
            list_num.push_back(tmp);
            num.push_back(data[i]);
            tmp = "";
        }
        else if (i == data.size() - 1)
        {
            tmp += data[i];
            list_num.push_back(tmp);
            tmp = "";
            break;
        }
        else
        {
            tmp += data[i];
        }
    }
}
int main()
{
    // OK: sin(90)+sin(90)+sin(90)-sin(90)
    // NG: sin(90)+num(90) Not Acceptable
    // OK: sin(90)+9999999
    // OK: sin(90)+(sin(90)+0.5)

    cin >> input;
    split(input);
    float ans = count();
    if (ans != 0x7fffffff)
    {
        cout << "The answer is:" << ans;
    }
    else
    {
        return -1;
    }
    return 0;
}
