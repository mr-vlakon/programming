class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int answer = 0;
        vector<bool> visited(words.size(), false);
        for (int i = 0; i != words.size() - 1; ++i) {
            for (int j = i + 1; j != words.size(); ++j) {
                if (words[i] == string(words[j].rbegin(), words[j].rend())) {
                    if (visited[i] == false && visited[j] == false) {
                        visited[i] = true;
                        visited[j] = true;
                        ++answer;
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
