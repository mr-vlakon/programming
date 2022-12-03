class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string, int> answer;
        for (auto &e: words) {
            unordered_map<int, string> um;
            for (int i = 0; i != e.size(); ++i) {
                um[i % 2].push_back(e[i]);
            }
            string s1 = um[0];
            string s2 = um[1];
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            ++answer[s1 + s2];
        }
        return answer.size();
    }
};

int main() {

  
  return 0;  
}
