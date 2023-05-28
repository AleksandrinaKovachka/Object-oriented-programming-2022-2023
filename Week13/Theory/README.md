# Седмица 13 - Шаблони (templates). Идея, особености, използване. Шаблони на функции. Шаблони на класове.

Шаблоните са мощнa характеристикa на C++, която ни позволява да пишем общи програми.
Можем да създадем една функция, която да работи с различни типове данни, като използваме шаблон.


Дефиниция на шаблон на функция:
=

Шаблонът на функцията започва с ключовата дума template, последван от параметър(и) на шаблона вътре в <>, което е последвано от дефиницията на функцията.
```
template <typename T>
T functionName(T parameter1, T parameter2, ...) 
{
    //...
}
```

В горния пример -  T е шаблонен аргумент, който приема различни типове данни (int, float и т.н.), а typename е ключова дума.
Когато аргумент от тип данни се предаде на functionName(), компилаторът генерира нова версия на functionName() за дадения тип данни.
(В горния пример резултатът, който функцията връща също е от указания тип - Т)

Извикване на шаблон на функция:
=
След като сме декларирали и дефинирали шаблон на функция,
можем да го извикаме в други функции или шаблони (като функцията main()) със следния синтаксис: 
```
functionName<dataType>(parameter1, parameter2,...);
```
-експлицитно обявяваме типа на данните, с които искаме функцията да работи, записвайки типа - dataType в <> след името на функцията

Пример:

Функция, която събира две числа от произволен тип и връща като резултат тяхната сума:
```
template <typename T>
T add(T num1, T num2) 
{
   return (num1 + num2);
}
```
Можем да извикаме функцията в main() - за int и double
```
int main() 
{

    int result1;
    double result2;

    // calling with int parameters
    result1 = add<int>(2, 3);
    cout << result1 << endl;

    // calling with double parameters
    result2 = add<double>(2.2, 3.3);
    cout << result2 << endl;

    return 0;
}   
```
```
output:

    2 + 3 = 5

    2.2 + 3.3 = 5.5
```

ВАЖНО функцията в горния пример няма да работи за типове, за които не е дефинирана операцията '+' (например, ако сме си дефинирали клас, в който не сме  имплементирали операцията '+') 

Шаблони на класове:
=

Подобно на шаблоните за функции, можем да използваме templates за класове, за да създадем един клас да работи с различни типове данни.
Class templates са полезни, тъй като могат да направят нашия код по-кратък и по-управляем.


Декларация за шаблон на клас:
=

Шаблонът на класа започва с ключовата дума template, последван от параметър(и) на шаблона вътре в <>, което е последвано от декларацията на класа.

Пример:
```
template <class T>
class className 
{
  private:
    T var;
    //...
  public:
    T functionName(T arg);
    //...
};
```

В горната декларация **T** е аргументът на шаблона, който е заместител за използвания тип данни, а class е ключова дума.
Вътре в тялото на класа, член данната var и резултатът върнат от метода functionName() са от тип T.

Създаване на обект на шаблон за клас:
=

След като сме декларирали и дефинирали шаблон на клас, можем да създадем обекти от този клас в други класове или функции (като функцията main()) със следния синтаксис
```
className<dataType> classObject;
```

Необходимо е експлицитно да означим типа на темплатния параметър в <> преди името на обекта.

Пример:

```
className<int> classObject;

className<float> classObject;

className<string> classObject;
```

Пример за template class :

```
// Class template
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor

    T getNum() {
        return num;
    }
};

int main() {

    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}
```

output:

```
int Number = 7
double Number = 7.7

от горния пример 
//Error
Number numberInt(7);
Number numberDouble(7.7);
```

Дефиниране на член на клас извън шаблона на класа:
=

Да предположим, че трябва да дефинираме метод извън шаблона на класа. Можем да направим това със следния код:

```
template <class T>
class ClassName 
{
    //...

    // Function prototype
    returnType functionName();
};

// Function definition
template <class T>
returnType ClassName<T>::functionName() 
{
    //...
}
```

Забележете, че template <class T> се повтаря, когато дефинираме функцията извън класа. Това е необходимо и е част от синтаксиса.

Шаблони за класове с множество параметри:
=

В C++ можем да използваме множество параметри на шаблона и дори да използваме аргументи по подразбиране за тези параметри по следния начин:

```
template <class T, class U, class V = int>
class ClassName 
{
  private:
    T member1;
    U member2;
    V member3;
    //...
  public:
    //...
};
```

Пример:
  
```
template <class T, class U, class V = char>
class ClassTemplate 
{
   private:
    T var1;
    U var2;
    V var3;

   public:
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}  // constructor

    void printVar() 
    {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }

    //...
};

int main() 
{
   
    ClassTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    //...
}
```
  
output:
```
obj1 values: 
var1 = 7
var2 = 7.7
var3 = c

obj2 values: 
var1 = 8.8
var2 = a
var3 = 0
```
