class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int i = 0;
        vector<int> answer;
        while ( i != arr.size() - 1) {
            auto max = *max_element(arr.cbegin() + i + 1, arr.cend());
            answer.push_back(max);
            ++i;
        }
        answer.push_back(-1);
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
