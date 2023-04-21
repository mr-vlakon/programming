class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int x = 0;
        int y = 0;
        int countSpaces = 0;
        int sizes = 0;
        string result;
        string tmp;
        int countWords = 0;
        string t;
        for (int i = 0; i != words.size(); ++i) {
            if (sizes == 0) {
                tmp = words[i];
                ++countWords;
                sizes += words[i].size();
            }else if ((sizes + countSpaces + words[i].size() + 1) <= maxWidth){
                if (tmp.size() != 0) {
                    tmp += ' ';
                    ++countSpaces;
                }
                sizes += words[i].size();
                tmp += words[i];
                ++countWords;
            } else {
                countSpaces += maxWidth - (sizes + countSpaces);
                x = countSpaces / ((countWords != 1) ? (countWords - 1) : 1);
                y = countSpaces % ((countWords != 1) ? (countWords - 1) : 1);
                result.resize(0);
                istringstream is(tmp);
                while (is >> t) {
                    result += t;
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
                countWords = 1;
                tmp = words[i];
                sizes = words[i].size();
                countSpaces = 0;
            }
        }
        if (tmp.size() != 0) {
            countSpaces += maxWidth - (sizes + countSpaces);
            x = countSpaces / ((countWords != 1) ? (countWords - 1) : 1);
            y = countSpaces % ((countWords != 1) ? (countWords - 1) : 1);
            result.resize(0);
            istringstream is(tmp);
            while (is >> t) {
                result += t;
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
