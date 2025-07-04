#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void arithmeticOperationError();

int main(void) {
    int number1, number2;
    printf("First number: ");
    scanf("%d", &number1);
    printf("Second number: ");
    scanf("%d", &number2);

    signal(SIGFPE, arithmeticOperationError);

    printf("%d + %d = %d\n", number1, number2, number1 + number2);
    printf("%d - %d = %d\n", number1, number2, number1 - number2);
    printf("%d + %d = %d\n", number1, number2, number1 * number2);
    printf("%d / %d = %d\n", number1, number2, number1 / number2);
}

void arithmeticOperationError() {
    printf("Erroneous arithmetic operation.\n");
}
