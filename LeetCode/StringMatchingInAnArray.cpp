class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> result;
        for (decltype(words.size()) i = 0; i != words.size(); ++i) {
            for (decltype(words.size()) j = 0; j != words.size(); ++j) {
                if (i != j) {
                    auto pos = words[j].find(words[i]);
                    if (pos != string::npos) {
                        result.insert(words[i]);
                    }
                
                } 
            }
        }
        return {result.cbegin(), result.cend()};
    }
};

int main() {
  
  
  
  return 0;  
}
