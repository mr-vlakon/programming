class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, deque<int>, greater<int>> pqMin(nums.cbegin(), nums.cend());
        vector<int> answer;
        while (!pqMin.empty()) {
            int al = pqMin.top();
            pqMin.pop();
            int bob = pqMin.top();
            pqMin.pop();
            answer.push_back(bob);
            answer.push_back(al);        
        }
        return answer;
    }
};

int main()
{



  return 0;
}
