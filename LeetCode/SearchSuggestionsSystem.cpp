class Solution {
public:
    void construct(string &s, const string &str) {
        if (s.size() == 0) {
            return;
        }
        um[s].push_back(str);
        s.pop_back();
        construct(s, str);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string tmp;
        for (const auto &e: products) {
            tmp = e;
            construct(tmp, e);
        }
        vector<vector<string>> answer;
        string str;
        vector<string> temp;
        vector<string>::iterator p;
        for (auto &e: um) {
            sort(e.second.begin(), e.second.end());
            p = unique(e.second.begin(), e.second.end());
            e.second.erase(p, e.second.end());
        }
        for (const auto &e: searchWord) {
            str.push_back(e);
            answer.push_back({um[str].begin(), um[str].begin() + min(3, static_cast<int>(um[str].size()))});
        }
        return answer;
    }
private:
    unordered_map<string, vector<string>> um;
};

int main() {
  
  
  
  
  return 0;  
}
