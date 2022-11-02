#include <bits/stdc++.h>

using namespace std;

const int maxN  = 110;

int r, c;
char a[maxN][maxN];
int d[maxN][maxN];
bool visit[maxN][maxN];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    for (int i = 1; i <= r; ++i) {
        fill_n(d[i], c + 1, 0);
        fill_n(visit[i], c + 1, false);
    }

    queue < pair <int, int> > q;
    q.push({sx, sy});
    visit[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Nếu gặp được ô B thì kết thúc thủ tục BFS
        if (a[x][y] == 'B') return;

        for (int i = 0; i < 4; ++i) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if (u > r || u < 1) continue;
            if (v > c || v < 1) continue;
            if (a[u][v] == '*') continue;

            if (!visit[u][v]) {
                d[u][v] = d[x][y] + 1;
                visit[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

int main() {
    int sx, sy, tx, ty;
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'C') { sx = i; sy = j; }
            if (a[i][j] == 'B') { tx = i; ty = j; }
        }

    bfs(sx, sy);
    cout << d[tx][ty];
}