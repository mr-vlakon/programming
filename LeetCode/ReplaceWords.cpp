class Solution {
public:
    void construct(string &s, const string &str) {
        if (s.size() == 0) {
            return;
        }     
        s.pop_back();
        if (dict.find(s) != dict.cend()) {
            um[str] = s;
        }
        construct(s, str);
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream is(sentence);
        vector<string> v;
        string s;
        while (is >> s) {
            v.push_back(s);
        }
        for (const auto &e: dictionary) {
            dict.insert(e);
        }
        string temp;
        for (auto &e: v) {
            s = e;
            temp = e;
            construct(temp, s);
        }
        unordered_map<string, string> unor;
        string answer;
        unordered_map<string, string>::iterator it;
        for (const auto &e: v) {
            it = um.find(e);
            if (it != um.cend()) {
                answer += um[e];
            } else {
                answer += e;
            }
            answer += " ";
        }
        answer.pop_back();
        return answer;
    }
private:
    unordered_map<string, string> um;
    unordered_set<string> dict;
};

int main() {
  
  
  return 0;  
}
