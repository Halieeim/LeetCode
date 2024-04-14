


typedef struct {
    int counter;
    int* ping;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* rc = (RecentCounter*)malloc(sizeof(RecentCounter));
    rc->counter = 0;
    rc->ping = (int*)malloc(10000 * sizeof(int));
    return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {
    int n = 0;
    obj->ping[obj->counter] = t;
    obj->counter++;
    for(int i = 0; i < obj->counter; i++){
        if((obj->ping[i] >= t-3000) && (obj->ping[i] <= t)) n++;
    }
    return n;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->ping);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/