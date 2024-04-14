bool canPlaceFlowers(int* flowerbed, int size, int n){
    int places = 0;
    int *p1 = flowerbed, *p2 = flowerbed, *p3 = size > 1 ? flowerbed + 1 : flowerbed;
    for(int i = 0; i < size; i++){
        if((!(*p1)) && (!(*p2)) && (!(*p3))){
            places++;
            *p2 = 1;
        }
        if(i != 0) p1++;
        p2++;
        if(i < size-2) p3++;
    }
    printf("%d", places);
    if(places >= n) return true;
    return false;
}