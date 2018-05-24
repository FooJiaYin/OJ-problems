#include<stdio.h>

int main(void)

{
	int var1, var2, ans, remainder;
	char operate, repeat;

	/* Introduction */
	printf("Hello! I am a calculator.\n");
	printf("I can do simple addition, subtraction, multiplication, and division.\n");
	printf("Example: 23+4 \n\n");

	do {

		/* Input */
		scanf("%d%c%d", &var1, &operate, &var2);

		/*Calculate */
		switch (operate) {
		case '+':
			ans = var1 + var2;
			printf("=%d\n", ans);
			break;
		case '-':
			ans = var1 - var2;
			printf("=%d\n", ans);
			break;
		case '*':
			ans = var1 * var2;
			printf("=%d\n", ans);
			break;
		case '/':
			ans = var1 / var2;
			remainder = var1 % var2;
			printf("=%d r %d\n", ans, remainder);
			break;
		default:
			printf("Error.\n");
		}
		printf("\nNew calculation: (Press e and enter to exit) \n");
		scanf("%c", &repeat);
	}

	while (repeat != 'e');

	return 0;
}
