#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

int guess(int num){
    return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int maxNumber = n, minNumber = 1;
        while (true) {
            int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
            int res = guess(meanNumber);
            if (res == 0) {
                return meanNumber;
            } else if (res == 1) {
                minNumber = meanNumber + 1;
            } else {
                maxNumber = meanNumber - 1;
            }
        }
    }
};




int main(){
    return 0;
}
