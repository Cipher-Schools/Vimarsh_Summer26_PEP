class Solution {
private:
    double solve(double x, long long n) {
        if (n == 0) return 1.0; // Base case
        
        double half = solve(x, n / 2);
        
        // If n is even: x^n = x^(n/2) * x^(n/2)
        // If n is odd:  x^n = x * x^(n/2) * x^(n/2)
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }

public:
    double myPow(double x, int n) {
        long long nn = n; // Use long long to safely convert INT_MIN to positive
        if (nn < 0) {
            nn = -nn;
            return 1.0 / solve(x, nn);
        }
        return solve(x, nn);
    }
};