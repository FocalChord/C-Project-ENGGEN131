/* ENGGEN131, Semester Two, 2017 */
/* The header file for Project Two */
/* Prepared by Paul Denny, October 2017 */

#include "project.h"
#include <time.h>

/* YOU WILL NOT BE SUBMITTING THIS FILE FOR MARKING */
/* You are encouraged to add additional tests to the testing functions */
/* defined in this program.  There are ten test functions, one for each */
/* of the functions you are required to define for this project */
void Test_DivisorOfThree(void);
void Test_AverageSheep(void);
void Test_Emphasise(void);
void Test_PrimeFactors(void);
void Test_ConnectTwo(void);
void Test_DayTrader(void);
void Test_Compress(void);
void Test_AddOne(void);
void Test_Histogram(void);
void Test_GoldRush(void);
void Test_GoldRush2(void);
void Test_GoldRush3(void);
int flag = 1;

/* You do not need to modify the main() function - it simply calls each of */
/* the test functions */
int main(void)
{
	// Print welcome message
	printf("\n  ______ _   _  _____  _____ ______ _   _ __ ____  __ \n");
	printf(" |  ____| \\ | |/ ____|/ ____|  ____| \\ | /_ |___ \\/_ |\n");
	printf(" | |__  |  \\| | |  __| |  __| |__  |  \\| || | __) || |\n");
	printf(" |  __| | . ` | | |_ | | |_ |  __| | . ` || ||__ < | |\n");
	printf(" | |____| |\\  | |__| | |__| | |____| |\\  || |___) || |\n");
	printf(" |______|_| \\_|\\_____|\\_____|______|_| \\_||_|____/ |_|\n\n");
	
	printf("\nWelcome to the baddass as fuck test program for Project Two.\n\n");
	printf("This  test  program  provides  a never seen before set of  test  cases.\n");
	printf("fire this shit up and test the functions you  have  defined.\n");
	printf("The original tests were left in and will report a pass. However\n");
	printf("my additional tests will only print something if a test is failed.\n");
	printf("Due to the nature of ConnectTwo, compare your maps with the output\n");
	printf("shown in the comments below.\n\n");
	printf("God speed my engineering brethren.\n");


	// [not so] Minimal testing of each function
	Test_DivisorOfThree();
	Test_AverageSheep();
	Test_Emphasise();
	Test_PrimeFactors();
	Test_ConnectTwo();
	Test_DayTrader();
	Test_Compress();
	Test_AddOne();
	Test_Histogram();
	Test_GoldRush();
	if (flag) {
		Test_GoldRush2();
		Test_GoldRush3();
	}
	printf("\n");
	return 0;
}

/* A function to test Task One */
void Test_DivisorOfThree(void)
{
	if (DivisorOfThree(1, 1, 2) == 99999) {
		printf("\nTask One:   DivisorOfThree() - not yet implemented");
	} else {
		printf("\nTask One:   DivisorOfThree() - ");
		if (DivisorOfThree(1288, 759, 1173) != 23) {
			printf("FAIL (1288, 759, 1173) ");
		} else {
			printf("PASS ");
		}
		if (DivisorOfThree(760, 1960, 2720) != 40) {
			printf("FAIL (760, 1960, 2720) ");
		} else {
			printf("PASS ");
		}
		if (DivisorOfThree(100, 0, 1000000) != -1) {
			printf("FAIL (100, 0, 1000000) ");
		} else {
			printf("PASS ");
		}
		// Bonus test cases
		if (DivisorOfThree(5, 5, 5) != 5) printf("FAIL (5, 5, 5) ");
		if (DivisorOfThree(8, 8, 8) != 8) printf("FAIL (8, 8, 8) ");
		if (DivisorOfThree(-4, 12, 100) != -1) printf("FAIL (-4, 12, 100) ");
		if (DivisorOfThree(4, -12, 100) != -1) printf("FAIL (4, -12, 100) ");
		if (DivisorOfThree(4, 12, -100) != -1) printf("FAIL (4, 12, -100) ");
		if (DivisorOfThree(0, 12, 100) != -1) printf("FAIL (0, 12, 100) ");
		if (DivisorOfThree(4, 0, 100) != -1) printf("FAIL (4, 0, 100) ");
		if (DivisorOfThree(4, 12, 0) != -1) printf("FAIL (4, 12, 0) ");
		if (DivisorOfThree(3, 5, 7) != 1) printf("FAIL (3, 5, 7) ");
		if (DivisorOfThree(5, 7, 13) != 1) printf("FAIL (5, 7, 13) ");
	}
}

