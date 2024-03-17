#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class asigurare
{
public:
    const static int idmax = 10000;
    int id_client;
    char nume[35], data[11], autom[20], tippol[10];
    float durata, val;
    static float valtotpolcl[idmax];

    asigurare(int fid_client, const char* fnume, const char* fdata,
        const char* fautom, const char* ftippol, float fdurata, float fval) :
        id_client(fid_client), durata(fdurata), val(fval)
    {
        strcpy(nume, fnume);
        strcpy(data, fdata);
        strcpy(autom, fautom);
        strcpy(tippol, ftippol);
    }

    static void get_polita_client(int idcautat, asigurare* asigurari, int nmax)
    {
        float valpolclient = 0;
        for (int i = 0; i < nmax; i++)
        {
            if (asigurari[i].id_client == idcautat)
                valpolclient = valpolclient + (asigurari[i].durata * asigurari[i].val);
        }
        valtotpolcl[idcautat] = valpolclient;
    }
};

float asigurare::valtotpolcl[asigurare::idmax] = { 0 };

class societate
{
private:
    static const int nras = 20000, idmaxi = 10000;
    asigurare* as[nras]; // societatea ARE asigurari
public:
    float TotalPolitePerSocietate[idmaxi];
    int id_soc;
    char denumire[30];

    societate(int fid_soc, const char* fdenumire) : id_soc(fid_soc)
    {
        TotalPolitePerSocietate[id_soc] = 0;
        strcpy(denumire, fdenumire);
    }

    void inregistrare_client(int idcl, int idsoc, float valo)
    {
        TotalPolitePerSocietate[idsoc] = TotalPolitePerSocietate[idsoc] + asigurare::valtotpolcl[idcl];
    }
};

int main()
{
    asigurare asigurari[6] = {
        asigurare(1, "Mirea Diana", "25-10-2022", "Dacia", "CASCO", 2.5, 1000),
        asigurare(2, "Ducu Sebastian", "01-02-2023", "Renault", "RCA", 3.0, 1500),
        asigurare(1, "Mirea Diana", "06-07-2022", "Dacia", "RCA", 1.5, 800),
        asigurare(1, "Mirea Diana", "06-10-2023", "Fiat", "RCA", 2, 800),
        asigurare(3, "Neagu Cristi", "09-01-2024", "Skoda", "CASCO", 5, 1200),
        asigurare(4, "Albu Elena", "01-07-2022", "Skoda", "RCA", 10, 120),
    };
    societate societate1(1, "Exos"), societate2(2, "Vanti"), societate3(3, "Zeni");

    for (int i = 1; i <= 4; i++)
    {
        asigurare::get_polita_client(i, asigurari, 6);
        cout << "Valoarea totala a politelor clientului " << i << " " << asigurari[i - 1].nume << " este de " <<
            asigurare::valtotpolcl[i] << " lei" << endl;
    }
    cout << endl;

    societate2.inregistrare_client(1, 2, 0);
    societate3.inregistrare_client(2, 3, 0);
    societate1.inregistrare_client(3, 1, 0);
    societate3.inregistrare_client(4, 3, 0);

    cout << "Societatea " << societate1.id_soc << " are valoarea totala a politelor de "
        << societate1.TotalPolitePerSocietate[societate1.id_soc] << " lei" << endl;

    cout << "Societatea " << societate2.id_soc << " are valoarea totala a politelor de "
        << societate2.TotalPolitePerSocietate[societate2.id_soc] << " lei" << endl;

    cout << "Societatea " << societate3.id_soc << " are valoarea totala a politelor de "
        << societate3.TotalPolitePerSocietate[societate3.id_soc] << " lei" << endl;

    return 0;
}
