#include <bits/stdc++.h>
using namespace std;

queue<int> pusher;
vector<int> branch, box;
int n, m, k;

void Lay()
{
    for (int i = 0; i < branch.size(); i++)
    {
        if (i == branch.size() - 1)
            cout << branch[i] << endl;
        else
            cout << branch[i] << " ";
    }

    branch.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int _new;
        cin >> _new;
        pusher.push(_new);
    }

    while (!pusher.empty() || !box.empty()) // 对于每一根松针
    {
        while (!box.empty() && (branch.empty() || box.back() <= branch.back())) // 盒不空，干空或盒顶松针比枝头细
        {
            branch.push_back(box.back());
            box.pop_back();
            if (branch.size() == k)
            {
                Lay();
                break;
            }
        }

        if (pusher.empty())
            Lay();
        if (!box.empty() && branch.empty())
            continue;

        while (!pusher.empty())
        {
            if (branch.size() == k)
                break;
            if (box.size() == m && pusher.front() > branch.back()) // 盒满且推送器顶松针比枝头粗
            {
                Lay();
                break;
            }
            if (branch.empty() || pusher.front() <= branch.back()) // 干空或推送器顶松针比枝头细
                branch.push_back(pusher.front());
            else
                box.push_back(pusher.front());
            pusher.pop();
        }

        if (branch.size() == k)
            Lay();
    }

    if (!branch.empty())
        Lay();

    return 0;
}