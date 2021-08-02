#include<bits/stdc++.h>
using namespace std;



void printchess(vector<vector<int>> chess, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
}

void knighttour(vector<vector<int>> &chess, int row, int col, int move, int N) {
    if (row < 0 || col < 0 || row >= N || col >= N || chess[row][col] > 0) {
        return;
    } else if (move == N * N) {
        chess[row][col] = move;
        printchess(chess, N);
        chess[row][col] = 0;
        return;
    }

    chess[row][col] = move;
    knighttour(chess, row - 2, col + 1, move + 1, N);
    knighttour(chess, row - 1, col + 2, move + 1, N);
    knighttour(chess, row + 1, col + 2, move + 1, N);
    knighttour(chess, row + 2, col + 1, move + 1, N);
    knighttour(chess, row + 2, col - 1, move + 1, N);
    knighttour(chess, row + 1, col - 2, move + 1, N);
    knighttour(chess, row - 1, col - 2, move + 1, N);
    knighttour(chess, row - 2, col - 1, move + 1, N);
    chess[row][col] = 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> chess;
    int N = 4;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            chess[i][j] = 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            knighttour(chess, i, j, 0, chess.size());

}