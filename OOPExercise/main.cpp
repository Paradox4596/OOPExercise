#include <iostream>

class Character
{
protected:
	int mHP;

public:
	Character() : mHP{ 100 }
	{
		std::cout << "[+] Character Created!" << std::endl;
	}

	virtual ~Character()
	{
		std::cout << "[+] Character Destroyed!" << std::endl;
	}

public:
	virtual void Attack() const
	{
		std::cout << "Unknown Attack!" << std::endl;
	}
};

class Warrior : public Character
{
public:
	Warrior()
	{
		std::cout << "[+] Warrior created!" << std::endl;
	}
	~Warrior()
	{
		std::cout << "[-] Warrior created!" << std::endl;
	}

public:
	void Attack() const override
	{
		std::cout << "전사는 칼을 휘둘렀다." << std::endl;
	}

	void DooubleSlash() const
	{
		std::cout << "전사는 강하게 두번 휘둘렀다." << std::endl;
	}
};

int main()
{
	Character* p = new Warrior;

	p->Attack();
	
	//((Warrior*)p)->DooubleSlash();

	//static_cast<Warrior*>(p); // 형변환은 상황에 따라 구분해서 사용하면 좋다

	Warrior* wp = dynamic_cast<Warrior*>(p); // 요런 형태가 안전하다
	if (wp)
	{
		wp->DooubleSlash();
	}
	else
	{
		std::cerr << "Warrior type expected" << std::endl;
	}

	delete p;
}