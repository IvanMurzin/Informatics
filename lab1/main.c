#include <stdio.h>

int getCountDigits(int num) {
    if (num == 0) return 1; // если передан 0, то число имеет всего 1 цифру
    int count = 0; // определяю счетчик количества цифр
    while (num != 0) { // запукаю цикл, пока в числе еще есть цифры
        num /= 10; // удаляю последнюю цифру числа
        count++; // увеличиваю счетчик на 1
    }
    return count; // возвращаю результат
}

void getDigits(int *digits, int count, int num) {
    if (num < 0) num = -num; // если число отрицательное, то делаю его положительным для корректной работы оператора %
    for (int i = 0; i < count; ++i) { // прохожусь по всем цифрам числа
        digits[i] = num % 10; // записываю последнюю цифру числа
        num /= 10; // удаляю последнюю цифру числа
    }
}

void bubbleSort(int *array, int count) {
    int temp; // объявляю вспомогательную переменную
    for (int i = 0; i < count - 1; i++) // прохожусь по всем элементам
        for (int j = 0; j < count - 1 - i; j++) // прохожусь по всем элементам до count-1-i
            if (array[j] < array[j + 1]) { // если следующий элемент больше предыдущего
                temp = array[j]; // запоминаю первый элемент
                array[j] = array[j + 1]; // записываю в первый элемент значение второго
                array[j + 1] = temp; // записываю во второй элемент значение вспомогательной переменной
            }
}

int makeNum(const int *array, int len, int source) {
    int ten = 1; // счетчик деятков
    int result = 0; //резульат вычислений
    if (source >= 0) { // если исходное положительно
        for (int i = len - 1; i >= 0; --i) {
            result += ten * array[i];
            ten *= 10; // увеличтваю порядок
        }
        return result; // то и результат положительный
    } else { // если исходное отрицательно
        for (int i = 0; i < len; ++i) {
            result += ten * array[i];
            ten *= 10; // увеличиваю порядок
        }
        return -result; // то и результат отрицательный
    }
}

int main() {
    int n; // объявляю переменную n
    scanf("%d", &n); // считываю n
    int count = getCountDigits(n); // получаю количество цифр этого числа
    int digits[count]; // создаю массив с цифрами этого числа
    getDigits(digits, count, n); // записываю в массив digits цифры числа n
    bubbleSort(digits, count); // сортирую цифры по невозрастанию
    int result = makeNum(digits, count, n); // собираю число из массива
    printf("%d\n", result); // печатаю результат
    return 0;
}


