class Solution {
public:
    void generate(const string &s, int i, string &str, vector<string> &v, unordered_set<string> &us) {
        if (i == n_) {
            answer = max(answer, static_cast<int>(us.size()));
            return;
        }
        if (i > n_) {
            return;
        }
        str.push_back(s[i]);
        auto it = us.insert(str);
        string empty;
        if (it.second) {
            generate(s, i + 1, empty, v, us);
            us.erase(it.first);
        }
        generate(s, i + 1, str, v, us);
    }
    int maxUniqueSplit(string s) {
        string str;
        n_ = s.size();
        vector<string> empty;
        unordered_set<string> us;
        generate(s, 0, str, empty, us);
        return answer;
    }
private:
    unordered_set<string> us1;
    int answer = 0;
    int n_ = 0;
};

int main() {
  
  
  return 0;  
}
