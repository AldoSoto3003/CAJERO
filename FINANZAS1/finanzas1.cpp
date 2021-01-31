#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <iomanip>

int main(),otraOpcion();
void menu(),ingreso(),validacionUsuario(),sacarHora(),mostrarTransacciones();
void subGastos(), subTransferencias();
std::string intToString();

// INICIA DECLARACION DE VARIABLES GLOBALES
int noCuenta [3] {123,456,789};
int passCuenta[3] {123,456,789};
int gastoAlimentacion[3]{}, gastoEducacion[3]{}, gastoEntretenimiento[3]{},gastoSalud[3]{},gastoTransporte[3]{},gastoOtros[3]{};
int ingresoTotal[3] {}, gastoTotal[3] {};
std::string nombreUsuario[3] = {"Aldo","Ruben","Carlos"}, version{"1.0"};
std::string listaTransacciones[10000]{};
std::string fechaHora{};
int billetera[3]{100,100,100}, tarjeta[3] {100,100,100}, ahorro[3] {100,100,100}, bandera[3] {0,0,0};
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
    gastoTotal[pivote] = gastoAlimentacion[pivote] + gastoEducacion[pivote] + gastoEntretenimiento[pivote] + gastoSalud[pivote] + gastoTransporte[pivote] + gastoOtros[pivote];
    system("cls");
    std::cout << "Bienvenido a la app FINANZAS PERSONALES Sr. "<< nombreUsuario[pivote] << '\n';
    std::cout << "    \n";
    std::cout << "                                                            ||DINERO EN BILLETERA: $" << billetera[pivote] <<'\n';
    std::cout << "                                                            ||DINERO EN TARJETA:   $" << tarjeta[pivote] << '\n';
    std::cout << "                                                            ||DINERO EN AHORROS:   $" << ahorro[pivote] << '\n';
    std::cout <<"       SELECCIONE UNA OPCION:       \n";
    std::cout <<"1.- INGRESO                                                  ||INGRESOS:  |$"<< ingresoTotal[pivote] << '\n'  ;
    std::cout <<"2.- GASTO                                                    ||GASTOS:    |$"<< gastoTotal[pivote] <<'\n';
    std::cout <<"3.- TRANSFERENCIA                                            ||...........|.....................\n";
    std::cout <<"4.- REGISTRO DE OPERACIONES                                  ||TOTAL:     |$"<< ingresoTotal[pivote] - gastoTotal[pivote] <<'\n';
    std::cout <<"5.- CAMBIAR DE USUARIO\n";
    std::cout <<"6.- SALIR\n";
    std::cout <<"\n";
    std::cout <<"Ingrese una de las opciones disponibles: ";
    std::cin >> opcion;

    switch(opcion){
        case 1:
            ingreso();
        break;

        case 2:
            subGastos();
        break;

        case 3:
            subTransferencias();
        break;

        case 4:
            mostrarTransacciones();
        break;

        case 6:
            main();
        break;
    }


}

void mostrarTransacciones(){

    system("cls");

    std::cout << "Total de gastos en ALIMENTOS: $" << gastoAlimentacion[pivote] << '\n';
    std::cout << "Total de gastos en EDUCACION: $" << gastoEducacion[pivote] << '\n';
    std::cout << "Total de gastos en ENTRETENIMIENTO: $" << gastoEntretenimiento[pivote] << '\n';
    std::cout << "Total de gastos en SALUD: $" << gastoSalud[pivote] << '\n';
    std::cout << "Total de gastos en TRANSPORTE: $" << gastoTransporte[pivote] << '\n';
    std::cout << "Total de gastos en OTROS: $" << gastoOtros[pivote] << '\n';

    if (listaTransacciones[0] == ""){
        std::cout << "No hay transacicones\n";
        system("pause");
        menu();
    }else{
        std::cout << "Transacciones generadas hasta el dia y hora: " + fechaHora << '\n';
        for (int i=0 ; i<=10000; i++){
            if (listaTransacciones[i] == ""){
                std::cout << "**FIN DE TRANSACCIONES**\n";
                system("pause");
                menu();
            }
            std::cout << listaTransacciones[i] << '\n';
        }
    }
      
}

