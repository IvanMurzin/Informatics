#include <stdio.h>

double pow2(int n) {
    return (double) (1 << n); // возведение 2 в степень есть сдвиг бита влево на n позиций
}

//double factorial(int n) {
//    double result = 1;
//    for (int i = 1; i <= n; ++i) result *= i; // факториал есть произведение всех чисел меньших данного числа
//    return result;
//}
//
//double prod(int n) {
//    double result = 1;
//    for (int i = 1; i <= n; ++i) result *= 1.0 / (i + 1); // считаю свое произведение
//    return result;
//}

double abs(double num) {
    return num > 0 ? num : -num; // возвращаю всегда положительное число
}

int main() {
    double eps; // погрешность измерений
    scanf("%lf", &eps); // считываю погрешность
    if (eps < 0) {
        printf("Точность не может быть отрицательной\n");
        return 0;
    }
    int k = 1; // счетчик итераций
    int sign = 1; // переменная, отвечающая за знак слагаемого
    double s = 0; // сумма ряда
    double temp; // предыдущее значение суммы
    double factorial = 1;
    double prod = 1;
    do {
        factorial *= k; // считаю факториал для конкретной итерации
        prod *= 1.0 / (k + 1); // считаю произведение для конкретной итерации
        double first = pow2(k) / factorial; // считаю (2^k)/(k!)
        ++k; // увеличиваю счетчик итераций
        temp = s; // запоминаю предыдущую сумму
        sign *= -1; // так как знак слагаемого (-1)^k не забываю его менять
        s += sign * first * prod; // считаю новую сумму
    } while (abs(s - temp) > eps); // пока результат не заданной точности продолжаю считать суцмму
    printf("Сумма: %.20f\n", s);  // печатаю результат с точностью до 20 знаков после запятой
    printf("Итераций: %d\n", k-1); // печатаю количество итераций
    return 0;
}


