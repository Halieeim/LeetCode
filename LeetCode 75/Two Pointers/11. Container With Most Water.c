int maxArea(int* arr, int size){
    int max = INT_MIN, h = 0, w = 0, *p1 = arr, *p2 = arr+size-1, area = 0;
    while(p1 < p2){
        w = p2 - p1;
        h = *p2 > *p1 ? *p1 : *p2;
        area = w * h;
        max = max > area ? max : area;
        *p1 >= *p2 ? p2-- : p1++;
    }
    return max;
}