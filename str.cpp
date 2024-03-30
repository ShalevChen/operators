#include "str.h"
Str::Str()
{
	m_str = _strdup("none");
}

Str::~Str()
{
	if (m_str)
	{
      delete m_str;
	}
	

}
Str::Str(const Str& other)
{
	m_str = new char[strlen(other.m_str) + 1];
	strcpy(m_str, other.m_str); // ��� ������� �� ��� ����� ����� ��� ������ 
}

Str::Str(const char* str)
{
	m_str = _strdup(str);
}



bool Str::operator==(const Str& other) const
{
	if (strcmp(this->m_str,other.m_str)==0)
	{
		return true;
	}
	return false;
}

bool Str::operator!=(const Str& other) const
{
	if (strcmp(this->m_str,other.m_str)!=0)
	{
		return true;
	}
	return false;
}

bool Str::operator>(const Str& other) const
{

	if (strcmp(this->m_str,other.m_str)>0)   // �� ������� ������� ����� ������� ����� �� -  ����� �����������
	{
		return true;
	}

	return false;
}

bool Str::operator<(const Str& other) const
{
	if (strcmp(this->m_str,other.m_str)<0)   //   �� ������� ������� ���� ������� ����� �� -����� �����������
	{
		return true;
	}
	return false;
}

const Str& Str::operator=(const Str& other)  // ����� * this
{
	if (this != &other)
	{
		if (m_str)
		{
			delete m_str;
		}
		m_str = new char[strlen(other.m_str) + 1]; // ������ ���� ����� ������� �� �������� ���� ���� +1 
		strcpy(m_str, other.m_str);  // ����� �� ������� ������� ������� ( ������ ) ����� 
	}
	return *this;

}

const Str& Str::operator=(const char* str)
{

	if (m_str)
	{
		delete m_str;
	}
	m_str = _strdup(str);
	return *this;
}

char& Str::operator[](int index) const
{
	return m_str[index];
}

const Str& Str::operator++()  // ���� ������ ����� ��������
{
	for (int i = 0; i < strlen(m_str); i++)
	{
		m_str[i]++;
	}
	return *this;
}

Str Str::operator++(int) // ���� ������ ������ ���
{
	Str s(*this);
	for (int i = 0; i < strlen(m_str); i++)
	{
		this->m_str[i] = m_str[i] + 1;
	}
	return s.m_str;
}
Str::operator int() const
{
	return strlen(m_str);
}
int Str::operator()(char ch) const
{
	for (int i = 0; i < strlen(m_str); i++)
	{
		if (m_str[i]==ch)
		{
			return i;
		}
	}
	return -1;
}

Str Str::operator+(const Str& other) const // ���� ������ ������ ��� ��� �� ����
{
	Str my;
	my.m_str = new char[strlen(m_str) + strlen(other.m_str) + 1]; // ����� ������ ���� ����� �� 2 �������� +1 ��� ����� ����
	strcpy(my.m_str, m_str);  // ���� �� �� ���� ���� �� ���� - ������
	strcat(my.m_str, other.m_str); // ���� �� ������ ���� ������� ����� 
	return my;
}

const Str& Str::operator+=(const Str& other) // ����� ����� �������� ��� �� ����
{
	*this = *this + other; //      ����� �������� + ������ ���� ���� �� ����� ������� ��� ���� ������ �� ���� ���� ��� �� ������
	return * this;
}



Str operator+(const char* str, const Str& other) // ����� ������ ��� ��� �� ����
{
	Str my;
	my = new char[strlen(str) + strlen(other.m_str) + 1];
	strcpy(my.m_str, str);// ���� �� �� ���� ����� �� ����
	strcat(my.m_str, other.m_str); // ����� �� ���� ���� ����
	return my;
}

Str operator*(int num, const Str& other)  // ����� ������ ��� ��� �� ����
{
	if (other.m_str)
	{
		Str my;
		my = new char[(strlen(other.m_str) * num ) + 1]; // ���� ������ ���� ��� ����� ���� ���� ����� +1
		strcpy(my.m_str, other.m_str); // ����� ��� ������
		for (int i = 0; i < num-1; i++) // ��� ���� ��� -������ ������� �� ��� �� ��� ������� ��� ����� ��� �� ���� ������ ���� ��� ���� ���
		{
			strcat(my.m_str, other.m_str);

		}
		return my;
	}
}

