class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int, int>> diff;
        for (int i = 0; i != reward1.size(); ++i) {
            diff.push_back({i, reward1[i] - reward2[i]});
        }
        sort(diff.begin(), diff.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        });
        int tmp = 0;
        int cnt = 0;
        for (int i = 0; i != diff.size(); ++i) {
            if (cnt != k) {
                tmp += reward1[diff[i].first]; 
                ++cnt;
            } else {
                tmp += reward2[diff[i].first];
            }
        }
        return tmp;
    }
};

int main() {
  
  
  
  return 0;  
}
