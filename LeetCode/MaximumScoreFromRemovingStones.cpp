class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt = 0;
        while(true) {
            int tmp1 = pq.top();
            if (tmp1 == 0)
                break;
            --tmp1;
            pq.pop();
            int tmp2 = pq.top();
            if (tmp2 == 0)
                break;
            --tmp2;
            pq.pop();
            pq.push(tmp1);
            pq.push(tmp2);
            ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
