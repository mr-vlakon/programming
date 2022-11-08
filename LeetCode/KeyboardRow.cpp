class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> first = {'Q','W','E','R','T','Y','U','I','O','P',
                                     'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> second = {'A','S','D','F','G','H','J','K','L',
                                      'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> third = {'Z','X','C','V','B','N','M',
                                     'z','x','c','v','b','n','m',};
        
        vector<string> v;
        
        for (const auto &e: words) {
            int size = e.size();
            int cnt = 0;
            for (const auto &p: e) {
                auto it = first.find(p);
                if (it != first.cend()) {
                    ++cnt;
                }
            }
            if (cnt == size) {
                v.push_back(e);
                continue;
            }
            
            cnt = 0;
            for (const auto &p: e) {
                auto it = second.find(p);
                if (it != second.cend()) {
                    ++cnt;
                }
            }
            if (cnt == size) {
                v.push_back(e);
                continue;
            }
            cnt = 0;
            for (const auto &p: e) {
                auto it = third.find(p);
                if (it != third.cend()) {
                    ++cnt;
                }
            }
            if (cnt == size) {
                v.push_back(e);
                continue;
            }
            
            
            
            
        }
        
        return v;
        
    }
};

int main() {
  
  
  return 0;  
}
