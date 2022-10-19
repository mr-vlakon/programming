class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.cbegin(), arr.cend());
        unordered_map<int, int> um;
        int rang = 1;
        for (const auto &e: s) {
            um[e] = rang;
            ++rang;
        }
        
        vector<int> answer;
        for (const auto &e: arr) {
            auto it = um.find(e);
            answer.push_back(it->second);
        }
        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
