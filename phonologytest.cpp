// This program tests the idea of implementing a word as a linked list with each
// phoneme serving as a node. 

#include <iostream>
#include <string>

using namespace std;

//Construcnts an individual letter, consonant or vowel, which acts as a node in a LL
//Contains basic LL node methods: constructor, display

class Phoneme 
{
	private: 
		bool isVowel;
	public:
		string phon;
		Phoneme *pNext; //Doubly linked list implimentation 
		Phoneme *pPrev;
		bool isVowel;

		Phoneme(string ph);
		void display();
		
};

Phoneme::Phoneme(string ph) : phon(ph), pNext(NULL), pPrev(NULL)
{
	switch(ph.phon)
	{
		case "ָ": // qamets
		case "ַ": // patach
		case "ֶ": // seghol
		case "ֵ": // tsere
		case "ִ": // hireq
		case "ּ": // shureq
		case "ֹ": // holem
		case "ֻ": // qibbuts
		case "ְ": // shewa  !!! <- write rule for mobile shewa !!!
		case "ֳ": // hateph-qamets
		case "ֲ": // hateph-patach
		case "ֳ": // hateph-seghol
			isVowel = true;
		default:
			isVowel = false;
	}
}

void Phoneme::display();
{
	cout<<phon;
}

// Word builder as LL implementation

class Word
{
	private:
		Phoneme *pNext;
		Phoneme *pPrevius;
		int numSyl;

	public:
		Word();
		~Word();
		bool isEmpty();
		//string getRoot(Word wd);		
		void insertFront(string st);
		void insertMiddle(Phoneme *pPrev, Phoneme *pNxt, string st);
		void insertEnd(string st);
		void removePhon(string st);
		void displayWord(Word wd);
}

Word::Word() : pFirst(NULL), pLast(NULL) {}

Word::~Word()
{
	Phoneme *pCurrent = pFirst;
	while(pCurrent != NULL)
	{
		Phoneme *pOldCur = pCurrent;
		pCurrent = pCurrent->pNext;
		delete pOldCur;
	}
}

bool Word::isEmpty()
{
	return pFirst == NULL;
}

void Word::insertFront(string st)
{
	Phoneme *pNewPhon = new Phoneme(st);

	if(isEmpty())
		pLast = pNewPhon;
	else
		pFirst->pPrevious = pNewPhon;
	pNewPhon->pNext = pFirst;
	pFirst = pNewPhon;
}

void Word::insertMiddle(Phoneme *pPrev, Phoneme *pNxt, string st)
{
	Phoneme *pNewPhon = new Phoneme(st);
	
	if(isEmpty())
		pFirst = pNewPhon;
	else
	{
		pPrev->pNext = pNewPhon;
		pNewPhon->previoius = pPrev;
	}
	pNxt = pNewPhon->pNext;
}

void Word::insertEnd(string st)
{
	Phoneme *pNewPhon = new Phoneme(st);

	if(isEmpty())
		pFirst = pNewPhon;
	else
	{
		pLast->pNext = pNewPhon;
		pNewPhon->previoius = pLast;
	}
	pLast = pNewPhon;
}

