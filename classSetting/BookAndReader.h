#include<iostream>

class Book //�洢ͼ����Ϣ����
{
	private:
		char *BookName; 				//���������ڲ���
		char *ISBN; 					//ISBN �ţ����ڲ���
		char *Writer; 				//�����������ڲ���
		char *Publisher; 			//�����̣����ڲ���
		char *PublishDate; 			//�������ڣ����ڲ���
		char *BriefIntroduction; 	//�������ݼ��
		char *Ebook;
		float Ebookprice;
		char *PaperBook;
		float BookPrice;
		int i_o; 						//�ж����Ƿ�����0 Ϊ�ڼܣ�1 Ϊ���
		Book *next; 					//ָ����һ���ڵ��ָ��
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

class Reader //�洢������Ϣ����
{
	protected:
		char *ReaderName; 			//��������
		char *Password; 			//����
		char *book1,*book2; 		//ÿ�����������飬���Ը�����Ҫ�����޶�
		int y_n; 					//��¼��������Ŀ��0 Ϊû�н��飬1 Ϊ����һ����2 Ϊ���˶���
		Reader *next; 				//ָ����һ�ڵ��ָ��
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
		}//����Ȩ��Ϊ0�� 
		void showInfo();
};

class administrator:public Reader{
	public:
		administrator(){}
		administrator(char *r,char *p):Reader(r,p){}
		int Allow(){
			return 1;
		}//Ȩ�� 
};




