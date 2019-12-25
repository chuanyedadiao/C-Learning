#include"BookAndReader.h"
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void Book::SetBookName(char *b)
{
	if(b[0] == '\0'){
		BookName = new char[1];
		BookName[0] = '\0';
		return;
	}
	BookName = new char[strlen(b)+1];
	strcpy(BookName,b);
	BookName[strlen(b)] = '\0';
}

void Book::SetISBN(char *I)
{
	if(I[0] == '\0'){
		ISBN = new char[1];
		ISBN[0] = '\0';
		return;
	}
	ISBN = new char[strlen(I)+1];
	strcpy(ISBN,I);
	ISBN[strlen(I)] = '\0';
}

void Book::SetWriter(char *w)
{
	if(w[0] == '\0'){
		Writer = new char[1];
		Writer[0] = '\0';
		return;
	}
	Writer = new char[strlen(w)+1];
	strcpy(Writer,w);
	Writer[strlen(w)] = '\0';
}

void Book::SetPublisher(char *p)
{
	if(p[0] == '\0'){
		Publisher = new char[1];
		Publisher[0] = '\0';
		return;
	}
	Publisher = new char[strlen(p)+1];
	strcpy(Publisher,p);
	Publisher[strlen(p)] = '\0';
}

void Book::SetPublishDate(char *p)
{
	if(p[0] == '\0'){
		PublishDate = new char[1];
		PublishDate[0] = '\0';
		return;
	}
	PublishDate = new char[strlen(p)+1];
	strcpy(PublishDate,p);
	PublishDate[strlen(p)] = '\0';
}

void Book::SetBriefIntroduction(char *b)
{
	if(b[0] == '\0'){
		BriefIntroduction = new char[1];
		BriefIntroduction[0] = '\0';
		return;
	}
	BriefIntroduction = new char[strlen(b)+1];
	strcpy(BriefIntroduction,b);
	BriefIntroduction[strlen(b)] = '\0';
}

void Book::SetEbook(char *e)
{
	if(e[0] == '\0'){
		Ebook = new char[1];
		Ebook[0] = '\0';
		return;
	}
	Ebook = new char[strlen(e)+1];
	strcpy(Ebook,e);
	Ebook[strlen(e)] = '\0';
}

void Book::SetEbookprice(float e)
{
	Ebookprice = e;
}

void Book::SetPaperBook(char *p)
{
	if(p[0] == '\0'){
		PaperBook = new char[1];
		PaperBook[0] = '\0';
		return;
	}
	PaperBook = new char[strlen(p)+1];
	strcpy(PaperBook,p);
	PaperBook[strlen(p)] = '\0';
}

void Book::SetBookPrice(float b)
{
	BookPrice = b;
}

void Book::SetNextNode(Book *in)
{
	next = in;
}

char* Book::GetBookName()
{
	return BookName;
}

char* Book::GetISBN()
{
	return ISBN;
}

char* Book::GetWriter()
{
	return Writer;
}

char* Book::GetPublisher()
{
	return Publisher; 
}

char* Book::GetPublishDate()
{
	return PublishDate;
}

char* Book::GetBriefIntroduction()
{
	return BriefIntroduction;
}

char* Book::GetEbook()
{
	return Ebook;
}

float Book::GetEbookprice()
{
	return Ebookprice;
}

char* Book::GetPaperBook()
{
	return PaperBook;
}

float Book::GetBookPrice()
{
	return BookPrice;
}

Book* Book::GetNextNode()
{
	return next;
}

