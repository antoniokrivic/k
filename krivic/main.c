#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funkcije.h"

int main() {
	double base, power, result;

	printf("Enter the base number: ");
	scanf("%lf", &base);

	printf("Enter the power raised: ");
	scanf("%lf", &power);

	result = toPow(base, power);

	printf("%.1lf^%.1lf = %.2lf", base, power, result);

	/*DRUGI DIO*/
	double a, b, c;

	printf("Enter coefficients a, b and c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	double discriminant = toQuadraticDiscriminant(a, b, c);
	toQuadratic(discriminant, a, b, c);

	return 0;
}

/*KOMENTARI
1.Varijable
// The crystal oscillator frequency of the module
#define RH_RF95_FXOSC 32000000.0

2.Funkcije
/// Initialise the Driver transport hardware and software.
/// Leaves the radio in idle mode,
/// with default configuration of: 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
/// \return true if initialisation succeeded.
virtual bool    init();
 */