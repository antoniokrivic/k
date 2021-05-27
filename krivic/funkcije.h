#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///Funkcija exp() uzima dva argumenta (x i result), tipa double
///Vrši se očitavanje broja x sa tipkovnice                                                          

double toExp(double x, double result){
  x = 12.0, result;
  result = exp(x);
  printf("Exponential of %.2lf = %.2lf", x, result);
  return 0;
}

///Funkcija toPow() uzima dva argumenta (vrijednost baze i vrijednost eksponenta) i vraća podignutu snagu osnovnom broju
///Funkcija u koju se ubacuju vrijednosti te dobijamo određeni broj, gdje smo zadali nekakav eksponent
///Vraća rezultat unesenih vrijednosti u funkciju

double toPow(double base, double power) {
	return pow(base, power);
}



/********************************************************************************************************************************************************************/

/*KVADRATNA FUNKCIJA*/

///Funkcija koja rješava prvi korijen koji je potreban za rješavanje kvadratne funkcije
///Ubacuju se članovi a b c i diskriminanta
///Funkcija vraća rezultat u funkciju toRoot1, te je ona jedan dio za rješavanje kvadratne jednadžbe

 double toRoot1(double a, double b, double discriminant){
	 return ((-b + sqrt(discriminant)) / (2 * a));                                                  
 }

 ///Funkcija koja rješava kvadratnu diskriminantu
 ///Ubacuju se članovi a b c koji su potrebni za izračunavanje iste
 ///Funkcija vraća rezultat iz formule, zapisane u returnu, u funkciju toQuadraticDiscriminant,
 ///te je ona drugi dio za rješavanje kvadratne jednadžbe

 double toQuadraticDiscriminant(double a, double b, double c){
	 return b * b - 4 * a * c;
 }

 /* 1.OVO JE UVJET KADA JE BROJ REALAN, ALI SU KORIJENI RAZLIČITI */
 ///Funkcija koristi varijable diskriminantu, prvi korijen, drugi korijen, a i b clanove
 ///Kao rješenje if uvjeta, vraća rezultat u samu funkciju te se ona koristi kasnije u toQuadratic funkciji, kao jedan od uvjeta

 double differentRoot(double discriminant, double b, double a) {
	 double root1, root2;

	 if (discriminant > 0) {
		 root1 = toRoot1(a,b,discriminant);                                                                                            
		 root2 = (-b - sqrt(discriminant)) / (2 * a);
		 printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
	 }
	 return root1;
 }

 /* 2.OVO JE UVJET KADA SU BROJEVI REALNI, A KORIJENI ISTI */
 ///Funkcija koristi varijable diskriminantu, prvi korijen, drugi korijen, a i b clanove
 ///Kao rješenje if uvjeta u funkciji, vraća rezultat u samu funkciju te se ona koristi kasnije u toQuadratic funkciji, kao jedan od uvjeta
 ///Za rješavanje kvadratne jednadžbe

 double sameRoot(double discriminant, double b, double a) {
	 double root1, root2;

	 if (discriminant == 0) {
	 root1 = root2 = -b / (2 * a);                                               
	 printf("root1 = root2 = %.2lf;", root1);
	 }
	 return root1;                                                          
 }

 ///Funkcija koristi varijable diskriminantu, prvi korijen, drugi korijen, a i b clanove, realni i imaginarni dio
 ///Kroz ispitivanje if uvjeta, koji je zapravo opisan u funkciji sameRoot, vrši se provjera
 double nonRealRoot(double discriminant, double b, double a) {
	 double root1, root2;
	 double realPart, imagPart;

	 if (discriminant == 0) {
		 root1 = root2 = -b / (2 * a);
	 }
	 else {
		 realPart = -b / (2 * a);
		 imagPart = sqrt(-discriminant) / (2 * a);
		 printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
	 }
	 //TODO odabir vrijednosti za vrastiti (realPart, imagPart, root1)
	 return realPart;                                                      
 }
 /* OVDJE SE VRŠI RJEŠAVANJE KVADRATNE JEDNADŽBE */

