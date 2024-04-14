int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;  // Start with a carry of 1.
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));  // Allocate memory for the result array.

    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;  // Store the least significant digit.
        carry = sum / 10;         // Update the carry for the next iteration.
    }

    if (carry) {
        result[0] = carry;  // If there's still a carry, store it in the most significant digit.
        *returnSize = digitsSize + 1;
    } else {
        // No carry in the most significant digit.
        for (int i = 0; i < digitsSize; i++) {
            result[i] = result[i + 1];  // Shift the digits to the right by one.
        }
        *returnSize = digitsSize;
    }

    return result;
}