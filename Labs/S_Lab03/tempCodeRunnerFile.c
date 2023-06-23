int ExtractMin(int* arr, int size){
    int min = arr[0];
    swap(&arr[0], &arr[size-1]);
    // free(arr[size-1]);
    size--;
    // *arr = realloc(arr, size*sizeof(int));

    int i=0;
    while (arr[i]>arr[2*i+1] || arr[i]>arr[2*i+2] && 2*i+2<size && 2*i+1<size){
        if (arr[2*i+1]<arr[2*i+2]){
            swap(&arr[i], &arr[2*i+1]);
            i = 2*i+1;
        }
        else{
            swap(&arr[i], &arr[2*i+2]);
            i = 2*i+2;
        }
    }