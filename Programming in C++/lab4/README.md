
# Лабораторная работа №4. Виртуальные функции(Интерфейсы).
## Файлы работы:
[main.cpp](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab4/main.cpp)<br>[Interface.cpp](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab4/Interface.cpp), [Interface.h](https://github.com/nazzrrg/Programming-in-Cpp-Language-II/blob/master/Programming%20in%20C%2B%2B/lab4/Interface.h)
## Задание

#### Реализовать все указанные интерфейсы (абстрактные базовые классы) для классов (согласно варианту):
- Круг
- Отрезок
- Равносторонний треугольник
- Прямоугольник
- Шестиугольник
- Параллелограмм
- Равнобедренная трапеция
- Эллипс (периметр можно считать по любой приближенной формуле: см. интернет, справочники и т.п.).
#### Функционал системы:
- Хранение множества фигур
- Динамическое добавление фигур пользователем. (через консоль)
- Отобразить все фигуры.
- Суммарная площадь всех фигур.
- Суммарный периметр всех фигур.
- Центр масс всей системы.
- Память, занимаемая всеми экземплярами классов.
- Сортировка фигур между собой по массе.
#### Вопросы для обдумывания:
- Есть ли необходимость делать методы сравнения по массе виртуальными?(*Нет, так как функция getSize внутри класса и уже будет перегружена*)
- Получится ли также перегрузить операторы сравнения для интерфейса BaseCObject чтобы сравнивать объекты по объему занимаемой памяти? (*Да*)
- Предположите, что в дальнейшем придется изменить код таким образом, чтобы фигуры (оставаясь сами по себе плоскими) задавались уже не в двумерном, а в трехмерном пространстве. Укажите как бы вы действовали? Что пришлось бы изменить? (*Создать переменные для углов, задающие направления отрезков в фигурах относительно осей; Добавить третью координату создав 3D вектор, добавить ее во входные данные при вводе и в расчет центра масс*)

```cpp
// Интерфейс "Геометрическая фигура".
class IGeoFig {
public:
// Площадь.
virtual double getSquare() = 0;
// Периметр.
virtual double getPerimeter() = 0;
};
// Вектор
class Vector2D {
public:
double x, y;
};
// Интерфейс "Физический объект".
class IPhysObject {
public:
// Масса, кг.
virtual double getMass() = 0;
// Координаты центра масс, м.
virtual Vector2D getPosition() = 0;
// Сравнение по массе.
virtual bool operator== ( const IPhysObject& ob ) const = 0;
// Сравнение по массе.
virtual bool operator< ( const IPhysObject& ob ) const = 0;
};
// Интерфейс "Отображаемый"
class IPrintable {
public:
// Отобразить на экране
// (выводить в текстовом виде параметры фигуры).
virtual void draw() = 0;
};
// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
// Задать параметры объекта с помощью диалога с пользователем.
virtual void initFromDialog() = 0;
};
// Интерфейс "Класс"
class BaseCObject {
public:
// Имя класса (типа данных).
virtual std::string classname() = 0;
// Размер занимаемой памяти.
virtual uint64_t size() = 0;
};
```
В работе выполнен вариант номер 12, потому что. 
