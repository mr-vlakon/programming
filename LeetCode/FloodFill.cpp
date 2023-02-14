class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int start = image[sr][sc];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if ((top.first - 1) >= 0) {
                if (image[top.first - 1][top.second] == start && !visited[top.first - 1][top.second]) {
                    q.push({top.first - 1, top.second});
                }
            }
            if (((top.first + 1) < image.size())) {
                if (image[top.first + 1][top.second] == start && !visited[top.first + 1][top.second]) {
                    q.push({top.first + 1, top.second});
                }
            }
            if ((top.second + 1) < image[0].size()) {
                if (image[top.first][top.second + 1] == start && !visited[top.first][top.second + 1]) {
                    q.push({top.first, top.second + 1});
                }
            }
            if ((top.second - 1) >= 0) {
                if (image[top.first][top.second - 1] == start && !visited[top.first][top.second - 1]) {
                    q.push({top.first, top.second - 1});
                }
            }
            visited[top.first][top.second] = true;
            image[top.first][top.second] = color;
        }
        return image;
    }
};

int main() {
  
  
  
  return 0;  
}
