int mySqrt(int x){
    int i = 0;
    if((x == 0) || (x == 1))
        return x;
        
    int start = 1, end = x, mid;
    while(start <= end){
        mid = start + (end-start)/2;
        long long result = (long long)mid * mid;
        if(result > x)
            end = mid-1;
        else if(result == x)
            return mid;
        else
            start = mid + 1;
    }
    return end;
}