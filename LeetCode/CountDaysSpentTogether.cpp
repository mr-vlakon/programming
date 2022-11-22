class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string alBM(arriveAlice.cbegin(), arriveAlice.cbegin() + 2);
        string alBD(arriveAlice.cbegin() + 3, arriveAlice.cend());
        
        string alEM(leaveAlice.cbegin(), leaveAlice.cbegin() + 2);
        string alED(leaveAlice.cbegin() + 3, leaveAlice.cend());
        
        int alBMint = stoi(alBM);
        int beginAlice = 0;
        int i = 0;
        while (i != alBMint - 1) {
            beginAlice += days[i];
            ++i;
        }
        beginAlice += stoi(alBD);
        
        int alEMint = stoi(alEM);
        int endAlice = 0;
        i = 0;
        while (i != alEMint - 1) {
            endAlice += days[i];
            ++i;
        }
        endAlice += stoi(alED);
        
        string bobBM(arriveBob.cbegin(), arriveBob.cbegin() + 2);
        string bobBD(arriveBob.cbegin() + 3, arriveBob.cend());
        
        string bobEM(leaveBob.cbegin(), leaveBob.cbegin() + 2);
        string bobED(leaveBob.cbegin() + 3, leaveBob.cend());
        
        int bobBMint = stoi(bobBM);
        int beginBob = 0;
        i = 0;
        while (i != bobBMint - 1) {
            beginBob += days[i];
            ++i;
        }
        beginBob += stoi(bobBD);
        
        int bobEMint = stoi(bobEM);
        int endBob = 0;
        i = 0;
        while (i != bobEMint - 1) {
            endBob += days[i];
            ++i;
        }
        endBob += stoi(bobED);
        if (beginAlice <= beginBob && endAlice >= endBob) {
            return endBob - beginBob + 1;
        } else if (beginAlice <= beginBob && endAlice <= endBob && beginBob <= endAlice) {
            return endAlice - beginBob + 1;    
        }
        
        if (beginBob <= beginAlice && endBob >= endAlice) {
            return endAlice - beginAlice + 1;
        } else if (beginBob <= beginAlice && endBob <= endAlice && beginAlice <= endBob) {
            return endBob - beginAlice + 1;    
        }
        return 0;      
    }
};

int main() {
  
  
  
  return 0;  
}
