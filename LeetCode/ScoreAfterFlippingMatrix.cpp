class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        bool status = false;
        for (int i = 0; i != grid.size(); ++i) {
            status = false;
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    status = true;
                } else if (!status){
                    break;
                }
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        int cnt = 0;
        int tmp = 0;
        for (int j = 0; j != grid[0].size(); ++j) {
            tmp = 0;
            cnt = 0;
            while (tmp != grid.size()) {
                if (grid[tmp][j] == 0) {
                    ++cnt;
                }
                ++tmp;
            }
            if ( cnt > (grid.size() - cnt)) {
                tmp = 0;
                while (tmp != grid.size()) {
                    if (grid[tmp][j] == 0) {
                        grid[tmp][j] = 1;
                    } else {
                        grid[tmp][j] = 0;
                    }
                    ++tmp;
                }
            }
        }
        int temp = 0;
        int answer = 0;
        for (int i = 0; i != grid.size(); ++i) {
            temp = 0;
            for (int j = grid[0].size() - 1; j >= 0; --j) {
                temp += grid[i][j] * pow(2, grid[0].size() - 1 - j);
            }
            answer += temp;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