/* A function to test Task Two */
void Test_AverageSheep(void)
{
	int sheep1[MAX_ARRAY_SIZE] = {0, 12, 18, 19, 9999};
	int sheep2[MAX_ARRAY_SIZE] = {-1, 25, 12, 18, -1, 9999};
	int sheep3[MAX_ARRAY_SIZE] = {-1, 22, 9999, -1, 25, 12};
	int sheep4[MAX_ARRAY_SIZE] = {-1, -1, 9999, -1, 25, 12};
	// For bonus test cases
	int sheep5[MAX_ARRAY_SIZE] = {-1,-1,-1,9999};
	int sheep6[MAX_ARRAY_SIZE] = {9999, 100, 100, 100};
	int sheep7[MAX_ARRAY_SIZE] = {0,0,0,9999, 100, 100, 100};
	int sheep8[MAX_ARRAY_SIZE] = {1,2,3,9999};
	int sheep9[MAX_ARRAY_SIZE] = { 9999, -1, 25, 12 };


	if (AverageSheep(sheep1) == 99999.9) {
		printf("\nTask Two:   AverageSheep()   - not yet implemented");
	} else {
		printf("\nTask Two:   AverageSheep()   - ");
		if ((AverageSheep(sheep2) < 18.333332) || (AverageSheep(sheep2) > 18.333334)) {
			printf("FAIL (sheep2) ");
		} else {
			printf("PASS ");
		}
		if ((AverageSheep(sheep3) < 21.999999) || (AverageSheep(sheep3) > 22.000001)) {
			printf("FAIL (sheep3) ");
		} else {
			printf("PASS ");
		}
		if ((AverageSheep(sheep4) < -0.000001) || (AverageSheep(sheep4) > 0.000001)) {
			printf("FAIL (sheep4) ");
		} else {
			printf("PASS ");
		}
		// Bonus test cases
		if ((AverageSheep(sheep5) < -0.000001) || (AverageSheep(sheep5) > 0.000001)) {
			printf("FAIL (sheep5) ");
		}
		if ((AverageSheep(sheep6) < -0.000001) || (AverageSheep(sheep6) > 0.000001)) {
			printf("FAIL (sheep6) ");
		}
		if ((AverageSheep(sheep7) < -0.000001) || (AverageSheep(sheep7) > 0.000001)) {
			printf("FAIL (sheep7) ");
		}
		if ((AverageSheep(sheep8) < 1.999999) || (AverageSheep(sheep8) > 2.000001)) {
			printf("FAIL (sheep8) ");
		}
		if (!(AverageSheep(sheep9) < 1 || AverageSheep(sheep9) >= 1)) printf("!! You divide by zero");
	}
}

/* A function to test Task Three */
void Test_Emphasise(void)
{
	char words0[MAX_ARRAY_SIZE] = "n_o_t implemented";
	char wordsA[MAX_ARRAY_SIZE] = "this is a _good_ question!";
	char wordsB[MAX_ARRAY_SIZE] = "It is _over 9000_!";
	char wordsC[MAX_ARRAY_SIZE] = "_Nothing to see here_";
	// For bonus test cases
	char wordsD[MAX_ARRAY_SIZE] = "te__st";
	char wordsE[MAX_ARRAY_SIZE] = "_!_";
	char wordsF[MAX_ARRAY_SIZE] = "__";
	char wordsG[MAX_ARRAY_SIZE] = "_a_";
	char wordsH[MAX_ARRAY_SIZE] = "a__";
	char wordsI[MAX_ARRAY_SIZE] = "a_a_";
	char wordsJ[MAX_ARRAY_SIZE] = "__a";
	char wordsK[MAX_ARRAY_SIZE] = "_a_a";

	Emphasise(words0);
	if (words0[0] == '~') {
		printf("\nTask Three: Emphasise()      - not yet implemented");
	} else {
		printf("\nTask Three: Emphasise()      - ");
		Emphasise(wordsA);
		if (strcmp(wordsA, "this is a GOOD question!")) {
			printf("FAIL (wordsA) ");
		} else {
			printf("PASS ");
		}
		Emphasise(wordsB);
		if (strcmp(wordsB, "It is OVER 9000!")) {
			printf("FAIL (wordsB) ");
		} else {
			printf("PASS ");
		}
		Emphasise(wordsC);
		if (strcmp(wordsC, "NOTHING TO SEE HERE")) {
			printf("FAIL (wordsC) ");
		} else {
			printf("PASS ");
		}
		// For bonus test cases
		Emphasise(wordsD);
		Emphasise(wordsE);
		Emphasise(wordsF);
		Emphasise(wordsG);
		Emphasise(wordsH);
		Emphasise(wordsI);
		Emphasise(wordsJ);
		Emphasise(wordsK);
		if (strcmp(wordsD, "test")) printf("\nFAIL (wordsD) ");
		if (strcmp(wordsE, "!")) printf("\nFAIL (wordsE) ");
		if (strcmp(wordsF, "")) printf("\nFAIL (wordsF) ");
		if (strcmp(wordsG, "A")) printf("\nFAIL (wordsH) ");
		if (strcmp(wordsH, "a")) printf("\nFAIL (wordsH) ");
		if (strcmp(wordsI, "aA")) printf("\nFAIL (wordsI) ");
		if (strcmp(wordsJ, "a")) printf("\nFAIL (wordsJ) ");
		if (strcmp(wordsK, "Aa")) printf("\nFAIL (wordsK) ");
	}
}

