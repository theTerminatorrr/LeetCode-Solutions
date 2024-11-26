int maximumSwap(int num) {
    int i = log10(num);
    char arr[9];

    sprintf(arr, "%d", num);
    int max = i, swap1 = -1, swap2;

    while (--i >= 0) {
        if (arr[i] > arr[max]) {
            max = i;
        } else if (arr[i] < arr[max]) {
            swap1 = i;
            swap2 = max;
        }
    }

    if (swap1 != -1) {
        int temp = arr[swap1];
        arr[swap1] = arr[swap2];
        arr[swap2] = temp;
    }

    num = atoi(arr);
    return num;
}
