class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        deque<int> deq(m);
        iota(deq.begin(), deq.end(), 1);
        vector<int> answer;
        for (const auto &e: queries) {
            auto it = find(deq.cbegin(), deq.cend(), e);
            answer.push_back(it - deq.cbegin());
            auto tmp = *it;
            deq.erase(it);
            deq.push_front(tmp);
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
