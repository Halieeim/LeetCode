uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0, i,j, bits = ceil(log2(n)), shift = 1;
    for(i = 0; i < 32; i++){
        reversed <<= 1; // Left-shift reversed to make room for the next bit
        if (n & 1) {
            reversed |= 1; // Set the least significant bit of reversed if the current bit of n is 1
        }
        n >>= 1;
    }
    return reversed;
}