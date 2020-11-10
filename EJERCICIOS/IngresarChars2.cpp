#include <iostream>

int main(){
    
    std::cout<< "ingrese un caracter:";
    
    char ch{};
    std::cin >> ch;
    std::cout << ch << "tiene el código ASCII " << static_cast<int>(ch) << '\n' ;

    std::cin >> ch;
    std::cout << ch << "tiene el código ASCII " << static_cast<int>(ch) << '\n' ;

    std::cin >> ch;
    std::cout << ch << "tiene el código ASCII " << static_cast<int>(ch) << '\n' ;

    std::cin >> ch;
    std::cout << ch << "tiene el código ASCII " << static_cast<int>(ch) << '\n' ;
    return 0;
}