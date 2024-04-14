/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    int start = 1, end =  n;
    int myGuess = n/2.0 + .5;
    int correct = guess(myGuess);
    printf("%d", correct);
    while((start <= end) && (correct != 0)){
        if(correct == -1){
            end = myGuess-1;
        }
        else if(correct == 1){
            start = myGuess+1;
        }
        else{
            return myGuess;
        }
        myGuess = start + (end - start)/2;
        correct = guess(myGuess);
    }
    return myGuess;
}