#include"BookAndReader.cpp"

class BookList;
class ReaderList;

class BookList 
{
	public:
    	Book *node, *head_ptr; 				//�������� Book ָ�룬head_ptr Ϊͷָ�룬node Ϊ�ָ��
		Book *rear_ptr,*before_node;
		BookList()
		{ 									//���캯����ʹָ���ʼ��
			head_ptr = new Book;
			head_ptr->SetNextNode(NULL);
			rear_ptr = head_ptr;
			before_node = head_ptr;
			node = NULL;
		}
		void save_file(); 					//�洢�ļ�
		void load_file(); 					//�ϴ��ļ�
		void AddNewBook(); 					//����Ǽǣ��� node ָ��������ֵ
		void Add_list(Book *p); 			//���ӽ�㵽 Book �����У������������ʱ
		char *borrow_book(); 				//��������
		char *return_book(); 				//��������
		int search_ISBN(char *p); 			//�� ISBN �Ų���ͼ��
		int search_BookName(char *p); 		//����������ͼ��
		int search_Writer(char *p); 		//������������ͼ��
		int search_Publisher(char *p); 		//�������̲���ͼ��
	    int search_PublishDate(char *p); 	//���������ڲ���ͼ��
		void search(); 						//������Ҳ˵�
		void show_content(Book *b); 			//��ʾĳ���������
		void show_all(); 					//��ʾ���п���δ�������ͼ��
		void delete_onebook(); 				//ɾ��ĳ����
		void change_content(); 				//����ĳ�������Ϣ
		void GoInto_BookInfo(); 			//���������Ϣ�˵�
		void Helper();
		void Display(int allow);
		friend void GoInto_bor_ret(BookList *book_ptr,ReaderList *reader_ptr);
};

class ReaderList
{
	private:
	    int position; 					//���������еĵڼ����ڵ�
	public:
		Reader *point,*head_point,*rear_point; 		//�������� Reader ָ�룬head_point Ϊͷָ�룬point Ϊ�ָ��
		Reader *before_point;											//rear_pointָ������β�� 
		ReaderList(){
			head_point = new Reader;
			head_point->SetNextNode(NULL);
			rear_point = head_point;
			before_point = head_point;
			point = NULL;
		}				   				 //���캯����ʹָ���ʼ��
		void save_readerfile(); 		//�洢�ļ�
		void load_readerfile(); 		//�ϴ��ļ�
		void reader_register(); 		//����ע��
		void Add_Point(Reader *p); 		//�����½�㵽����
		void reader_land(); 			//���ߵ�¼
		int search_ReaderName(char *p); //����������
		void show_OneReader(Reader *p); //��ʾĳ������Ϣ
		void change_password(); 		//�޸�����
		void delete_reader(); 			//����ע��
		void GoInto_ReaderInfo(); 		//������Ϣ�˵�
		void ShowAll();
		void DeleteAll();
		void Helper(); 
		void exit();
		friend void GoInto_bor_ret(BookList *book_ptr,ReaderList *reader_ptr);
};

