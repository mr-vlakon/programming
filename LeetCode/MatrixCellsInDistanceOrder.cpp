class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int, pair<int, int>> > v;
        for (int i = 0; i != rows; ++i) {
            for (int j = 0; j != cols; ++j) {
                v.push_back({abs(rCenter - i) + abs(cCenter - j), {i, j}});
            }
        }
        sort(v.begin(), v.end(), [=] (pair<int, pair<int, int>> &lhs, pair<int, pair<int, int>> &rhs) {
            return lhs.first < rhs.first;    
        }
        );
        vector<vector<int>> answer;
        for (const auto &e: v) {
            answer.push_back({e.second.first, e.second.second});
        }
        return answer;
    }
};

int main() {
  
  
      
  return 0;  
}