/* A function to test Task Four */
void Test_PrimeFactors(void)
{
	int numFactors;
	int factors[MAX_ARRAY_SIZE];

	numFactors = PrimeFactors(2, factors);
	if (numFactors == 99999) {
		printf("\nTask Four:  PrimeFactors()   - not yet implemented");
	} else {
		printf("\nTask Four:  PrimeFactors()   - ");
		numFactors = PrimeFactors(567, factors);
		if (numFactors != 5 || (factors[0] * factors[1] * factors[2] * factors[3] * factors[4] != 567)) {
			printf("FAIL (567) ");
		} else {
			printf("PASS ");
		}
		numFactors = PrimeFactors(5678901, factors);
		if (numFactors != 4 || (factors[0] * factors[1] * factors[2] * factors[3] != 5678901)) {
			printf("FAIL (5678901) ");
		} else {
			printf("PASS ");
		}
		numFactors = PrimeFactors(13, factors);
		if (numFactors != 1 || (factors[0] != 13)) {
			printf("FAIL (13) ");
		} else {
			printf("PASS");
		}
		// For bonus tests
		numFactors = PrimeFactors(2, factors);
		if (numFactors != 1 || (factors[0] != 2)) printf("FAIL (2) ");
		numFactors = PrimeFactors(3, factors);
		if (numFactors != 1 || (factors[0] != 3)) printf("FAIL (3) ");
		numFactors = PrimeFactors(4, factors);
		if (numFactors != 2 || (factors[0] * factors[1] != 4)) printf("FAIL (4) ");
		numFactors = PrimeFactors(13, factors);
		if (numFactors != 1 || (factors[0] != 13)) printf("FAIL (13) ");
		printf("\nThe next test might take a while (about 7 seconds for me).\nSo dont assume its in an infinite loop if nothings happening. ");
		numFactors = PrimeFactors(2147483647, factors);
		if (numFactors != 1 || (factors[0] != 2147483647)) printf("FAIL (2147483647) ");
		numFactors = PrimeFactors(2147483646, factors);
		if (numFactors != 8 || (factors[0] * factors[1] * factors[2] * factors[3] * factors[4] * factors[5] * factors[6] * factors[7] != 2147483646)) printf("FAIL (2147483646) ");
		if (!(factors[7] >= factors[6]) && (factors[6] >= factors[5]) && (factors[5] >= factors[4]) && (factors[4] >= factors[3]) && (factors[3] >= factors[2]) && (factors[2] >= factors[1]) && (factors[1] >= factors[0])) printf("FAIL (Factors not in increasing order) ");
	}
}

/* A function to test Task Five */
void Test_ConnectTwo(void)
{
	int map0[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 2, 0, 0, 0, 0, 0, 0}};
	int map1[10][10] = {{1, 0, 2, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int map2[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{2, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int map3[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 2, 0, 0}};
	// For bonus tests
	int map4[10][10] = { { 1, 2, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map5[10][10] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map6[10][10] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 2 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map7[10][10] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map8[10][10] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } };
	int map9[10][10] = { { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
	int map10[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
	int map11[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
	int map12[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 1 } };
	int map13[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
	int map14[10][10] = { { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } };
	int map15[10][10] = { { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map16[10][10] = { { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 } };
	int map17[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 } };
	int map18[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map19[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } };
	int map20[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int map21[10][10] = { { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	ConnectTwo(map0);
	if (map0[0][0] == 99999) {
		printf("\nTask Five:  ConnectTwo()     - not yet implemented");
	} else {
		printf("\nTask Five:  ConnectTwo()     - ");
		ConnectTwo(map1);
		if (map1[0][1] != 3) {
			printf("FAIL (map1) ");
		} else {
			printf("PASS ");
		}
		ConnectTwo(map2);
		if ((map2[1][0] != 3) || (map2[2][0] != 3)) {
			printf("FAIL (map2) ");
		} else {
			printf("PASS ");
		}
		ConnectTwo(map3);
		if ((map3[1][1] != 3) || (map3[2][2] != 3) || (map3[3][3] != 3) || (map3[4][4] != 3) || (map3[5][5] != 3) || (map3[6][6] != 3) || (map3[7][7] != 3) || (map3[8][7] != 3)) {
			printf("FAIL (map3) ");
		} else {
			printf("PASS ");
		}
		// Bonus Tests (manually check, better way?)
		printf("\nMap4\n");
		ConnectTwo(map4);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map4[i][j]);
			}
			printf("\n");
		}
		printf("\nMap5\n");
		ConnectTwo(map5);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map5[i][j]);
			}
			printf("\n");
		}
		printf("\nMap6\n");
		ConnectTwo(map6);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map6[i][j]);
			}
			printf("\n");
		}
		printf("\nMap7\n");
		ConnectTwo(map7);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map7[i][j]);
			}
			printf("\n");
		}
		printf("\nMap8\n");
		ConnectTwo(map8);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map8[i][j]);
			}
			printf("\n");
		}
		printf("\nMap9\n");
		ConnectTwo(map9);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map9[i][j]);
			}
			printf("\n");
		}
		printf("\nMap10\n");
		ConnectTwo(map10);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map10[i][j]);
			}
			printf("\n");
		}
		printf("\nMap11\n");
		ConnectTwo(map11);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map11[i][j]);
			}
			printf("\n");
		}
		printf("\nMap12\n");
		ConnectTwo(map12);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map12[i][j]);
			}
			printf("\n");
		}
		printf("\nMap13\n");
		ConnectTwo(map13);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map13[i][j]);
			}
			printf("\n");
		}
		printf("\nMap14\n");
		ConnectTwo(map14);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map14[i][j]);
			}
			printf("\n");
		}
		printf("\nMap15\n");
		ConnectTwo(map15);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map15[i][j]);
			}
			printf("\n");
		}
		printf("\nMap16\n");
		ConnectTwo(map16);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map16[i][j]);
			}
			printf("\n");
		}
		printf("\nMap17\n");
		ConnectTwo(map17);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map17[i][j]);
			}
			printf("\n");
		}
		printf("\nMap18\n");
		ConnectTwo(map18);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map18[i][j]);
			}
			printf("\n");
		}
		printf("\nMap19\n");
		ConnectTwo(map19);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map19[i][j]);
			}
			printf("\n");
		}
		printf("\nMap20\n");
		ConnectTwo(map20);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map20[i][j]);
			}
			printf("\n");
		}
		printf("\nMap21\n");
		ConnectTwo(map21);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", map21[i][j]);
			}
			printf("\n");
		}

	}
}

