#include <bits/stdc++.h>
using namespace std;

pair<int, int> mark;

int main()
{
    bool vis[11];
    vector<vector<int>> ticket(4, vector<int>(4));
    vector<int> prize = {0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            cin >> ticket[i][j];
            vis[ticket[i][j]] = true;
            if (ticket[i][j] == 0)
            {
                mark.first = i;
                mark.second = j;
            }
        }
    }

    for (int i = 1; i <= 9; ++i)
        if (!vis[i])
            ticket[mark.first][ticket.second] = i;

    for (int i = 1; i <= 3; ++i)
    {
        int x, y;
        cin >> x >> y;
        cout << ticket[x][y] << endl;
    }
    int direction;
    cin >> direction;
    int sum = 0;
    if (direction <= 3)
    {
        for (int j = 1; j <= 3; ++j)
        {
            sum += ticket[direction][j];
        }
    }
    else if (direction <= 6)
    {
        for (int i = 1; i <= 3; ++i)
        {
            sum += ticket[i][direction - 3];
        }
    }
    else if (direction == 7)
    {
        for (int i = 1; i <= 3; ++i)
        {
            sum += ticket[i][i];
        }
    }
    else
    {
        for (int i = 1; i <= 3; ++i)
        {
            sum += ticket[i][3 - i];
        }
    }
    cout << prize[sum] << endl;
    return 0;
}