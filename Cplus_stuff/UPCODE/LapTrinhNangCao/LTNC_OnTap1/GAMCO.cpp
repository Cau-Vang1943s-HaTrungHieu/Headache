#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1e9;

int R, C;
char a[105][105];

int dista[105][105];
int grass[105][105];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Node
{
    int x, y;
};

int main()
{
    cin >> R >> C;

    int sx, sy; // vị trí của C

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> a[i][j];

            if (a[i][j] == 'C')
            {
                sx = i;
                sy = j;
            }
        }
    }

    // Khởi tạo
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dista[i][j] = INF;
            grass[i][j] = -1;
        }
    }

    queue<Node> q;

    q.push({sx, sy});

    dista[sx][sy] = 0;
    grass[sx][sy] = 0;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // kiểm tra biên
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            // đá thì bỏ qua
            if (a[nx][ny] == '*')
                continue;

            int newDist = dista[x][y] + 1;

            int addGrass = (a[nx][ny] == '.') ? 1 : 0;

            int newGrass = grass[x][y] + addGrass;

            // tìm được đường ngắn hơn
            if (newDist < dista[nx][ny])
            {
                dista[nx][ny] = newDist;
                grass[nx][ny] = newGrass;

                q.push({nx, ny});
            }

            // cùng độ dài nhưng ăn được nhiều cỏ hơn
            else if (newDist == dista[nx][ny]
                     && newGrass > grass[nx][ny])
            {
                grass[nx][ny] = newGrass;

                q.push({nx, ny});
            }
        }
    }

    // B luôn ở (0,0)
    cout << grass[0][0];

    return 0;
}