#include <iostream>
#include <vector>
#include <string>
#include<windows.h>

class Establishment {
public:
    virtual void deliverOrder() = 0;
    virtual void getMenu() const = 0;
};

class Restaurant : public Establishment {
public:
    void deliverOrder() override {
        std::cout << "Доставка з ресторану\n";
    }

    void getMenu() const override {
        std::cout << "Меню ресторану:\n";
        std::cout << "Картопляне пюре з котлетами з індички\n";
        std::cout << "Шніцель з печеною картоплею\n";
        std::cout << "Грибний крем-суп\n";
    }
};

class Pizzeria : public Establishment {
public:
    void deliverOrder() override {
        std::cout << "Доставка з піцерії\n";
    }

    void getMenu() const override {
        std::cout << "Меню піцерії:\n";
        std::cout << "Піцца 4 сири 1\n";
        std::cout << "Піцца Парма\n";
        std::cout << "Піцца Маргарита\n";
    }
};

class Cafe : public Establishment {
public:
    void deliverOrder() override {
        std::cout << "Доставка з кафе\n";
    }

    void getMenu() const override {
        std::cout << "Меню кафе:\n";
        std::cout << "Еспрессо\n";
        std::cout << "Капуччіно 2\n";
        std::cout << "Латте 3\n";
    }
};

class Courier {
public:
    void deliver(Establishment* establishment) {
        establishment->deliverOrder();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Restaurant restaurant;
    Pizzeria pizzeria;
    Cafe cafe;

    std::vector<Establishment*> establishments = { &restaurant, &pizzeria, &cafe };

    Courier courier;
    for (Establishment* establishment : establishments) {
        establishment->getMenu();
        courier.deliver(establishment);
        std::cout << "------------\n";
    }

    return 0;
}
