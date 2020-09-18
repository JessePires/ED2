int min (int *v, int inicio, int fim) {
  int i;
  int posicao = inicio;

  for (i = inicio; i < fim; i++) {
    if (v[i] < v[posicao]) {
      posicao = i;
    }
  }

  return posicao;
}

int max (int *v, int inicio, int fim) {
  int i;
  int posicao = inicio+1;

  for (i = inicio; i < fim; i++) {
    if (v[i] > v[posicao]) {
      posicao = i;
    }
  }

  return posicao;
}

void troca (int *v, int i, int j) {
  int auxiliar = v[i];
  v[i] = v[j];
  v[j] = auxiliar;
}

void print_vector (int *v, int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", v[i]);
    printf("%s", i == n-1 ? "]" : ", ");
  }
}
