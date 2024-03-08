#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

void __ClearFloat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    visited[x][y] = true;
    int has_treasure = grid[x][y] > 1 ? 1 : 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] > 0 && !visited[nx][ny])
        {
            has_treasure = max(has_treasure, dfs(nx, ny, grid, visited));
        }
    }
    return has_treasure;
}

int main()
{
    __ClearFloat();
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &grid[i][j]);
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int total_islands = 0, treasure_islands = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] > 0 && !visited[i][j])
            {
                total_islands++;
                treasure_islands += dfs(i, j, grid, visited);
            }
        }
    }

    cout << total_islands << " " << treasure_islands;
    
    return 0;
}