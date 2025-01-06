// If n was number of digits
// DP values is = DIGIT * pow (10, DIGIT -1)
int countDigitOne(int n) {
    int digit = 0;
    int tn = n;
    while(tn) {
        digit++;
        tn /= 10;
    }
    digit--;
    vector<int> dp(digit+1, 0);
    dp[1] = 1;
    for(int i=2; i<=digit; i++) {
        int isum = 0;
        int tdigit = i;
        for(int j=0; j<tdigit; j++) {
            int val = 0;
            int fdv = 9, odv = 10;
            val = fdv;
            if(j == tdigit-1)
                val = pow(odv, (tdigit-1));
            else if(tdigit > 2)
                val = fdv* pow(odv,(tdigit-2));
            isum += val;
        }
        dp[i] = dp[i-1] + isum;
    }
    for(int el: dp)
        cout << el << " ";
    int ans = dp[digit];
    digit++;
    
    return ans;
}

int countDigitOne(int n) {
    int digit = 0;
    int tn = n;
    while(tn) {
        digit++;
        tn /= 10;
    }
    digit--;
    vector<int> dp(digit+1, 0);
    for(int i=1; i<=digit; i++) {
        dp[i] = i * pow(10, i-1);
    }
    for(int el: dp)
        cout << el << " ";
    int ans = dp[digit];
    digit++;

    return ans;
}