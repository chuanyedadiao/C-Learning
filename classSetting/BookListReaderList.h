#include"BookAndReader.cpp"

class BookList;
class ReaderList;

class BookList 
{
	public:
    	Book *node, *head_ptr; 				//定义两个 Book 指针，head_ptr 为头指针，node 为活动指针
		Book *rear_ptr,*before_node;
		BookList()
		{ 									//构造函数，使指针初始化
			head_ptr = new Book;
			head_ptr->SetNextNode(NULL);
			rear_ptr = head_ptr;
			before_node = head_ptr;
			node = NULL;
		}
		void save_file(); 					//存储文件
		void load_file(); 					//上传文件
		void AddNewBook(); 					//新书登记，对 node 指向的类对象赋值
		void Add_list(Book *p); 			//增加结点到 Book 链表中，用于添加新书时
		char *borrow_book(); 				//借书手续
		char *return_book(); 				//还书手续
		int search_ISBN(char *p); 			//按 ISBN 号查找图书
		int search_BookName(char *p); 		//按书名查找图书
		int search_Writer(char *p); 		//按作者名查找图书
		int search_Publisher(char *p); 		//按出版商查找图书
	    int search_PublishDate(char *p); 	//按出版日期查找图书
		void search(); 						//进入查找菜单
		void show_content(Book *b); 			//显示某本书的内容
		void show_all(); 					//显示所有库存的未被借出的图书
		void delete_onebook(); 				//删除某本书
		void change_content(); 				//更改某本书的信息
		void GoInto_BookInfo(); 			//进入书库信息菜单
		void Helper();
		void Display(int allow);
		friend void GoInto_bor_ret(BookList *book_ptr,ReaderList *reader_ptr);
};

class ReaderList
{
	private:
	    int position; 					//表明链表中的第几个节点
	public:
		Reader *point,*head_point,*rear_point; 		//定义两个 Reader 指针，head_point 为头指针，point 为活动指针
		Reader *before_point;											//rear_point指向链表尾部 
		ReaderList(){
			head_point = new Reader;
			head_point->SetNextNode(NULL);
			rear_point = head_point;
			before_point = head_point;
			point = NULL;
		}				   				 //构造函数，使指针初始化
		void save_readerfile(); 		//存储文件
		void load_readerfile(); 		//上传文件
		void reader_register(); 		//读者注册
		void Add_Point(Reader *p); 		//增加新结点到链表
		void reader_land(); 			//读者登录
		int search_ReaderName(char *p); //按姓名查找
		void show_OneReader(Reader *p); //显示某读者信息
		void change_password(); 		//修改密码
		void delete_reader(); 			//读者注销
		void GoInto_ReaderInfo(); 		//读者信息菜单
		void ShowAll();
		void DeleteAll();
		void Helper(); 
		void exit();
		friend void GoInto_bor_ret(BookList *book_ptr,ReaderList *reader_ptr);
};

