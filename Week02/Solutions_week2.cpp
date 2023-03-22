// Week02_solutions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task_1
struct CashReceipt {
    char companyName[256];
    unsigned number;
    unsigned price;
    bool paymentProcess;
};

//task_2
enum Color {
    Red,
    Blue,
    Green
};

bool checkColor(const Color *colors, unsigned size, Color color) {
    for (unsigned i = 0; i < size; ++i) {
        if (colors[i] == color) {
            return true;
        }
    }
    return false;
}

//task_3


int main()
{
    //task_1
    //option 1
    CashReceipt cashReciept1 = { "name", 1234, 12, true };
    //option 2
    CashReceipt cashReciept2;
    cashReciept2.companyName[0] = 'a';
    cashReciept2.number = 1234;
    cashReciept2.price = 123;
    cashReciept2.paymentProcess = true;

    std::cout << cashReciept1.companyName << std::endl;
    std::cout << cashReciept2.companyName[0] << std::endl;

    //task_2
    Color color[3] = { Blue, Green, Green };
    std::cout << checkColor(color, 3, Color::Green) << std::endl;

    //task_3

    return 0;
}
