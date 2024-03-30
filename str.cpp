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
	strcpy(m_str, other.m_str); // פונ שמאתחלת את הצד הימני במקום הצד השמאלי 
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

	if (strcmp(this->m_str,other.m_str)>0)   // אם המחרוזת השמאלית גדולה מהימנית נחזיר כן -  בדיקה לקסיקוגרפית
	{
		return true;
	}

	return false;
}

bool Str::operator<(const Str& other) const
{
	if (strcmp(this->m_str,other.m_str)<0)   //   אם המחרוזת השמאלית קטנה מהימנית נחזיר כן -בדיקה לקסיקוגרפית
	{
		return true;
	}
	return false;
}

const Str& Str::operator=(const Str& other)  // נחזיר * this
{
	if (this != &other)
	{
		if (m_str)
		{
			delete m_str;
		}
		m_str = new char[strlen(other.m_str) + 1]; // מחרוזת חדשה בגודל המחרוזת של האובייקט החדש ועוד +1 
		strcpy(m_str, other.m_str);  // מעתיק את המחרוזת הימינית לשמאלית ( במקומה ) כמובן 
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

const Str& Str::operator++()  // צריך להחזיר מצביע לאובייקט
{
	for (int i = 0; i < strlen(m_str); i++)
	{
		m_str[i]++;
	}
	return *this;
}

Str Str::operator++(int) // צריך להחזיר אסטיאר חדש
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

Str Str::operator+(const Str& other) const // צריך להחזיר אסטיאר חדש לפי צד שמאל
{
	Str my;
	my.m_str = new char[strlen(m_str) + strlen(other.m_str) + 1]; // פתחנו מחרוזת חדשה בגודל של 2 המחרוזות +1 ואז נשרשר אותם
	strcpy(my.m_str, m_str);  // נשים את צד ימין בתוך צד שמאל - במקומה
	strcat(my.m_str, other.m_str); // נשים את הימנית אחרי השמאלית נשרשר 
	return my;
}

const Str& Str::operator+=(const Str& other) // נחזיר מצביע לאובייקט לפי צד שמאל
{
	*this = *this + other; //      בעזרת האופרטור + שעשינו נבצע השמה של שרשור מחרוזות לכן נשלח למטודה זו והיא תבצע לנו את השרשור
	return * this;
}



Str operator+(const char* str, const Str& other) // נחזיר אסטיאר חדש לפי צד שמאל
{
	Str my;
	my = new char[strlen(str) + strlen(other.m_str) + 1];
	strcpy(my.m_str, str);// נשים את צד ימין במקום צד שמאל
	strcat(my.m_str, other.m_str); // נשרשר את ימין לאחר שמאל
	return my;
}

Str operator*(int num, const Str& other)  // נחזיר אסטיאר חדש לפי צד שמאל
{
	if (other.m_str)
	{
		Str my;
		my = new char[(strlen(other.m_str) * num ) + 1]; // נקצה מחרוזת חדשה לפי מכפלת הנאם שלנו בנתון +1
		strcpy(my.m_str, other.m_str); // נשרשר פעם ראשונה
		for (int i = 0; i < num-1; i++) // נאם פחות אחד -מכיוון שבהתחלה יש לנו שם כבר מחרוזתת לכן נשרשר לשם את אותה מרחוזת כפול נאם פחות אחד
		{
			strcat(my.m_str, other.m_str);

		}
		return my;
	}
}