/* A function to test Task Six */
void Test_DayTrader(void)
{
	int prices0[5] = {0, 2, 3, 4, 5};
	int pricesA[15] = {59, 60, 55, 23, 42, 44, 48, 50, 43, 45, 43, 44, 47, 51, 52};
	int pricesB[10] = {1, 2, 3, 3, 3, 4, 3, 4, 5, 6};
	int pricesC[10] = {123, 120, 118, 119, 121, 126, 127, 130, 129, 132};
	int bestRun, bestRunIndex;
	// For bonus tests
	int pricesD[5] = { 5, 4, 3, 2, 1 };
	int pricesE[5] = { 0, 0, 0, 0, 0 };
	int pricesF[5] = { 1, 1, 1, 1, 1 };
	int pricesG[5] = { 1, 2, 1, 1, 2 };
	int pricesH[9] = { 1, 1, 3, 1, 1, 2, 1, 1, 2 };
	int pricesI[5] = { 1, 2, 3, 4, 5 };
	int pricesJ[1] = { 1 };
	int pricesK[2] = { 1, 2 };
	int pricesL[2] = { 2, 1 };
	int pricesM[2] = { 1, 1 };

	DayTrader(prices0, 5, &bestRun, &bestRunIndex);
	if (bestRun == 99999) {
		printf("\nTask Six:   DayTrader()      - not yet implemented");
	} else {
		printf("\nTask Six:   DayTrader()      - ");
		DayTrader(pricesA, 15, &bestRun, &bestRunIndex);
		if (bestRun != 4 || bestRunIndex != 3) {
			printf("FAIL (pricesA) ");
		} else {
			printf("PASS ");
		}
		DayTrader(pricesB, 10, &bestRun, &bestRunIndex);
		if (bestRun != 3 || bestRunIndex != 6) {
			printf("FAIL (pricesB) ");
		} else {
			printf("PASS ");
		}
		DayTrader(pricesC, 10, &bestRun, &bestRunIndex);
		if (bestRun != 5 || bestRunIndex != 2) {
			printf("FAIL (pricesC) ");
		} else {
			printf("PASS ");
		}
		// Bonus tests
		DayTrader(pricesD, 5, &bestRun, &bestRunIndex);
		if (bestRun != 0 || bestRunIndex != 0) printf("FAIL (pricesD) ");
		DayTrader(pricesE, 5, &bestRun, &bestRunIndex);
		if (bestRun != 0 || bestRunIndex != 0) printf("FAIL (pricesE) ");
		DayTrader(pricesF, 5, &bestRun, &bestRunIndex);
		if (bestRun != 0 || bestRunIndex != 0) printf("FAIL (pricesF) ");
		DayTrader(pricesG, 5, &bestRun, &bestRunIndex);
		if (bestRun != 1 || bestRunIndex != 0) printf("FAIL (pricesG) ");
		DayTrader(pricesH, 9, &bestRun, &bestRunIndex);
		if (bestRun != 1 || bestRunIndex != 1) printf("FAIL (pricesH) ");
		DayTrader(pricesI, 5, &bestRun, &bestRunIndex);
		if (bestRun != 4 || bestRunIndex != 0) printf("FAIL (pricesI) ");
		DayTrader(pricesJ, 1, &bestRun, &bestRunIndex);
		if (bestRun != 0 || bestRunIndex != 0) printf("FAIL (pricesJ) ");
		DayTrader(pricesK, 2, &bestRun, &bestRunIndex);
		if (bestRun != 1 || bestRunIndex != 0) printf("FAIL (pricesK) ");
		DayTrader(pricesL, 2, &bestRun, &bestRunIndex);
		if (bestRun != 0 || bestRunIndex != 0) printf("FAIL (pricesL) ");
		DayTrader(pricesM, 2, &bestRun, &bestRunIndex);
		if (bestRun != 0 || bestRunIndex != 0) printf("FAIL (pricesM) ");
	}
}

