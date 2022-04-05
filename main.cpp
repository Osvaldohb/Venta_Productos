#include <iostream>
#include <conio.h>
#include "cordenadas.h"

using namespace std;

void entrada(int lim);
void reavas(int lim);
void titulos();
void consulta(int lim);
void venta(int lim);
void cambiarP(int lim);

struct Productos
{
    int cla,exi,min;
    string des;
    float Pu;
};
Productos articulo[' '];

main()
{
    char res;
    int cant;

    do
    {
        char Seleccion;

            gotoxy(10,5) ;cout<<"a) Entrada de productos"<<endl;
            gotoxy(10,6); cout<<"b) Venta de producto"<<endl;
            gotoxy(10,7);cout<<"c) Reavastecimiento de un producto"<<endl;
            gotoxy(10,8); cout<<"d) Actualizacion de precio"<<endl;
            gotoxy(10,9);cout<<"e) Consulta sobre un producto"<<endl;
            gotoxy(10,10);cout<<"----->";  
            cin>>Seleccion;

            switch (Seleccion)
            {
            case 'a':
                 system("cls");
                   gotoxy(10,5);cout<<"Cuantos productos?"<<endl;
                    gotoxy(10,6); cin>>cant;
                  system("cls");
                entrada(cant);
                break;
            case 'b':
                system("cls");
                venta(cant);
                break;
            case 'c':
                 system("cls");
                reavas(cant);
                break;
                case 'd':
                 system("cls");
                cambiarP(cant);
                break;
                case 'e':
                 system("cls");
                consulta(cant);
                break;
            default:
                 system("cls");
                cout<<"No existe la opcion seleccionada"<<endl;
                break;
            }

        cout<<"Deseas repetir alguna accion s/n: "<<endl;
        cin>>res;
        system("cls");
    } while (res=='s');
    

}

void entrada(int lim)
{

    int x;
    for(x=0;x<lim;x++)
    {
        titulos();
          gotoxy(8,6);cin>>articulo[x].cla;
          gotoxy(25,6);cin>>articulo[x].des; 
          gotoxy(54,6);cin>>articulo[x].exi;
          gotoxy(69,6);cin>>articulo[x].min;
          gotoxy(98,6);cin>>articulo[x].Pu;
           cout<<"\n";
           system("cls");
    }
    
}

void titulos()
{
    gotoxy(8,5);cout<<"Clave producto:";
 gotoxy(25,5); cout<<"Descripcion del Producto:";
  gotoxy(54,5);cout<<"Existencia:"<<endl;
   gotoxy(69,5); cout<<"Minimo de existencia:"<<endl;
    gotoxy(98,5);  cout<<"Precio unitario:"<<endl;
}

void reavas(int lim)
{
     int x,cl;
     cout<<"Ingresa la clave del producto:";
     cin>>cl;
    for(x=0;x<lim;x++)
    {
        if(cl==articulo[x].cla)
        {
            gotoxy(10,5); cout<<"Ingresa la nueva existencia:"<<endl;
             gotoxy(10,6);cin>>articulo[x].exi;
            gotoxy(10,7); cout<<"Cambio realizado con exito!"<<endl;
            cout<<"\n";
        }
    }
}

void consulta(int lim)
{
    int x,cla;
    cout<<"Porfavor ingresa la clave del producto"<<endl;
    cin>>cla;
    titulos();
    for(x=0;x<lim;x++)
    {
        if(cla==articulo[x].cla)
        {
            gotoxy(8,6);cout<<articulo[x].cla;
          gotoxy(25,6);cout<<articulo[x].des; 
          gotoxy(54,6);cout<<articulo[x].exi;
          gotoxy(69,6);cout<<articulo[x].min;
          gotoxy(98,6);cout<<articulo[x].Pu;
          cout<<"\n";
        }
    }
    cout<<"\n";

}

void venta(int lim)
{
    int pd,can,x,ac;
    char dec;
    string nombres[lim];
    float sp,tp;

     gotoxy(10,5);cout<<"Porfavor ingrese su numero de producto y la cantidad a comprar"<<endl;
    do
    {
          gotoxy(10,6);cout<<"Clave del producto:"<<endl;
         gotoxy(10,7);cin>>pd;
        gotoxy(10,8);cout<<"Cantidad a comprar"<<endl;
        gotoxy(10,9);cin>>can;

    for(x=0;x<lim;x++)
    {
       
        if(articulo[x].cla==pd)
        {
         if(articulo[x].exi>=can)
          {
                nombres[x]=articulo[x].des;
                sp=articulo[x].Pu*can;
                articulo[x].exi=articulo[x].exi-can;
                ac=x;
                
           }
           else{
               cout<<"Lo sentimos no tenemos el suficiente stock"<<endl;
           }
        }
        tp=tp+sp;
        sp=0;
        system("cls");
    }
    cout<<"Deseas seguir comprando otro producto? s/n: "<<endl;
        cin>>dec;
     } while (dec=='s');

    cout<<"Esta es tu lista de productos comprados:"<<endl;
    for(string y:nombres)
    {
        cout<<y<<endl;
    }
  gotoxy(40,7);  cout<<"El total a pagar es de:"<<endl;
  gotoxy(40,8);  cout<<tp<<endl;
    cout<<"\n";
}

void cambiarP(int lim)
{
     int x,cl;
     cout<<"Ingresa la clave del producto:";
     cin>>cl;
    for(x=0;x<lim;x++)
    {
        if(cl==articulo[x].cla)
        {
            gotoxy(10,5); cout<<"Ingresa el nuevo precio:"<<endl;
             gotoxy(10,6);cin>>articulo[x].Pu;
            gotoxy(10,7); cout<<"Cambio realizado con exito!"<<endl;
            cout<<"\n";
        }
    }
}