#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std;
typedef enum
{
    B,
    C,
    D,
    E,

} EhliyetSinifi;
class Surucu
{
private:
    char *ad = nullptr;
    unsigned int yas : 5;
    EhliyetSinifi EhliyetSiniflar;

public:
    friend ostream &operator<<(ostream &out, const Surucu &other)
    {
        out << "Surucu Adi: " << other.ad << endl
            << "Yasi: " << other.getter_yas()
            << endl
            << "Ehliyet: ";
        if (other.getter_ehliyet() == 0)
            out << "B";
        if (other.getter_ehliyet() == 1)
            out << "C";
        if (other.getter_ehliyet() == 2)
            out << "D";
        if (other.getter_ehliyet() == 3)
            out << "E";

        out << endl;
        return out;
    }
    Surucu()
    {
        ad = nullptr;
        //
    }
    Surucu(char *ad, unsigned int yas, EhliyetSinifi ehliyet)
    {
        setter_ad(ad);
        this->yas = yas;
        this->EhliyetSiniflar = ehliyet;
    }
    Surucu(const Surucu &other)
    {
        setter_ad(other.ad);
        setter_yas(other.yas);
        setter_ehliyet(other.EhliyetSiniflar);
    }
    ~Surucu()
    {
        delete[] ad;
    }
    Surucu &operator=(const Surucu &other)
    {
        setter_ad(other.ad);
        setter_yas(other.yas);
        setter_ehliyet(other.EhliyetSiniflar);
        return *this;
    }
    char *getter_ad() const;
    void setter_ad(char *yeniad);
    unsigned int getter_yas() const;
    void setter_yas(unsigned int yeniyas);
    EhliyetSinifi getter_ehliyet() const;
    void setter_ehliyet(EhliyetSinifi ehliyet);
};
class Yolcu
{
private:
    char *ad = nullptr;
    char *binisnoktasi = nullptr;
    string inisnoktasi;

public:
    friend ostream &operator<<(ostream &out, const Yolcu &other)
    {
        out << "Yolcu Adi: " << other.ad << endl
            << "Yolcu Binis: " << other.binisnoktasi
            << endl
            << "Yolcu Inis: " << other.inisnoktasi << endl;
        return out;
    }
    Yolcu()
    {
        ad = nullptr;
        binisnoktasi = nullptr;
        //
    }
    Yolcu(char *ad, char *binisnoktasi, string inisnoktasi)
    {
        setter_ad(ad);
        setter_binis(binisnoktasi);
        setter_inis(inisnoktasi);
    }
    ~Yolcu()
    {
        delete[] ad;
        delete[] binisnoktasi;
    }
    Yolcu(const Yolcu &other)
    {
        setter_ad(other.ad);
        setter_binis(other.binisnoktasi);
        inisnoktasi = other.inisnoktasi;
    }
    Yolcu &operator=(const Yolcu &other)
    {
        setter_ad(other.ad);
        setter_binis(other.binisnoktasi);
        setter_inis(other.inisnoktasi);
        return *this;
    }

    char *getter_ad() const;
    void setter_ad(char *yeniad);
    char *getter_binis() const;
    void setter_binis(char *yenibinis);
    string getter_inis() const;
    void setter_inis(string yeninis);
};
class Yuk
{
private:
    char *icerik = nullptr;
    double agirlik;
    double hacim;
    string alici;
    string binisnoktasi;
    string inisnoktasi;

public:
    friend ostream &operator<<(ostream &out, const Yuk &other)
    {
        out << "Yuk Icerigi: " << other.icerik << endl
            << "Agirligi: " << other.agirlik << endl
            << "Hacmi: " << other.hacim << endl
            << "Alici: " << other.alici << endl
            << "Binis: " << other.binisnoktasi << endl
            << "Inis: " << other.inisnoktasi
            << endl;

        return out;
    }
    Yuk()
    {
        icerik = nullptr;
    }
    Yuk(char *icerik, double agirlik, double hacim, string alici, string binisnoktasi, string inisnoktasi)
    {
        setter_icerik(icerik);
        setter_agirlik(agirlik);
        setter_hacim(hacim);
        setter_alici(alici);
        setter_binis(binisnoktasi);
        setter_inis(inisnoktasi);
    }
    ~Yuk()
    {
        delete[] icerik;
    }
    Yuk(const Yuk &other)
    {
        setter_icerik(other.icerik);
        setter_agirlik(other.agirlik);
        setter_hacim(other.hacim);
        setter_alici(other.alici);
        setter_binis(other.binisnoktasi);
        setter_inis(other.inisnoktasi);
    }
    Yuk &operator=(const Yuk &other)
    {
        setter_icerik(other.icerik);
        setter_agirlik(other.agirlik);
        setter_hacim(other.hacim);
        setter_alici(other.alici);
        setter_binis(other.binisnoktasi);
        setter_inis(other.inisnoktasi);
        return *this;
    }

