class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [=] (const vector<int> &lhs , const vector<int> &rhs) {
            return lhs[1] > rhs[1];
        });
        int i = 0;
        int answer = 0;
        int k = 0;

        while (i != truckSize) {
            if (boxTypes[k][0] == 0) {
                ++k;
            }
            if (k == boxTypes.size())
                break;
            answer += boxTypes[k][1];
            ++i;
            --boxTypes[k][0];
        }
        
        return answer;  
    }
};

int main() {
  
  
  return 0;  
}
