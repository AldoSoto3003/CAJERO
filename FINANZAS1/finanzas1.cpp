#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <iomanip>

int main();
void menu(),ingreso(),validacionUsuario(),sacarHora(),mostrarTransacciones();
std::string intToString();

// INICIA DECLARACION DE VARIABLES GLOBALES
int noCuenta [3] {123,456,789};
int passCuenta[3] {123,456,789};
int ingresoTotal[3] {};
std::string nombreUsuario[3] = {"Aldo","Ruben","Carlos"}, version{"1.0"};
std::string listaTransacciones[10000]{};
std::string fechaHora{};
int billetera[3]{}, tarjeta[3] {}, ahorro[3] {}, bandera[3] {0,0,0};
int pivote{}, pivoteLista{0};

std::string IntToString(int intValor) {
char *myBuff;
std::string strRetVal;

// Crea nuevo array de caracteres
myBuff = new char[100];

// Pone a myBuff a 0
memset(myBuff,'\0',100);

// Convierte a string
itoa(intValor,myBuff,10);

// Copia myBuff dentro de strRetVal
strRetVal = myBuff;

// Borra myBuff
delete[] myBuff;

//retorna la cadena
return(strRetVal);
}

void menu(){
    int opcion{};
    system("cls");
    std::cout << "Bienvenido a la app FINANZAS PERSONALES Sr. "<< nombreUsuario[pivote] << '\n';
    std::cout << "    \n";
    std::cout << "   \n";
    std::cout <<"       SELECCIONE UNA OPCION:       \n";
    std::cout <<"1.- INGRESO                                                  ||INGRESOS:  |$"<< ingresoTotal[pivote] << '\n'  ;
    std::cout <<"2.- GASTO                                                    ||GASTOS:    |$0.00\n";
    std::cout <<"3.- TRANSFERENCIA                                            ||...........|.....................\n";
    std::cout <<"4.- REGISTRO DE OPERACIONES                                  ||TOTAL:     |$0.00\n";
    std::cout <<"5.- CAMBIAR DE USUARIO\n";
    std::cout <<"6.- SALIR\n";
    std::cout <<"\n";
    std::cout <<"Ingrese una de las opciones disponibles: ";
    std::cin >> opcion;

    switch(opcion){
        case 1:
            ingreso();
        break;

        case 4:
            mostrarTransacciones();
        break;
    }


}

void mostrarTransacciones(){


    if (listaTransacciones[0] == ""){
        std::cout << "No hay transacicones\n";
        system("pause");
        menu();
    }else{
        for (int i=0 ; i<=10000; i++){
            if (listaTransacciones[i] == ""){
                std::cout << "**FIN DE TRANSACCIONES**\n";
                system("pause");
                main();
            }
            std::cout << listaTransacciones[i] << '\n';
        }
    }
      
}

