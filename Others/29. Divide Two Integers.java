class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        
        boolean negativeResult = (dividend < 0) ^ (divisor < 0);
        
        long x = Math.abs((long) dividend);
        long y = Math.abs((long) divisor);
        
        long quotient = 0;
        while (x >= y) {
            long temp = y;
            long multiple = 1;
            while (x >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            x -= temp;
            quotient += multiple;
        }
        
        if (negativeResult) {
            quotient = -quotient;
        }
        
        if (quotient > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (quotient < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        
        return (int) quotient;
    }
}
