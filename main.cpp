#include <iostream>
#include <string>
#include <vector>

class Aplicant{
private:

std::string nume;
int varsta;
bool practicant;
int experienta;//luni in cadrul clubului
//int grupa;//nivel de experienta

public:
    Aplicant()=default;
    Aplicant(const std::string& nume_, const int varsta_, bool practicant, const int experienta_) :
        nume{nume_}, varsta{varsta_}, practicant{practicant}, experienta{experienta_}
        {
            std::cout<<"Con de in! \n";
        }
    Aplicant(const Aplicant& other) :
        nume{other.nume}, varsta{other.varsta}, practicant{other.practicant}, experienta{other.experienta}
        {
            std::cout<<"Cc ! \n";
        }
    Aplicant& operator=(const Aplicant& other){
        std::cout<<"Oper = de copi! \n";
       nume=other.nume;
       varsta=other.varsta;
       practicant=other.practicant;
       experienta=other.experienta;
       return *this;
    }
    bool getPracticant() const{return practicant;}
    int getXP() const {return experienta;}


    virtual ~Aplicant();
    virtual void afisare(std::ostream &out);
    virtual void citire(std::istream &in);

    friend std :: ostream& operator<<(std :: ostream& out, Aplicant&);
    friend std :: istream& operator>>(std :: istream& in, Aplicant&);


};

Aplicant :: ~Aplicant(){
    nume = "";
    varsta;
    practicant;
    experienta;
}

    std::istream& operator>>(std::istream& in, Aplicant& apl){
    apl.citire(in);
    return in;
    }


    void Aplicant::citire(std::istream &in) {
    std::cout<<"\n"<<"  Bine ati venit in dojo-ul nostru!"<<" \n"<<"  Va rugam sa va introduceti datele: " << "\n";
    std::cout<<"Nume :";
    in>>nume;
    std::cout<<"Varsta :";
    in>>varsta;
    std::cout<<"Practicant :";
    in>>practicant;
    std::cout<<"Experienta :";
    in>>experienta;
}

    std::ostream& operator<<(std::ostream& out, Aplicant& apl){
       apl.afisare(out);
       return out;
}

   void Aplicant::afisare(std::ostream &out){
       out<<"Numele : "<<nume<< "\n";
       out<<"Varsta :"<<varsta<<"\n";
       if(practicant)
        out<<"Practicant : DA \n";
       else
        out<<"Practicant : NU \n";

       out<<"Experienta :"<<experienta<<" luni \n";
}




class Student : public Aplicant{
protected:
    int grupa;
public:
    Student(std :: string, int, bool, int, int);
    ~Student();
    Student(const Student&);

    void afisare(std :: ostream &out) override;
    void citire(std::istream &in) override;

    friend std::ostream& operator<<(std :: ostream& out, Student&);
    friend std::istream& operator>>(std :: istream& in, Student&);

};

Student::Student(const std::string nume, const int varsta, bool practicant, const int experienta, int grupa) : Aplicant(nume,varsta,practicant,experienta) {
    this->grupa=grupa;
}

Student :: ~Student(){
    grupa=0;
}

void Student ::citire(std::istream &in){
    Aplicant ::citire(in);
    int a=getPracticant();
        if(a==0)
            grupa=1;
        else{
                int b=getXP();
            if(b>=1 && b<=3)
                grupa=1;
            if(b>=4 && b<=8)
                grupa=2;
            if(b>=9)
                grupa=3;
        }

    std::cout<<"Ati fost repartizat in grupa: "<<grupa<<" !\n";

}
std::istream& operator>>(std::istream &in, Student& stu){
    stu.citire(in);
    return in;
}

void Student ::afisare(std::ostream &out) {
    Student :: afisare(out);
    out<<"Ati fost repartizat in grupa : " <<grupa<< "\n";
}

std::ostream & operator<<(std::ostream& out, Student& stu){
    stu.afisare(out);
    return out;
}


class Antrenor{
private:
    std::string nume;
    int varsta;
    std::string specializare;//stil de lupta
    std::string telefon;
public:
    Antrenor()=default;
    Antrenor(const std::string& nume_, const int varsta_, const std::string& specializare_, const std :: string& telefon_) :
        nume{nume_}, varsta{varsta_}, specializare{specializare_}, telefon{telefon_}
        {
            std::cout<<"Despre antrenor: "<<"\n"<<"Nume: "<<nume<<"\n"<<"Numar de telefon: "<<telefon<<"\n"<<"Varsta: "<<varsta<<" de ani \n"<<"Specializat in stilul de lupta : "<<specializare<<" \n";
        }
    Antrenor(const Antrenor& other) :
        nume{other.nume}, varsta{other.varsta},specializare{other.specializare}, telefon{other.telefon}
        {
            std::cout<<"Cc ! \n";
        }
    Antrenor& operator=(const Antrenor& other){
        std::cout<<"Oper = de copi! \n";
       nume=other.nume;
       varsta=other.varsta;
       specializare=other.specializare;
       telefon=other.telefon;
       return *this;
    }

   /* friend std::ostream& operator<<(std::ostream& os, const Antrenor& a1){
        os<<"Despre antrenor: "<<"\n"<<"Nume: "<<a1.nume<<"\n"<<"Numar de telefon: "<<a1.telefon<<"\n"<<"Varsta: "<<a1.varsta<<" de ani \n"<<"Specializat in stilul de lupta : "<<a1.specializare<<" \n";
        return os;
    }*/
    ~Antrenor()=default;

};

class Antrenament{
    std::string stil;//Muay Thai, Kickboxing, MMA
    int zi;//a saptamanii;
public:
    Antrenament()=default;
    Antrenament(const std::string& stil_,const int zi_):
        stil{stil_},zi{zi_}
        {
            std::cout<<"C de init \n";
        }
    Antrenament(const Antrenament& other) :
        stil{other.stil},zi{other.zi}
        {
            std::cout<<"cc \n";
        }
     Antrenament& operator=(const Antrenament& other){
       std::cout<<"Oper = de copi! \n";
       stil=other.stil;
       zi=other.zi;
       return *this;
    }
    ~Antrenament()=default;
} ;


class Dojo {
private:
    std::string nume;
    std::string adresa;
    std::vector <Student> studenti;
    std::vector <Antrenor> antrenori;
    std::vector <Antrenament> antrenamente;
public:
    Dojo(const std::string &nume_, const std::string &adresa_, const std::vector<Student> &studenti_, const std::vector<Antrenor> &antrenori_, const std::vector<Antrenament> &antrenamente_);

    Dojo(const Dojo &other);

    Dojo& operator=(const Dojo &other) {
        nume=other.nume;
        adresa=other.adresa;
        studenti=other.studenti;
        antrenori=other.antrenori;
        antrenamente=other.antrenamente;
        return *this;
    }

   ~Dojo()=default;
};
/*
class Tehnici{
   std::string stil;
   int difficulty_level;
   int base_damage;
   int base_miss_chance;
   ...
   //jab, hooks, low kicks, front kicks, side kicks, roundhouse kicks...

}; */
int main()
{

    Student s1{"Tudor",17,1,7,0};
    s1.citire(std::cin);
    //s1.afisare(std::cout);
    Antrenor a1("Andrei",24,"Muay Thai","0790959930");






    return 0;
}


