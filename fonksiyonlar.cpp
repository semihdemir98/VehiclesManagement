#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include "siniflar.h"
using namespace std;

int length(char *str)
{
    int uzunluk = 0;
    while (*str++ != '\0')
        ++uzunluk;
    return uzunluk;
}
//-------Surucu Sınıfı Fonksiyonları-----------//
char *Surucu::getter_ad() const
{
    return ad;
}
void Surucu::setter_ad(char *yeniad)
{
    if (ad != nullptr)
        delete[] ad;
    try
    {
        ad = new char[length(yeniad)];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    for (int i = 0; i < length(yeniad); i++)
        ad[i] = yeniad[i];
}
unsigned int Surucu::getter_yas() const
{
    return yas + 32;
}
void Surucu::setter_yas(unsigned int yeniyas)
{
    yas = yeniyas;
}
EhliyetSinifi Surucu::getter_ehliyet() const
{
    return EhliyetSiniflar;
}
void Surucu::setter_ehliyet(EhliyetSinifi ehliyet)
{
    EhliyetSiniflar = ehliyet;
}

//-------Yolcu Sınıfı Fonksiyonları-----------//

char *Yolcu::getter_ad() const
{
    return ad;
}
void Yolcu::setter_ad(char *yeniad)
{
    if (ad != nullptr)
        delete[] ad;
    try
    {
        ad = new char[length(yeniad)];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    for (int i = 0; i < length(yeniad); i++)
        ad[i] = yeniad[i];
}
char *Yolcu::getter_binis() const
{
    return binisnoktasi;
}
void Yolcu::setter_binis(char *yenibinis)
{
    if (binisnoktasi != nullptr)
        delete[] binisnoktasi;
    try
    {
        binisnoktasi = new char[length(yenibinis)];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    for (int i = 0; i < length(yenibinis); i++)
        binisnoktasi[i] = yenibinis[i];
}
string Yolcu::getter_inis() const
{
    return inisnoktasi;
}
void Yolcu::setter_inis(string yeninis)
{
    inisnoktasi = yeninis;
}

//-------Yuk Sınıfı Fonksiyonları-----------//

char *Yuk::getter_icerik() const
{
    return icerik;
}
void Yuk::setter_icerik(char *yenicerik)
{
    if (icerik != nullptr)
        delete[] icerik;
    try
    {
        icerik = new char[length(yenicerik)];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    for (int i = 0; i < length(yenicerik); i++)
        icerik[i] = yenicerik[i];
}
double Yuk::getter_agirlik() const
{
    return agirlik;
}
void Yuk::setter_agirlik(double yeniagirlik)
{
    agirlik = yeniagirlik;
}
double Yuk::getter_hacim() const
{
    return hacim;
}
void Yuk::setter_hacim(double yenihacim)
{
    hacim = yenihacim;
}
string Yuk::getter_alici() const
{
    return alici;
}
void Yuk::setter_alici(string yenialici)
{
    alici = yenialici;
}
string Yuk::getter_binis() const
{
    return binisnoktasi;
}
void Yuk::setter_binis(string yenibinis)
{
    binisnoktasi = yenibinis;
}
string Yuk::getter_inis() const
{
    return inisnoktasi;
}
void Yuk::setter_inis(string yeninis)
{
    inisnoktasi = yeninis;
}

//-------Arac Sınıfı Fonksiyonları-----------//

char *Arac::getter_plaka() const
{
    return plaka;
}
void Arac::setter_plaka(char *yeniplaka)
{
    if (plaka != nullptr)
        delete[] plaka;
    try
    {
        plaka = new char[length(yeniplaka)];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    for (int i = 0; i < length(yeniplaka); i++)
        plaka[i] = yeniplaka[i];
}
list<Surucu> Arac::getter_surucu() const
{
    return Suruculer;
}
void Arac::setter_surucu(list<Surucu> Surucu)
{
    Suruculer = Surucu;
}

//-------Otobus Sınıfı Fonksiyonları-----------//

ostream &Otobus::print(ostream &stm) const
{
    stm << "Otobusun Plakasi: " << getter_plaka() << endl;
    stm << endl
        << "Suruculer: " << endl
        << endl;
    for (Surucu const &v : getter_surucu())
    {
        stm << v << endl;
    }
    stm << endl
        << "Yolcular: " << endl;
    for (unsigned i = 0; i < Yolcular.size(); i++)
    {
        stm << Yolcular[i] << endl;
    }
    return stm;
}
void Otobus::setter_yolcu(vector<Yolcu> yeniyolcu)
{
    this->Yolcular.clear();
    for (unsigned i = 0; i < yeniyolcu.size(); i++)
        this->Yolcular.push_back(yeniyolcu[i]);
}

//-------Kamyon Sınıfı Fonksiyonları-----------//

ostream &Kamyon::print(ostream &stm) const
{
    stm << "Kamyonun Plakasi: " << getter_plaka() << endl;
    stm << endl
        << "Ozlu Soz:" << getter_soz() << endl
        << "Suruculer: " << endl
        << endl;
    for (Surucu const &v : getter_surucu())
    {
        stm << v << endl;
    }
    stm << endl
        << "Yukler: " << endl;
    for (unsigned i = 0; i < Yukler.size(); i++)
    {
        stm << Yukler[i] << endl;
    }
    return stm;
}
char *Kamyon::getter_soz() const
{
    return OzluSoz;
}
void Kamyon::setter_soz(char *yenisoz)
{
    if (OzluSoz != nullptr)
        delete[] OzluSoz;
    try
    {
        OzluSoz = new char[length(yenisoz)];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    for (int i = 0; i < length(yenisoz); i++)
        OzluSoz[i] = yenisoz[i];
}
void Kamyon::setter_yuk(vector<Yuk> yeniyukler)
{
    this->Yukler.clear();
    for (unsigned i = 0; i < yeniyukler.size(); i++)
        this->Yukler.push_back(yeniyukler[i]);
}