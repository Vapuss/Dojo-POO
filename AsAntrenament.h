#pragma once

class Antrenor{
private:
    std::string nume;
    int varsta;
    std::string specializare;//stil de lupta
    std::string telefon;
public:
    Antrenor(){
        nume="";
        varsta=0;
        specializare="";
        telefon="";
    };
    Antrenor(const std::string& nume_, const int varsta_, const std::string& specializare_, const std :: string& telefon_) :
        nume{nume_}, varsta{varsta_}, specializare{specializare_}, telefon{telefon_}
        {
            std::cout<<"Con de init";
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
    void setDate(const std::string& nume_, const int varsta_, const std::string& specializare_, const std :: string& telefon_){nume=nume_;varsta=varsta_;specializare=specializare_;telefon=telefon_;}



    ~Antrenor()=default;
    const std::string& getName()const {return nume;}
    const std::string& getSpec()const {return specializare;}

};

class Antrenament{
    std::string stil;//Muay Thai, Kickboxing, MMA, Karate
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
    ~Antrenament();

    virtual void citire(std::istream &r);
    virtual void afisare(std::ostream &w);

    friend std :: istream& operator>>(std :: istream& r, Antrenament&);
    friend std :: ostream& operator<<(std :: ostream& w, Antrenament&);

    const std::string& getStil()const {return stil;}


} ;
  void Antrenament::citire(std::istream& r){
    std::cout<<"  Acesta este programul nostru, te rog sa iti alegi o zi care este cat mai convenabila pentru tine! :D \n\n";
    std::cout<<"\t Ziua \t|\t Stilul \t|\t Orele \n\n";
    std::cout<<" L\t 1 \t\t Kickboxing \t\t 16:00 & 18:00 \n M\t 2 \t\t Muay Thai \t\t 12:30 & 17:30 \n Mi\t 3 \t\t MMA \t\t\t 19:30 & 21:30 \n J\t 4 \t\t Muay Thai \t\t 17:30 & 19:30 \n V\t 5 \t\t Kickboxing \t\t 10:00 & 12:00 \n S\t 6 \t\t MMA \t\t\t 19:00 & 21:00 \n\n";
    std::cout<<" Ziua in care ma voi antrena: ";
    do{
        r>>zi;
        std::cout<<"\n";
        if(zi<1 ||zi>6)
        std::cout<<" Te rugam sa introduci un numar intre 1 si 6, reprezentativ pentru zilele de Luni pana Sambata : ";
        }
        while(zi<1 ||zi>6);
    }
  void Antrenament::afisare(std::ostream& w){
      switch(zi){
  case 1:
      w<<"\t Te asteptam Luni la antrenamentul de Kickboxing ! :> \n";
      stil="Kickboxing";
      break;
  case 2:
      w<<"\t Te asteptam Marti la antrenamentul de Muay Thai ! :> \n";
      stil="Muay Thai";
      break;
  case 3:
      w<<"\t Te asteptam Miercuri la antrenamentul de MMA ! :> \n";
      stil="MMA";
      break;
  case 4:
      w<<"\t Te asteptam Joi la antrenamentul de Muay Thai ! :> \n";
      stil="Muay Thai";
      break;
  case 5:
      w<<"\t Te asteptam Vineri la antrenamentul de Kickboxing ! :> \n";
      stil="Kickboxing";
      break;
  case 6:
      w<<"\t Te asteptam Sambata la antrenamentul de MMA ! :> \n";
      stil="MMA";
      break;


      }



  }

Antrenament::~Antrenament(){}
