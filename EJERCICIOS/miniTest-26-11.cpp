#include <iostream>

int main(){
    int numMenor {}, numMayor{} ;

    std::cout<< "Ingrese un numero: ";
    std::cin >> numMenor ;
    std::cout << "ingrese un numero mayor que el anterior: ";
    std::cin >> numMayor ;

    if (numMenor < numMayor){
        std::cout << "El numero menor es: " << numMenor << '\n';
        std::cout << "El numero mayor es: " << numMayor << '\n';
        } else {
        int aux{} ; // aqui empieza la vida de aux
        aux = numMayor;
        numMayor = numMenor;
        numMenor = aux;

        std::cout << "" << '\n';
        std::cout << "intercambiando valores " << '\n';
        std::cout << " " << '\n';
        std::cout << "El numero menor es: " << numMenor << '\n';
        std::cout << "El numero mayor es: " << numMayor << '\n'; 
        } //aqui muere la variable aux 




    return 0;
} //aqui mueren las variables numMayor y numMenor 