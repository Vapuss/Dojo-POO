#include <iostream>
#include <string>
#include <vector>
#include "AsAntrenament.h"
#include "ApStudent.h"
#include "Dojo.h"
int main()
{

    Antrenor antrenori[3];
    antrenori[0].setDate("Razvan",30,"MMA","0743267532");
    antrenori[1].setDate("Stefan",23,"Muay Thai","0774689432");
    antrenori[2].setDate("Radu",28,"Kickboxing","0789346723");

    Student s1{"Tudor",17,1,7,0};
    s1.citire(std::cin);
    s1.afisare(std::cout);
    Antrenament at1("lol",2);
    at1.citire(std::cin);
    at1.afisare(std::cout);
    int i;
    for(i=0;i<3;i++){
        if(at1.getStil()==antrenori[i].getSpec())
            std::cout<<"\t Antrenamentul il vei face alaturi de antrenorul "<<antrenori[i].getName()<<"! \n \t Succes ! :D ";
    }





    return 0;
}


