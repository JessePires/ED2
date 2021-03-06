#pragma once

typedef struct prime_list_t{
  int* PL;
  int n;
}prime_list_t;

void PL_Create(const char* txt_prime_list, const char* output_filename);
prime_list_t* PL_Load(const char* prime_data);
int PL_NextPrime(prime_list_t* pl, int n);
void PL_Destroy(prime_list_t* pl);
