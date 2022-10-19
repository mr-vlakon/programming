class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        for (auto &e: words) {
            sort(e.begin(), e.end());
        }
        vector<char> result;
        set_intersection(words[0].begin(), words[0].end(), words[1].begin(), words[1].end(), back_inserter(result));
        string tmp(result.cbegin(), result.cend());
        sort(tmp.begin(), tmp.end());
        result.resize(0);
        for (decltype(words.size()) i = 1; i != words.size(); ++i) {
            set_intersection(words[i].begin(), words[i].end(), tmp.begin(), tmp.end(), back_inserter(result));
            tmp = string(result.cbegin(), result.cend());
            result.resize(0);
            sort(tmp.begin(), tmp.end());
        }
        vector<string> res;
        for (const auto &e: tmp) {
            string t;
            t += e;
            res.push_back(t);
        }
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}
