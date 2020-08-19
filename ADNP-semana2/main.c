#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 1000
#define SEED 0
#define MAX_VALUE N*100

// PROTOTYPES

// Aux Functions
int* randomVector (int n, int max, int seed);
int* createVector (int n);
int* descendingVector (int n);
int max (int *v, int begin, int end, int *comparisons);
void insertion (int *v, int k, int *insertionComparisons);
void merge (int *v, int p, int q, int r, int *inversions);
void troca (int *v, int i, int j);
int partition (int *v, int p, int r);
void printVector (int *v, int n);

// Sorting algorithms
void selectionSort (int *v, int n, int *selectionComparisons);
void bubbleSort (int *v, int n, int *bubbleComparisons);
void insertionSort (int *v, int n, int *insertionComparisons);
int mergeSort (int *v, int left, int right);
void quickSort (int *v, int left, int right);


// IMPLEMENTATIOS

// Aux Functions
int* randomVector (int n, int max, int seed) {
  int *v = (int *) calloc(n, sizeof(int));
  srand(seed);

  for (int i = 0; i < n; i++) {
    v[i] = rand() % max;
  }

  return v;
}

// this function creates a vector with some elements out of the correct place 
int* createVector (int n) {
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

int* descendingVector (int n) {
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

void merge (int *v, int p, int q, int r, int *inversions) {
  int *e, *d;
  int i, j, k;
  
  int n1 = q - p+1;
  int n2 = r - q;
  e = (int*) calloc(n1+1, sizeof(int));
  d = (int*) calloc(n2+1, sizeof(int));
  
  for (i = 0; i < n1; i++) {
    e[i] = v[p+i];
  }
  e[n1] = INT_MAX;

  for (j = 0; j < n2; j++) {
    d[j] = v[(q+1) + j];
  }
  d[n2] = INT_MAX;

  i = 0;
  j = 0;

  for (k = p; k <= r; k++) {
    if (e[i] <= d[j]) {
      v[k] = e[i];
      i++;
    } else {
      v[k] = d[j];
      
      if (i < j) {
        *inversions += 1;
      }

      j++;
    }
  }

  free(e);
  free(d);
}

void troca (int *v, int i, int j) {
  int element = v[i];
  v[i] = v[j];
  v[j] = element;
}

int partition (int *v, int p, int r) {
  int pivot, i, j;
  
  pivot = v[r]; // this implementation always uses the last vector element as pivot
  i = p-1; // no problem, because i is incremented before be used

  for (j = p; j < r; j++) {
    if (v[j] <= pivot) {
      i++;
      troca(v, i, j);
    }
  }

  troca(v, i+1, r);
  return i+1;
}

void printVector (int *v, int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", v[i]);
    printf("%s", i == n-1 ? "]\n" : ", ");
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

int mergeSort (int *v, int left, int right) {
  int middle;
  int inversions = 0;

  if (left < right) {
    middle = (left + right) / 2;
    mergeSort(v, left, middle);
    mergeSort(v, middle+1, right);
    merge(v, left, middle, right, &inversions);
  }

  return inversions;
}

void quickSort (int *v, int left, int right) {
  int q;

  while (left < right) {
    q = partition(v, left, right);

    if (q - left < right - q) {
      quickSort(v, left, q-1);
      right = q + 1;
    } else {
      quickSort(v, q+1, right);
      right = q - 1;
    }
  }
}

int main () {
  int *v;
  int mergeInversions;
  int comparisons;
  clock_t time;

  printf("N = %d\n\n", N);

  // SELECTION SORT
  comparisons = 0;
  v = randomVector(N, MAX_VALUE, SEED);
  
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("selectionSort --> number of comparisons: %d\n", comparisons);
  printf("Time spent: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;
  v = randomVector(N, MAX_VALUE, SEED);

  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("bubbleSort --> number of comparisons: %d\n", comparisons);
  printf("Time spent: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;
  v = randomVector(N, MAX_VALUE, SEED);

  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("insertionSort --> number of comparisons: %d\n", comparisons);  
  printf("Time spent: %f seconds \n\n", ((float) time)/CLOCKS_PER_SEC);

  // MERGE SORT
  v = randomVector(N, MAX_VALUE, SEED);

  time = clock();
  mergeInversions = mergeSort(v, 0, N);
  time = clock() - time;
  
  printf("Time spent with MergeSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  printf("Amount of inversions maded: %d\n\n", mergeInversions);

  // QUICK SORT
  v = randomVector(N, MAX_VALUE, SEED);
  
  time = clock();
  quickSort(v, 0, N);
  time = clock() - time;

  printf("Time spent with QuickSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  printf("\n====================Already ordered vector====================\n\n");
  
  // SELECTION SORT
  comparisons = 0;
  
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("Time spent with SelectionSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;

  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("Time spent with BubbleSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;
  v = randomVector(N, MAX_VALUE, SEED);

  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("Time spent with InsertionSort: %f seconds \n\n", ((float) time)/CLOCKS_PER_SEC);

  // MERGE SORT
  time = clock();
  mergeInversions = mergeSort(v, 0, N);
  time = clock() - time;
  
  printf("Time spent with MergeSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  printf("Amount of inversions maded: %d\n\n", mergeInversions);

  // QUICK SORT
  time = clock();
  quickSort(v, 0, N);
  time = clock() - time;

  printf("Time spent with QuickSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  free(v);

  printf("\n====================Almost ordered vector====================\n\n");

  // SELECTION SORT
  comparisons = 0;
  
  v = createVector(N);
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("Time spent with SelectionSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;

  v = createVector(N);
  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("Time spent with BubbleSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;

  v = createVector(N);
  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("Time spent with InsertionSort: %f seconds \n\n", ((float) time)/CLOCKS_PER_SEC);

  // MERGE SORT
  v = createVector(N);
  time = clock();
  mergeInversions = mergeSort(v, 0, N);
  time = clock() - time;
  
  printf("Time spent with MergeSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  printf("Amount of inversions maded: %d\n\n", mergeInversions);

  // QUICK SORT
  v = createVector(N);  
  time = clock();
  quickSort(v, 0, N);
  time = clock() - time;

  printf("Time spent with QuickSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  free(v);

  printf("\n====================Descending vector====================\n\n");

    // SELECTION SORT
  comparisons = 0;
  
  v = descendingVector(N);
  time = clock();
  selectionSort(v, N, &comparisons);
  time = clock() - time;
  
  printf("Time spent with SelectionSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // BUBBLE SORT
  comparisons = 0;

  v = descendingVector(N);
  time = clock();  
  bubbleSort(v, N, &comparisons);
  time = clock() - time;

  printf("Time spent with BubbleSort: %f seconds\n\n", ((float)time)/CLOCKS_PER_SEC);

  // INSERTION SORT
  comparisons = 0;

  v = descendingVector(N);
  time = clock();
  insertionSort(v, N, &comparisons);
  time = clock() - time;

  printf("Time spent with InsertionSort: %f seconds \n\n", ((float) time)/CLOCKS_PER_SEC);

  // MERGE SORT
  v = descendingVector(N);
  time = clock();
  mergeInversions = mergeSort(v, 0, N);
  time = clock() - time;
  
  printf("Time spent with MergeSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
  printf("Amount of inversions maded: %d\n\n", mergeInversions);

  // QUICK SORT
  v = descendingVector(N);  
  time = clock();
  quickSort(v, 0, N);
  time = clock() - time;

  printf("Time spent with QuickSort: %f seconds\n", ((float)time)/CLOCKS_PER_SEC);

  free(v);

  return 0;
}
