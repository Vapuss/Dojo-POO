#pragma once

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
