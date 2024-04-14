int trailingZeroes(int n){
    if(n < 5) {
        return 0;
    }
    int counter = 0;
    for(int i = 5; i <= n; i*=5){
        counter += n/i;
    }
    return counter;
}