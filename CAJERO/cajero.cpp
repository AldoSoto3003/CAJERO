#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>

  //empiezo declaración de variables goblaes
    std::string version {"1.0"};
    std::string nombres[3] = {};
    int noCuenta[3] = {};
    int passCuenta[3] = {}; 
    int bandera[3] ={0,0,0};
    double fondoCuenta[3] = {};
    int key{}, aux {0}, pivote {}, opcion{}, intentos{};
    int menu(),login(),trasnferencia(), retiro(), consultaDeSaldo(),changeNip();
    void leer(),guardar();      
  //Termino declaración de 1varaibles globales  

int otraOpcion(){
    system("cls");
    std::cout << "                 " << '\n';
    std::cout << "desea realizar otra opcion ?" << '\n';
    std::cout << "1.- SI    2.- NO"<< '\n';
    std::cin >> opcion;

    if (opcion == 1){
        menu();
    }else if (opcion == 2){
        login();
    }else{
        std::cout << "Opcion no valida " << '\n';
        std::cout << "Vuelva a intentarlo " << '\n'; 
        otraOpcion();
    }
    system("pause");
    return 0;
}

int deposito(){
    system("cls");
    int monto{};

    std::cout<<"Ingrese la cantidad a depositar: ";
    std::cin>>monto;

    if (monto<=0){
        std::cout<<"La cantidad debe ser mayor que 0"<<'\n';
    }else{
        fondoCuenta[pivote] += monto;
        std::cout<<"El deposito fue realizado con exito!"<< '\n';
    }
    system("pause");
    otraOpcion();
    return 0;
}
int changeNip(){
    int nipActual{}, nuevoNip1{}, nuevoNip2{}, flag{};

    system("cls");

    std::cout << "Ingrese su nip actual: ";
    std::cin >> nipActual;
    
    if (nipActual == passCuenta[pivote]){
        while (flag == 0){
        std::cout << "Ingrese nuevo nip: " ;
        std::cin >> nuevoNip1;
        std::cout << "Confirme nuevo nip: ";
        std::cin >> nuevoNip2;
        if (nuevoNip1 == nuevoNip2){
            passCuenta[pivote] = nuevoNip1;
            std::cout << "El nip ha sido cambiado con exito!" << '\n';
            flag = 1;
        }else{
            std::cout << "El nuevo nip no coincide con la confirmación" << '\n';
            std::cout << "Intente de nuevo" << '\n';           
        }
      }    
    }else{
        std::cout << "No coincide su nip actual "<< '\n';
    }
   system("pause");
   otraOpcion();
    return 0;
}  

int login (){
    //variables locales
    system("cls");
    int numeroCuenta{}, nip {},pivoteaux{};
    aux = 0;
    std::cout<<"Bienvenido al cajero BBVA                          version: "<<version<<'\n';
    std::cout<<""<<'\n';
    std::cout<<""<<'\n';
    std::cout<<""<<'\n';
    std::cout<<"Ingrese su numero de cuenta"<<'\n';
    std::cin >> numeroCuenta;

    std::cout<<"Ingrese su nip"<<'\n';
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
       login();
   }

    if (bandera[pivote] == 1){
        std::cout << "no se puede acceder "<< '\n'; 
        system("pause");
        login();
    }else{
        menu();
    }

    return 0;
}

int consultaDeSaldo(){

    system("cls");
    std::cout <<"su saldo actualmente es de: " << fondoCuenta[pivote] << '\n';
    system("pause");
    otraOpcion();
   
    menu();
    return 0;
}

int retiro(){
    double montoRetirar {};

    std::cout <<" ingrese el monto a retirar: " << '\n';
    std::cin >> montoRetirar;

    if (montoRetirar<=0 ){
        std::cout << "No es posiblo retirar dicha cantidad" << '\n';
        system("cls");
        otraOpcion();
    }

    if (montoRetirar > fondoCuenta[pivote]){
        std::cout << "Fondos insufucientes" << '\n';
    }else{ 
        fondoCuenta[pivote] -= montoRetirar;
        system("cls");
        std::cout << "Retiro realizado con exito! " << '\n';
    }
    system("pause");
    otraOpcion();
        
    return 0;
}

int trasnferencia(){
    double montoTransferir{};
    int cuentaTransferir {}, pivote2{}, aux2{}, flag{0};
    system("cls");
    std::cout << "Ingrese numero de cuenta a transferir " << '\n';
    std::cin >> cuentaTransferir;

    for(int i=0; i <= 3; i+=1){

         if (cuentaTransferir == noCuenta[i]){           
                 flag = 1;
        }
    }

    if(cuentaTransferir == noCuenta[pivote]){
        std::cout << "No se puede transferir a su misma cuenta" << '\n';
        system("pause");
        menu();
    }else if(flag == 0){
        std::cout << "No se encontró cuenta para transferir" << '\n';
        system("pause");
        menu();
    }

    for(int i = 0; i < 3; i+=1){
        if (cuentaTransferir == noCuenta[i]){
            pivote2 = i;
            std::cout << "Ingrese monto a transferir ";
            std::cin >> montoTransferir;

            if (montoTransferir <= fondoCuenta[pivote]){
                fondoCuenta[pivote] -= montoTransferir;
                fondoCuenta[pivote2] += montoTransferir;
                std::cout << "transferencia realizada con exito!"<<'\n';
            }else if (montoTransferir > fondoCuenta[pivote]){
                std::cout << "Fondos insuficientes" << '\n';
            }
            
        }else if (i == 3){
            std::cout << "Ingrese un numero de cuenta valido "<< '\n';      
            i=4;   
        }
    }
    system("pause");
    otraOpcion();
    return 0;
}