void ingreso(){

    int opcionCategoria{}, opcion2{}, dineroIngreso{};
retornoCategoria:
    system("cls");
    std::cout << "Seleccione categoria:\n";
    std::cout << "                       \n";
    std::cout << "1 .- SUELDO\n";
    std::cout << "2 .- VENTA\n";
    std::cout << "3 .- PRESTAMO\n";
    std::cout << "Ingrese: ";

    std::cin >> opcionCategoria;
    if (opcionCategoria < 1 || opcionCategoria>3){
        std::cout<< "\n";
        std::cout << "Seleccione una opcion valida!\n";
        std::cout<< "\n";
        std::cout << "Vuelva a intentarlo\n";
        std::cout<< "\n";
        system("pause");
        system("cls");
        goto retornoCategoria;
    }

retorno:
    std::cout << "        \n";
    std::cout << "         \n";
    std::cout << "Seleccione donde guardara el ingreso: \n";
    std::cout << "1 .-  BILLETERA\n";
    std::cout << "2 .- TARJETA\n";
    std::cout << "3 .- AHORRO\n";
    std::cout << "Ingrese:   ";

    std::cin >> opcion2;

    if (opcion2 < 1 || opcion2 > 3){
       std::cout<< "\n";
        std::cout << "Seleccione una opcion valida!\n";
        std::cout<< "\n";
        std::cout << "Vuelva a intentarlo\n";
        std::cout<< "\n";
        system("pause");
        system("cls");

        goto retorno;
    }

retornoCuantoGuardar:
    std::cout << "\n";
    std::cout << "Digite el monto a ingresar: ";
    std::cin >> dineroIngreso;

    if (dineroIngreso <= 0){

        std::cout<< "\n";
        std::cout << "Ingrese monto correcto!\n";
        std::cout<< "\n";
        std::cout << "Vuelva a intentarlo\n";
        std::cout<< "\n";
        system("pause");
        system("cls");
        goto retornoCuantoGuardar;
    }

    sacarHora(); //determinamos la fecha y hora a que se está haciendo la transacción

    switch(opcionCategoria){
        case 1:
            if (opcion2 == 1){
                billetera[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: BILLETERA por SUELDO con fecha de: " + fechaHora;
                pivoteLista += 1; 
            }else if (opcion2 == 2){
                tarjeta[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) +  " a: TARJETA por SUELDO con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }else if(opcion2 == 3){
                ahorro[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: AHORROS por SUELDO con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }
            std::cout << "Transaccion dada de alta!\n";
            ingresoTotal[pivote] += dineroIngreso;           
            menu();
        break;

        case 2: 
              if (opcion2 == 1){
                billetera[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: BILLETERA por VENTA con fecha de: " + fechaHora;
                pivoteLista += 1;  
            }else if (opcion2 == 2){
                tarjeta[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: TARJETA por VENTA con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }else if(opcion2 == 3){
                ahorro[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: AHORROS por VENTA con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }
            std::cout << "Transaccion dada de alta!\n";
            ingresoTotal[pivote] += dineroIngreso;
            menu();
        break;

        case 3: 
              if (opcion2 == 1){
                billetera[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: BILLETERA por PRESTAMO con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }else if (opcion2 == 2){
                tarjeta[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: TARJETA por PRESTAMO con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }else if(opcion2 == 3){
                ahorro[pivote] += dineroIngreso;
                listaTransacciones[pivoteLista] = "Ingreso de: " + IntToString(dineroIngreso) + " a: AHORRO por PRESTAMO con fecha de: " + fechaHora; 
                pivoteLista += 1; 
            }
            std::cout << "Transaccion dada de alta!\n";
            ingresoTotal[pivote] += dineroIngreso;
            menu();
        break;

    }
    
}

void validacionUsuario (){
    //variables locales
    system("cls");
    sacarHora();
    int numeroCuenta{}, aux{}, nip {},pivoteaux{}, intentos{};
    aux = 0;
    std::cout<<"Bienvenido a la APP finanzas personales               version: "<<version<<"          fecha y hora: " << fechaHora << '\n';
    std::cout<<""<<'\n';
    std::cout<<""<<'\n';
    std::cout<<""<<'\n';
    std::cout<<"Ingrese su usuario"<<'\n';
    std::cin >> numeroCuenta;

    std::cout<<"Ingrese su contrasenia"<<'\n';
    std::cin >> nip;
    for(int i=0; i <= 3; i+=1){

         if (numeroCuenta == noCuenta[i]){
             pivoteaux = i;
             if(nip == passCuenta[i]){
                 pivote = i;
                 aux = 1;
                 i = 3;
             }
        }
    }

    if (aux == 0){
       std::cout<<"                             "<<'\n';
       std::cout<<"Numero de cuenta y/o password incorrectas"<<'\n';
       intentos++;
       if (intentos == 3){
           std::cout<<"        "<<'\n';
           std::cout<<"Ha superado el limite de intentos"<<'\n';
           std::cout<<"Regrese mas tarde!!"<<'\n';
           bandera[pivoteaux] = 1;
       }
       system("pause");
       validacionUsuario();
   }

    if (bandera[pivote] == 1){
        std::cout << "no se puede acceder "<< '\n'; 
        system("pause");
        validacionUsuario();
    }else{
        menu();
    }

}

void sacarHora(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    auto str = oss.str();

    fechaHora = str;

}



int main(){

    validacionUsuario();

    menu();

    return 0;
}
