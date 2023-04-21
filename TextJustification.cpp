class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int x = 0;
        int y = 0;
        int countSpaces = 0;
        deque<string> deq;
        int sizes = 0;
        string result;
        for (int i = 0; i != words.size(); ++i) {
            if (sizes == 0) {
                deq.push_back(words[i]);
                sizes += words[i].size();
            }else if ((sizes + countSpaces + words[i].size() + 1) <= maxWidth){
                if (deq.size() != 0) {
                    ++countSpaces;
                }
                sizes += words[i].size();
                deq.push_back(words[i]);
            } else {
                countSpaces += maxWidth - (sizes + countSpaces);
                x = countSpaces / ((deq.size() != 1) ? (deq.size() - 1) : 1);
                y = countSpaces % ((deq.size() != 1) ? (deq.size() - 1) : 1);
                result.resize(0);
                while (deq.size() != 0) {
                    result += deq.front();
                    deq.pop_front();
                    if (countSpaces >= x) {
                        result += string(x + ((y > 0) ? 1 : 0), ' ');
                        if (y > 0) {
                            y--;
                            countSpaces -= 1;
                        }
                        countSpaces -= x;
                    }
                }
                if (countSpaces > 0) {
                    result += string(countSpaces, ' ');
                }
                answer.push_back(result);
                deq.push_back(words[i]);
                sizes = words[i].size();
                countSpaces = 0;
            }
        }
        if (deq.size() != 0) {
            countSpaces += maxWidth - (sizes + countSpaces);
            x = countSpaces / ((deq.size() != 1) ? (deq.size() - 1) : 1);
            y = countSpaces % ((deq.size() != 1) ? (deq.size() - 1) : 1);
            result.resize(0);
            while (deq.size() != 0) {
                result += deq.front();
                deq.pop_front();
                if (countSpaces >= x && countSpaces > 0) {
                    result += ' ';
                    if (y > 0)
                        y--;
                        countSpaces -= 1;
                    }
            }
            if (countSpaces > 0) {
                result += string(countSpaces, ' ');
            }
            answer.push_back(result);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
