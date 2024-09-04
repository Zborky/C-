#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

/**
 * Trieda Calculator poskytuje funkcie na výpočty spojené s úrokmi, splátkami a investíciami.
 */
class Calculator {
private:
    bool jeRocna; // Indikuje, či sú splátky ročné (true) alebo nie (false)
    bool jeMesacna; // Indikuje, či sú splátky mesačné (true) alebo nie (false)
    double casoveObdobie; // Časové obdobie v rokoch
    string typSplatky; // Typ splátky
    double pozicanaSuma; // Pozičaná suma
    double urokovaSadzba; // Úroková sadzba
    int pocetMesiacov; // Počet mesiacov
    double urokovaSadzbaNaInvesticie; // Úroková sadzba na investície
    double investovanaSuma; // Investovaná suma

public:
    /**
     * Konštruktor triedy Calculator.
     * @param jeRocna Indikuje, či sú splátky ročné.
     * @param jeMesacna Indikuje, či sú splátky mesačné.
     * @param urokovaSadzba Úroková sadzba pre pôžičky.
     * @param casoveObdobie Časové obdobie v rokoch.
     * @param typSplatky Typ splátky.
     * @param pozicanaSuma Pozičaná suma.
     * @param pocetMesiacov Počet mesiacov pre splátky.
     * @param urokovaSadzbaNaInvesticie Úroková sadzba na investície.
     * @param investovanaSuma Investovaná suma.
     */
    Calculator(bool jeRocna, bool jeMesacna, double urokovaSadzba, double casoveObdobie, string typSplatky, double pozicanaSuma, int pocetMesiacov, double urokovaSadzbaNaInvesticie, double investovanaSuma) {
        this->jeRocna = jeRocna;
        this->jeMesacna = jeMesacna;
        this->urokovaSadzba = urokovaSadzba;
        this->casoveObdobie = casoveObdobie;
        this->typSplatky = typSplatky;
        this->pozicanaSuma = pozicanaSuma;
        this->pocetMesiacov = pocetMesiacov;
        this->urokovaSadzbaNaInvesticie = urokovaSadzbaNaInvesticie;
        this->investovanaSuma = investovanaSuma;
    }

    /**
     * Získa časové obdobie v rokoch.
     * @return Časové obdobie.
     */
    double getCasoveObdobie() {
        return this->casoveObdobie;
    }

    /**
     * Získa typ splátky.
     * @return Typ splátky.
     */
    string getTypSplatky() {
        return this->typSplatky;
    }

    /**
     * Získa pozičanú sumu.
     * @return Pozičaná suma.
     */
    double getPozicanaSuma() {
        return this->pozicanaSuma;
    }

    /**
     * Vypočíta jednoduché úroky.
     * @return Jednoduché úroky.
     */
    double vypocetUrokov() {
        return this->pozicanaSuma * urokovaSadzba * casoveObdobie;
    }

    /**
     * Vypočíta zložené úroky.
     * @return Zložené úroky.
     */
    double vypocetZlozitychUrokov() {
        return this->pozicanaSuma * pow(1 + urokovaSadzba, this->casoveObdobie);
    }

    /**
     * Vypočíta výšku splátky na základe zvolených parametrov.
     * @return Výška splátky.
     */
    double vypocetSplatky() {
        if (this->jeRocna) {
            return this->pozicanaSuma * this->urokovaSadzba / 12;
        } else {
            return this->pozicanaSuma * urokovaSadzba / this->pocetMesiacov;
        }
    }

    /**
     * Vypočíta výnos z investícií.
     * @return Výnos z investícií.
     */
    double vypocetNaInvesticie() {
        return this->investovanaSuma * this->pocetMesiacov * this->urokovaSadzbaNaInvesticie;
    }

    /**
     * Uloží údaje do súboru.
     * @param nazovSuboru Názov súboru, do ktorého sa údaje uložia.
     */
    void vlozDoSuboru(string nazovSuboru) {
        ofstream outputfile(nazovSuboru, ios::app);

        if (outputfile.is_open()) {
            // Získanie aktuálneho času
            time_t now = time(0);
            tm *ltm = std::localtime(&now);

            // Formátovanie času na reťazec
            char datumCas[30];
            strftime(datumCas, sizeof(datumCas), "%Y-%m-%d %H:%M:%S", ltm);

            // Zápis údajov do súboru
            outputfile << datumCas << endl;
            outputfile << "Typ splatky: " << typSplatky << endl;
            outputfile << "Pozicana suma: " << pozicanaSuma << " EUR" << endl;
            outputfile << "Urokova sadzba: " << urokovaSadzba * 100 << " %" << endl;
            outputfile << "Casove obdobie: " << casoveObdobie << " rokov" << endl;
            outputfile << "Pocet mesiacov: " << pocetMesiacov << endl;
            outputfile << "-------------------------------" << endl;

            outputfile.close();
        } else {
            cerr << "\033[31mChyba pri otvarani suboru: " << nazovSuboru << "\033[0m" << endl;
        }
    }