void ingreso(){

    int opcionCategoria{}, opcion2{};
    int dineroIngreso{};
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
           ingresoTotal[pivote]  += dineroIngreso;         
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
             ingresoTotal[pivote]  += dineroIngreso;  
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
             ingresoTotal[pivote]  += dineroIngreso;  
            system("pause");
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
        ingresoTotal[pivote] = billetera[pivote] + tarjeta[pivote] + ahorro[pivote];
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

void subGastos(){
    system("cls");
    int opcionCategoria{},opcionPago{};
    int dineroGasto{};
    std::string otroGastoDescrip{};

    std::cout << "Seleccione categoria gasto:  \n";
    std::cout << "1.- ALIMENTACION \n";
    std::cout << "2.- EDUCACION \n";
    std::cout << "3.- ENTRETENIMIENTO \n";
    std::cout << "4.- SALUD  \n";
    std::cout << "5.- TRANSPORTE \n";
    std::cout << "6.- OTROS \n";
    std::cout << "Ingrese: ";

    std::cin >> opcionCategoria;
    if (opcionCategoria < 1 || opcionCategoria >6){
        std::cout << "Ingrese opcion valida!!\n";
        std::cout << "\n";
        std::cout << "vuelva a intentarlo\n";
        subGastos();
    }
retornoMetodoPago:
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Seleccione metodo de pago: \n";
    std::cout << "1.- BILLETERA\n";
    std::cout << "2.- TARJETA\n";
    std::cout << "3.- AHORROS\n";
    std::cout << "Ingrese: ";
    std::cin >> opcionPago;

    if (opcionPago < 1 || opcionPago > 3){
        std::cout << "Ingrese opcion valida!!\n";
        std::cout << "\n";
        std::cout << "vuelva a intentarlo\n";
        system("pause");
        system("cls");
        goto retornoMetodoPago;
    }
retornoDigiteGasto:
    std::cout << "\n";
    std::cout << "Ingrese monto gastado: $";
    std::cin >> dineroGasto;
    if (dineroGasto <= 0 ){
        std::cout << "La cantidad no puede ser menor o igual que 0\n";
        std::cout << "Vuelva a intentarlo\n";
        system("pause");
        system("cls");
        goto retornoDigiteGasto;
    }else if(billetera[pivote] < dineroGasto || tarjeta[pivote] < dineroGasto || ahorro[pivote] < dineroGasto){
        std::cout << "monto incorrecto: tu gasto no puede ser mayor que tus ingresos\n";
        std::cout << "Vuelva a intentarlo\n";
        system("pause");
        system("cls");
        goto retornoDigiteGasto;
    }

    switch (opcionCategoria){
        case 1:
            if (opcionPago == 1){
                billetera[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por ALIMENTOS con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else if(opcionPago == 2){
                tarjeta[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: TARJETA por ALIMENTOS con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else{
                ahorro[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: AHORROS por ALIMENTOS con fecha de: " + fechaHora;
                pivoteLista += 1;
            }
            gastoAlimentacion[pivote] += dineroGasto;
        break;

        case 2:
            if (opcionPago == 1){
                billetera[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por EDUCACION con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else if(opcionPago == 2){
                tarjeta[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: TARJETA por EDUCACION con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else{
                ahorro[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: AHORROS por EDUCACION con fecha de: " + fechaHora;
                pivoteLista += 1;
            }
            gastoEducacion[pivote] += dineroGasto;
        break;

        case 3:
            if (opcionPago == 1){
                billetera[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por ENTRETENIMIENTO con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else if(opcionPago == 2){
                tarjeta[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: TARJETA por ENTRETENIMIENTO con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else{
                ahorro[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: AHORROS por ENTRETENIMIENTO con fecha de: " + fechaHora;
                pivoteLista += 1;
            }
            gastoEntretenimiento[pivote] += dineroGasto;
        break;

        case 4:
            if (opcionPago == 1){
                billetera[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por SALUD con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else if(opcionPago == 2){
                tarjeta[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: TARJETA por SALUD con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else{
                ahorro[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: AHORROS por SALUD con fecha de: " + fechaHora;
                pivoteLista += 1;
            }
            gastoSalud[pivote] += dineroGasto;
        break;

        case 5:
            if (opcionPago == 1){
                billetera[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por TRANSPORTE con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else if(opcionPago == 2){
                tarjeta[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: TARJETA por TRANSPORTE con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else{
                ahorro[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: AHORROS por TRANSPORTE con fecha de: " + fechaHora;
                pivoteLista += 1;
            }
            gastoTransporte[pivote] += dineroGasto;
        break;

        case 6:
            std::cout <<"\n";
            std::cout << "Ingrese breve descripcion del tipo de gastos: ";
            std::cin >> otroGastoDescrip;
             if (opcionPago == 1){
                billetera[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por " + otroGastoDescrip + "con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else if(opcionPago == 2){
                tarjeta[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por " + otroGastoDescrip + "con fecha de: " + fechaHora;
                pivoteLista += 1;
            }else{
                ahorro[pivote] -= dineroGasto;
                listaTransacciones[pivoteLista] = "Gasto de: " + IntToString(dineroGasto) + " en: BILLETERA por " + otroGastoDescrip + "con fecha de: " + fechaHora;
                pivoteLista += 1;
            }
            gastoOtros[pivote] += dineroGasto;
        break;
    }
    

menu();

}

void subTransferencias(){

    int opcionOrigen{}, opcionDestino{},dineroTrasnf{};

    system("cls");
    std::cout << "Seleccione origen del dinero: \n";
    std::cout << "1.- BILLETERA \n";
    std::cout << "2.- TARJETA \n";
    std::cout << "3.- AHORRO \n";
    std::cin >> opcionOrigen;
    if (opcionOrigen <1 || opcionOrigen > 3){
        std::cout << "Debe ingresar una de las opciones correctas!\n";
        std::cout << "vuelva a intentarlo!\n";
        subTransferencias();
    }

    std::cout << "Seleccione destino del dinero: \n";
    std::cout << "1.- BILLETERA \n";
    std::cout << "2.- TARJETA \n";
    std::cout << "3.- AHORRO \n";
    std::cin >> opcionDestino;
    if (opcionDestino <1 || opcionDestino > 3){
        std::cout << "Debe ingresar una de las opciones correctas!\n";
        std::cout << "vuelva a intentarlo!\n";
        menu();
    }

    if (opcionOrigen == opcionDestino){
        std::cout << "No se puede transferir a la misma cuenta!! \n";
        std::cout << "Intentelo de nuevo!\n";
        system("pause");
        system("cls");
         menu();
    }
retornoDigiteMonto:
    std::cout << "\n";
    std::cout << "Ingrese monto a transferir: $";
    std::cin >> dineroTrasnf;

    if (dineroTrasnf <= 0){
        std::cout << "Digite una cantidad mayor que 0! \n";
        std::cout << "vuelva a intentarlo!\n";
        system("pause");
        system("cls");
        goto retornoDigiteMonto;
    }

    switch (opcionOrigen){
        case 1: 
            if(dineroTrasnf > billetera[pivote]){
                std::cout << "Fondos insuficientes!\n";
                system("pause");
                menu();
            }
        break;

        case 2: 
            if(dineroTrasnf > tarjeta[pivote]){
                std::cout << "Fondos insuficientes!\n";
                system("pause");
                menu();
            }
        break;

        case 3: 
            if(dineroTrasnf > ahorro[pivote]){
                std::cout << "Fondos insuficientes!\n";
                system("pause");
                menu();
            }
        break;
    }

    switch (opcionOrigen){
        case 1:
            if (opcionDestino == 2){
                tarjeta[pivote] += dineroTrasnf;
                billetera[pivote] -= dineroTrasnf;
            }else{
                ahorro[pivote] += dineroTrasnf;
                billetera[pivote] -= dineroTrasnf;
            }
        break;

        case 2:
            if (opcionDestino == 1){
                billetera[pivote] += dineroTrasnf;
                tarjeta[pivote] -= dineroTrasnf;
            }else{
                ahorro[pivote] += dineroTrasnf;
                tarjeta[pivote] -= dineroTrasnf;
            }
        break;

        case 3:
            if (opcionDestino == 1){
                billetera[pivote] += dineroTrasnf;
                ahorro[pivote] -= dineroTrasnf;
            }else{
                tarjeta[pivote] += dineroTrasnf;
                ahorro[pivote] -= dineroTrasnf;
            }
        break;
    }
menu();
}

int otraOpcion(){
    int opcion {};
    system("cls");
    std::cout << "                 " << '\n';
    std::cout << "desea realizar otra opcion ?" << '\n';
    std::cout << "1.- SI    2.- NO"<< '\n';
    std::cin >> opcion;

    if (opcion == 1){
        menu();
    }else if (opcion == 2){
        validacionUsuario();
    }else{
        std::cout << "Opcion no valida " << '\n';
        std::cout << "Vuelva a intentarlo " << '\n'; 
        otraOpcion();
    }
    system("pause");
    return 0;
}

int main(){

    validacionUsuario();

    menu();

    return 0;
}
