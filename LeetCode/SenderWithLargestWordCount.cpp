class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        size_t max = 0;
        size_t index = 0;
        unordered_map<string, size_t> um;
        for (const auto &e: messages) {
            size_t tmp = count(e.cbegin(), e.cend(), ' ');
            um[senders[index]] += tmp + 1;
            ++index;
        }
        
        for (const auto &e: um)  {
            if (e.second > max) {
                max = e.second;
            }
        }
        
        string answer;
        for (const auto &e: um) {
            if (e.second == max && e.first > answer) {
                answer = e.first;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
