#include <stdio.h>
#include <stdlib.h>

// Function declarations
void showMenu();
double performOperation(char op, double num1, double num2);

int main() {
    char choice;
    double a, b, result;

    while (1) {
        showMenu();
        printf("Enter your choice (or 'q' to quit): ");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q') {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // Validate operation
        if (choice != '+' && choice != '-' && choice != '*' && choice != '/') {
            printf("Invalid operation! Please try again.\n\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);

        if (choice == '/' && b == 0) {
            printf("Error: Division by zero is undefined!\n\n");
            continue;
        }

        result = performOperation(choice, a, b);
        printf("Result: %.2lf %c %.2lf = %.2lf\n\n", a, choice, b, result);
    }

    return 0;
}

// Function to display the operation menu
void showMenu() {
    printf("===== Basic Calculator =====\n");
    printf("Choose an operation:\n");
    printf(" + : Addition\n");
    printf(" - : Subtraction\n");
    printf(" * : Multiplication\n");
    printf(" / : Division\n");
    printf(" q : Quit\n");
}

// Function to perform the arithmetic operation
double performOperation(char op, double num1, double num2) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0; // Should not reach here
    }
}
