#include <iostream>
#include <vector>
#include <queue>
#define MAX_M 20
#define MAX_N 20

using namespace std;

struct Point {
    int x;
    int y;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxTime(int m, int n, vector<vector<int>>& fortress) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxTime = 0;

    auto bfs = [&](int start_x, int start_y) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<Point> q;

        Point start = {start_x, start_y};
        q.push(start);
        visited[start_x][start_y] = true;

        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dir[i][0];
                int ny = p.y + dir[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && fortress[nx][ny] == 0) {
                    dist[nx][ny] = dist[p.x][p.y] + 1;
                    visited[nx][ny] = true;

                    Point newPoint = {nx, ny};
                    q.push(newPoint);
                }
            }
        }

        return dist[m - 1][n - 1];
    };

    int dist = bfs(0, 0);
    maxTime = dist;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (fortress[i][j] == 0) {
                fortress[i][j] = 1;
                dist = bfs(0, 0);
                maxTime = max(maxTime, dist);
                fortress[i][j] = 0;
            }
        }
    }

    return maxTime + 1;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> fortress(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> fortress[i][j];
        }
    }

    int result = maxTime(m, n, fortress);
    cout << result;

    return 0;
}
