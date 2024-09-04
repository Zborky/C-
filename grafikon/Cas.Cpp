#include<iostream>

using namespace std;

class Cas{
    private:
        int hodiny;
        int minuty;

    public:

    Cas(int hodiny,int minuty){
        this->hodiny = hodiny;
        this->minuty = minuty;

    }

    int getHodiny() const{
        return this->hodiny;

    }

    int getMinuty()const{
        return this->minuty;

    }

    bool jeSkorAko(Cas* druhyCas){
        
        if(this->hodiny > druhyCas->getHodiny()){
            return true;

        }else if (this->hodiny == druhyCas->getHodiny()){
            if(this->minuty > druhyCas->getMinuty()){
                return true;
            }
            

        }
        return false;
    }
    void formatuj(){
        cout<< " " << this->hodiny << " : " << " " << this->minuty;

    }
};

class Jazda{
    private:
    string stanicaZ;
    string stanicaDo;
    Cas* zaciatok;
    Cas* koniec;

    public:
        Jazda(string stanicaZ,string stanicaDo,Cas* zaciatok,Cas* koniec){
            this->koniec = koniec;
            this->zaciatok = zaciatok;
            this->stanicaDo = stanicaDo;
            this->stanicaZ = stanicaZ;

        }

        bool jeKonfliktnaZ(Jazda* druhaJazda){
            if(this->zaciatok && koniec == druhaJazda->zaciatok && koniec ){
                return true;

            }else if(this->stanicaZ  == druhaJazda->stanicaZ ){
                return true;
                             
            }else if(this->stanicaDo == druhaJazda->stanicaDo){
                return true;


            }
            return false;
        }  
};

class Zastavenie{
    private:
        string stanica;
        Cas* prijazd;
        Cas* odjazd;
    public:

        Zastavenie(string stanica,Cas* prijazd, Cas* odjazd){
            this->stanica = stanica;
            this->prijazd = prijazd;
            this->odjazd = odjazd;

        }

        Jazda vytvorJazduDo(Zastavenie* nasledujuceZastavenie){
            return Jazda(this->stanica, nasledujuceZastavenie->stanica, this->odjazd, nasledujuceZastavenie->prijazd);


        }

        void vypis(){
            cout << "Stanica: " << stanica << ". Prijazd: ";
        prijazd->formatuj();
        cout << ", Odyjazd: ";
        odjazd->formatuj();
        cout << endl;

        }
};