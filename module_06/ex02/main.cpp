#include "../class/Base.hpp"

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <exception>
#include <typeinfo>


// ────────────────────────────────
// Функція generate()
// ────────────────────────────────

Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(0)));  // ініціалізуємо random
    int random = std::rand() % 3;

    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return 0;  // fallback, теоретично unreachable
}

// ────────────────────────────────
// Функція identify(Base* p)
// ────────────────────────────────

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// ────────────────────────────────
// Функція identify(Base& p)
// ────────────────────────────────

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}

int main() {
    std::cout << "Generating random instances and identifying types:\n" << std::endl;

    for (int i = 0; i < 5; ++i) {
        Base* ptr = generate();

        std::cout << "[Test " << i + 1 << "]" << std::endl;
        std::cout << "identify(Base*): ";
        identify(ptr);

        std::cout << "identify(Base&): ";
        identify(*ptr);  // посилання

        std::cout << "--------------------------\n";

        delete ptr;  // не забуваємо звільнити пам’ять
    }

    return 0;
}