void Book::print()
{
	cout<<"BookName:\t";
	if(BookName[0] == '\0') cout<<"无"<<endl;
	else cout<<BookName<<endl;
	cout<<"ISBN:\t\t";
	if(ISBN[0] == '\0')  cout<<"无"<<endl;
	else cout<<ISBN<<endl; 
	cout<<"Writer:\t\t";
	if(Writer[0] == '\0')  cout<<"无"<<endl;
	else cout<<Writer<<endl; 
	cout<<"Publisher\t";
	if(Publisher[0] == '\0')  cout<<"无"<<endl;
	else cout<<Publisher<<endl; 
	cout<<"PublishDate\t";
	if(PublishDate[0] == '\0')  cout<<"无"<<endl;
	else cout<<PublishDate<<endl; 
	cout<<"BriefIntroduction:\n";
	if(BriefIntroduction[0] == '\0')  cout<<"无"<<endl;
	else cout<<BriefIntroduction<<endl; 
	cout<<"Ebook:\t\t";
	if(Ebook[0] == '\0')  cout<<"无"<<endl;
	else cout<<Ebook<<endl; 
	cout<<"EbookPrice:\t";
	if(Ebookprice == 0)  cout<<"无"<<endl;
	else cout<<Ebookprice<<endl; 
	cout<<"PaperBook:\t";
	if(PaperBook[0] == '\0')  cout<<"无"<<endl;
	else cout<<PaperBook<<endl; 
	cout<<"BookPrice:\t";
	if(BookPrice == 0)  cout<<"无"<<endl;
	else cout<<BookPrice<<endl; 
	if(i_o == 1) cout<<"This book has already been borrowed\n";
	else cout<<"This book has not been borrowed\n";
	cout<<endl;
}

Reader::Reader(char *r,char *p)
{
	ReaderName = new char[strlen(r)+1];
	strcpy(ReaderName,r);
	ReaderName[strlen(r)] = '\0';
	Password = new char[strlen(p)+1];
	strcpy(Password,p);
	Password[strlen(p)] = '\0';
	book1 = NULL;
	book2 = NULL;
	y_n = 0;
}

void Reader::SetReaderName(char *r)
{
	ReaderName = new char[strlen(r)+1];
	strcpy(ReaderName,r);
	ReaderName[strlen(r)] = '\0';
}

void Reader::SetPassword(char *p)
{
	Password = new char[strlen(p)+1];
	strcpy(Password,p);
	Password[strlen(p)] = '\0';
}

char* Reader::GetReaderName()
{
	return ReaderName;
}

char* Reader::GetPassWord()
{
	return Password;
}

char* Reader::GetBook1()
{
	return book1;
}

char* Reader::GetBook2()
{
	return book2;
}

void Reader::BorrowBook(char *b)
{
	if(*b == '\0') return;
	if(y_n == 2){
		cout<<"Can't Borrow Books anymore"<<endl;
		cout<<"\n";
		return;
	}
	else if(book1[0] == '\0'){
		book1 = new char[strlen(b)+1];
		strcpy(book1,b);
		book1[strlen(b)] = '\0';
		y_n++;
	}
	else if(book2[0] == '\0'){
		book2 = new char[strlen(b)+1];
		strcpy(book2,b);
		book2[strlen(b)] = '\0';
		y_n++;
	}
}

int Reader::ReturnBook(char *BookName)
{
	if(y_n == 0){
		cout<<"This Reader didn't borrow any book"<<endl;
		return 0;
	}
	else if(book1[0] != '\0' && strcmp(book1,BookName) == 0){
		book1[0] = '\0';
		y_n --;
		return 1;
	}
	else if(book2[0] != '\0' && strcmp(book2,BookName) == 0){
		book2[0] = '\0';
		y_n --;
		return 1;
	}
	else {
		cout<<"This Reader didn't borrow the book whose BookName is";
		cout<<" "<<BookName<<endl;
		return 0;
	}
}

void Reader::SetNextNode(Reader *in)
{
	next = in;
}

Reader *Reader::GetNextNode()
{
	return next;
} 

void Reader::showInfo()
{
	cout<<"Name:"<<ReaderName<<endl;
	if(y_n == 0){
		cout<<"You haven't borrow any book yet\n";
		return;
	}
    if(book1[0] != '\0'){
		cout<<"You borrowed a book whose Book1Name is: "<<book1<<endl;
	}
	if(book2[0] != '\0'){
		cout<<"You borrowed a book whose Book2Name is: "<<book2<<endl;
	}
	cout<<endl;
}

