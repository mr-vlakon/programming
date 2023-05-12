class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() == sentence2.size()) return sentence1 == sentence2;
        int start1 = 0;
        int start2 = 0;
        int pos1 = -1;
        while (start1 < sentence1.size() && start2 < sentence2.size() && sentence1[start1] == sentence2[start2]) {
            if (sentence1[start1] == ' ' && sentence2[start2] == ' ') {
                pos1 = start1;
            }
            ++start1;
            ++start2;
        }
        if (start1 == sentence1.size()) {
            if (sentence2[start1] == ' ') {
                return true;
            }
        }
        if (start2 == sentence2.size()) {
            if (sentence1[start2] == ' ') {
                return true;
            }
        }
        start1 = pos1 + 1;
        start2 = pos1 + 1;
        int st = 0;
        int pos = 0;
        if (sentence1.size()  > sentence2.size()) {
            st = sentence2.size() - start1 - 1;
            pos = sentence1.size() - st - 1;
            if (sentence1[pos - 1] != ' ') return false;
            while (start1 < sentence2.size()) {
                if (sentence1[pos] != sentence2[start1]) return false;
                ++pos;
                ++start1;
            }
        } else {
            st = sentence1.size() - start2 - 1;
            pos = sentence2.size() - st - 1;
            if (sentence2[pos - 1] != ' ') return false;
            while (start1 < sentence1.size()) {
                if (sentence2[pos] != sentence1[start1]) return false;
                ++pos;
                ++start1;
            }
        }
        return true;
    }
};

int main() {
  
  
  
  return 0;  
}
