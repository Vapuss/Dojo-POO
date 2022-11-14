#pragma once


class Aplicant{
private:

std::string nume;
int varsta;
int practicant;
int experienta;//cate luni au fost practicate arte martiale
//int grupa;//nivel de experienta

public:
    Aplicant(){}
    Aplicant(const std::string& nume_, const int varsta_, const int practicant, const int experienta_) :
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
    int getPracticant() const{return practicant;}
    int getXP() const {return experienta;}


    virtual ~Aplicant();
    virtual void citire(std::istream &in);
    virtual void afisare(std::ostream &out);

    friend std :: istream& operator>>(std :: istream& in, Aplicant&);
    friend std :: ostream& operator<<(std :: ostream& out, Aplicant&);



};

Aplicant :: ~Aplicant(){}

    std::istream& operator>>(std::istream& in, Aplicant& apl){
    apl.citire(in);
    return in;
    }

    void Aplicant::citire(std::istream &in) {
    std::cout<<"\n"<<"  Bine ai venit in dojo-ul nostru!"<<" \n"<<"  Te rugam sa iti introduci datele: "<<"\n";
    std::cout<<" Nume :";
    in>>nume;
    std::cout<<" Varsta :";
    in>>varsta;
    std::cout<<" Practicant :";
        do{
        in>>practicant;
        if(practicant!=0 && practicant!=1)
        std::cout<<" Te rugam sa introduci 1 in cazul in care ai mai practicat sporturi de contact, iar 0 in caz contrar: ";
        }
        while(practicant!=0 && practicant!=1);

    std::cout<<" Experienta :";
    in>>experienta;
}

    std::ostream& operator<<(std::ostream& out, Aplicant& apl){
       apl.afisare(out);
       return out;

}

   void Aplicant::afisare(std::ostream &out){
        out<<"\n\n Datele tale: \n";
        out<<"\t Numele : "<<nume<< ";\n";
        out<<"\t Varsta : "<<varsta<<";\n";
       if(practicant)
        out<<"\t Practicant : DA; \n";
       else
        out<<"\t Practicant : NU; \n";

    out<<"\t Experienta : "<<experienta<<" luni; \n";
}




class Student : public Aplicant{
protected:
    int grupa;
public:
    Student(std::string, int, int, int, int);
    ~Student();
    Student(const Student&);

    void afisare(std::ostream &out) override;
    void citire(std::istream &in) override;

    friend std::ostream& operator<<(std::ostream& out, Student&);
    friend std::istream& operator>>(std::istream& in, Student&);

};

    Student::Student(const std::string nume, const int varsta, const int practicant, const int experienta, int grupa) : Aplicant(nume,varsta,practicant,experienta) {
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
 }


void Student ::afisare(std::ostream &out) {
    Aplicant::afisare(out);
    switch(grupa){
case 1:
    out<<"\t Ai fost repartizat in grupa : Novici! \n\n";
    break;
case 2:
    out<<"\t Ai fost repartizat in grupa : Intermediari! \n\n";
    break;
case 3:
    out<<"\t Ai fost repartizat in grupa : Avansati! \n\n";
    break;
    }


}

 std::istream& operator>>(std::istream &in, Student& stu){
    stu.citire(in);
    return in;
}

       std::ostream & operator<<(std::ostream& out, Student& stu){
    stu.afisare(out);
    return out;
}
