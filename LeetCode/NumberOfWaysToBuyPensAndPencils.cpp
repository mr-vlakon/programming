class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long answer = 0;
        int tmp = cost1;
        answer += (total / cost2) + 1;
        while (tmp <= total) {
            int x = total - tmp;
            answer += (x / cost2) +  1; 
            tmp += cost1;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