/* A function to test Task Seven */
void Test_Compress(void)
{
	int inputA[MAX_ARRAY_SIZE] = {0,1,2,2,-1};
	int inputB[MAX_ARRAY_SIZE] = {1,1,2,2,-1};
	int inputC[MAX_ARRAY_SIZE] = {7,7,7,7,7,7,7,7,7,7,-1};
	int inputD[MAX_ARRAY_SIZE] = {4,7,7,7,-1};
	int output[MAX_ARRAY_SIZE];
	// For bonus tests
	int inputE[MAX_ARRAY_SIZE] = { 1, -1 };
	int inputF[MAX_ARRAY_SIZE] = { 1, 2, 3, 4, -1 };
	int inputG[MAX_ARRAY_SIZE] = { 1, 2, 1, 2, -1 };
	int inputH[MAX_ARRAY_SIZE] = { 1, 2, 2, 3, 3, 3, -1 };
	int inputI[MAX_ARRAY_SIZE] = { 7,7,7,7,7,3,4,4,4,7,0,0,0,0,0,0,0,0,0,0,0,0,-1 };

	Compress(inputA, output);
	if (output[0] == 99999) {
		printf("\nTask Seven: Compress()       - not yet implemented");
	} else {
		printf("\nTask Seven: Compress()       - ");
		Compress(inputB, output);
		if (output[0] != 2 || output[1] != 1 || output[2] != 2 || output[3] != 2 || output[4] != -1) {
			printf("FAIL (inputB) ");
		} else {
			printf("PASS ");
		}
		Compress(inputC, output);
		if (output[0] != 10 || output[1] != 7 || output[2] != -1) {
			printf("FAIL (inputC) ");
		} else {
			printf("PASS ");
		}
		Compress(inputD, output);
		if (output[0] != 1 || output[1] != 4 || output[2] != 3 || output[3] != 7 || output[4] != -1) {
			printf("FAIL (inputD) ");
		} else {
			printf("PASS ");
		}
		// Bonus tests
		Compress(inputE, output);
		if (output[0] != 1 || output[1] != 1 || output[2] != -1) printf("FAIL (inputE) ");
		Compress(inputF, output);
		if (output[0] != 1 || output[1] != 1 || output[2] != 1 || output[3] != 2 || output[4] != 1 || output[5] != 3 || output[6] != 1 || output[7] != 4 || output[8] != -1) printf("FAIL (inputF) ");
		Compress(inputG, output);
		if (output[0] != 1 || output[1] != 1 || output[2] != 1 || output[3] != 2 || output[4] != 1 || output[5] != 1 || output[6] != 1 || output[7] != 2 || output[8] != -1) printf("FAIL (inputG) ");
		Compress(inputH, output);
		if (output[0] != 1 || output[1] != 1 || output[2] != 2 || output[3] != 2 || output[4] != 3 || output[5] != 3 || output[8] != -1) printf("FAIL (inputH) ");
		Compress(inputI, output);
		if (output[0] != 5 || output[1] != 7 || output[2] != 1 || output[3] != 3 || output[4] != 3 || output[5] != 4 || output[6] != 1 || output[7] != 7 || output[8] != 12 || output[9] != 0 || output[10] != -1) printf("FAIL (inputI) ");
	}
}

/* A function to test Task Eight */
void Test_AddOne(void)
{
	char words0[MAX_ARRAY_SIZE] = "123";
	char wordsA[MAX_ARRAY_SIZE] = "99999";
	char wordsB[MAX_ARRAY_SIZE] = "12399999999";
	char wordsC[MAX_ARRAY_SIZE] = "9";
	char output[MAX_ARRAY_SIZE];
	// for bonus tests
	char wordsD[MAX_ARRAY_SIZE] = "1";
	char wordsE[MAX_ARRAY_SIZE] = "12";
	char wordsF[MAX_ARRAY_SIZE] = "123";
	char wordsG[MAX_ARRAY_SIZE] = "10";
	char wordsH[MAX_ARRAY_SIZE] = "190";
	char wordsI[MAX_ARRAY_SIZE] = "9998";
	char wordsJ[MAX_ARRAY_SIZE] = "09";
	char wordsK[MAX_ARRAY_SIZE] = "009";

	AddOne(words0, output);
	if (output[0] == '~') {
		printf("\nTask Eight: AddOne()         - not yet implemented");
	} else {
		printf("\nTask Eight: AddOne()         - ");
		AddOne(wordsA, output);
		if (strcmp(output, "100000")) {
			printf("FAIL (wordsA) ");
		} else {
			printf("PASS ");
		}
		AddOne(wordsB, output);
		if (strcmp(output, "12400000000")) {
			printf("FAIL (wordsB) ");
		} else {
			printf("PASS ");
		}
		AddOne(wordsC, output);
		if (strcmp(output, "10")) {
			printf("FAIL (wordsC) ");
		} else {
			printf("PASS ");
		}
		// Bonus tests
		AddOne(wordsD, output);
		if (strcmp(output, "2")) printf("FAIL (wordsD) ");
		AddOne(wordsE, output);
		if (strcmp(output, "13")) printf("FAIL (wordsE) ");
		AddOne(wordsF, output);
		if (strcmp(output, "124")) printf("FAIL (wordsF) ");
		AddOne(wordsG, output);
		if (strcmp(output, "11")) printf("FAIL (wordsG) ");
		AddOne(wordsH, output);
		if (strcmp(output, "191")) printf("FAIL (wordsH) ");
		AddOne(wordsI, output);
		if (strcmp(output, "9999")) printf("FAIL (wordsI) ");
		AddOne(wordsJ, output);
		if (strcmp(output, "10")) printf("FAIL (wordsJ) ");
		AddOne(wordsK, output);
		if (strcmp(output, "010")) printf("FAIL (wordsK) ");
		printf("%s", output);
	}
}

