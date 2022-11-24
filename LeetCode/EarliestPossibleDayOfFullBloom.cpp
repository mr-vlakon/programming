class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> v;
        for (int i = 0; i != plantTime.size(); ++i) {
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end(), [=](const pair<int, int> &lhs,
                                     const pair<int, int> &rhs) {
            return lhs.second < rhs.second; 
        });
        stable_sort(v.begin(), v.end(), [=](const pair<int, int> &lhs,
                                     const pair<int, int> &rhs) {
            return lhs.first > rhs.first; 
        });
        int answer = 0;
        int offset = 0;
        int max = 0;
        for (int i = 0; i != v.size(); ++i) {
            if (v[i].second + v[i].first + offset > max)
                max = v[i].second + v[i].first + offset;
            offset += v[i].second;
            if (v.size() - 1 == i) {                
                answer = std::max(v[i].first + v[i].second, max);
            }
        } 
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
