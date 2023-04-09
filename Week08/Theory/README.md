# Седмица 8 - Статични и константни членове на клас. Приятели. Разделна компилация

Статични член данни:
=
Можем да дефинираме статични членове на класа с помощта на ключова дума static. Когато декларираме член данна на клас като статична, това означава, че независимо колко обекта на класа са създадени, има само едно копие на член данната.

Статичните член данни се споделят от всички обекти на класа. Всички статични данни се инициализират с нула при създаването на първия обект, ако не е налице друга инициализация. Не можем да го поставим в дефиницията на класа, но може да бъде инициализиран извън класа, чрез повторно деклариране на статичната променлива, като се използва операторът за разделяне на обхвата ::, за да се идентифицира към кой клас принадлежи.
```
class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         //...
         // Increase every time object is created
         objectCount++;
      }

      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects.
   cout << "Total objects: " << Box::objectCount << endl;

   return 0;
}
```

Статични методи:
=

Декларирайки метод като статичен, го правим независим от всеки обект от класа. Статичния метод може да бъде извикан, дори ако не съществуват обекти от класа
Статичния метод се извиква чрез използване на името на класа и оператора за разделяне на обхвата ::.
Статичните методи имат достъп само до статичните член данни, други статични функции и всякакви други функции извън класа. Статичните методи нямат достъп до укаателя this на класа. 
Можем да използваме статичен метод, за да определим дали е създаден обект от класа или не.

```
class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         // ...

         // Increase every time object is created
         objectCount++;
      }

      static int getCount() {
         return objectCount;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   // Print total number of objects before creating object.
   cout << "Inital Stage Count: " << Box::getCount() << endl; // 0 objects created

   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Box::getCount() << endl; // 2 objects created

   return 0;
}
```

Константни членове на клас:
=

Констатните член данни паказват дали променливата може да бъде променяна или не.
Константните член данни могат да получават стойност един единствен път. 
Променлива const трябва да бъде декларирана в класа, но не може да бъде дефинирана в него. 
Трябва да дефинираме променливата const извън класа. 
Присвоената стойност не може да бъде променяна по време на изпълнение на програмата.

За да зададем стойност на член данна в конструктура използваме:

```
class Point {
   private:
   int x;
   int y;
   const int temp = 10;

   public:
   Point(int _x, int _y, int _temp) : x(_x), y(_y), temp(_temp) {}
};
```

Констатни методи на клас:
=

Константната функция в клас ни гарантира, че обекта, който връщаме няма да бъде променян.

```
class Point {
   private:
   int x;
   int y;

   public:
   const int getX() {
      return this->x; // гарантираме си, че като получим стойността на х, тя няма да бъде променяна
   }
}
```

Какво означава, когато поставим const след декларирането на функцията: 

```
class Point {
   private:
   int x;
   int y;

   public:
   const int getX() const {
      return this->x;
   }
}
```

По този начин показваме, че в този метод getX() ние няма да променямe член данната х.

Приятелски класове:
=
Клас означен като приятелски на друг му позволява да използва private и protected член данните му.

```
class Point {
private:
    int x;
    int y;

    friend class Board; // Board има директен достъп до x и y
};
```

**Важно: Това, че класът Board е приятел на Point не означава, че Point e приятел на Board**

Приятелски функции на клас:
=
Функция означена като приятелска на клас и позволява да използва private и protected член данните на класа.

Функцията може да бъде:
- метод на друг клас
- глобална функция

```
class Point {
private:
    int x;
    int y;

    friend class Board::boardGame(); // функцията boardGame() от класа Board има директен достъп до x и y
};
```

Пример 1:
```
class B;
 
class A {
public:
    void showB(B&);
};
 
class B {
private:
    int b;
 
public:
    B() { b = 0; }
    friend void A::showB(B& x); // Friend function
};
 
void A::showB(B& x)
{
    // Since showB() is friend of B, it can
    // access private members of B
    std::cout << "B::b = " << x.b;
}
 
int main()
{
    A a;
    B x;
    a.showB(x);
    return 0;
}
```

Пример 2:
```
class A {
    int a;
 
public:
    A() { a = 0; }
 
    // global friend function
    friend void showA(A&);
};
 
void showA(A& x)
{
    // Since showA() is a friend, it can access
    // private members of A
    std::cout << "A::a=" << x.a;
}
 
int main()
{
    A a;
    showA(a);
    return 0;
}
```