/* A function to test Task Nine */
void Test_Histogram(void)
{
	int values0[3] = {0, 0, 1};
	int values1[10] = {1, 0, 3, 1, 2, 4, 5, 6, 2, 2};
	int values2[3] = {1, 0, 1};
	int values3[3] = {0, 1, 0};
	char formatted[MAX_ARRAY_SIZE];

	// For bonus tests
	int values4[1] = { 1 };
	int values5[2] = { 1, 1 };
	int values6[3] = { 1, 1, 1 };
	int values7[1] = { 5 };


	Histogram(formatted, values0, 0);
	if (formatted[0] == '~') {
		printf("\nTask Nine:  Histogram()      - not yet implemented");
	} else {
		printf("\nTask Nine:  Histogram()      - ");
		Histogram(formatted, values1, 10);
		if (strcmp(formatted, "************\n*       X  *\n*      XX  *\n*     XXX  *\n*  X  XXX  *\n*  X XXXXXX*\n*X XXXXXXXX*\n************")) {
			printf("FAIL (values1) ");
		} else {
			printf("PASS ");
		}
		Histogram(formatted, values2, 3);
		if (strcmp(formatted, "*****\n*X X*\n*****")) {
			printf("FAIL (values2) ");
		} else {
			printf("PASS ");
		}
		Histogram(formatted, values3, 3);
		if (strcmp(formatted, "*****\n* X *\n*****")) {
			printf("FAIL (values3) ");
		} else {
			printf("PASS ");
		}
		// Bonus tests
		Histogram(formatted, values4, 1);
		if (strcmp(formatted, "***\n*X*\n***")) printf("FAIL (values4) ");
		Histogram(formatted, values5, 2);
		if (strcmp(formatted, "****\n*XX*\n****")) printf("FAIL (values5) ");
		Histogram(formatted, values6, 3);
		if (strcmp(formatted, "*****\n*XXX*\n*****")) printf("FAIL (values6) ");
		Histogram(formatted, values7, 1);
		if (strcmp(formatted, "***\n*X*\n*X*\n*X*\n*X*\n*X*\n***")) printf("FAIL (values7) ");
	}
}

/* A function to test Task Ten */
void Test_GoldRush(void)
{
	int results[MAX_ARRAY_SIZE];
	int map0[MAX_MAP_SIZE][MAX_MAP_SIZE] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	int map1[MAX_MAP_SIZE][MAX_MAP_SIZE] = {
			{1,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,4,3,0,0,0,0,9,9,8,0,0,0,0,0},
			{0,2,0,3,3,0,0,9,9,0,0,0,0,0,0},
			{0,0,0,0,0,4,6,9,9,6,0,0,0,0,0},
			{0,0,0,0,0,0,9,0,8,0,0,6,0,0,0},
			{0,0,9,9,9,9,0,0,0,0,7,7,8,8,0},
			{0,0,9,9,9,9,0,0,0,0,0,7,0,0,0},
			{0,0,9,9,9,9,0,1,1,1,2,2,2,2,2},
			{0,0,0,9,9,0,0,0,0,0,0,0,0,3,0},
			{0,0,0,4,4,0,0,0,0,0,0,0,5,6,0},
			{0,0,0,0,9,9,9,0,0,9,0,0,0,5,0},
			{0,0,1,2,9,9,9,0,0,0,9,0,0,4,2},
			{0,0,0,0,9,9,9,0,0,0,9,9,9,0,0},
			{9,9,0,0,0,0,1,0,0,0,0,9,0,0,0},
			{9,0,0,0,0,0,2,2,0,0,0,0,0,0,0}
		};
	int map2[MAX_MAP_SIZE][MAX_MAP_SIZE] = { {9, 9, 9}, {9, 9, 9}, {9, 9, 9} };
	int map3[MAX_MAP_SIZE][MAX_MAP_SIZE] = { {9, 9, 9}, {9, 9, 9}, {9, 9, 8} };

	GoldRush(results, 3, 3, map0, 0);
	if (results[0] == 99999) {
		printf("\nTask Ten:   GoldRush()       - not yet implemented");
		flag = 0;
	} else {
		printf("\nTask Ten:   GoldRush()       - ");
		GoldRush(results, 15, 15, map1, 0);
		if (results[0] != 39 || results[1] != 3) {
			printf("FAIL (map1) ");
		} else {
			printf("PASS ");
		}
		GoldRush(results, 3, 3, map2, 0);
		if (results[0] != 9 || results[1] != 1) {
			printf("FAIL (map2) ");
		} else {
			printf("PASS ");
		}
		GoldRush(results, 3, 3, map3, 0);
		if (results[0] != 8 || results[1] != 0) {
			printf("FAIL (map3) ");
		} else {
			printf("PASS ");
		}

		// Bonus tests
		GoldRush(results, 2, 2, map0, 0);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map0) ");
		GoldRush(results, 2, 2, map0, 1);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map0-bonus1) ");
		GoldRush(results, 2, 2, map0, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map0-bonus2) ");

		GoldRush(results, 15,15, map1, 1);
		if (results[0] != 21 || results[1] != 9 || results[2] != 6 || results[3] != 3 || results[4] != 0) printf("FAIL (map1-bonus1) ");
		GoldRush(results, 15, 15, map1, 2);
		if (results[0] != 2 || results[1] != 1 || results[2] != 0) printf("FAIL (map1-bonus2) ");

		GoldRush(results, 3, 3, map2, 1);
		if (results[0] != 9 || results[1] != 0) printf("FAIL (map2-bonus1) ");
		GoldRush(results, 3, 3, map2, 2);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map2-bonus2) ");

		GoldRush(results, 3, 3, map3, 1);
		if (results[0] != 8 || results[1] != 0) printf("FAIL (map3-bonus1) ");
		GoldRush(results, 3, 3, map3, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map3-bonus2) ");

		int map4[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 9 },{ 9, 9 } };
		GoldRush(results, 2, 2, map4, 0);
		if (results[0] != 4 || results[1] != 0) printf("FAIL (map4) ");
		GoldRush(results, 2, 2, map4, 1);
		if (results[0] != 4 || results[1] != 0) printf("FAIL (map4-bonus1) ");
		GoldRush(results, 2, 2, map4, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map4-bonus2) ");

		int map5[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
		GoldRush(results, 3, 3, map5, 0);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map5) ");
		GoldRush(results, 3, 3, map5, 1);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map5-bonus1) ");
		GoldRush(results, 3, 3, map5, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map5-bonus2) ");

		int map6[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 9, 0, 0 },{ 0, 0, 0 } };
		GoldRush(results, 3, 3, map6, 0);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map6) ");
		GoldRush(results, 3, 3, map6, 1);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map6-bonus1) ");
		GoldRush(results, 3, 3, map6, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map6-bonus2) ");

		int map7[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 0, 0 },{ 9, 0, 0 } };
		GoldRush(results, 3, 3, map7, 0);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map7) ");
		GoldRush(results, 3, 3, map7, 1);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map7-bonus1) ");
		GoldRush(results, 3, 3, map7, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map7-bonus2) ");

		int map8[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 9, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
		GoldRush(results, 3, 3, map8, 0);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map8) ");
		GoldRush(results, 3, 3, map8, 1);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map8-bonus1) ");
		GoldRush(results, 3, 3, map8, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map8-bonus2) ");

		int map9[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 9, 0 },{ 0, 0, 0 } };
		GoldRush(results, 3, 3, map9, 0);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map9) ");
		GoldRush(results, 3, 3, map9, 1);
		if (results[0] != 1 || results[1] != 0) printf("FAIL (map9-bonus1) ");
		GoldRush(results, 3, 3, map9, 2);
		if (results[0] != 0 || results[1] != 0) printf("FAIL (map9-bonus2) ");
	}
}

