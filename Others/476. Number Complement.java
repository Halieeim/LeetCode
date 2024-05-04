class Solution {
    public int findComplement(int num) {
        if(num == 0) return num;
        int size = (int)(Math.log(num) / Math.log(2) +1);
        int i = 0;
        while(size-- > 0){
            num ^= 1<<i++;
        }
        return num;
    }
}