#include <iostream>
#include <string>
//DECLARACION DE ESTRUCTURAS
struct Tarjeta{
    std::string nombreTarjeta {};
    int numTarjeta {};    
};

struct Transacciones{
    std::string descripcion {};
    std::string categoria {};
    std::string tipoCuenta {};    
    int monto{};
}

//EMPIEZA DECLARACIÓN DE VARIABLES
std::string nombre;
double billetera{};
Tarjeta tdc{}; //tarjeta de credito
Transacciones vector[100] {};

//TERMINA DECLARACION DE VARIABLES

int transferencia(){

    return 0;
}

int ingreso(){


    return 0;
}

int gasto(){

    return 0;
}



int main(){

    std::cout << "Bienvenido a la app FINANZAS PERSONALES PERRONA para que dejes de gastar a lo pendejo" << '\n';
    std::cout << "" << '\n';

    



    return 0;
}

