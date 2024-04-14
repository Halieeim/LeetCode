int hammingWeight(uint32_t n) {
    uint32_t counter = 0, i, j, bits = log2(n)+1, shift = 1;  
    for(i = 0; i < bits; i++){
        if((shift<<i) & n){
            counter++;
        }
    }
    return counter;
}