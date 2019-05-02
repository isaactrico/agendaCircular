#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>


using namespace std;

class Nodo{
  public:
    int id;
    string mail, phone, address, name;


  public:
    Nodo* next;

    Nodo(){
    };

    Nodo(int id, string mail, string phone, string address, string name){
      this->id = id;
      this->mail = mail;
      this->phone = phone;
      this->address = address;
      this->name = name;
      this->next = NULL;
    };

    string toString(){
      stringstream ss;
      ss<<"ID: "<<id<<endl;
      ss<<"Mail: "<<mail<<endl;
      ss<<"Phone: "<<phone<<endl;
      ss<<"Address: "<<address<<endl;
      ss<<"Name: "<<name<<endl;
      std::cout << "\n\n" << '\n';

      return ss.str();

    }

    void setId(int id){
      this->id = id;
    }

    void setMail(string mail){
      this->mail = mail;
    }

    void setPhone(string phone){
      this->phone = phone;
    }

    void setAddress(string address){
      this->address = address;
    }

    void setName(string name){
      this->name = name;
    }

    int getId(){
      return this->id;
    }
    string getMail(){
      return this->mail;
    }
    string getPhone(){
      return this->phone;
    }
    string getAddress(){
      return this->address;
    }
    string getName(){
      return this->name;
    }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Agenda{
  private:
    Nodo *frente = NULL;
  	Nodo *fin = NULL;


  public:

    bool cola_vacia(Nodo *frente){
    	return (frente == NULL);
    };

    void add(int id, string mail, string phone, string address, string name){

      Nodo *nuevo_nodo = new Nodo( id,  mail,  phone,  address,  name);

    	nuevo_nodo->next = NULL;

    	if(cola_vacia(frente)){
    		frente = nuevo_nodo;
    	}
    	else{
    		fin->next = nuevo_nodo;
    	}

    	fin = nuevo_nodo;
      nuevo_nodo->next = frente;
    };




    Nodo* localizaName(string name){
      Nodo* aux = frente;
      do{
        if(aux->name == name)
          return aux;
        aux = aux->next;
      }while(aux != frente);
      return NULL;
    }

    Nodo* localizaPos(int pos){
      int index = 0;
      Nodo* aux = frente;
      do{
        if(index == pos)
          return aux;
        index++;
        aux = aux->next;
      }while(aux != frente);
      return NULL;
    }

    Nodo* anterior(Nodo* n){
      Nodo* aux = frente;
      while(aux->next != NULL){
        if(aux->next == n){
          return aux;
        }
        aux = aux->next;
      }
      return NULL;
    }

    void eliminar(Nodo* e){
      if(e){

        Nodo* temp = e;
        while(temp != frente){
          temp->id--;
          temp=temp->next;
        }

        if(e == frente){
          frente = frente->next;
          fin->next = frente;
        }else{
          if(fin == e)
            fin = anterior(e);
          anterior(e)->next = e->next;
        }
        delete(e);


      }
    }

    void deleteAll(){
      frente=NULL;
      fin=NULL;
    }


    void mostrarTodo(){
        Nodo* temp = frente->next;
        do{
          cout<<temp->toString()<<endl;
          temp=temp->next;
        }while(temp!=frente->next);
    }

    void edit(Nodo* nodo){
      int id, op;
      string mail, phone, address, name;

      do {
        fflush(stdin);
        cout<<"\n ------MENU DE EDICION-------"
        "\n -Elige el campo a modificar-"
        "\n 1.- Mail"
        "\n 2.- Telefono"
        "\n 3.- Direccion"
        "\n 4.- Nombre"
        "\n 0.- Salir"<<endl;
        cout<<"\nIngrese el campo que desea modificar: "<<endl;
        cin>>op;

        switch (op) {
          case 0:
          cout<<"\nEdicion finalizada"<<endl;
          break;

          case 1:{
            fflush(stdin);
            string mail;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, mail);
            nodo->setMail(mail);
          }
          break;

          case 2:{
            fflush(stdin);
            string phone;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, phone);
            nodo->setPhone(phone);
          }
          break;

          case 3:{
            fflush(stdin);
            string address;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, address);
            nodo->setAddress(address);
          }
          break;

          case 4:{
            fflush(stdin);
            string name;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, name);
            nodo->setName(name);
          }
          break;

          default: cout<<"\n Opcion no disponible"<<endl;
        }
      } while(op!=0);
    }


};

