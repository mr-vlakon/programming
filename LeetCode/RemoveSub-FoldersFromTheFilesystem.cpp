class Solution {
public:
    void construct(string &s) {
        if (s.size() == 0) {
            return;
        }
        t = 0;
        if (s.back() == '/') {
            t = 1;
        }
        s.pop_back();
        if (dict.find(s) != dict.cend() && t == 1) {
            status = false;
            return;
        }        
        construct(s);
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        string tmp;
        for (const auto &e: folder) {
            dict.insert(e);
        }
        for (const auto &e: folder) {
            tmp = e;
            status = true;
            construct(tmp);
            if (status) {
                answer.push_back(e);
            }
        }
        return answer;
    }
private:
    int t = 0;
    bool status = false;
    unordered_set<string> dict;
    vector<string> answer;
};

int main() {
  
  
  
  return 0;  
}
