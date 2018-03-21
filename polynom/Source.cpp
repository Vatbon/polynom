/*
**На вход командной строки даются коэффициенты многолченов a и b
** "a(n-1) a(n-2) ... a(1)" "b(n-1) b(n-2) ... b(1)"
** Вывести коэффициенты 
*/
/* http://cppstudio.com/post/812/ */

#include <stdlib.h>
#include <stdio.h>

struct polynomial {
	double coef[128];
	int degree;
};

void swap(double polynomial:: *a, double polynomial:: *b) {

}

int makePoly(struct polynomial *pol, char* string) {
	/* Инициализация многочлена */
	pol->degree = 0;
	int i;
	for (i = 0; i < 128; i++) {
		pol->coef[i] = 0;
	}
	if (string) {
		/* Заполнение многолчена коффициентами */
		char* endptr = string;
		i = -1;
		do {
			i++;
			pol->coef[i] = strtod(endptr, &endptr);
		} while (pol->coef[i]);
		pol->degree = i-1;
		double temp;
		for (i = 0; i <= pol->degree / 2; i++) {
			temp = pol->coef[i];
			pol->coef[i] = pol->coef[pol->degree - i];
			pol->coef[pol->degree - i] = temp;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	char* InputStringA = argv[1];
	char* InputStringB = argv[2];
	struct polynomial InputPolyA,
		InputPolyB,
		OutputPolyC;
	makePoly(&InputPolyA, InputStringA);
	makePoly(&InputPolyB, InputStringB);
	makePoly(&OutputPolyC, NULL);

	/* Вывод на экран многочленов */
	printf("\n");
	for (int i = 0; i <= InputPolyA.degree; i++) {
		printf("(%f)*x^%d ", InputPolyA.coef[i], i);

	}
	printf("\ndeg P1(x)=%d\n", InputPolyA.degree);
	printf("\n");
	for (int i = 0; i <= InputPolyB.degree; i++) {
		printf("(%f)*x^%d ", InputPolyB.coef[i], i);
	}
	printf("\ndeg P2(x)=%d\n", InputPolyB.degree);
	printf("\n");

	/*OutputPolyC = multPoly(PolyA, PolyB);*/
	return 0;
}