void Test_GoldRush2(void)
{
	int results[MAX_ARRAY_SIZE];
	int map10[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 9, 0 } };
	GoldRush(results, 3, 3, map10, 0);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map10) ");
	GoldRush(results, 3, 3, map10, 1);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map10-bonus1) ");
	GoldRush(results, 3, 3, map10, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map10-bonus2) ");

	int map11[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 9 },{ 0, 0, 0 },{ 0, 0, 0 } };
	GoldRush(results, 3, 3, map11, 0);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map11) ");
	GoldRush(results, 3, 3, map11, 1);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map11-bonus1) ");
	GoldRush(results, 3, 3, map11, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map11-bonus2) ");

	int map12[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 0, 9 },{ 0, 0, 0 } };
	GoldRush(results, 3, 3, map12, 0);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map12) ");
	GoldRush(results, 3, 3, map12, 1);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map12-bonus1) ");
	GoldRush(results, 3, 3, map12, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map12-bonus2) ");

	int map13[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 9 } };
	GoldRush(results, 3, 3, map13, 0);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map13) ");
	GoldRush(results, 3, 3, map13, 1);
	if (results[0] != 1 || results[1] != 0) printf("FAIL (map13-bonus1) ");
	GoldRush(results, 3, 3, map13, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map13-bonus2) ");

	int map14[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 0, 0 },{ 9, 0, 0 },{ 0, 0, 0 } };
	GoldRush(results, 3, 3, map14, 0);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map14) ");
	GoldRush(results, 3, 3, map14, 1);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map14-bonus1) ");
	GoldRush(results, 3, 3, map14, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map14-bonus2) ");

	int map15[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 9, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	GoldRush(results, 3, 3, map15, 0);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map15) ");
	GoldRush(results, 3, 3, map15, 1);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map15-bonus1) ");
	GoldRush(results, 3, 3, map15, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map15-bonus2) ");

	int map16[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 0, 9 },{ 0, 0, 9 } };
	GoldRush(results, 3, 3, map16, 0);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map16) ");
	GoldRush(results, 3, 3, map16, 1);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map16-bonus1) ");
	GoldRush(results, 3, 3, map16, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map16-bonus2) ");

	int map17[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 9, 9 } };
	GoldRush(results, 3, 3, map17, 0);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map17) ");
	GoldRush(results, 3, 3, map17, 1);
	if (results[0] != 2 || results[1] != 0) printf("FAIL (map17-bonus1) ");
	GoldRush(results, 3, 3, map17, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map17-bonus2) ");

	int map18[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 9, 9 },{ 9, 0, 9 },{ 9, 9, 9 } };
	GoldRush(results, 3, 3, map18, 0);
	if (results[0] != 8 || results[1] != 0) printf("FAIL (map18) ");
	GoldRush(results, 3, 3, map18, 1);
	if (results[0] != 8 || results[1] != 0) printf("FAIL (map18-bonus1) ");
	GoldRush(results, 3, 3, map18, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map18-bonus2) ");

	int map19[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 9, 0 },{ 9, 9, 9 },{ 0, 9, 0 } };
	GoldRush(results, 3, 3, map19, 0);
	if (results[0] != 5 || results[1] != 0) printf("FAIL (map19) ");
	GoldRush(results, 3, 3, map19, 1);
	if (results[0] != 5 || results[1] != 0) printf("FAIL (map19-bonus1) ");
	GoldRush(results, 3, 3, map19, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map19-bonus2) ");

	int map20[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 0, 9 },{ 0, 9, 0 },{ 9, 0, 9 } };
	GoldRush(results, 3, 3, map20, 0);
	if (results[0] != 5 || results[1] != 0) printf("FAIL (map20) ");
	GoldRush(results, 3, 3, map20, 1);
	if (results[0] != 5 || results[1] != 0) printf("FAIL (map20-bonus1) ");
	GoldRush(results, 3, 3, map20, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map20-bonus2) ");

	int map21[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 9, 0, 9 },{ 0, 0, 0 },{ 9, 0, 9 } };
	GoldRush(results, 3, 3, map21, 0);
	if (results[0] != 4 || results[1] != 0) printf("FAIL (map21) ");
	GoldRush(results, 3, 3, map21, 1);
	if (results[0] != 1 || results[1] != 1 || results[2] != 1 || results[3] != 1 || results[4] != 0) printf("FAIL (map21-bonus1) ");
	GoldRush(results, 3, 3, map21, 2);
	if (results[0] != 0) printf("FAIL (map21-bonus2) ");

	int map22[MAX_MAP_SIZE][MAX_MAP_SIZE] = { { 0, 9, 0 },{ 9, 0, 9 },{ 0, 9, 0 } };
	GoldRush(results, 3, 3, map22, 0);
	if (results[0] != 4 || results[1] != 0) printf("FAIL (map22) ");
	GoldRush(results, 3, 3, map22, 1);
	if (results[0] != 4 || results[1] != 0) printf("FAIL (map22-bonus1) ");
	GoldRush(results, 3, 3, map22, 2);
	if (results[0] != 0 || results[1] != 0) printf("FAIL (map22-bonus2) ");
}

