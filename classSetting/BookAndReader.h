#include<iostream>

class Book //存储图书信息的类
{
	private:
		char *BookName; 				//书名，用于查找
		char *ISBN; 					//ISBN 号，用于查找
		char *Writer; 				//作者名，用于查找
		char *Publisher; 			//出版商，用于查找
		char *PublishDate; 			//出版日期，用于查找
		char *BriefIntroduction; 	//该书内容简介
		char *Ebook;
		float Ebookprice;
		char *PaperBook;
		float BookPrice;
		int i_o; 						//判断书是否借出，0 为在架，1 为借出
		Book *next; 					//指向下一个节点的指针
	public:
		Book(){}
		void SetBookName(char *b);
		void SetISBN(char *I);
		void SetWriter(char *w);
		void SetPublisher(char *p);
		void SetPublishDate(char *p);
		void SetBriefIntroduction(char *b);
		void SetEbook(char *e);
		void SetEbookprice(float e);
		void SetPaperBook(char *p);
		void SetBookPrice(float b);
        void Seti_o(int i){i_o = i;}
		void SetNextNode(Book *in);
		char* GetBookName();
		char* GetISBN();
		char* GetWriter();
		char* GetPublisher();
		char* GetPublishDate();
		char* GetBriefIntroduction();
		char* GetEbook();
		float GetEbookprice();
		char* GetPaperBook();
		float GetBookPrice();
		Book* GetNextNode();
		int geti_o(){return i_o;}
		void print();
};

class Reader //存储读者信息的类
{
	protected:
		char *ReaderName; 			//读者姓名
		char *Password; 			//密码
		char *book1,*book2; 		//每人最多借两本书，可以根据需要增减限额
		int y_n; 					//记录借的书的数目，0 为没有借书，1 为借了一本，2 为借了二本
		Reader *next; 				//指向下一节点的指针
	public:
		Reader(){
			y_n = 0;
			book1 = new char[1];
			book1[0] = '\0';
			book2 = new char[1];
			book2[0] = '\0';
		}
		Reader(char *r,char *p);
		void SetReaderName(char *r);
		void SetPassword(char *p);
		char* GetReaderName();
		char* GetPassWord();
		char* GetBook1();
		char* GetBook2();
		int Gety_n(){return y_n;}
		void BorrowBook(char *b);
		int ReturnBook(char *BookName);
		void SetNextNode(Reader *in);
		Reader *GetNextNode();
		virtual int Allow(){
			return 0;
		}//读者权限为0啊 
		void showInfo();
};

class administrator:public Reader{
	public:
		administrator(){}
		administrator(char *r,char *p):Reader(r,p){}
		int Allow(){
			return 1;
		}//权限 
};




