class Solution {
public:
    bool isVowel(const char &c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactly;
        unordered_map<string, string> cap;
        unordered_map<string, string> vow;
        string tmp;
        for (const auto &e: wordlist) {
            exactly.insert(e);
            tmp = e;
            for (auto &p: tmp) {
                p = tolower(p);
            }
            if (cap.find(tmp) == cap.cend()) {
                cap[tmp] = e;
            }
            for (auto &p: tmp) {
                if (isVowel(p)) {
                    p = 'a';
                }
            }
            if (vow.find(tmp) == vow.cend()) {
                vow[tmp] = e;
            }
        }
        vector<string> answer;
        for (auto &e: queries) {
            if (exactly.find(e) != exactly.cend()) {
                answer.push_back(e);
            } else {
                for (auto &p: e) {
                    p = tolower(p);
                }
                if (cap.find(e) != cap.cend()) {
                    answer.push_back(cap[e]);
                } else {
                    for (auto &p: e) {
                        if (isVowel(p)) {
                            p = 'a';
                        }
                    }
                    if (vow.find(e) != vow.cend()) {
                        answer.push_back(vow[e]);
                    } else {
                        answer.push_back("");
                    }  
                }
            } 
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
