class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int i = 0;
        int max = 0;
        while (i != sentences.size()) {
            istringstream is(sentences[i]);
            int cnt = 0;
            string s;
            while (is >> s) {
                ++cnt;
            }
            if (cnt > max)
                max = cnt;
            ++i;
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
