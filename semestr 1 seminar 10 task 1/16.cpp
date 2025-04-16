#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
using namespace std;
#pragma comment( lib, "winmm.lib")

class BasicMarmelas
{
public:
	int HP;  // Здоровье Мармеласа 

	BasicMarmelas(int p_HP) :HP(p_HP) {}
};

class FreddyFazbear
{
public:
	int HP;  // Здоровье медведя

	// Конструктор медведя
	FreddyFazbear(int p_HP = 100) : HP(p_HP) {}

	// Деструктор
	~FreddyFazbear() {};

	// Метод получения всей информации о медведе
	void Print()
	{
		std::cout << "\nFreddyFazbear " << "\nHP: " << HP  << "\n" << std::endl;
	}

	// Метод атаки медведя
	void FreddyFazbearAttack(BasicMarmelas* mage)
	{
		std::cout << "Ur ur ur ur ur" << std::endl;
		mage->HP -= 10;
		PlaySound(L"wave1.wav", NULL, SND_FILENAME);
	}
};

class Attack_Marmelad // атакующие заклинания
{
public:
	Attack_Marmelad(const std::string& s) { std::cout << "Creating " << s << std::endl; } // Отчет о созании заклинания
	virtual ~Attack_Marmelad() {};                                                        // деструктор
	virtual std::string cast_attack_spells() const = 0;                                   // Отчет о вызове заклинания
	virtual void do_attack_spells(FreddyFazbear* bear) const = 0;                         // действие заклинания
};

class Expelliarmus : public Attack_Marmelad // Атакующее заклинание первого уровня
{
public:
	Expelliarmus() : Attack_Marmelad("Expelliarmus") {}
	std::string cast_attack_spells() const override
	{
		return "Expelliarmus";
	}
	void do_attack_spells(FreddyFazbear* bear) const override
	{
		bear->HP -= 5;
		PlaySound(L"wave10.wav", NULL, SND_FILENAME);
	}
};

class Bombarda : public Attack_Marmelad // Атакующее заклинание второго уровня
{
public:
	Bombarda() : Attack_Marmelad("Bombarda") {}
	std::string cast_attack_spells() const override
	{
		return "Bombarda";
	}
	void do_attack_spells(FreddyFazbear* bear) const override
	{
		bear->HP -= 10;
		PlaySound(L"wave21.wav", NULL, SND_FILENAME);
	}
};

class Riddikulus : public Attack_Marmelad // Атакующее заклинание третьего уровня
{
public:
	Riddikulus() : Attack_Marmelad("Riddikulus") {}
	std::string cast_attack_spells() const override
	{
		return "Riddikulus";
	}
	void do_attack_spells(FreddyFazbear* bear) const override
	{
		bear->HP -= 15;
		PlaySound(L"wave13.wav", NULL, SND_FILENAME);
	}
};

class Petrificus_Totalus : public Attack_Marmelad // Атакующее заклинание четвертого уровня
{
public:
	Petrificus_Totalus() : Attack_Marmelad("Petrificus_Totalus") {}
	std::string cast_attack_spells() const override
	{
		return "Petrificus_Totalus";
	}
	void do_attack_spells(FreddyFazbear* bear) const override
	{
		bear->HP -= 20;
		PlaySound(L"wave19.wav", NULL, SND_FILENAME);
	}
};


class Protection_Marmelad // защитные заклинания
{
public:
	Protection_Marmelad(const std::string& s) { std::cout << "Creating " << s << std::endl; } // Отчет о созании заклинания
	virtual ~Protection_Marmelad() {};                                                        // деструктор
	virtual std::string cast_protection_spells() const = 0;                                   // Отчет о вызове заклинания
	virtual void do_protection_spells(BasicMarmelas* mage) const = 0;                         // действие заклинания
};

class Protego : public Protection_Marmelad // Защитное заклинание первого уровня
{
public:
	Protego() : Protection_Marmelad("Protego") {}
	std::string cast_protection_spells() const override
	{
		return "Protego";
	}
	void do_protection_spells(BasicMarmelas* mage) const override
	{
		mage->HP += 5;
		PlaySound(L"wave14.wav", NULL, SND_FILENAME);
	}
};

class Protego_Diabolica : public Protection_Marmelad // Защитное заклинание второго уровня
{
public:
	Protego_Diabolica() : Protection_Marmelad("Protego_Diabolica") {}
	std::string cast_protection_spells() const override
	{
		return "Protego_Diabolica";
	}
	void do_protection_spells(BasicMarmelas* mage) const override
	{
		mage->HP += 10;
		PlaySound(L"wave12.wav", NULL, SND_FILENAME);
	}
};

