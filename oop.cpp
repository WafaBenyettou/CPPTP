//100% ghalet
#include <iostream>
using namespace std;

class Facteur{
    private:
        string name;
        string id;
        int age;
        string geographiczone;

  public:
  //constructor
    Facteur(string name, string id, int age, string geographiczone){
        this->name = name;
        this->id = id;
        this->age = age;
        this->geographiczone = geographiczone;
    }

    //setter and getter
    void setName(string name){
        this->name = name;
    }
    void setId(string id){
        this->id = id;
    }
    void setAge(int age){
        this->age = age;
    }
    void setGeographiczone(string geographiczone){
        this->geographiczone = geographiczone;
    }
    string getName(){
        return name;
    }
    string getId(){
        return id;
    }
    int getAge(){
        return age;
    }
    string getGeographiczone(){
        return geographiczone;
    }

    void distribuer(){
        cout<<"distribuer"<<endl;
    }


   //getting information 
    void getInformation(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Geographic Zone: " << geographiczone << endl;
    }


};

class Habitants{
    private:
    string geographiczone;
    string name;
    int id_habitants;

    public:
    Habitants(string geographiczone, string name, int id_habitants){
        this->geographiczone = geographiczone;
        this->name = name;
        this->id_habitants = id_habitants;
    }
};

class Recommandes{
    
    private:
    string facture_id;
    string destinataire_name;

    public:
    Recommandes(string facture_id, string destinataire_name){
        this->facture_id = facture_id;
        this->destinataire_name = destinataire_name;
    }
   
    void getInformation(){
        cout << "Facture ID: " << facture_id << endl;
        cout << "Destinataire Name: " << destinataire_name << endl;
    }
};

class Letters:public Recommandes{
    public:
    Letters(string facture_id, string destinataire_name):Recommandes(facture_id, destinataire_name){
        cout<<"Letters"<<endl;
    }

};

class Colis:public Recommandes{
    public:
    Colis(string facture_id, string destinataire_name):Recommandes(facture_id, destinataire_name){
        cout<<"Colis"<<endl;
    }

};

int main(){
     Facteur facteur1("Mohamed","123",25,"Alger");
     Habitants habitants1("Alger","Mohamed",123);
     Recommandes recommandes1("123","Mohamed");
     
    recommandes1.getInformation();
       
    system("pause>0");
    return 0;
}
