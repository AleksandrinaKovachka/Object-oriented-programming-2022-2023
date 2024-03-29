# Седмица 10 - Наследяване. Идея. Основни концепции.

Една от най-важните концепции в обектно-ориентираното програмиране е **наследяването**. Наследяването ни позволява да дефинираме клас чрез друг клас.
Когато създаваме клас, вместо да пишем напълно нови член данни и/или методи,можем да ги наследим от вече съществуващ клас. Този съществуващ клас се нарича Base class, а новият клас се нарича Derived class.

```
derived class (child) - класът който наследява друг клас/класове
base class (parent) - класът който се наследява
```

**Идеята за наследяване осъществява връзката 'is a'.**

Декларация:
=

За да наследим клас изпозваме символа **:** последван от спецификатор за достъп и името на класа който наследяваме.

```
class derived_class_name : access_specifier base_class_name
{
    //..
};
```

пример:

```
// Base class
class Shape 
{
   //...
};

// Derived class
class Rectangle: public Shape 
{
   //...
};
```

Достъп при наследяването:
=

Наследяващият клас има достъп до всички член данни и методи на базовия клас, които НЕ са private, т.е ако дадени член данни или методи не трябва да бъдат достъпвани от наследените класове , се дефинират като private.
Когато данните на даден клас (член данни или методи) са дефинирани като protected, те нe са видими извън класа, но са видими и достъпни от класовете които го наследяват.


|Access|public|protected|private|
| :---: | :---: | :---: | :---: |
|Same class|yes||yes|yes|
|Derived classes|yes|yes|no|
|Outside classes|yes|no|no|


Типове наследяване:
=

Типът на наследяване се определя от спецификатора на достъп, в derivation list-a. Наследяването може да бъде : **private**, **protected** или **public**.
При използване на различен тип наследяване се прилагат следните правила:

- (public inheritance) –  public данните на базовия клас стават  public данни на наследяващия клас, а защитените данни на базовия клас стават защитени данни на производния клас. Частните членове на базовия клас НИКОГА не са достъпни директно от производен клас, но могат да бъдат достъпни чрез извиквания към публичните и защитени членове на базовия клас.

- (protected inheritance) – public и private данните на базовия клас стават protected данни в наследения клас.

- (private inheritance) – public и private данните на базовия клас стават private членове на производния клас.
