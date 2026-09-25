#import <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> pastNumbers;

        while(!pastNumbers.contains(n)){
            pastNumbers[n] = n;
            n = digitFunction(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }

    int digitFunction(int x){
        int sum = 0;
        int numDigits = to_string(x).length();

        for(int i = 0; i < numDigits; i++){
            sum += pow(x % 10, 2);
            x /= 10;
        }

        return sum;
    }
};
