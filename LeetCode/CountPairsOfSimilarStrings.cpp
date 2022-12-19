class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<unordered_set<char>> um;
        for (const auto &e: words) {
            unordered_set<char> tmp;
            for (const auto &p: e) {
                tmp.insert(p);
            }
            um.push_back(tmp);
        }
        int answer = 0;
        for (int i = 0; i != um.size() - 1; ++i) {
            for (int j = i + 1; j != um.size(); ++j) {
                if (um[i] == um[j])
                    ++answer;
            }
        }
        return answer;;
    }
};

int main() {
  
  
  
  return 0;  
}
