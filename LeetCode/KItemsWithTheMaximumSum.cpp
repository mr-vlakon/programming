class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int answer = 0;
        int tmp = 0;
        if (k > 0) {
            tmp = min(numOnes, k);
            k -= min(numOnes, tmp);
            answer += tmp;
        }
        if (k > 0) {
            k -= min(numZeros, k);
        }
        if (k > 0) {
            tmp = min(numNegOnes, k);
            k -= tmp;
            answer -= tmp;
        }       
        return answer;
    }
};

int main()  {
  
  
  
  return 0;  
}