///Funkcija vrši konačno izračunavanje, uz provjeru samih uvjeta
///Uvjeti su postavljeni u prošle tri funkcije pod nazivom sameRoot, differentRoot i nonRealRoot
///@params parts of quadratic functiom
///@return root1, root2, realPart, imagPart

 double toQuadratic(double discriminant, double a, double b, double c) {
	 double root1, root2, realPart, imagPart;

	 // Uvjet za realne, a različite korijene

	 if (discriminant > 0) {                                                          
		//pozivanje differentRoot funkcije
		 return differentRoot(discriminant, b,  a);
	 }

	 // Uvjet za realne i iste korijene
	 else if (discriminant == 0) {
		 //pozivanje sameRoot funkcije
		 return sameRoot( discriminant,  b,  a);
	 }
	 //Ako korijeni nisu realni
	 else {
		 //pozivanje nonRealRoot funkcije
		 return nonRealRoot(discriminant, b, a);
	 }
 }
 
 /********************************************************************************************************************************************************************/

 /*OSNOVNE OPERACIJE KALKULATORA*/

 double toBasicOperation(double prvibroj, double drugibroj) {
	 char operator;
	 printf("Unesite operator od sljedećih (+, -, *, /): ");
	 scanf("%c", &operator);
	 printf("Unesite dva broja za računanje: ");
	 scanf("%lf %lf", &prvibroj, &drugibroj);

	 switch (operator)
	 {
	 case '+':
		 printf("%.1lf + %.1lf = %.1lf", prvibroj, drugibroj, prvibroj + drugibroj);
		 break;

	 case '-':
		 printf("%.1lf - %.1lf = %.1lf", prvibroj, drugibroj, prvibroj - drugibroj);
		 break;

	 case '*':
		 printf("%.1lf * %.1lf = %.1lf", prvibroj, drugibroj, prvibroj * drugibroj);
		 break;

	 case '/':
		 printf("%.1lf / %.1lf = %.1lf", prvibroj, drugibroj, prvibroj / drugibroj);
		 break;

		/*Ovu liniju koda će program ispisati ukoliko se ne upiše nešto od ponuđenog (+, -, *, /)*/
	 default:
		 printf("Greška! Niste unijeli dobar operator. Probajte ponovno sa (+, -, *, /)");
	 }
	 return 0;
 }
 

 /*KREIRANJE UVODNOG IZBORNIKA*/

 double izbornik() {
	 char izbor;
	 do {
		 printf("+-----------------------------------------------------------------------------+\n");
		 printf("+----------------------------Dobrodošli u kalkulator!-------------------------+\n");
		 printf("+-----------------------------------------------------------------------------+\n");
		 printf("|1.Osnovne operacije (+, -, *, /)  |2.Složenije operacije  |3.Otvori povijest rezultata  \n|4.Izlaz");
		 printf("Unesite izbor: ");
		 fflush(stdin);
		 //brisanje "enter" tipke
		 izbor = getchar();
		 while (izbor == '\n') {
			 izbor = getchar();
		 }
		
		 switch (izbor) {
		 case '1':
			 printf("Izabrali ste osnove operacije.\n");
			 break;
		 case '2':
			 printf("Izabrali ste složenije operacije.\n");
			 break;
		 case '3':
			 printf("Izabrali ste otvaranje povijesti rezultata. Molim pričekajte da se otvore.");
		 default:
			 printf("Zatvaranje programa, doviđenja!");
			 break;
		 }
		 printf("Želite li nastaviti?\n");
		 printf("Da, želim. (pritisnite 'Y' ili 'y')\n");
		 printf("Ne, ne želim. (pritisnite 'N' ili 'n')\n");
		 printf("Očistiti 'screen' (pritisnite 'c' ili 'C')\n");
		 printf("Vaš izbor: ");
	     fflush(stdin);
		 //brisanje "enter" tipke
		 izbor getchar();
		 while (izbor == '\n') {
			 izbor = getchar();
		 }
		 if (izbor == 'c' || izbor == 'C') {
			 system("cls");                                  //system("clear
		 }
	 } while (izbor != 'n' && izbor != 'N');
 }