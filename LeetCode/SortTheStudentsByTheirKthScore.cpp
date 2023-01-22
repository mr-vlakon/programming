class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i != score.size(); ++i) {
            pq.push({score[i][k], i});
        }
        vector<vector<int>> v;
        while(!pq.empty()) {
            auto top = pq.top();
            v.push_back(score[top.second]);
            pq.pop();
        }
        return v;
    }
};

int main() {
  
  
  
  return 0;  
}
