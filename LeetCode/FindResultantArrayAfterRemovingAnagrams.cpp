class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<pair<string, string>> v;
        for (auto &e: words) {
            string tmp = e;
            sort(e.begin(), e.end());
            v.push_back({e, tmp});
        }
        while (true) {
            int index = -1;
            for (int i = 1; i != v.size(); ++i) {
                if (v[i - 1].first == v[i].first) {
                    index = i;
                }    
            }
            if (index == -1)
                break;
            v.erase(v.cbegin() + index);   
        }
        vector<string> answer;
        for (const auto &e: v) {
            answer.push_back(e.second);
        }    
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
