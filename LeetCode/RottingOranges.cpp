class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> queue;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = -1;
                    queue.push(i*grid[0].size() + j);
                }
            }
        }
        int answer = 0;
        while (!queue.empty()) {
            int x = queue.front() / grid[0].size();
            int y = queue.front() % grid[0].size();
            queue.pop();
            answer = max(answer, abs(grid[x][y] + 1));
            if ((x - 1) >= 0 &&  grid[x - 1][y] == 1) {
                grid[x - 1][y] = grid[x][y] - 1;
                queue.push((x - 1)*grid[0].size() + y);
            }
            if ((x + 1) < grid.size()  && grid[x + 1][y] == 1) {
                grid[x + 1][y] = grid[x][y] - 1;
                queue.push((x + 1)*grid[0].size() + y);
            }
            if ((y - 1) >= 0  && grid[x][y - 1] == 1) {
                grid[x][y - 1] = grid[x][y] - 1;
                queue.push((x)*grid[0].size() + y - 1);
            }
            if ((y + 1) < grid[0].size()  && grid[x][y + 1] == 1) {
                grid[x][y + 1] = grid[x][y] - 1;
                queue.push((x)*grid[0].size() + y + 1);
            }
        }
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}

