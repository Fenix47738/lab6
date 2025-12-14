#include <iostream>
#include <array>

using namespace std;

void Array43(); // Оголошуємо перший метод завдання

int AmountOfArray(int* arr, int N); // Оголошуємо метод який рахує кількість різних елементів у масиві
void Array43_Console(int* arr, int amount, int N); // Оголошуємо метод який виводе інформацию вже виконаного першого завдання

void Array96(); // Оголошуємо другий метод завдання

int* RemoveIdenticalElements(int*& arr, int N, int& size_result_arr); // Оголошуємо метод який буде повертати масив який хранить тільки уникальні елементи основного масиву
void Array96_Console(int* arr, int N, int* result_arr, int size_result_arr); // Оголошуємо метод який виводить готовий результат для другого завдання

int* EnterConsole(int& N); // оголошуємо метод за допомогою якого користувач зможе ввести данні у консоль загальний метод для цих завдань

int main()
{
    int menu; // оголошення змінної з якого користувач обере яке саме завдання він хоче переглянути

    cout << "Task number: "; // просимо користувача обрати
    cin >> menu; // доємо можливість обрати
    
    switch (menu) // перевірка що саме користувач обрав?
    {
        case 1: Array43(); break; // перше завдання
        case 2: Array96(); break; // друге завдання
        default: cout << "Wrong task (only 1 or 2)" << endl; // якщо користувач ввів інше
    }

    // завершення программи
    system("pause");
    return 0;
}

void Array43()
{
    // Метод першого завдання

    int N; // змінна яка хранить розмір масиву
    int* arr = EnterConsole(N); // створення масива через метод який описан вишче

    int amount = AmountOfArray(arr, N); // створення змінної яка хранить кількість різних елементів із основго масиво, для цього програма викликаємо метод який описан вишче

    Array43_Console(arr, amount, N); // масив який виводить результат цього завдання

    delete[] arr; // звільняємо пам'ять
}

int AmountOfArray(int* arr, int N)
{
    // створюємо змінну в якій буде зберігатися кількість різних елемментів, потім у першому циклі створюємо змінну типу булеан який хранить перше значення правда потім у наступньому
    // змінній створюємо умову якщи данні співпали тоді другий цикл преривається а перед остання дія ми змінюємо значення змінної типу бул на ложь а вже після цього циклу за допомогою
    // цієї змінної ми зможимо додати до змінної amount якщо елемент э уникальним, перший цикл це є той елемент масива за допомогою якого ми перевіряжмо елемент масива з тим же масивом але у другому масиві
    // у другому циклі навмисно написан k = i + 1 тим самим предбачая логічні помилки у майбутньому

    int amount = 0;

    for (int i = 0; i < N; i++)
    {
        bool unique = true;

        for (int k = i+1; k < N; k++)
        {
            if (arr[i] == arr[k])
            {
                unique = false;
                break;
            }
        }

        amount += unique ? 1 : 0;
    }

    return amount;
}

void Array43_Console(int* arr, int amount, int N)
{
    // просто виводимо інформацію що до виконня завдання

    cout << "Your array:" << endl;

    for (int i = 0; i < N; i++)
        cout << arr[i];

    cout << "\namount of different elements: " << amount << endl;
}

void Array96()
{
    // друге завдання

    int N; // змінна яка хранить розмір масиву
    int* arr = EnterConsole(N); // створення масива через метод який описан вишче

    int size_result_arr; // змінна яка хранить розмір масива який хранить тільки різних елементів
    int* result_arr = RemoveIdenticalElements(arr, N, size_result_arr); // створення змінної яка хранить масив різних елементів із основго масиво, для цього програма викликаємо метод який описан вишче

    Array96_Console(arr, N, result_arr, size_result_arr); // масив який виводить результат цього завдання

    delete[] arr; //звільняємо пам'ять
    delete[] result_arr;
}

int* RemoveIdenticalElements(int*& arr, int N, int& size_result_arr)
{
    int* result_arr = new int[N]; // свторюємо масив длінною N
    size_result_arr = -1; // змінна яка хранить розмір масива який хранить тільки різних елементів

    for (int i = 0; i < N; i++) // цикл який проходить по кожному елементу основго масиву
    {
        bool isEqual = false; // змінна для того щоб хранити чи одинаковий елемент?
        for (int k = 0; k <= size_result_arr; k++) // цикл який проходить по масиву який буде хранити різні елементи
            if (result_arr[k] == arr[i]) // порівнюємо якщо співпало тоді змінюємо змінну на тру
                isEqual = true;
        
        if (!isEqual) // якщо не буле однаковіх елементів у основному та у іншому масиві
        {
            size_result_arr++; // збільшуємо масив для різних елементів щоб додати ще один елемент якого ще не було
            result_arr[size_result_arr] = arr[i];
        }
    }

    int* correctResult_arr = new int[size_result_arr+1]; // свторюємо новий масив але він буде хранити його розмір вже точний

    for (int i = 0; i <= size_result_arr; i++) // записуємо із старого масива різних елементів в коректний масив інших елементів
        correctResult_arr[i] = result_arr[i];

    delete[] result_arr; // звільняємо пам'ять

    return correctResult_arr; // повертаємо коректний масив різних елементів
}

void Array96_Console(int* arr, int N, int* result_arr, int size_result_arr)
{
    // просто виводимо інформацію що до виконня завдання

    cout << "Your array:" << endl;

    for (int i = 0; i < N; i++)
        cout << arr[i];

    cout << "\namount of different elements: " << size_result_arr+1 << endl;
    cout << "Array only different elements:" << endl;

    for (int i = 0; i < size_result_arr+1; i++)
        cout << result_arr[i] << " ";

    cout << endl;
}

int* EnterConsole(int& N)
{
    // просимо користувача ввести змінну N та потім просимо ввести данні елементів масиву за допомогою цикла, закінчення методу буде повернення вже готового мосива до змінної

    cout << "Enter array size N: ";
    cin >> N;

    cout << "Enter array" << endl;

    int* arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    return arr;
}
