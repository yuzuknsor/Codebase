#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    stack<int> num;
    stack<char> ope;

    for (int i = 0; i < N; ++i)
    {
        int number;
        cin >> number;
        num.push(number);
    }

    for (int i = 0; i < N - 1; ++i)
    {
        char op;
        cin >> op;
        ope.push(op);
    }

    while (!ope.empty())
    {
        int n1 = num.top();
        num.pop();
        int n2 = num.top();
        num.pop();
        char op = ope.top();
        ope.pop();
        int result;
        if (op == '+')
        {
            result = n2 + n1;
        }
        else if (op == '-')
        {
            result = n2 - n1;
        }
        else if (op == '*')
        {
            result = n2 * n1;
        }
        else
        {
            if (n1 == 0)
            {
                cout << "ERROR: " << n2 << "/0" << endl;
                return 0;
            }
            result = n2 / n1;
        }
        num.push(result);
    }

    cout << num.top() << endl;
    
    return 0;
}