void Test_GoldRush3(void)
{
	int results[5000];

	printf("\nThe following tests make use of max map size and may take some time\nTesting map23\n");
	int map23[MAX_MAP_SIZE][MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			map23[i][j] = 9;
		}
	}
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map23, 0);
	if (results[0] != 10000 || results[1] != 9604) printf("FAIL (map23) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map23, 1);
	if (results[0] != 10000 || results[1] != 0) printf("FAIL (map23-bonus1) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map23, 2);
	if (results[0] != 9604 || results[1] != 0) printf("FAIL (map23-bonus2) ");

	printf("\nTesting map24\n");
	int map24[MAX_MAP_SIZE][MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			if (i*j % 2 == 0) map24[i][j] = 9;
			else map24[i][j] = 0;
		}
	}
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map24, 0);
	if (results[0] != 7500 || results[1] != 0) printf("FAIL (map24) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map24, 1);
	if (results[0] != 7500 || results[1] != 0) printf("FAIL (map24-bonus1) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map24, 2);
	if (results[0] != 0) printf("FAIL (map24-bonus2) ");

	printf("\nTesting map25\n");
	int map25[MAX_MAP_SIZE][MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			if ((i % 2 == 0) && (j % 2 == 0)) map25[i][j] = 9;
			else map25[i][j] = 0;
		}
	}
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map25, 0);
	if (results[0] != 2500 || results[1] != 0) printf("FAIL (map25) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map25, 1);
	int correct = 1;
	for (int i = 0; i < 250; i++) {
		if (results[i] != 1) correct = 0;
	}
	if (correct != 1 || results[2500] != 0) printf("FAIL (map25-bonus1) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map25, 2);
	if (results[0] != 0) printf("FAIL (map25-bonus2) ");

	printf("\nTesting map26\n");
	int counter = 0;
	int map26[MAX_MAP_SIZE][MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			if (((i+1) % 4 == 0) || ((j+1) % 4 == 0)) map26[i][j] = 0;
			else {
				counter += 1;
				map26[i][j] = 9;
			}
		}
	}
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map26, 0);
	if (results[0] != 5625 || results[1] != 625) printf("FAIL (map26) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map26, 1);
	correct = 1;
	for (int i = 0; i < 625; i++) {
		if (results[i] != 9) correct = 0;
	}
	if (results[625] != 0 || correct != 1) printf("FAIL (map26-bonus1) ");
	GoldRush(results, MAX_MAP_SIZE, MAX_MAP_SIZE, map26, 2);
	correct = 1;
	for (int i = 0; i < 625; i++) {
		if (results[i] != 1) correct = 0;
	}
	if (results[625] != 0 || correct != 1) printf("FAIL (map26-bonus2) ");

}