int menu(){
  int opc;
  cout<<"\n 1.- Dar de Alta"


  "\n 2.- Buscar"

  "\n 3.- Editar"

  "\n 4.- Borrar Contacto"

  "\n 5.- Mostrar Agenda"

  "\n 6.- Borrar Agenda"

  "\n 0.- Salir"<<endl;
  cin>>opc;

  return opc;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
  Agenda A;
  int opc, cont=0;

  do {

    opc = menu();

    switch (opc) {
      case 0:
        std::cout << "\nCerrando Agenda" << '\n';
      break;

      case 1:{
        int id;
        string mail, phone, address, name;

        fflush(stdin);

        std::cout << "\n Se ha asignado el ID: " <<cont<< '\n';
        id = cont;
        cont++;

        cout<<"\nIngrese el E-mail de su nuevo contacto: "<<endl;
        getline(cin, mail);

        cout<<"\nIngrese el Telefono de su nuevo contacto"<<endl;
        getline(cin, phone);

        cout<<"\nIngrese la Direccion de su nuevo contacto"<<endl;
        getline(cin, address);

        cout<<"\nIngrese el Nombre de su nuevo contacto"<<endl;
        getline(cin, name);

        A.add(id, mail, phone, address, name);

      }

      break;

      case 2:{

        int searchBy;
        cout<<"\n1.- Buscar por Posicion"
              "\n2.- Buscar por Nombre"<<endl;
        cin>>searchBy;

        switch (searchBy) {
          case 1:{
            int ind;
            cout<<"\nIngresa la posicion a buscar:"<<endl;
            cin>>ind;

            if(A.localizaPos(ind)){
              cout<<"\nEncontramos: \n"<<A.localizaPos(ind)->toString();
            }else{
              std::cout << "\nNo encontramos coincidencia alguna para la posicion proporcionada" << '\n';
            }
          }
          break;

          case 2:{
            string name;

            fflush(stdin);
            cout<<"\nIngrese el Nombre del contacto"<<endl;
            getline(cin, name);

            if(A.localizaName(name)){
              cout<<A.localizaName(name)->toString()<<endl;
            }else{
              std::cout << "\nNo encontramos resultados satisfactorios" << '\n';
            }
          }
          break;

          default: std::cout << "\nOpcion no disponible" << '\n';
        }

      }

      break;

      case 3:{

        int searchBy;
        cout<<"\n1.- Editar por Posicion"
              "\n2.- Editar por Nombre"<<endl;
        cin>>searchBy;

        switch (searchBy) {
          case 1:{
            int ind;
            cout<<"\nIngresa la posicion a editar:"<<endl;
            cin>>ind;

            if(A.localizaPos(ind)){
              cout<<"\nEncontramos: \n"<<A.localizaPos(ind)->toString();
              A.edit(A.localizaPos(ind));
            }else{
              std::cout << "\nNo encontramos coincidencia alguna para la posicion proporcionada" << '\n';
            }

          }
          break;

          case 2:{
            string name;

            fflush(stdin);
            cout<<"\nIngrese el Nombre del contacto que desea editar"<<endl;
            getline(cin, name);

            if(A.localizaName(name)){
              cout<<"\nEncontramos: "<<A.localizaName(name)->toString()<<endl;
              A.edit(A.localizaName(name));
            }else{
              std::cout << "\nNo encontramos resultados satisfactorios" << '\n';
            }
          }
          break;

          default: std::cout << "\nOpcion no disponible" << '\n';
        }

      }
      break;

      case 4:{

        int searchBy;
        cout<<"\n1.- Eliminar por Posicion"
              "\n2.- Eliminar por Nombre"<<endl;
        cin>>searchBy;

        switch (searchBy) {
          case 1:{
            int ind;
            cout<<"\nIngresa la posicion a eliminar:"<<endl;
            cin>>ind;

            if(A.localizaPos(ind)){
              cout<<"\nEliminando: \n"<<A.localizaPos(ind)->toString();
              A.eliminar(A.localizaPos(ind));
              cont--;
            }else{
              std::cout << "\nNo encontramos coincidencia alguna para la posicion proporcionada" << '\n';
            }
          }
          break;

          case 2:{
            string name;

            fflush(stdin);
            cout<<"\nIngrese el Nombre del contacto"<<endl;
            getline(cin, name);

            if(A.localizaName(name)){
              cout<<"\nEliminando: \n"<<A.localizaName(name)->toString()<<endl;
              A.eliminar(A.localizaName(name));
              cont--;
            }else{
              std::cout << "\nNo encontramos resultados satisfactorios" << '\n';
            }
          }
          break;

          default: std::cout << "\nOpcion no disponible" << '\n';
        }
      }
      break;

      case 5:{
        A.mostrarTodo();
      }
      break;

      case 6:
        A.deleteAll();
      break;

      default: std::cout << "\nOpcion no disponible" << '\n';
    }

  } while(opc!=0);

};
