class Solution {
public:
    int longestDecomposition(string text) {
        int answer = 0;
        int start = 0;
        int end = text.size() - 1;
        while (start <= end) {
            string s;
            string beg;
            bool status = true;
            while (start < end) {
                s.push_back(text[end]);
                --end;
                beg.push_back(text[start]);
                ++start;
                if (s == string{beg.rbegin(), beg.rend()}) {
                    status = false;
                    answer += 2;
                    break;
                }
            }
            if (status) {
                ++answer;
                break;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