class Expecto_Patronum : public Protection_Marmelad // Защитное заклинание третьего уровня
{
public:
	Expecto_Patronum() : Protection_Marmelad("Expecto_Patronum") {}
	std::string cast_protection_spells() const override
	{
		return "Expecto_Patronum";
	}
	void do_protection_spells(BasicMarmelas* mage) const override
	{
		mage->HP += 15;
		PlaySound(L"wave16.wav", NULL, SND_FILENAME);
	}
};

class Protego_Maxima : public Protection_Marmelad // Защитное заклинание четвертого уровня
{
public:
	Protego_Maxima() : Protection_Marmelad("Protego_Maxima") {}
	std::string cast_protection_spells() const override
	{
		return "Protego_Maxima";
	}
	void do_protection_spells(BasicMarmelas* mage) const override
	{
		mage->HP += 20;
		PlaySound(L"wave11.wav", NULL, SND_FILENAME);
	}
};


class HenHaoChi_Marmelad // вкусные заклинания    Hen Hao Chi - очень вкусно
{
public:
	HenHaoChi_Marmelad(const std::string& s) { std::cout << "Creating " << s << std::endl; }    // Отчет о созании заклинания
	virtual ~HenHaoChi_Marmelad() {};                                                           // деструктор
	virtual std::string cast_HenHaoChi_spells() const = 0;                                      // Отчет о вызове заклинания
	virtual void do_HenHaoChi_spells() const = 0;                                               // действие заклинания
};

class Wingardium_Leviosa : public HenHaoChi_Marmelad // Повседневное заклинание первого уровня
{
public:
	Wingardium_Leviosa() : HenHaoChi_Marmelad("Wingardium_Leviosa") {}
	std::string cast_HenHaoChi_spells() const override
	{
		return "Wingardium_Leviosa";
	}
	void do_HenHaoChi_spells() const override
	{
		PlaySound(L"wave5.wav", NULL, SND_FILENAME);
	}
};

class Lumos : public HenHaoChi_Marmelad // Повседневное заклинание второго уровня
{
public:
	Lumos() : HenHaoChi_Marmelad("Lumos") {}
	std::string cast_HenHaoChi_spells() const override
	{
		return "Lumos";
	}
	void do_HenHaoChi_spells() const override
	{
		PlaySound(L"wave9.wav", NULL, SND_FILENAME);
	}
};

class Nox : public HenHaoChi_Marmelad // Повседневное заклинание третьего уровня
{
public:
	Nox() : HenHaoChi_Marmelad("Nox") {}
	std::string cast_HenHaoChi_spells() const override
	{
		return "Nox";
	}
	void do_HenHaoChi_spells() const override
	{
		PlaySound(L"wave23.wav", NULL, SND_FILENAME);
	}
};

class Alohomora : public HenHaoChi_Marmelad // Повседневное заклинание четвертого уровня
{
public:
	Alohomora() : HenHaoChi_Marmelad("Alohomora") {}
	std::string cast_HenHaoChi_spells() const override
	{
		return "Alohomora";
	}
	void do_HenHaoChi_spells() const override
	{
		PlaySound(L"wave24.wav", NULL, SND_FILENAME);
	}
};


class Unforgivable_Marmelad // непростительные заклинания
{
public:
	Unforgivable_Marmelad(const std::string& s) { std::cout << "Creating " << s << std::endl; } // Отчет о созании заклинания
	virtual ~Unforgivable_Marmelad() {};                                                        // деструктор
	virtual std::string cast_unforgivable_spells() const = 0;                                   // Отчет о вызове заклинания
	virtual void do_unforgivable_spells(BasicMarmelas* mage, FreddyFazbear* bear) const = 0;    // действие заклинания
};

class Crucio : public Unforgivable_Marmelad // Непростительное заклинание первого уровня
{
public:
	Crucio() : Unforgivable_Marmelad("Crucio") {}
	std::string cast_unforgivable_spells() const override
	{
		return "Crucio";
	}
	void do_unforgivable_spells(BasicMarmelas* mage, FreddyFazbear* bear) const override
	{
		mage->HP = 0;
		bear->HP -= 30;
		PlaySound(L"wave25.wav", NULL, SND_FILENAME);
	}
};

class Imperio : public Unforgivable_Marmelad // Непростительное заклинание второго уровня
{
public:
	Imperio() : Unforgivable_Marmelad("Imperio") {}
	std::string cast_unforgivable_spells() const override
	{
		return "Imperio";
	}
	void do_unforgivable_spells(BasicMarmelas* mage, FreddyFazbear* bear) const override
	{
		mage->HP = 0;
		bear->HP -= 60;
		PlaySound(L"wave26.wav", NULL, SND_FILENAME);
	}
};

