void multip_matrice(int **A, int **B, int **C, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j<n; j++) {
      for (int k = 0; k<n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void create_matrice(int **A, int n) {
  A = new int*[n];
  for (int i = 0; i < n; i++) {
    A[i] = new int[n];
  }
}



int main()
{
  int n = 1000;
  int **C; int **A; int**B;
  create_matrice(A, n);
  create_matrice(B, n);
  create_matrice(C, n);
  multip_matrice(A, B, C, n);
}
