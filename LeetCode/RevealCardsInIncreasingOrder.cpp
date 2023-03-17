class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (const auto &e: deck) {
            q.push(e);
        }
       vector<int> answer(deck.size(), 0);
        int start = 0;
        int cnt = 0;
        answer[0] = q.front();
        q.pop();
        int top = 0;
        while (!q.empty()) {
            cnt = 0;
            top = q.front();
            q.pop();
            while (cnt != 1) {
                if (start >= answer.size()) {
                    start = 0;
                }
                if (answer[start] == 0) {
                    ++cnt;
                }
                ++start;
            }
            if (start >= answer.size()) {
                start = 0;
            }
            while (answer[start] != 0) {
                ++start;
                if (start >= answer.size()) {
                    start = 0;
                }
            }
            answer[start] = top;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
