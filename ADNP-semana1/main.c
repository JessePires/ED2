#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define SEED 0
#define MAX_VALUE 1000


// PROTOTYPES

// Aux Functions
int* random_vector (int n, int max, int seed);
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

  return 0;
}
