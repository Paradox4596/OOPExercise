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
		std::cout << "����� Į�� �ֵѷ���." << std::endl;
	}

	void DooubleSlash() const
	{
		std::cout << "����� ���ϰ� �ι� �ֵѷ���." << std::endl;
	}
};

int main()
{
	Character* p = new Warrior;

	p->Attack();
	
	//((Warrior*)p)->DooubleSlash();

	//static_cast<Warrior*>(p); // ����ȯ�� ��Ȳ�� ���� �����ؼ� ����ϸ� ����

	Warrior* wp = dynamic_cast<Warrior*>(p); // �䷱ ���°� �����ϴ�
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