int menu(){
    system("cls");
    std::cout << "Bienvenido Sr. "<< nombres[pivote] << '\n';
    std::cout<<""<<'\n';
    std::cout<<""<<'\n';
     //Menú del programa 
    std::cout<<"Seleccione la opcion que desea realizar:"<<'\n';
    std::cout<<"1.- consulta de saldo "<< '\n';
    std::cout<<"2.- retiro "<< '\n';
    std::cout<<"3.- deposito "<< '\n';
    std::cout<<"4.- transferencia "<< '\n';
    std::cout<<"5.- cambio de nip "<< '\n';
    std::cout<<"6.- cerrar sesion"<< '\n';
    std::cout<<"7.- SALIR" << '\n';

    std::cin >> key;
    
    //en el siguiente ciclo, valido que entre una opcion permitida
    //de lo contrario, que vuelva a ingresar una opción
    while((key <= 0) or (key >=8)){
        std::cout<<"Debe eligir una de las opciones validas"<<'\n';
        std::cin >> key;
    }
    
    switch (key){
        case 1:
            consultaDeSaldo();
            
            if (opcion == 1 )
                 menu();
            else
                login();  

        break;
       
        case 2:

            retiro();

            if (opcion == 1 )
                menu();
            else
                login();  

        break;
        case 3:
            deposito();
           
            
        break;
        case 4:

             trasnferencia();

            if (opcion == 1 )
                menu();
            else
                login();
        break;
        case 5:
            changeNip();

            if (opcion == 1 )
                menu();
            else
                login();
        break;

        case 6:
            login();

        break;
        
        case 7:
            guardar();
            exit(1);
        break;
  
    }
    return 0;
}

int main(){

    leer();

    system ("cls"); 
    login(); //Aqui llamo a la funcion que se encarga de verificar las credenciales del usuario
    
   
    getch();
    return 0 ;
}

void leer(){
  int aux{1};
  std::fstream archivo;
  archivo.open("datosCajero.txt",std::ios::in);
  std::string linea;
  while (getline(archivo,linea)){
      if (aux == 1){
          nombres[0] = linea;
          aux++;
      }else if(aux == 2){
          noCuenta[0] = atoi(linea.c_str());
          aux++;
      }else if (aux ==3){
          passCuenta[0] = atoi(linea.c_str());
          aux++;
      }else if (aux == 4){
          fondoCuenta[0] = atoi(linea.c_str());
          aux++;
      }else if (aux == 5){
          nombres[1] = linea;
           std::cout << atoi(linea.c_str()) << '\n';
          system("pause");
          aux++;
      }else if(aux == 6){
          noCuenta[1] = atoi(linea.c_str());
          std::cout << atoi(linea.c_str()) << '\n';
          system("pause");
          aux++;
      }else if (aux ==7){
          passCuenta[1] = atoi(linea.c_str());
          aux++;
      }else if (aux == 8){
          fondoCuenta[1] = atoi(linea.c_str());
          aux++;
      }else if (aux == 9){
          nombres[2] = linea;
          aux++;
      }else if(aux == 10){
          noCuenta[2] = atoi(linea.c_str());
          aux++;
      }else if (aux ==11){
          passCuenta[2] = atoi(linea.c_str());
          aux++;
      }else if (aux == 12){
          fondoCuenta[2] = atoi(linea.c_str());
      }
}
}

void guardar(){
    std::cout<<""<<std::endl;
    std::string linea;
    std::ofstream archivo;
    archivo.open("D://Semester 3//PROGRAMACION II RECURSAMIENTO//EJERCICIOS//CAJERO//datosCajero.txt", std::ios::out);

    if (archivo.fail()){
        std::cout << "El archivo no se pudo abrir"<<'\n';
        system("pause");
    }

    archivo << nombres[0] + '\n';
    archivo << noCuenta[0] + '\n';
    archivo << passCuenta[0]+ '\n';
    archivo << fondoCuenta[0]+ '\n';
    archivo << nombres[1]+ '\n';
    archivo << noCuenta[1]+ '\n';
    archivo << passCuenta[1]+ '\n';
    archivo << fondoCuenta[1]+ '\n';
    archivo << nombres[2]+ '\n';
    archivo << noCuenta[2]+ '\n';
    archivo << passCuenta[2]+ '\n';
    archivo << fondoCuenta[2]+ '\n';


}