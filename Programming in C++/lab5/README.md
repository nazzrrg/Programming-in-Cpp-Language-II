

# Лабораторная работа №5. Шаблоны, исключения.
## Файлы работы:
[main.cpp](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab5/main.cpp)<br>[myArray.tpp](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab5/myArray.tpp), [myArray.h](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab5/myArray.h)<br>[myException.cpp](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab5/myException.cpp), [myException.h](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab5/myException.h)
## Задание

Написать шаблонную функцию или класс согласно варианту.
Описать класс-исключение или иерархию классов-исключений. Генерировать исключения в соответствующих исключительных ситуациях. Если у вас есть другие предложения по исключительным ситуациям – используйте их.

#### Функции
||Описание|Параметры шаблона|
|---|---|---|
|A|Поиск максимального элемента в массиве.|Тип элементов массива.|
|B|Поиск минимального из двух элементов.|Тип элементов.|
|C|Меняет значения двух переменных одного типа местами (swap).|Тип переменных.|
|D|Вычисляет N-ю (целую) степень числа.|Степень (показатель) – целое число. Тип переменной.|

#### Классы
||Описание|Параметры шаблона|Исключения|
|---|---|---|---|
|E|Стек из макс. N элементов типа T|int N, class T|Переполнение стека.<br>Изъятие элемента из пустого стека.|
|F|Массив из N элементов типа T|int N, class T|Обращение по несуществующему индексу.|
|G|Очередь из макс. N элементов типа T|int N, class T|Переполнение очереди.<br>Изъятие элемента из пустой очереди.|
|H|Матрица NxM элементов типа T|int N, int M, class T|Обращение по несуществующему индексу.|

В работе выполнен вариант номер 12, потому что. 