class Avada_Kedavra : public Unforgivable_Marmelad // Непростительное заклинание третьего уровня
{
public:
	Avada_Kedavra() : Unforgivable_Marmelad("Avada_Kedavra") {}
	std::string cast_unforgivable_spells() const override
	{
		return "Avada_Kedavra";
	}
	void do_unforgivable_spells(BasicMarmelas* mage, FreddyFazbear* bear) const override
	{
		mage->HP = 0;
		bear->HP = 0;
		PlaySound(L"wave22.wav", NULL, SND_FILENAME);
	}
};

class Absos_Marmelasa : public Unforgivable_Marmelad // Непростительное заклинание четвертого уровня
{
public:
	Absos_Marmelasa() : Unforgivable_Marmelad("Absos_Marmelasa") {}
	std::string cast_unforgivable_spells() const override
	{
		return "Absos_Marmelasa";
	}
	void do_unforgivable_spells(BasicMarmelas* mage, FreddyFazbear* bear) const override
	{
		mage->HP = 100;
		bear->HP = 0;
		PlaySound(L"wave4.wav", NULL, SND_FILENAME);
	}
};


class Book_of_Marmelad // Книга заклинаний
{
public:
	virtual Attack_Marmelad* WriteSpell1() const = 0;          // Функция для создание атакующих заклинаний 
	virtual Protection_Marmelad* WriteSpell2() const = 0;      // Функция для создание защитных заклинаний 
	virtual HenHaoChi_Marmelad* WriteSpell3() const = 0;       // Функция для создание вкусных заклинаний 
	virtual Unforgivable_Marmelad* WriteSpell4() const = 0;    // Функция для создание непростительных заклинаний 
};

template<class Singleton>
Singleton* GetSpellInstance() // Функция синглтон для щаблонных классов
{
	static Singleton* singleton = NULL;
	if (!singleton) singleton = new Singleton();
	return singleton;
}

template< class S1, class S2, class S3, class S4 > // Шаблонный класс создания заклинаний
class Four_Types_of_Marmelad : public Book_of_Marmelad
{
public:
	Attack_Marmelad* WriteSpell1() const override
	{
		return GetSpellInstance<S1>(); // Если заклинание еще не созданно то создаем
	}
	Protection_Marmelad* WriteSpell2() const override
	{
		return GetSpellInstance<S2>(); // Если заклинание еще не созданно то создаем
	}
	HenHaoChi_Marmelad* WriteSpell3() const override
	{
		return GetSpellInstance<S3>(); // Если заклинание еще не созданно то создаем
	}
	Unforgivable_Marmelad* WriteSpell4() const override
	{
		return GetSpellInstance<S4>(); // Если заклинание еще не созданно то создаем
	}
};

typedef Four_Types_of_Marmelad<Expelliarmus, Protego, Wingardium_Leviosa, Crucio> Marmelad_level_1;              // класс Недомармеласов
typedef Four_Types_of_Marmelad<Bombarda, Protego_Diabolica, Lumos, Imperio> Marmelad_level_2;                    // класс Низших мармеласов
typedef Four_Types_of_Marmelad<Riddikulus, Expecto_Patronum, Nox, Avada_Kedavra> Marmelad_level_3;               // класс Средних мармеласов
typedef Four_Types_of_Marmelad<Petrificus_Totalus, Protego_Maxima, Alohomora, Absos_Marmelasa> Marmelad_level_4; // класс Высших мармеласов




class Marmelas: public BasicMarmelas
{
private:
    std::string firstname;  // Имя Мармеласа
    std::string secondname; // Фамилия Мармеласа
	int rank;               // Ранг Мармеласа
    int age;                // Возраст Мармеласа   
public:
	Book_of_Marmelad* book;

    // Конструктор Мармеласа
    Marmelas(std::string p_firstname,
        std::string p_secondname,
        int p_rank,
        int p_age,
        int p_HP = 100)
        : BasicMarmelas( p_HP )
		, firstname(p_firstname)
        , secondname(p_secondname)
        , rank(p_rank)
        , age(p_age)
    {
		if (rank == 1) book = new Marmelad_level_1();
		if (rank == 2) book = new Marmelad_level_2();
		if (rank == 3) book = new Marmelad_level_3();
		if (rank == 4) book = new Marmelad_level_4();
	}

    // Деструктор
    ~Marmelas() {};

    // Метод получения всей информации о Мармеласа
    void Print()
    {
        std::cout << "\nFirstname: " << firstname
            << "\nSecondname: " << secondname
            << "\nRank: " << rank
            << "\nAge: " << age
            << "\nHP: " << HP << std::endl;
    }
};

