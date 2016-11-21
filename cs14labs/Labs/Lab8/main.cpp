


const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
const int NUMBERS_SIZE = 50000;

void fillArrays(int arr1[], int arr2[],int arr3[]);
int genRandInt(int low, int high);
void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize);

void InsertionSort(int numbers[], int numbersSize) {
    
}

void Quicksort_midpoint(int numbers[], int i, int k) {
    
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
    
}

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {
    
    
    clock_t Start = clock();
    //call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
}