#include <iostream>

using namespace std;

void task_5() {

    const int size = 10;
    int arr[size] = { 2, -4, 5, 7, -9, 8, 1, -3, 6, -2 };
    int negCount = 0;
    int newPos = 0;
    int* newArr = new int[size];

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            newArr[negCount] = arr[i];
            negCount++;
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            newArr[negCount + newPos] = arr[i];
            newPos++;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << newArr[i] << " ";
    }

    delete[] newArr;
}

void task_6() {
    const int size = 14;
    double arr[size] = { 1.4, 3.2, 5.1, 2.0, 4.7, 9.3, 6.5, 8.2, 7.6, 0.3, 6.1, 2.9, 1.5, 4.8 };
    int swaps = 0;

    for (int i = 0; i < size / 2; i++) {
        double temp = arr[i];
        arr[i] = arr[i + (size / 2)];
        arr[i + (size / 2)] = temp;
        swaps++;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Number of swaps: " << swaps;
}

void task_7() {

    const int size = 10;
    int arr[size] = { 5, 3, 1, 2, 7, 4, 8, 6, 9, 2 };
    int count = 0;

    for (int i = 1; i < size - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            count++;
        }
    }

    cout << "Number of local minimums: " << count;
}

void task_8() {

    const int size = 3;
    int arr[size][size] = { {3, 5, 0}, {1, 0, 7}, {0, 2, 6} };
    int sum = 0;
    int zeroCount = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 0) {
                zeroCount++;
            }
            if (zeroCount == 1 && arr[i][j] != 0) {
                sum += arr[i][j];
            }
            if (zeroCount == 2) {
                cout << "Sum of row " << i << ": " << sum << endl;
                break;
            }
        }
    }
}

void task_9() {
   
    const int N = 15;
    int* a = new int[N]; // создаем динамический массив
    cout << "Enter " << N << " numbers:\n";
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int* p = a; // указатель на начало
    int* q = a + N - 1; // указатель на конец
    while (p <= q) {
        if (*p < 0) {
            p++; 
        }
        else if (*q >= 0) {
            q--; 
        }
        else {
            int temp = *p; // обмен значениями через временную переменную
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }

    // сортировка отрицательных чисел по возрастанию
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[i] >= 0) break; // выходим из цикла, если дошли до положительного числа
            if (a[i] > a[j])
                swap(a[i], a[j]); 
        }
    }

    // сортировка положительных чисел по убыванию
    for (int i = N - 1; i >= 0; i--) {
        if (a[i] < 0) break;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < 0) break; // выходим из цикла, если дошли до отрицательного числа
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }

    // выводим отсортированный массив на экран
    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << ' '<< endl;

    delete[] a; // удаляем динамический массив
}

void task_10() {

    const int N = 5;
    double* a = new double[N];
    double* b = new double[N];
    cout << "Enter " << N << " number of first array:\n";
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cout << "Enter " << N << " numbers of second array:\n";
    for (int i = 0; i < N; i++)
        cin >> b[i];

    // находим индексы максимальных элементов
    int index_a = 0, index_b = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] > a[index_a]) index_a = i;
        if (b[i] > b[index_b]) index_b = i;
    }

    // меняем местами максимальные элементы
    double temp = a[index_a];
    a[index_a] = b[index_b];
    b[index_b] = temp;

    // выводим измененные массивы на экран
    cout << "Changed first array:\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ' << endl;

    cout << "Changed second array:\n";
    for (int i = 0; i < N; i++)
        cout << b[i] << ' ' << endl;

    delete[] a;
    delete[] b;
}

void task_11() {

    const int ROWS = 3;
    const int COLS = 4;
    int** a = new int* [ROWS]; // создаем динамический двумерный массив
    for (int i = 0; i < ROWS; i++)
        a[i] = new int[COLS];

    cout << "Enter elements of matrix " << ROWS << 'x' << COLS << ":\n";
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> a[i][j];

    // циклический сдвиг столбцов на один вправо
    int temp[ROWS];
    for (int j = 0; j < COLS - 1; j++) {
        // сохраняем последний элемент столбца
        for (int i = 0; i < ROWS; i++)
            temp[i] = a[i][COLS - 1 - j];
        // сдвигаем столбцы на одну позицию вправо
        for (int i = 0; i < ROWS; i++)
            a[i][COLS - 1 - j] = a[i][COLS - 2 - j];
        // копируем последний элемент в первый столбец
        for (int i = 0; i < ROWS; i++)
            a[i][0] = temp[i];
    }

    // выводим измененную матрицу на экран
    cout << "Changed matrix:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << a[i][j] << ' ' << endl;
    }

    // освобождаем память
    for (int i = 0; i < ROWS; i++)
        delete[] a[i];
    delete[] a;
}



void task_12() {

    const int ROWS = 3;
    const int COLS = 4;
    int** a = new int* [ROWS];
    for (int i = 0; i < ROWS; i++)
        a[i] = new int[COLS];

    cout << "Enter elements of matrix " << ROWS << 'x' << COLS << ":\n";
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> a[i][j];

    // находим максимальную сумму и соответствующую строку
        int max_sum = -1, max_index = -1;
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++)
            sum += a[i][j];
        if (sum > max_sum || max_index == -1) {
            max_sum = sum;
            max_index = i;
        }
    }

    // находим минимальную сумму и соответствующую строку
    int min_sum = -1, min_index = -1;
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++)
            sum += a[i][j];
        if (sum < min_sum || min_index == -1) {
            min_sum = sum;
            min_index = i;
        }
    }

    // выводим результаты на экран
    cout << "Row with maximum sum of elements:\n";
    for (int j = 0; j < COLS; j++)
        cout << a[max_index][j] << ' ' << endl;

    cout << "Row with minimum sum of elements:\n";
    for (int j = 0; j < COLS; j++)
        cout << a[min_index][j] << ' ' << endl;

    // освобождаем память
    for (int i = 0; i < ROWS; i++)
        delete[] a[i];
    delete[] a;

}

int main() {
	
	task_5();
    
    task_6();
    
    task_7();

    task_8();

    task_9();

    task_10();

    task_11();

    task_12();
	

    return 0;
}
