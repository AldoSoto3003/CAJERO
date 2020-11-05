#include <iostream>

int main(){
    std::cout << "ingrese un entero ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "El valor es cero\n";
    return 0;
    
}