class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> v;
        for (const auto &e: queries) {
            
            for (const auto &p: dictionary) {
                int tmp = 0;
                bool status = true;
                for (decltype(e.size()) i = 0; i != e.size(); ++i) {
                    if (e[i] != p[i]) {
                        ++tmp;
                    }
                    if (tmp > 2) {
                        status = false;
                        break;
                    }
                }
                if (status) {
                    v.push_back(e);
                    break;
                }
                
            }
        }
        return v;
    }
};

int main() {
  
  
  return 0;  
}
