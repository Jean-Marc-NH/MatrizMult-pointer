#include <iostream>
using namespace std;

void mult(int (*A)[3][3]) {
  int *p = **(A);
  int *q = **(A + 1);
  int *r = **(A + 2);

  int *ini_q = **(A + 1);
  int *ini_p = **(A);
  int *ini_r = **(A + 2);
  int *fin_p = **(A + 1);
  int *sfin_q = **(A + 1) + 3;
  int *fin_q = **(A + 2);
  int *fin_r = **(A + 3);

  while (p < fin_p) {
    *r += (*p) * (*q);
    cout << *p << " * " << *q << " = " << *r << "\n";
    q++;
    r++;
    if(sfin_q >= fin_q && q >= fin_q){
      ini_r += 3;
    }
    if (q == sfin_q) {
      sfin_q += 3;
      p++;
      r = ini_r;
      cout << "\n";
    }

    if(sfin_q >= fin_q && q >= fin_q){
      sfin_q = **(A + 1) + 3;
      q = ini_q;
      cout << "----\n";
    }
  }
}

int main() {
  int A[3][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                    {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}},
                    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

  mult(A);

  for (int *i = **(A + 2); i < **(A + 3); i++) {
    cout << *i << " ";
  }
}
