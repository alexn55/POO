/*Political Union Management Project developed using OOP principles, in C ++,
 * presenting operations for adding/deleting/managing countries or data about countries.
 * The user can view the complete list of countries or just one country and can perform CRUD operations
 * on a country.*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class IOInterface
{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};

class Tara : public IOInterface
{
protected:
    float pib, rata_somaj, salariu_mediu, coef_economic, inflatie;
    string nume, moneda;
public:
    Tara()
    {
        this->nume ="";
        this->moneda = "";
        this->pib = 0;
        this->rata_somaj = 0;
        this->salariu_mediu = 0;
        this->coef_economic = 0;
        this->inflatie = 0;
    }
    Tara(string nume, string moneda, float pib, float rata_somaj,
        float salariu_mediu, float inflatie, float coef_economic)
    {
        this->nume = nume;
        this->moneda = moneda;
        this->pib = pib;
        this->rata_somaj = rata_somaj;
        this->salariu_mediu = salariu_mediu;
        this->coef_economic = coef_economic;
        this->inflatie = inflatie;
    }
    Tara(const Tara& t)
    {
        this->nume = t.nume;
        this->moneda = t.moneda;
        this->pib = t.pib;
        this->rata_somaj = t.rata_somaj;
        this->salariu_mediu = t.salariu_mediu;
        this->coef_economic = t.coef_economic;
        this->inflatie = t.inflatie;
    }

    void setPib(float pib)
    {
        this->pib = pib;
    }
    float getPib()
    {
        return this->pib;
    }
    void setRata_somaj(float rata_somaj)
    {
        this->rata_somaj = rata_somaj;
    }
    float getRata_somaj()
    {
        return this->rata_somaj;
    }
    void setSalariumediu(float salariu_mediu)
    {
        this->salariu_mediu = salariu_mediu;
    }
    float getSalariumediu()
    {
        return this->salariu_mediu;
    }
    void setInflatia(float inflatie)
    {
        this->inflatie = inflatie;
    }
    float getInflatia()
    {
        return this->inflatie;
    }
    void setMoneda(string moneda)
    {
        this->moneda = moneda;
    }
    float getMoneda()
    {
        return this->moneda;
    }
    void setNume(string nume)
    {
        this->nume = nume;
    }
    float getNume()
    {
        return this->nume;
    }

    virtual istream& citire(istream& in)
    {
        Tara::citire(in);
        cout << "Numele tarii este: ";
        in >> this->nume;
        cout << "Moneda tarii este: ";
        in >> this->moneda;
        cout << "Pib-ul tarii este: ";
        in >> this->pib;
        cout << "Rata de somaj a tarii este: ";
        in >> this->rata_somaj;
        cout << "Salariul mediu al tarii este: ";
        in >> this->salariu_mediu;
        cout << "Inflatia tarii este: ";
        in >> this->inflatie;
        return in;
    }

    virtual ostream& afisare(ostream& out) const
    {
        Tara::afisare(out);
        out << "Numele tarii este: " << this->nume << endl;
        out << "Moneda tarii este: " << this->moneda << endl;
        out << "Pib-ul tarii este: " << this->pib << endl;
        out << "Rata de somaj a tarii este: " << this->rata_somaj << endl;
        out << "Salariul mediu al tarii este: " << this->salariu_mediu << endl;
        out << "Inflatia tarii este: " << this->inflatie << endl;
        out << "Coeficientul economic al tarii este: " << this->coef_economic << endl;

        return out;
    }

    Tara& operator= (const Tara& t);

    float calcCoef()
    {
        this->coef_economic = (this->pib + this->salariu_mediu) / this->rata_somaj;
    }

    ~Tara()
    {
        this->nume = "";
        this->moneda = "";
        this->pib = 0;
        this->rata_somaj = 0;
        this->salariu_mediu = 0;
        this->inflatie = 0;
        this->coef_economic = 0;

    }
};

Tara& Tara ::operator=(const Tara& t)
{
    if (this != &t)
    {
        this->nume = t.nume;
        this->pib = t.pib;
        this->rata_somaj = t.rata_somaj;
        this->salariu_mediu = t.salariu_mediu;
    }

    return *this;
}


class Uniune : public virtual Tara
{
protected:
    float coeficientMediu;

public:
    Uniune() : Tara()
    {
        this->coeficientMediu = 0;
    }

    Uniune(string nume, string moneda, float pib, float rata_somaj, float salariu_mediu,
        float inflatie, float coef_economic, float coeficientMediu) : Tara(nume, moneda, pib,
            rata_somaj, salariu_mediu, inflatie, coef_economic)
    {
        this->coeficientMediu = coeficientMediu;
    }

    Uniune(const Uniune& u) : Tara(u)
    {
        this->coeficientMediu = u.coeficientMediu;
    }

    void setCoefM(float coeficientMediu)
    {
        this->coeficientMediu = coeficientMediu;
    }
    float getCoefM()
    {
        return this->coeficientMediu;
    }

    virtual istream& citire(istream& in)
    {
        Tara::citire(in);
        this->calcCoefMediu();
        return in;
    }

    virtual ostream& afisare(ostream& out) const
    {
        Tara::afisare(out);
        out << "Coeficientul mediu al uniunii este: " << this->coeficientMediu << endl;
        return out;
    }

    void calcCoefMediu(Tara t) 
    {
        this->coeficientMediu = (this->coef_economic+t.calcCoef)/2;
    }

    ~Uniune()
    {
        this->coeficientMediu = 0;
    }
};

class SpatiuEconomic : public virtual Tara
{
protected:
    float inflatie_medie;

public:
    SpatiuEconomic() : Tara()
    {
        this->inflatie_medie = 0;
    }

    SpatiuEconomic(string nume, string moneda, float pib, float rata_somaj, float salariu_mediu,
        float inflatie, float coef_economic, float inflatie_medie) : Tara(nume, moneda, pib,
            rata_somaj, salariu_mediu, inflatie, coef_economic)
    {
        this->inflatie_medie = inflatie_medie;
    }

    SpatiuEconomic(const SpatiuEconomic& se) : Tara(se)
    {
        this->inflatie_medie = se.inflatie_medie;
    }

    void setInflatieMedie(float inflatie_medie)
    {
        this->inflatie_medie = inflatie_medie;
    }

    float geInflatieMedie()
    {
        return this->inflatie_medie;
    }

    virtual istream& citire(istream& in)
    {
        Tara::citire(in);
        this->calcInflatiaMedie();
        return in;
    }

    virtual ostream& afisare(ostream& out) const
    {
        Tara::afisare(out);
        out << "Inflatia medie a spatiului economic este: " << this->inflatie_medie << endl;
        return out;
    }

    void calcInflatiaMedie(Tara t)
    {
        this->inflatie_medie = (this->inflatie_medie + t.getInflatia()) / 2;
    }

    ~SpatiuEconomic()
    {
        this->inflatie_medie = 0;
    }
};




class Alianta : public virtual Uniune, public virtual SpatiuEconomic {
private:
    bool exista_uniune, exista_spatiu;

public:
    // Constructori
    Alianta() : Uniune(), SpatiuEconomic(), Tara()
    {
        this->exista_uniune = false;
        this->exista_spatiu = false;
    }

    Alianta(string nume, string moneda, float pib, float rata_somaj, float salariu_mediu,
        float inflatie, float coef_economic, float coeficientMediu, float inflatie_medie, bool uniune, bool spatiu)
        : Tara(nume, moneda, pib, rata_somaj, salariu_mediu, inflatie, coef_economic),
        Uniune(nume, moneda, pib, rata_somaj, salariu_mediu, inflatie, coef_economic, coeficientMediu),
        SpatiuEconomic(nume, moneda, pib, rata_somaj, salariu_mediu, inflatie, coef_economic, inflatie_medie)
    {
        this->exista_spatiu = exista_spatiu;
        this->exista_uniune = exista_uniune;
    }

    Alianta(const Alianta& a) : Uniune(a), SpatiuEconomic(a)
    {
        this->exista_uniune = a.exista_uniune;
        this->exista_spatiu = a.exista_spatiu;
    }

    virtual istream& citire(istream& in)
    {
        Tara::citire(in);
        cout << "Coeficientul mediu al uniunii este: ";
        in >> this->coeficientMediu;
        cout << "Inflatia medie a spatiului economic este: ";
        in >> this->inflatie_medie;
        cout << "Exista spatiu? true/false ";
        in >> this->exista_spatiu;
        cout << "Exista uniune? true/false";
        in >> this->exista_uniune;
        return in;
    }

    virtual ostream& afisare(ostream& out) const
    {
        Tara::afisare(out);
        out << "Coeficientul mediu al uniunii este: " << this->coeficientMediu << endl;
        out << "Inflatia medie a spatiului economic este: " << this->inflatie_medie << endl;
        out << "Exista spatiu? true/false " << this->exista_spatiu << endl;
        out << "Exista uniune? true/false" << this->exista_uniune << endl;
        return out;
    }

    void setExistaUniune(bool exista_uniune)
    {
        this->exista_uniune = exista_uniune;
    }

    bool getExistaUniune() const
    {
        return exista_uniune;
    }

    void setExistaSpatiu(bool exista_spatiu)
    {
        this->exista_spatiu = exista_spatiu;
    }

    bool getExistaSpatiu() const
    {
        return exista_spatiu;
    }

    ~Alianta()
    {
        this->exista_uniune = false;
        this->exista_spatiu = false;
    }
};

class Meniu {

private:
    static Meniu* INSTANCE;
    Meniu() {}
    Meniu(const Meniu& meniu) {}

public:
    static Meniu* getInstance() {
        if (INSTANCE == NULL) {
            INSTANCE = new Meniu();
        }

        return INSTANCE;
    }

    void launch()
    {
        Alianta a;
        Tara t;
        Uniune u;
        SpatiuEconomic se;
        int i;
        string n;
        bool ok = true;
        while (ok == true)
        {
            int alegere;
            cout << "Apasa (1) pentru a adauga o tara in baza de date" << endl;
            cout << "Apasa (2) pentru a afla daca o tara poate adera la o uniune." << endl;
            cout << "Apasa (3) pentru a adauga o tara intr-o uniune." << endl;
            cout << "Apasa (4) pentru a afla daca o tara poate adera la un spatiu economic." << endl;
            cout << "Apasa (5) pentru a adauga o tara intr-un spatiu economic." << endl;
            cout << "Apasa (6) pentru a afla daca o tara face parte dintr-o alianta." << endl;
            cout << "Apasa (7) pentru a sterge o tara dintr-o uniune" << endl;
            cout << "Apasa (8) pentru a sterge o tara dintr-un spatiu economic" << endl;
            cout << "Apasa (9) pentru a iesi" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin >> alegere;
            switch (alegere)
            {
            case 1:
            {
                //Tara t;
                //t.citire(cin);

                cout << "Numele tarii este: " << endl;
                cin >> n; t.setNume(n);
                cout << "Moneda tarii este: " << endl;
                cin >> n; t.setMoneda(n);
                cout << "Pib-ul tarii este: ";
                cin >> n; t.setPib(n);
                cout << "Rata de somaj a tarii este: " << endl;
                cin >> n; t.setRata_somaj(n);
                cout << "Salariul mediu al tarii este: " << endl;
                cin >> n; t.setSalariumediu(n);
                cout << "Inflatia tarii este: " << endl;
                cin >> n; t.setSalariumediu(n);

                break;
            }
            case 2:
            {
                cout << "La ce uniune doriti sa aderati? Tastati 1 pentru UE, 2 pentru ASEAN, iar 3 pentru NAFTA."<< endl;
                if (i == 1 && t.calcCoef() > 2) cout << "Tara poate adera la UE!" << endl;
                else if (i == 2 && t.calcCoef() > 1.5) cout << "Tara poate adera la ASEAN!" << endl;
                else if (i == 3 && t.calcCoef() > 3) cout << "Tara poate adera la NAFTA!" << endl;
                else cout << "Tara nu poate adera la uniunea respectiva pentru ca are o situatie economica precara.";
                break;
            }
            case 3:
            {
                cout << "La ce uniune doriti sa aderati? Tastati 1 pentru UE, 2 pentru ASEAN, iar 3 pentru NAFTA." << endl;
                if (i == 1) 
                { 
                    UE.calcCoefMediu(Tara t);
                    cout << "Tara a aderat la UE!" << endl; 
                }
                else if (i == 2)
                {
                    ASEAN.calcCoefMediu(Tara t);
                    cout << "Tara a aderat la ASEAN!" << endl;
                }
                else if (i == 3)
                {
                    NAFTA.calcCoefMediu(Tara t);
                    cout << "Tara a aderat la NAFTA!" << endl;
                }
                a.setExistaUniune(1);
                break;
            }
            case 4:
            {
                if (t.getInflatia < 3) cout << "Tara poate adera la spatiul Schengen." << endl;
                else cout << "Tara nu poate adera in spatii economice, deoarece are inflatia prea mare." << endl;
                break;
            }
            case 5:
            {
                Schengen.calcInflatiaMedie(Tara t);
                cout << "Tara a aderat in spatiul Schengen." << endl;
                a.setExistaSpatiu(1);
                break;
            }
            case 6:
            {
                if (a.getExistaSpatiu != 0 && a.getExistaUniune != 0)
                    cout << "Tara face parte dintr-o alianta!" << endl;
                else cout << "Tara nu poate fi adaugata intr-o alianta." << endl;
                break;
            }
            case 7:
            {
                cout << "Daca doriti sa iesiti din UE apasati 1, din ASEAN 2, iar din NAFTA apasati 3!" << endl;
                if (i == 1 && UE.coeficientMediu < t.coef_economic)
                {
                    cout << "Tara a iesit din UE!" << endl;
                    UE.coeficientMediu = UE.coeficientMediu * 2 - t.coef_economic;
                }
                else if (i == 2 && ASEAN.coeficientMediu < t.coef_economic)
                {
                    cout << "Tara a iesit din ASEAN!" << endl;
                    ASEAN.coeficientMediu = ASEAN.coeficientMediu * 2 - t.coef_economic;
                }
                else if (i == 3 && NAFTA.coeficientMediu < t.coef_economic)
                {
                    cout << "Tara a iesit din NAFTA!" << endl;
                    NAFTA.coeficientMediu = NAFTA.coeficientMediu * 2 - t.coef_economic;
                }
                else cout << "Din motive economice, tara nu poate iesi din uniune." << endl;
                break;
            }
            case 8:
            {
                
                if (t.inflatie < 3 && sp.inflatie_medie > t.inflatie)
                {
                    cout << "Tara a iesit din spatiul economic." << endl;
                    Schengen.inflatie_medie = Schengen.inflatie_medie * 2 - t.inflatie;
                }
                else cout << "Inflatia este mult prea mare si nu se permite iesirea din spatiul economic!" << endl;
                break;
            }
            case 9:
            {
                ok = false;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            }
        }
    }

    Meniu& operator=(const Meniu& meniu) {
        return *INSTANCE;
    }
};

Meniu* Meniu::INSTANCE = 0;



int main()
{   
    Uniune UE("Uniunea Europeana", "euro", 57, 5.9, 2800, 3.1, 0, 0),
        ASEAN("Asociatia natiunilor din sud-estul Asiei", "diverse", 46, 3, 1400, 4.2, 0, 0),
        NAFTA("Acordul Nord - American de comert liber", "dolar", 48, 5.1, 4000, 10, 0, 0);
    UE.calcCoef(); ASEAN.calcCoef();NAFTA.calcCoef();
    SpatiuEconomic Schengen("Schengen", "euro", 60, 5.2, 2700, 2.9, 0, 0);
    Schengen.calcCoef(); 
    Meniu::getInstance()->launch();
    return 0;
}
