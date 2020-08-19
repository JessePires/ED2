#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
#define SEED 0
#define MAX_VALUE N*100


// PROTOTYPES

// Aux Functions
int* random_vector (int n, int max, int seed);
int* create_vector (int n);
int* descending_vector (int n);
int max (int *v, int begin, int end, int *comparisons);
void troca (int *v, int x, int y);
void insertion (int *v, int k, int *insertionComparisons);
void printVector(int *v, int n);

// Sorting Algorithms
void selectionSort (int *v, int n, int *selectionComparisons);
void bubbleSort (int *v, int n, int *bubbleComparisons);
void insertionSort (int *v, int n, int *insertionComparisons);


//IMPLEMENTATIONS

// Aux Functions
int* random_vector (int n, int max, int seed) {
  int *v = (int *) calloc(n, sizeof(int));
  srand(seed);

  for (int i = 0; i < n; i++) {
    v[i] = rand() % max;
  }

  return v;
}

// this function creates a vector with some elements out of the correct place 
int* create_vector (int n) {
  int *v = (int *) calloc(n, sizeof(int));

  for (int i = 0; i < n - 1; i++) {
    if (i == n/3) {
      v[i] = i+1 * 2 + 3;  
    } else if (i == n/2) {
      v[i] = i+2 * 10;
    }else if (i == n/2+10) {
      v[i] = i+5; 
    }else {
      v[i] = i+1;
    }
  }

  v[n] = 0;
  return v;
}

int* descending_vector (int n) {
  int *v = (int *) calloc(n, sizeof(int));
  int value = n;

  for (int i = 0; i < n; i++) {
    v[i] = n;
    n--;
  }

  return v;
}

int max (int *v, int begin, int end, int *comparisons) {
  int position = end;
  
  for (int i = end-1; i >= begin; i--) {
    if (v[i] > v[position]) {
      position = i;
    }
    *comparisons += 1;
  }

  return position;
}

void troca (int *v, int x, int y) {
  int element = v[x];
  v[x] = v[y];
  v[y] = element;
}

void insertion (int *v, int k, int *insertionComparisons) {
  int i = k-1;
  int element = v[k]; 

  while (i >= 0 && v[i] > element) {
    *insertionComparisons += 1;
    v[i+1] = v[i];
    i--;
  }

  v[i+1] = element;
}

void printVector (int *v, int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", v[i]);
    printf("%s", i == n-1 ? "]" : ", ");
  }
}

// Sorting Algorithms
void selectionSort (int *v, int n, int *selectionComparisons) {
  int maxPosition;

  for (int i = n - 1; i > 0; i--) {
    maxPosition = max(v, 0, i, selectionComparisons);
    troca(v, maxPosition, i);
  }
}

void bubbleSort (int *v, int n, int *bubbleComparisons) {
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      *bubbleComparisons += 1;      
      if (v[j] > v[j+1]) {
        troca(v, j, j+1);
      }
    }
  }
}

void insertionSort (int *v, int n, int *insertionComparisons) { 
  for (int i = 0; i < n; i++) {
    insertion(v, i, insertionComparisons);
  }
}

int main () {
  int comparisons;
  int *v;
  clock_t time;

  printf("N = %d\n\n", N);

  // INSERTION SORT
  comparisons = 0;
  v = random_vector(N, MAX_VALUE, SEED);
  
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("selectionSort --> number of comparisons: %d\n", comparisons);
  printf("time spent: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);


  // BUBBLE SORT
  comparisons = 0;
  v = random_vector(N, MAX_VALUE, SEED);

  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("bubbleSort --> number of comparisons: %d\n", comparisons);
  printf("time spent: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);


  // INSERTION SORT
  comparisons = 0;
  v = random_vector(N, MAX_VALUE, SEED);

  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("insertionSort --> number of comparisons: %d\n", comparisons);  
  printf("time spent: %f seconds \n", ((float) time)/CLOCKS_PER_SEC);

  printf("\n====================Vector already ordered====================\n\n");

  // INSERTION SORT
  comparisons = 0;
  
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("time spent with SelectionSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;

  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("time spent with BubbleSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;
  v = random_vector(N, MAX_VALUE, SEED);

  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("time spent with InsertionSort: %f seconds \n", ((float) time)/CLOCKS_PER_SEC);

  free(v);

  printf("\n====================Almost ordered vector====================\n\n");

  // INSERTION SORT
  comparisons = 0;
  
  v = create_vector(N);
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("time spent with SelectionSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;

  v = create_vector(N);
  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("time spent with BubbleSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;

  v = create_vector(N);
  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("time spent with InsertionSort: %f seconds \n", ((float) time)/CLOCKS_PER_SEC);

  free(v);

  printf("\n====================Descending vector====================\n\n");

  // INSERTION SORT
  comparisons = 0;
  
  v = descending_vector(N);
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("time spent with SelectionSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;

  v = descending_vector(N);
  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("time spent with BubbleSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;

  v = descending_vector(N);
  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("time spent with InsertionSort: %f seconds \n", ((float) time)/CLOCKS_PER_SEC);

  free(v);

  return 0;
}
