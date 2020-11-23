#include <iostream>

int isEven(int x){

    if (x % 2 == 0)
        std::cout<< "El numero " << x << " es par " << '\n';
    else
        std::cout<< "El numero " << x << " es impar " << '\n';
    return 0;
}


int main(){
    int x{}, cont {};
    std::cout <<"Ingrese un numero: ";
    std::cin >> x;

    isEven(x);

    for (int i =1; i <= x; i++){

        if ((x % i) == 0)
            cont +=1;

    }

    if (cont == 2)
        std::cout<< "El numero es primo " << '\n';
    else
        std::cout<< "El numero no es primo "<< '\n';



    return 0;
}