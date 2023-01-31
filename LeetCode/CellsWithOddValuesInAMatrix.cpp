class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        int answer = 0;
        for (const auto &e: indices) {
            for (auto &p: matrix[e[0]]) {
                ++p;
                if ((p % 2) == 1) {
                    ++answer;
                } else {
                    --answer;
                }
            }
            for (auto &p: matrix) {
                p[e[1]]++;
                if ((p[e[1]] % 2) == 1) {
                    ++answer;
                } else {
                    --answer;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;
}
