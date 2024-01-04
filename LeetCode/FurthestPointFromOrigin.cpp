class Solution {
public:    
    int furthestDistanceFromOrigin(string moves) {
        vector<int> dpMin(moves.size(), 0);
        vector<int> dpMax(moves.size(), 0);
        if (moves[0] == '_') {
            dpMin[0] = -1;
            dpMax[0] = 1;
        } else if (moves[0] == 'R') {
            dpMin[0] = 1;
            dpMax[0] = 1;
        } else {
            dpMin[0] = -1;
            dpMax[0] = -1;
        }
        for (int i = 1; i != moves.size(); ++i) {
            if (moves[i] == '_') {
                dpMin[i] = dpMin[i - 1] - 1;
                dpMax[i] = dpMax[i - 1] + 1;
            } else if (moves[i] == 'R') {
                dpMin[i] = dpMin[i - 1] + 1;
                dpMax[i] = dpMax[i - 1] + 1;
            } else {
                dpMin[i] = dpMin[i - 1] - 1;
                dpMax[i] = dpMax[i - 1] - 1;
            }
        }
        return max(dpMax.back(), abs(dpMin.back()));
    }
private:
    int answer = 0;
};

int main()
{


  return 0;
}
