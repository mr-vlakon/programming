class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> answer;
        for (int i = 1; i != mountain.size() - 1; ++i) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};

int main()
{


  return 0;
}
