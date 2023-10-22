#include <bits/stdc++.h>
using namespace std;

#define l first
#define r second

struct APPLY
{
    string name;
    string id;
    int health;
    int time;
    int day;
};

struct cmp // greater<APPLY>
{
    bool operator()(const APPLY &a, const APPLY &b)
    {
        return a.time > b.time;
    }
};

int d, p;
unordered_map<string, int> last;   // hash
// unordered_map<string, bool> added; // patients hash
vector<APPLY> ill;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    cin >> d >> p;

    for (int i = 1; i <= d; ++i)
    {
        int t, s;
        cin >> t >> s;
        priority_queue<APPLY, vector<APPLY>, cmp> apl;

        for (int j = 0; j < t; ++j)
        {
            APPLY app;
            pair<int, int> time;
            cin >> app.name >> app.id >> app.health;
            scanf("%d:%d", &time.l, &time.r);
            app.time = time.l * 60 + time.r;
            app.day = i;
            if (app.id.length() == 18)
            {
                apl.push(app);
                if (app.health == 1) // 生病
                {
                    ill.push_back(app);
                }
            }
        }

        while (!apl.empty() && s > 0)
        {
            APPLY app = apl.top();
            apl.pop();
            if (last.find(app.id) == last.end() || i - last[app.id] > p)
            {
                cout << app.name << " " << app.id << endl;
                last[app.id] = i; // 更新获取口罩日期
                --s;
            }
        }

        for (auto app : ill)
        {
            cout << app.name << " " << app.id << endl;
        }

        return 0;
    }
}