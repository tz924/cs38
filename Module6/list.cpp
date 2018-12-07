#include <iostream>
#include <string>
using namespace std;

class Word
{
private:
	string m_word;
	Word * m_next;
	Word * m_prev;
public:
	Word(string s = "");
	void display() const;
	Word * next() { return m_next; }
	Word * prev() { return m_prev; }
	bool operator == (string s);
	friend class List;
	friend ostream & operator <<  (ostream &out, const Word &w);
};

bool Word::operator == (string s)
{
	return m_word == s;
}

ostream & operator <<  (ostream &out, const Word &w)
{
	out << w.m_word;	// <<(ostream, string)
	return out;
}

class List
{
private:
	Word * m_head;
	Word *m_tail;
	// How big is the string
	int m_size;
public:
	List();
	//List(const List &otherList);
	~List();
	void append(Word *);
	void insert(Word * newWord, Word *beforeWord);
	void remove(Word *);
	Word & at(int offset) const;
	bool isEmpty() const;
	int size() const;
	void display() const;
};

List::List() :
	m_head(nullptr), m_tail(nullptr), m_size(0)
{}
//List::List(const List &otherList) {}

List::~List() {}

// add new Word to end of the list
void List::append(Word *w)
{
	//case 1:  list is empty
	if (this->isEmpty())
	{
		m_head = m_tail = w;
	}

	//case 2: list is not empty
	else
	{
		w->m_prev = m_tail;
		m_tail->m_next = w;
		m_tail = w;
	}
	m_size++;
}

void List::insert(Word * newWord, Word *beforeWord) {}

// remove Word pointed to by w
// assumes w is in the list - no validation occurs
void List::remove(Word *wRemove)
{
	//case 1: item to be removed is only item in the list
	if (size() == 1)
		m_head = m_tail = nullptr;

	//case 2: item to be removed is first item in the list
	else if (wRemove == m_head)
	{
		m_head = wRemove->next();
		m_head->m_prev = nullptr;
	}
	//case 3: item to be removed is last item in the list
	else if (wRemove == m_tail)
	{
		m_tail = wRemove->prev();
		m_tail->m_next = nullptr;
	}
	//case 4: item to be removed is middle item in the list
	else
	{
		wRemove->next()->m_prev = wRemove->prev();
		wRemove->prev()->m_next = wRemove->next();
	}
	m_size--;
}
Word & List::at(int offset) const { Word w; return w; }
bool List::isEmpty() const { return m_size == 0; }
int List::size() const { return m_size; }
// display all strings in the Word elements in the list
void List::display() const
{
	Word *t = m_head;
	while (t)
	{
		t->display();
		t = t->next();
	}
}

Word::Word(string s) :
	m_word(s), m_prev(nullptr), m_next(nullptr)
{ }

void Word::display() const
{
	cout << m_word << endl;
}

int main()
{
	Word w1 = string("hello");
	cout << w1;
	List myList;
	cout << "Display list with no items: ";
	myList.display();
	cout << endl;

	// Test append()
	Word w2("there"), w3("sally");
	myList.append(&w1);
	myList.append(&w2);
	myList.append(&w3);
	cout << "Display list with 3 items: ";
	myList.display();
	cout << endl;

	// Test remove()
	myList.remove(&w2);
	myList.display();
	cout << endl;
	string s = "hello";
	if (w1 == s)
	{
		//do something
	}
	system("pause");
	return 0;
}