/*
**На вход командной строки даются коэффициенты многолченов a и b
** "a(n-1) a(n-2) ... a(1)" "b(n-1) b(n-2) ... b(1)"
** Вывести коэффициенты 
*/
/* http://cppstudio.com/post/812/ */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct polynomial {
	double coef[128];/* Коэффициенты многочлена */
	int deg;/* Степень многочлена */
};

int multPoly(struct polynomial *result, struct polynomial *pola, struct polynomial *polb) {
	result->deg = pola->deg + polb->deg;
	int i,j;
	for (i = 0; i <= pola->deg; i++)
	for (j = 0; j <= polb->deg; j++)
		result->coef[i + j] += pola->coef[i] * polb->coef[j];
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

		/* Заполнение многолчена коэффициентами */
		char* endptr = string;
		i = -1;
		int len = strlen(string);
		do {
			i++;
			pol->coef[i] = strtod(endptr, &endptr);
		} while ((endptr - string) != len);
		pol->coef[++i] = strtod(endptr, &endptr);
		/* Конец заполнения */

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
	for (int i = OutputPolyC.deg; i >= 0; i--) {
		printf("%f ", OutputPolyC.coef[i]);

	}
	printf("\n");
	return 0;
}
