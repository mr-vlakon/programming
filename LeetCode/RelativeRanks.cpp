class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, string> um;
        priority_queue<int> pq(score.cbegin(), score.cend());
        int i = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (i == 0) {
                um[top] = "Gold Medal";
            } else if (i == 1) {
                um[top] = "Silver Medal";
            } else if (i == 2) {
                um[top] = "Bronze Medal";
            } else {
                um[top] = to_string(i + 1);
            }
            ++i;
        }
        vector<string> result;
        for (const auto &e: score) {
            result.push_back(um[e]);
        }
        return result;
    }
};

int main() {
  
  
  
  
  return 0;  
}
