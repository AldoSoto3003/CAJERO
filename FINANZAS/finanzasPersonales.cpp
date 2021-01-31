#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include <iomanip>
#include <ctime>
#include <sstream>

std::string nombre{};
int noCuenta{},password{};
int ingresoTotal{}, gastoTotal{};


int funcTransfe(),funcIngresos(), funcGasto(), funcRegistros(),funcChangeUser();
void menu(),leer();

int funcTrasnfe(){

    return 0;
}

int funcIngresos(){


    return 0;
}

int funcGasto(){

    return 0;
}

int funcRegistros(){

    return 0;
}

int funcChangeUser(){


    return 0;
}


void menu(){
    int opcion{};
    std::cout << "Bienvenido a la app FINANZAS PERSONALES " << '\n';
    std::cout << "    \n";
    std::cout << "   \n";
    std::cout <<"       MENU        \n";
    std::cout <<"1.- INGRESO\n";
    std::cout <<"2.- GASTO\n";
    std::cout <<"3.- TRANSFERENCIA\n";
    std::cout <<"4.- REGISTRO DE OPERACIONES\n";
    std::cout <<"5.- CAMBIAR DE USUARIO\n";
    std::cout <<"6.- SALIR\n";
    std::cout <<"\n";
    std::cout <<"Ingrese una de las opciones disponibles: ";
    std::cin >> opcion;

    switch(opcion){
        case 1:
            funcIngresos();
        break;
        case 2:
            funcGasto();
        break;
        case 3:
            funcTransfe();
        break;
        case 4:
            funcRegistros();
        break;
        case 5:
            funcChangeUser();
        break;
        case 6:
            std::cout <<"Hasta pronto!!"<<std::endl;
        break;

    }

}

int main(){


    return 0;
}


