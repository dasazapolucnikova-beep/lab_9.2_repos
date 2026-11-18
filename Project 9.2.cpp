#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "macros.h"

// Задаємо значення Z для умовної компіляції.
// Змінюй це число (наприклад, на 5 або на 2), щоб перевірити обидві гілки!
#define Z 5

int main()
{
    double x, y, z, w;
    char ch;

    // Присвоюємо змінній z значення константи Z, щоб формула відповідала умові
    z = Z;

    do
    {
        printf("Current Z = %d\n", Z);
        printf("Input x and y: ");
        scanf_s("%lf %lf", &x, &y);

        // Умовна компіляція на основі значення Z
#if Z > 3
        printf("Branch: z > 3\n");
        w = MAX(SQR(x + y), SQR(x - z));
#else
        printf("Branch: z <= 3\n");
        w = MIN(x * y + y * z, SQR(z * x + y * z));
#endif

        // Виведення результату за допомогою макросу
        PRINTR(w);

        printf("Repeat? (y/n): ");
        ch = _getch();
        printf("%c\n\n", ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}