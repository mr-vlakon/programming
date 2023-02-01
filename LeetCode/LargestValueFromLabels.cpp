class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v;
        for (int i = 0; i != values.size(); ++i) {
            v.push_back({values[i], labels[i]});
        }
        sort(v.begin(), v.end(), [] (pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first > rhs.first;
        });
        int count = 0;
        int answer = 0;
        unordered_map<int, int> um;
        for (const auto &e: v) {
            if (count == numWanted) {
                break;
            }
            if (um[e.second] < useLimit) {
                answer += e.first;
                ++count;
                um[e.second]++;
            }

        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
