#include <stdio.h>

void printFibonacci(int n);
int isLeapYear(int year);
int isValidDate(int day, int month, int year);

int main() {
    int choice;

    do {
        
        printf("\nMenu:\n");
        printf("1- Fibonacci sequence\n");
        printf("2- Check a date\n");
        printf("3- Quit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int n;
                    printf("Enter a positive integral number (n) for Fibonacci sequence: ");
                    scanf("%d", &n);
                    if (n > 0) {
                        printFibonacci(n);
                    } else {
                        printf("Invalid input. Please enter a positive integral number.\n");
                    }
                    break;
                }
            case 2:
                {
                    int day, month, year;
                    printf("Enter a date (day month year): ");
                    scanf("%d %d %d", &day, &month, &year);
                    if (isValidDate(day, month, year)) {
                        printf("Valid date.\n");
                    } else {
                        printf("Invalid date.\n");
                    }
                    break;
                }
            case 3:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void printFibonacci(int n) {
    int a = 0, b = 1, next;

    printf("Fibonacci sequence for the first %d numbers: ", n);
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
}


int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; 
    }
    return 0; 
}

int isValidDate(int day, int month, int year) {
    if (year >= 1 && month >= 1 && month <= 12) {
        int daysInMonth;

        switch (month) {
            case 2:
                daysInMonth = (isLeapYear(year)) ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            default:
                daysInMonth = 31;
        }

        if (day >= 1 && day <= daysInMonth) {
            return 1; 
    }

    return 0; 
}
}