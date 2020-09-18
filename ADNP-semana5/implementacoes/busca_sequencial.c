int busca_sequencial (int *v, int n, int x) {
  int i;

  for (i = 0; i < n; i++) {
    if (v[i] == x) {
      return i;
    }
  }

  return -1;
}
