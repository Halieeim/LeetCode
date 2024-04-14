#define GET_BIT(REG,BIT) ((REG & 1UL<<BIT)?1:0)
int minFlips(int a, int b, int c){
    unsigned int counter = 0, i = 0;
    // unsigned int res = a | b, shift = 1;
    while(i<32){
        int bit1 = GET_BIT(a,i);
        int bit2 = GET_BIT(b,i);
        int bit3 = GET_BIT(c,i);
        // printf("bit1 = %d, bit2 = %d\n", bit1, bit2);
        if(bit1 == 1 && bit2 == 1 && bit3 == 0){
            counter += 2;
        }
        else if((bit1 | bit2) != bit3){
            counter++;
        }
        i++;
    }
    return counter;
}