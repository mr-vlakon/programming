class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> v;
        istringstream is(text);
        string s;
        while (is >> s) {
            v.push_back(s);
        }
        vector<string> answer;
        for (int i = 0; i != v.size() - 2; ++i) {
            if (v[i] == first && v[i + 1] == second) {
                answer.push_back(v[i + 2]);
            }
        }    
        return answer;
    }
};

int main() {

  
  
  return 0;  
}
