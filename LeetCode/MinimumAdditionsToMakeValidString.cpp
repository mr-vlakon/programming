class Solution {
public:
    int addMinimum(string word) {
        int answer = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == 'a') {
                if ((i + 1) < word.size()) {
                    if (word[i + 1] == 'b') {
                        if ((i + 2) < word.size()) {
                            if (word[i + 2] != 'c') {
                                ++answer;
                                ++i;
                            } else {
                                ++i;
                                ++i;
                            }
                        } else {
                            ++answer;
                            ++i;
                            ++i;
                        }
                    } else if (word[i + 1] == 'a') {
                        answer += 2;
                    } else if (word[i + 1] == 'c') {
                        ++answer;
                        ++i;
                    }
                } else {
                    answer += 2;
                    ++i;
                } 
            } else if (word[i] == 'b') {
                ++answer;
                if ((i + 1) < word.size()) {
                    if (word[i + 1] == 'c') {
                        ++i;
                    } else {
                        ++answer;
                    }
                } else {
                    ++answer;
                    ++i;
                }
            } else if (word[i] == 'c') {
                answer += 2;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
