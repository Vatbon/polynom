/*
**На вход командной строки даются коэффициенты многолченов a и b
** "a(n-1) a(n-2) ... a(1)" "b(n-1) b(n-2) ... b(1)"
** Вывести коэффициенты 
*/
/* http://cppstudio.com/post/812/ */

#include <stdlib.h>
#include <stdio.h>

struct polynomial {
	double coef[128];/* Коэффициенты многочлена */
	int deg;/* Степень многочлена */
};

int multPoly(struct polynomial *result, struct polynomial *pola, struct polynomial *polb) {
	result->deg = pola->deg + polb->deg;
	int i,j;
	for (i = 0; i <= pola->deg; i++)
	for (j = 0; j <= polb->deg; j++)
		result->coef[i + j] = pola->coef[i] * polb->coef[j];
	return 0;
}

int makePoly(struct polynomial *pol, char* string) {
	/* Инициализация многочлена */
	pol->deg = 0;
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
		pol->deg = i-1;
		double temp;
		for (i = 0; i <= pol->deg / 2; i++) {
			temp = pol->coef[i];
			pol->coef[i] = pol->coef[pol->deg - i];
			pol->coef[pol->deg - i] = temp;
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
	multPoly(&OutputPolyC, &InputPolyA, &InputPolyB);
	/* Вывод на экран многочленов */
	printf("\n");

	for (int i = 0; i <= InputPolyA.deg; i++) {
		printf("(%f)*x^%d ", InputPolyA.coef[i], i);

	}
	printf("\ndeg P1(x)=%d\n", InputPolyA.deg);
	printf("\n");

	for (int i = 0; i <= InputPolyB.deg; i++) {
		printf("(%f)*x^%d ", InputPolyB.coef[i], i);
	}
	printf("\ndeg P2(x)=%d\n", InputPolyB.deg);
	printf("\n");

	for (int i = 0; i <= OutputPolyC.deg; i++) {
		printf("(%f)*x^%d ", OutputPolyC.coef[i], i);

	}
	printf("\ndeg P3(x)=%d\n", OutputPolyC.deg);
	printf("\n");

	return 0;
}
