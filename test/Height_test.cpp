#include "Height.h"

int main() {

  /* simple square with */
  Height h1(3, 3);

  /* one-dimentionnal height axis x*/
  Height h2(5, 1, 3.0);

  Height h3(h2);

  /* one-dimentionnal height axis y*/
  Height h4(1, 5, 5.0);

  Height h5(h4);

  /* two dimenstionnal height ~ normal square */
  Height h6(2, 2);

  std::stringstream str1;
  cout << h1 << endl;
  cout << h2 << endl;
  cout << h3 << endl;
  cout << h4 << endl;
  cout << h5 << endl;

  cout << h2.getWidth() << endl;
}
