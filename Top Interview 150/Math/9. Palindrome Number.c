bool isPalindrome(int x){
    long long digit = 0, digit2 = 0, m = x;
    if(x < 0)
        return false;

    while(x){
        digit *= 10;
        digit2 = x % 10;
        digit += digit2;
        x /= 10;
    }
    if(digit == m)
        return true;
    else
        return false;
}