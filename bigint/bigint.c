#include <stdio.h>
#include "asmlib.h"
// superfluous comment
struct largenum {
	long unsigned int low;
	long unsigned int high;
};

int addTest(struct largenum num1, struct largenum num2);
int subTest(struct largenum num1, struct largenum num2);
int mulTest(struct largenum num1, struct largenum num2);

int main()
{
    struct largenum num1;
    struct largenum num2;

    printf("Number 1 high bits: ");
    scanf("%lx",&num1.high);
    printf("Number 1 low bits: ");
    scanf("%lx",&num1.low);

    printf("Number 2 high bits: ");
    scanf("%lx",&num2.high);
    printf("Number 2 low bits: ");
    scanf("%lx",&num2.low);

	addTest(num1, num2);

	subTest(num1, num2);

	mulTest(num1, num2);

    return 0;
}

int addTest(struct largenum num1, struct largenum num2)
{
	register long unsigned int rsi asm("rsi"); //carry
  	register long unsigned int rdx asm("rdx"); //high
  	register long unsigned int rdi asm("rdi"); //low

    long unsigned int high, low;

	// addition test
    add128(num1.low, num2.low, num1.high, num2.high);

    int carry = rsi;
    high = rdx;
    low = rdi;

    printf("Sum:\n");
    printf("0x%016lX%016lX\n",high,low);
    printf("0x%lX-%lX\n",high,low);

    if(carry)
	printf("with carry\n");
	else
	printf("no carry\n");

	return 0;
}

int subTest(struct largenum num1, struct largenum num2)
{
	register long unsigned int rsi asm("rsi"); //carry
  	register long unsigned int rdx asm("rdx"); //high
  	register long unsigned int rdi asm("rdi"); //low

    long unsigned int high, low;

	// subtract test
	sub128(num1.low, num2.low, num1.high, num2.high);

    int carry = rsi;
    high = rdx;
    low = rdi;

	printf("Difference:\n");
    printf("0x%016lX%016lX\n",high,low);
    printf("0x%lX-%lX\n",high,low);

	if(carry)
	printf("with carry\n");
	else
	printf("no carry\n");

	return 0;
}

int mulTest(struct largenum num1, struct largenum num2)
{
	// multiplication test
	register long unsigned int r8 asm("r8");
	register long unsigned int r9 asm("r9");
	register long unsigned int r10 asm("r10");
	register long unsigned int r11 asm("r11");

	mul128(num1.low, num2.low, num1.high, num2.high);

	long unsigned int lowlow, lowhigh, highlow, highhigh;

	lowlow = r8;
	lowhigh = r9;
	highlow = r10;
	highhigh = r11;

	printf("Product:\n");
    printf("0x%016lX%016lX%016lX%016lX\n",highhigh,highlow,lowhigh,lowlow);
    printf("0x%lX-%lX-%lX-%lX\n",highhigh,highlow,lowhigh,lowlow);

	return 0;
}