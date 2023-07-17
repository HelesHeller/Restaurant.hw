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
        std::cout << "�������� � ���������\n";
    }

    void getMenu() const override {
        std::cout << "���� ���������:\n";
        std::cout << "���������� ���� � ��������� � �������\n";
        std::cout << "������ � ������� ���������\n";
        std::cout << "������� ����-���\n";
    }
};

class Pizzeria : public Establishment {
public:
    void deliverOrder() override {
        std::cout << "�������� � ����\n";
    }

    void getMenu() const override {
        std::cout << "���� ����:\n";
        std::cout << "ϳ��� 4 ���� 1\n";
        std::cout << "ϳ��� �����\n";
        std::cout << "ϳ��� ���������\n";
    }
};

class Cafe : public Establishment {
public:
    void deliverOrder() override {
        std::cout << "�������� � ����\n";
    }

    void getMenu() const override {
        std::cout << "���� ����:\n";
        std::cout << "��������\n";
        std::cout << "��������� 2\n";
        std::cout << "����� 3\n";
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
