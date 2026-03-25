#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int x, y, dist;
};

int shortestEscapePath(const vector<vector<int>>& grid, int sx, int sy, int tx, int ty) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Check if start/target are out of bounds
    if (sx < 0 || sx >= rows || sy < 0 || sy >= cols ||
        tx < 0 || tx >= rows || ty < 0 || ty >= cols) {
        return -1;
    }

    // Cannot start or end on a blocked cell
    if (grid[sx][sy] == 1 || grid[tx][ty] == 1) {
        return -1;
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<Cell> q;

    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    // Directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.x == tx && current.y == ty) {
            return current.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.dist + 1});
            }
        }
    }

    return -1; // target not reachable
}

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter the grid values (0 for open, 1 for blocked, space in between all numbers):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int sx, sy, tx, ty;
    cout << "Enter start position (sx sy): ";
    cin >> sx >> sy;

    cout << "Enter target position (tx ty): ";
    cin >> tx >> ty;

    int result = shortestEscapePath(grid, sx, sy, tx, ty);

    cout << "Minimum number of moves: " << result << endl;

    return 0;
}