    /**
     * Číta údaje zo súboru a vypisuje ich na konzolu.
     * @param nazovSuboru Názov súboru, z ktorého sa údaje čítajú.
     */
    void citajZoSuboru(string nazovSuboru) {
        ifstream inputfile(nazovSuboru);

        if (inputfile.is_open()) {
            string line;
            while (getline(inputfile, line)) {
                cout << "\033[32m" << line << "\033[0m" << endl;
            }
            inputfile.close();
        } else {
            cerr << "\033[31mChyba pri otvarani suboru: " << nazovSuboru << "\033[0m" << endl;
        }
    }
};

/**
 * Vytlačí nadpis v okne s farbami.
 * @param text Text nadpisu.
 */
void vypisNadpis(const string &text) {
    cout << "\033[34m╔══════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[34m║\033[0m " << text << "\033[34m \033[34m║\033[0m" << endl;
    cout << "\033[34m╚══════════════════════════════════════════╝\033[0m" << endl;
}

int main() {
    // Vytlačenie nadpisu
    vypisNadpis("Kalkulacka financnych operacii");

    // Deklarácia premenných pre vstup od používateľa
    bool jeRocna, jeMesacna;
    double urokovaSadzba, casoveObdobie, pozicanaSuma, urokovaSadzbaNaInvesticie, investovanaSuma;
    int pocetMesiacov;
    string typSplatky;

    // Vstup od používateľa
    cout << "\033[33mZadajte, ci je splatka rocna (1 = ano, 0 = nie): \033[0m";
    cin >> jeRocna;
    cout << "\033[33mZadajte, ci je splatka mesacna (1 = ano, 0 = nie): \033[0m";
    cin >> jeMesacna;
    cout << "\033[33mZadajte urokovu sadzbu (napr. 0.05 pre 5%): \033[0m";
    cin >> urokovaSadzba;
    cout << "\033[33mZadajte casove obdobie v rokoch: \033[0m";
    cin >> casoveObdobie;
    cout << "\033[33mZadajte typ splatky: \033[0m";
    cin >> typSplatky;
    cout << "\033[33mZadajte pozicanu sumu: \033[0m";
    cin >> pozicanaSuma;
    cout << "\033[33mZadajte pocet mesiacov: \033[0m";
    cin >> pocetMesiacov;
    cout << "\033[33mZadajte urokovu sadzbu na investicie (napr. 0.035 pre 3.5%): \033[0m";
    cin >> urokovaSadzbaNaInvesticie;
    cout << "\033[33mZadajte investovanu sumu: \033[0m";
    cin >> investovanaSuma;

    // Vytvorenie objektu Calculator s poskytnutými údajmi
    Calculator kalkulator(jeRocna, jeMesacna, urokovaSadzba, casoveObdobie, typSplatky, pozicanaSuma, pocetMesiacov, urokovaSadzbaNaInvesticie, investovanaSuma);

    // Výpis informácií o kalkuláciách
    cout << "\033[32mCasove obdobie: \033[0m" << kalkulator.getCasoveObdobie() << " rokov" << endl;
    cout << "\033[32mTyp splatky: \033[0m" << kalkulator.getTypSplatky() << endl;
    cout << "\033[32mPozicana suma: \033[0m" << kalkulator.getPozicanaSuma() << " EUR" << endl;

    double uroky = kalkulator.vypocetUrokov();
    cout << "\033[32mJednoduchy urok: \033[0m" << uroky << " EUR" << endl;

    double zloziteUroky = kalkulator.vypocetZlozitychUrokov();
    cout << "\033[32mZlozeny urok: \033[0m" << zloziteUroky << " EUR" << endl;

    double splatka = kalkulator.vypocetSplatky();
    cout << "\033[32mSplatka: \033[0m" << splatka << " EUR mesacne" << endl;

    double investicia = kalkulator.vypocetNaInvesticie();
    cout << "\033[32mVynos z investicii: \033[0m" << investicia << " EUR" << endl;

    // Uloženie údajov do súboru a čítanie zo súboru
    kalkulator.vlozDoSuboru("Zoznam.txt");
    kalkulator.citajZoSuboru("Zoznam.txt");

    return 0;
}