// Функция дуэли
void Duel(Marmelas* mage, FreddyFazbear* bear)
{
	for (int i = 1;; i++)
	{
		bear->FreddyFazbearAttack(mage);
		if (mage->HP <= 0)
		{
			break;
		}
		if (i % 4 == 0)
		{
			std::cout << mage->book->WriteSpell4()->cast_unforgivable_spells() << std::endl;
			mage->book->WriteSpell4()->do_unforgivable_spells(mage, bear);
		}
		else if (i % 3 == 0)
		{
		    std::cout << mage->book->WriteSpell3()->cast_HenHaoChi_spells() << std::endl;
			mage->book->WriteSpell3()->do_HenHaoChi_spells();
		}
		else if (i % 2 == 0)
		{
		    std::cout << mage->book->WriteSpell2()->cast_protection_spells() << std::endl;
			mage->book->WriteSpell2()->do_protection_spells(mage) ;
		}
		else
		{
		    std::cout << mage->book->WriteSpell1()->cast_attack_spells() << std::endl;
			mage->book->WriteSpell1()->do_attack_spells(bear);
		}
		if (bear->HP <= 0)
		{
			break;
		}
	}
}

// Функция битвы
void Battle(Marmelas** mage_mass,FreddyFazbear* bear_mass, int n)
{
	int i = 0;
	int j = 0;
	while(i != n && j != n)
	{
		mage_mass[i]->Print();
		bear_mass[j].Print();
		Duel(mage_mass[i], &bear_mass[j]);
		if (mage_mass[i]->HP <= 0)
		{
			i += 1;
			std::cout << "marmelas is dead" << std::endl;
			PlaySound(L"wave18.wav", NULL, SND_FILENAME);
		}
		if (bear_mass[j].HP <= 0)
		{
			j += 1;
			std::cout << "freddy fazbear is dead" << std::endl;
			PlaySound(L"wave20.wav", NULL, SND_FILENAME);
		}
	}
	if (j == n && i == n) // Ничья
	{
		std::cout << "draw" << std::endl;
		PlaySound(L"wave6.wav", NULL, SND_FILENAME);
	}
	else if (j == n)       // Победили мармеласы
	{
	    std::cout << "marmelases won" << std::endl;
		PlaySound(L"wave3.wav", NULL, SND_FILENAME);
	}
	else if (i == n)       // Победили медведи
	{
		std::cout << "freddy fazbears won" << std::endl;
		PlaySound(L"wave7.wav", NULL, SND_FILENAME);
	}
}

int main()
{
	try
	{
		FreddyFazbear freddy_fazbear;
		std::cout << "Marmelases vs Freddy Fazbears simulation" << std::endl; // Начало симуляции
		PlaySound(L"wave15.wav", NULL, SND_FILENAME);
		PlaySound(L"wave2.wav", NULL, SND_FILENAME);
		int n = 0;
		std::cout << "Choose the number of soldiers" << std::endl;
		freopen("marmelas.txt", "r", stdin);    // Связываем поток ввода с созданным файлом
		std::cin >> n;
		if (std::cin.fail()) throw "\nsoldiers number should be an integer number.";
		if (n < 1 || n > 100 ) throw "You can only write a number between 1 and 100.";
		Marmelas** mage_mass = new Marmelas * [n];
		FreddyFazbear* bear_mass = new FreddyFazbear[n];
		int type = 0;
		for (int i = 0; i < n; i++)
		{
			std::cout << "Choose type of marmelas from 1 to 4" << std::endl;
			std::cin >> type;
			if (std::cin.fail()) throw "\ntype number should be an integer number.";
			if (type == 4)
			{
				mage_mass[i] = new Marmelas("highest", "marmelas", 4, 40);
			}
			else if (type == 3)
			{
				mage_mass[i] = new Marmelas("middle", "marmelas", 3, 30);
			}
			else if (type == 2)
			{
				mage_mass[i] = new Marmelas("inferior", "marmelas", 2, 20);
			}
			else if (type == 1)
			{
				mage_mass[i] = new Marmelas("sub", "marmelas", 1, 10);
			}
			else
			{
				std::cout << "There are only 4 types of marmelases" << std::endl;
				exit(0);
			}
		}
		Battle(mage_mass, bear_mass, n);
		std::cout << "End of the Battle" << std::endl;
		PlaySound(L"wave8.wav", NULL, SND_FILENAME);
	}
	catch (const char* s)               // Ловиться ввод известных недопустимых параметров
	{
		std::cout << s << std::endl;
	}
	catch (...)                         // Ловиться ввод неизвестных недопустимых параметров
	{
		cout << "Unknown exception" << std::endl;
	}
	return 0;
}