class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> index;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == c)
                index.push_back(i);
        }
        vector<int> answer;
        for (int i = 0; i != s.size(); ++i) {
            int min = 100000;
            for (int j = 0; j != index.size(); ++j) {
                if (abs(index[j] - i) < min)
                    min = abs(index[j] - i);
            }
            answer.push_back(min);
            
        }
        return answer;
        
    }
};

int main() {
  
  
  
  return 0;  
}
