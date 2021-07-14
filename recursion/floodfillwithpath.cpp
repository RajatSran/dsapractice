#include<bits/stdc++.h>
using namespace std;

// realised while doing this question dry running your code is realy important
void floodfill(vector<vector<int>> maze, int r, int c, string answer, nvector<vector<bool>>& visited) {
    if (r < 0 || c < 0 || r >= maze.size() || c >= maze.size() || maze[r][c] == 1 || visited[r][c]) {
        return;
    }
    if (r == maze.size() - 1 && c == maze.size() - 1) {
        cout << answer << endl;
        return;
    }
    visited[r][c] = true;
    floodfill(maze, r - 1, c, answer + "t", visited);
    floodfill(maze, r, c - 1, answer + "l", visited);
    floodfill(maze, r + 1, c, answer + "d", visited);
    floodfill(maze, r, c + 1, answer + "r", visited);
    visited[r][c] = false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int r;
    int c;
    cin >> r >> c;
    vector<vector<int>> maze;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> maze[i][j];
        }
    }
    vector<vector<bool>> visited;
    floodfill(maze, 0, 0, "", visited);
}