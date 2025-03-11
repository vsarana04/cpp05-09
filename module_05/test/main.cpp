#include <iostream>
#include <string>

// Функція, яка може викликати виключення
void divideNumbers(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!"); // Викидання виключення
    }
    std::cout << "Result: " << a / b << std::endl;
}

int main() {
    try {
        double num1 = 10, num2 = 0;
        
        std::cout << "Trying to divide " << num1 << " by " << num2 << std::endl;
        divideNumbers(num1, num2); // Спроба виконати потенційно небезпечний код
    }
    catch (const std::runtime_error& e) {
        // Обробка виключення
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "Program continues after exception handling." << std::endl;
    return 0;
}
