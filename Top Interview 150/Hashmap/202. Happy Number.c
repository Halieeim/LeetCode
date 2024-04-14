int sumDigits(int x){
    int sum = 0;
    while(x){
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}
bool isHappy(int n){
    int temp = n, origin = n, x =  0, j = 0;
    while(temp != 1){
        temp = 0;
        while(n){
            int d = n % 10;
            temp += (d*d);
            n /= 10;
        }
        n = temp;
        x = sumDigits(n);
        if(++j > 50) 
            return false;
    }
    return true;
}