class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.cbegin(), beans.cend(), 0LL);
        long long answer = LONG_LONG_MAX;
        long long t = 0;
        for (int i = 0; i != beans.size(); ++i) {
            t = sum - (beans.size() - i)*beans[i];
            answer = min(answer, t);
        }
        return answer;
  }
};

int main() {
  
  
  return 0;  
}
