class Solution {
public:
    string alphabetBoardPath(string target) {
        int startR = 0;
        int startC = 0;
        int searchR = 0;
        int searchC = 0;
        string answer;
        for (int i = 0; i != target.size(); ++i) {
            searchR = (target[i] - 'a') / 5;
            searchC = (target[i] - 'a') % 5;
            if (searchR > startR) {
                answer += string(searchR - startR - ((searchR == 5) ? 1 : 0), 'D');
                startR = searchR - ((searchR == 5) ? 1 : 0);
            } else {
                answer += string(startR - searchR, 'U');
                startR = searchR;
            }
            if (startC < searchC) {
                answer += string(searchC - startC, 'R');
                startC = searchC;
            } else {
                answer += string(startC - searchC, 'L');
                startC = searchC;
            }
            if (startR != searchR) {
                answer += 'D';
                ++startR;
            }
            answer += '!';
        }
        return answer;
    }
};
/*
class Solution {
public:
    string alphabetBoardPath(string target) {
        int startR = 0;
        int startC = 0;
        int searchR = 0;
        int searchC = 0;
        string answer;
        for (int i = 0; i != target.size(); ++i) {
            searchR = (target[i] - 'a') / 5;
            searchC = (target[i] - 'a') % 5;
            if (searchR > startR) {
                if (searchR != 5) {
                    answer += string(searchR - startR, 'D');
                    startR = searchR;
                } else {
                    answer += string(searchR - startR - 1, 'D');
                    startR = searchR - 1;
                }
            } else {
                answer += string(startR - searchR, 'U');
                startR = searchR;
            }
            if (startC < searchC) {
                answer += string(searchC - startC, 'R');
                startC = searchC;
            } else {
                answer += string(startC - searchC, 'L');
                startC = searchC;
            }
            if (startR != searchR) {
                answer += 'D';
                ++startR;
            }
            answer += '!';
        }
        return answer;
    }
};
*/
/*
class Solution {
public:
    string alphabetBoardPath(string target) {
        int startR = 0;
        int startC = 0;
        int searchR = 0;
        int searchC = 0;
        string answer;
        for (int i = 0; i != target.size(); ++i) {
            searchR = (target[i] - 'a') / 5;
            searchC = (target[i] - 'a') % 5;
            if (searchR > startR) {
                while (searchR > startR && startR < 4) {
                    answer += 'D';
                    ++startR;
                }
            } else {
                while (searchR < startR) {
                    answer += 'U';
                    --startR;
                }    
            }
            if (startC < searchC) {
                while (startC < searchC) {
                    answer += 'R';
                    ++startC;
                }
            } else {
                while (startC > searchC) {
                    answer += 'L';
                    --startC;
                }
            }
            if (startR !=  searchR) {
                answer += 'D';
                ++startR;
            }
            answer += '!';
        }
        return answer;
    }
};
*/
/*
class Solution {
public:
    string alphabetBoardPath(string target) {
        int startR = 0;
        int startC = 0;
        int searchR = 0;
        int searchC = 0;
        string answer;
        for (int i = 0; i != target.size(); ++i) {
            searchR = (target[i] - 'a') / 5;
            searchC = (target[i] - 'a') % 5;
            if (searchR > startR) {
                while (searchR > startR && startR < 4) {
                    answer += 'D';
                    ++startR;
                }
                if (startR != searchR) {
                    if (startC < searchC) {
                        while (startC < searchC) {
                            answer += 'R';
                            ++startC;
                        }
                    } else {
                        while (startC > searchC) {
                            answer += 'L';
                            --startC;
                        }
                    }
                    answer += 'D';
                    ++startR;         
                }
            } else {
                while (searchR < startR) {
                    answer += 'U';
                    --startR;
                }    
            }
            if (startC < searchC) {
                while (startC < searchC) {
                    answer += 'R';
                    ++startC;
                }
            } else {
                while (startC > searchC) {
                    answer += 'L';
                    --startC;
                }
            }
            answer += '!';
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