    char *getter_icerik() const;
    void setter_icerik(char *yenicerik);
    double getter_agirlik() const;
    void setter_agirlik(double yeniagirlik);
    double getter_hacim() const;
    void setter_hacim(double yenihacim);
    string getter_alici() const;
    void setter_alici(string yenialici);
    string getter_binis() const;
    void setter_binis(string yenibinis);
    string getter_inis() const;
    void setter_inis(string yeninis);
};
class Arac
{
protected:
    char *plaka = nullptr;
    list<Surucu> Suruculer;

public:
    virtual ostream &print(ostream &stm) const = 0;
    friend ostream &operator<<(ostream &out, const Arac &other)
    {
        /* out << "Arac: " << other.plaka << " " <<other.Suruculer << endl; */
        return other.print(out);
    }
    Arac()
    {
        plaka = nullptr;
    }
    Arac(char *plaka, list<Surucu> Surucu)
    {
        setter_plaka(plaka);
        setter_surucu(Surucu);
    }
    virtual ~Arac()
    {
        delete[] plaka;
    }
    Arac(const Arac &other)
    {
        setter_plaka(other.plaka);
        setter_surucu(other.Suruculer);
    }
    Arac &operator=(const Arac &other)
    {
        setter_plaka(other.plaka);
        setter_surucu(other.Suruculer);
        return *this;
    }

    virtual char *getter_plaka() const;
    virtual void setter_plaka(char *yeniplaka);
    virtual list<Surucu> getter_surucu() const;
    virtual void setter_surucu(list<Surucu> Surucu);
};

class Otobus : public Arac
{
private:
    vector<Yolcu> Yolcular;

public:
    ostream &print(ostream &stm) const;
    Otobus()
    {
        //
    }
    Otobus(char *plaka1, list<Surucu> Suruculer, vector<Yolcu> Yolcular2) : Arac(plaka1, Suruculer), Yolcular(Yolcular2)
    {
        //
    }
    Otobus(const Otobus &other)
    {
        setter_plaka(other.plaka);
        setter_surucu(other.Suruculer);
        setter_yolcu(Yolcular);
    }
    ~Otobus()
    {
        this->Arac::~Arac();
    }
    Otobus &operator=(const Otobus &other)
    {
        setter_plaka(other.plaka);
        setter_surucu(other.Suruculer);
        setter_yolcu(Yolcular);
        return *this;
    }
    void setter_yolcu(vector<Yolcu> yeniyolcu);
};

class Kamyon : public Arac
{
private:
    char *OzluSoz = nullptr;
    vector<Yuk> Yukler;

public:
    ostream &print(ostream &stm) const;
    Kamyon()
    {
        OzluSoz = nullptr;
    }
    Kamyon(char *plaka2, list<Surucu> Suruculer, vector<Yuk> Yukler2, char *Soz) : Arac(plaka2, Suruculer), Yukler(Yukler2), OzluSoz(Soz)
    {
        //
    }
    ~Kamyon()
    {
        this->Arac::~Arac();
        delete[] OzluSoz;
    }
    Kamyon(const Kamyon &other)
    {
        setter_plaka(other.plaka);
        setter_surucu(other.Suruculer);
        setter_soz(other.OzluSoz);
        setter_yuk(other.Yukler);
    }
    Kamyon &operator=(const Kamyon &other)
    {
        setter_plaka(other.plaka);
        setter_surucu(other.Suruculer);
        setter_soz(other.OzluSoz);
        setter_yuk(other.Yukler);
        return *this;
    }
    char *getter_soz() const;
    void setter_soz(char *yenisoz);
    void setter_yuk(vector<Yuk> yeniyukler);
};
