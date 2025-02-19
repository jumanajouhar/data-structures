#include <stdio.h>
#define MAX_DEGREE 101

/* Define a structure to represent a polynomial */
typedef struct {
  int degree;
  float coef[MAX_DEGREE];
} polynomial;

/* Function prototypes */
void initPolynomial(polynomial *p, int degree);
void printPolynomial(polynomial p);
polynomial multiplyPolynomials(polynomial p1, polynomial p2);

int main() {
  polynomial p1, p2, p3;

  /* Initialize polynomials p1 and p2 */
  initPolynomial(&p1, 2);
  p1.coef[2] = 2;
  p1.coef[1] = 3;
  p1.coef[0] = 4;
  initPolynomial(&p2, 3);
  p2.coef[3] = 1;
  p2.coef[2] = 2;
  p2.coef[1] = 3;
  p2.coef[0] = 4;

  /* Print polynomials p1 and p2 */
  printf("p1 = ");
  printPolynomial(p1);
  printf("p2 = ");
  printPolynomial(p2);

  /* Multiply polynomials p1 and p2 */
  p3 = multiplyPolynomials(p1, p2);

  /* Print the result */
  printf("p3 = p1 * p2 = ");
  printPolynomial(p3);

  return 0;
}

/* Initialize a polynomial with a given degree */
void initPolynomial(polynomial *p, int degree) {
  int i;
  p->degree = degree;
  for (i = 0; i <= degree; i++) {
    p->coef[i] = 0;
  }
}

/* Print a polynomial in a human-readable form */
void printPolynomial(polynomial p) {
  int i;
  for (i = p.degree; i >= 0; i--) {
    if (p.coef[i] != 0) {
      printf("%.2fx^%d", p.coef[i], i);
      if (i > 0) {
        printf(" + ");
      }
    }
  }
  printf("\n");
}

/* Multiply two polynomials and return the result */
polynomial multiplyPolynomials(polynomial p1, polynomial p2) {
  polynomial result;
  int i, j;
  initPolynomial(&result, p1.degree + p2.degree);
  for (i = 0; i <= p1.degree; i++) {
    for (j = 0; j <= p2.degree; j++) {
      result.coef[i + j] += p1.coef[i] * p2.coef[j];
    }
  }
  return result;
}

