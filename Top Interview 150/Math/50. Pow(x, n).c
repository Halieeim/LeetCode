double myPow(double x, int n){
    double result = 1;
    unsigned long long absN = n;
    if(n < 0){
        absN *= (-1);
        x = (1/x);
    }
    else{
        absN = n;
    }
    double current = x;
    while(absN > 0){
        if(absN % 2 == 1)
            result *= current;
        current *= current;
        absN = floor(absN/2);
    }
    return result;
}