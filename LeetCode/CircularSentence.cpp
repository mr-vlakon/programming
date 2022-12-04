class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream is(sentence);
        string s;
        vector<string> v;
        while(is >> s) {
            v.push_back(s);
        }
        if (v[0][0] != v[v.size() - 1][v[v.size() - 1].size() - 1])
            return false;

        for (int i = 1; i != v.size(); ++i) {
            if (v[i - 1][v[i - 1].size() - 1] != v[i][0])
                return false;
        }
            
        return true;
    }
};

int main() {
  
  
  return 0;  
}
