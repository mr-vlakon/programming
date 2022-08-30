class Solution {
public:
    string sortSentence(string s) {
        istringstream is(s);
        string s1;
        vector<pair<string, size_t>> result;
        while(is >> s1) {
            result.push_back({{s1.begin(), s1.end() - 1}, s1[s1.size() - 1]});
        }
        sort(result.begin(), result.end(), [=](const pair<string, size_t> &lhs,
                                                const pair<string, size_t> &rhs) {
            return lhs.second < rhs.second;
        });
        string res;
        for (const auto &e: result) {
            res += e.first + " ";
        }
        res.erase(res.size() - 1);
        return res;
    }
};

int main() {
  
  return 0;  
}
