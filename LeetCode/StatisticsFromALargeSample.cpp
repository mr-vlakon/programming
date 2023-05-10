class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> answer(5, 0);
        int minV = INT_MAX;
        int maxV = 0; 
        long long sum = 0;
        int cnt = 0;
        int maxCnt = 0;
        double mode = 0;
        long long i = 0;
        for (const auto &e: count) {
            sum += e*i;
            if (e > maxCnt) {
                maxCnt = e;
                mode = i;
            }
            if (e != 0) {
                cnt += e;
                maxV = i;
                if (minV == INT_MAX) {
                    minV = i;
                }
            }
            ++i;
        }
        answer[0] = minV;
        answer[1] = maxV;
        answer[2] = static_cast<double>(sum) / cnt;
        int posMed = 0;
        if ((cnt % 2) == 1)  {
            posMed = cnt / 2 + 1;
        } else {
            posMed = cnt / 2;
        }
        int med = -1;
        int firstMed = -1;
        int secondMed = -1;
        int counter = 0;
        i = 0;
        for (const auto &e: count) {
            if ((cnt % 2) == 0 && e != 0) {
                if ((counter + e) >= posMed && firstMed == -1) {
                    firstMed = i;
                }
                if ((counter + e) >= (posMed + 1) && secondMed == -1) {
                    secondMed = i;
                }
            } else if ((cnt % 2) && e){
                if (counter < posMed && (counter + e) >= posMed &&  med == -1) {
                    med = i;
                }
            }
            counter += e; 
            ++i;   
        }
        if ((cnt % 2) == 1) {
            answer[3] = med;
        } else {
            answer[3] = (firstMed + secondMed) / 2.0;
        }
        answer[4] = mode;
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
