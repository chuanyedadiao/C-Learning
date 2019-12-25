#include"BookListReaderList.h" 

void BookList::save_file()
{
	float a,b;
	int temp;
	before_node = head_ptr;
	node = head_ptr->GetNextNode();
	fstream out("Books.txt",ios::out|ios::binary);
	if(!out){
		cout<<"Can not open the file \n";
		exit(0);
	}
	while(node)
	{
		out.write((char*)node->GetBookName(),256);
		out.write((char*)node->GetISBN(),80);
		out.write((char*)node->GetWriter(),256);
		out.write((char*)node->GetPublisher(),256);
		out.write((char*)node->GetPublishDate(),80);
		out.write((char*)node->GetBriefIntroduction(),512);
		out.write((char*)node->GetEbook(),80);
		out.write((char*)node->GetPaperBook(),80);
		a = node->GetEbookprice();
		b = node->GetBookPrice();
	    out.write((char*)&a,sizeof(float));
		out.write((char*)&b,sizeof(float));
		temp = node->geti_o();
		out.write((char*)&temp,4);
		before_node = node;
		node = node->GetNextNode();
	}
	out.close();
}

void BookList::load_file()
{
	Book *p;
	fstream in("Books.txt",ios::in|ios::binary);
	if(!in){
		cout<<"Can not open the file\n";
		exit(0);
	}
	char bn[256],I[80],w[256],pl[256];
	char pd[80],bi[512];
	char eb[80],pb[80];
	float a,b;
	int temp;
	in.read((char*)bn,sizeof(bn));
	in.read((char*)I,sizeof(I));
	in.read((char*)w,sizeof(w));
	in.read((char*)pl,sizeof(pl));
	in.read((char*)pd,sizeof(pd));
	in.read((char*)bi,sizeof(bi));
	in.read((char*)eb,sizeof(eb));
	in.read((char*)pb,sizeof(pb));
	in.read((char*)&a,sizeof(a));
	in.read((char*)&b,sizeof(b));
	in.read((char*)&temp,sizeof(temp));
	while(!in.eof()){
		p = new Book;
		p->SetBookName(bn);
		p->SetISBN(I);
		p->SetWriter(w);
		p->SetPublisher(pl);
		p->SetPublishDate(pd);
		p->SetBriefIntroduction(bi);
		p->SetEbook(eb);
		p->SetPaperBook(pb);
		p->SetEbookprice(a);
		p->SetBookPrice(b);
		p->Seti_o(temp);
		p->SetNextNode(NULL);
		Add_list(p);
		if(!in.eof()) in.read((char*)bn,sizeof(bn));
		if(!in.eof()) in.read((char*)I,sizeof(I));
		if(!in.eof()) in.read((char*)w,sizeof(w));
		if(!in.eof()) in.read((char*)pl,sizeof(pl));
		if(!in.eof()) in.read((char*)pd,sizeof(pd));
		if(!in.eof()) in.read((char*)bi,sizeof(bi));
		if(!in.eof()) in.read((char*)eb,sizeof(eb));
		if(!in.eof()) in.read((char*)pb,sizeof(pb));
		if(!in.eof()) in.read((char*)&(a),sizeof(a));
		if(!in.eof()) in.read((char*)&(b),sizeof(b));
		if(!in.eof()) in.read((char*)&temp,sizeof(temp));
	}
	in.close();
}

void BookList::AddNewBook()
{
	char bookname[256],ISBN[80],writer[80],publisher[256];
	char publishDate[80],briefIntroduction[512];
	char ebook[80],paperbook[80];
	float Ebookprice,BookPrice;
	cout<<"输入新书的名字:"<<endl;
	cin>>bookname;
	cout<<"输入新书的ISBN:"<<endl;
	cin>>ISBN;
	cout<<"输入新书的作者:"<<endl;
	cin>>writer;
	cout<<"输入新书的出版商:"<<endl;
	cin>>publisher;
	cout<<"输入新书的出版日期:"<<endl;
	cin>>publishDate;
	cout<<"输入新书的简介:"<<endl;
	cin>>briefIntroduction;
	cout<<"输入书本类型:"<<endl;
	cin>>ebook;
	cout<<"输入书本类型的价格:"<<endl;
	cin>>Ebookprice;
	cout<<"输入书本的纸张类型:"<<endl;
	cin>>paperbook;
	cout<<"输入书本的价格:"<<endl;
	cin>>BookPrice;
	Book *temp;
	temp = new Book;
	temp->SetBookName(bookname);
	temp->SetISBN(ISBN);
	temp->SetWriter(writer);
	temp->SetPublisher(publisher);
	temp->SetPublishDate(publishDate);
	temp->SetBriefIntroduction(briefIntroduction);
	temp->Seti_o(0);
	temp->SetEbookprice(Ebookprice);
	temp->SetEbook(ebook);
	temp->SetBookPrice(BookPrice);
	temp->SetPaperBook(paperbook);
	temp->SetNextNode(NULL);
	Add_list(temp);
}

void BookList::Add_list(Book *p)
{
	rear_ptr->SetNextNode(p);
	rear_ptr = p;
}

char *BookList::borrow_book()
{
	char temp[80];
	cout<<"Before Borrow,you have to search this book By ISBN!\n";
	cout<<"Please enter the ISBN of the book you want to find\n";
	cin>>temp;
	search_ISBN(temp);
	if(node != NULL){
		return node->GetBookName();
	}
	else return NULL; 
}

char *BookList::return_book()
{
	char temp[80];
	cout<<"Before Return,you have to search this book By ISBN!\n";
	cout<<"Please enter the ISBN of the book you want to return\n";
	cin>>temp;
	search_ISBN(temp);
	if(node != NULL){
		return node->GetBookName();
	}
	else return NULL; 
}

int BookList::search_ISBN(char *p)
{
	int flag = 0;
	before_node = head_ptr;
	node = head_ptr->GetNextNode();
	while(node){
		if(strcmp(node->GetISBN(),p) == 0){
			flag = 1;
			break;
		}
		before_node = node;
		node = before_node->GetNextNode();
	}
	return flag;
} 

int BookList::search_BookName(char *p)
{
	int flag = 0;
	before_node = head_ptr;
	node = head_ptr->GetNextNode();
	while(node){
		if(strcmp(node->GetBookName(),p) == 0){
			flag = 1;
			break;
		}
		before_node = node;
		node = before_node->GetNextNode();
	}
	return flag;
}

int BookList::search_Writer(char *p)
{
	int flag = 0;
	before_node = head_ptr;
	node = head_ptr->GetNextNode();
	while(node){
		if(strcmp(node->GetWriter(),p) == 0){
			flag = 1;
			break;
		}
		before_node = node;
		node = before_node->GetNextNode();
	}
	return flag;
}

int BookList::search_Publisher(char *p)
{
	int flag = 0;
	before_node = head_ptr;
	node = head_ptr->GetNextNode();
	while(node){
		if(strcmp(node->GetPublisher(),p) == 0){
			flag = 1;
			break;
		}
		before_node = node;
		node = before_node->GetNextNode();
	}
	return flag;
}

int BookList::search_PublishDate(char *p)
{
	int flag = 0;
	before_node = head_ptr;
	node = head_ptr->GetNextNode();
	while(node){
		if(strcmp(node->GetPublishDate(),p) == 0){
			flag = 1;
			break;
		}
		before_node = node;
		node = before_node->GetNextNode();
	}
	return flag;
}

void BookList::search()
{
	char searchName[80];
	char temp[256];
	cout<<"Do you want to search book by what?"<<endl;
	cout<<"Please enter ISBN or BookName or Writer or Publisher or PublishDate"<<endl;
	cin>>searchName;
	int judge[5];
	judge[0] = strcmp(searchName,"ISBN");
	judge[1] = strcmp(searchName,"BookName");
	judge[2] = strcmp(searchName,"Writer");
	judge[3] = strcmp(searchName,"Publisher");
	judge[4] = strcmp(searchName,"PublishDate");
	if(judge[0] == 0){
		cout<<"Please enter the ISBN you want to find\n";
		cin>>temp;
		if(search_ISBN(temp) == 0){
			cout<<"There is no such a book\n";
			return;
		}
		show_content(node);
		return;
	}
	if(judge[1] == 0){
		cout<<"Please enter the BookName you want to find\n";
		cin>>temp;
		if(search_BookName(temp) == 0){
			cout<<"There is no such a book\n";
			return;
		}
		show_content(node);
		return ;
	}
	if(judge[2] == 0){
		cout<<"Please enter the Writer you want to find\n";
		cin>>temp;
		if(search_Writer(temp) == 0){
			cout<<"There is no such a book\n";
			return;
		}
		show_content(node);
		return ;
	}
	if(judge[3] == 0){
		cout<<"Please enter the Publisher you want to find\n";
		cin>>temp;
		if(search_Publisher(temp) ==0){
			cout<<"There is no such a book\n";
			return;
		};
		show_content(node);
		return;
	}
	if(judge[4] == 0){
		cout<<"Please enter the PublishDate you want to find\n";
		cin>>temp;
		if(search_PublishDate(temp) == 0){
			cout<<"There is no such a book\n";
			return;
		}
		show_content(node);
		return ;
	}
}

void BookList::show_content(Book *b)
{
	if(b!=NULL){
		b->print();
	}
}

void BookList::show_all()
{
	Book *b1;
	b1 = head_ptr->GetNextNode();
	while(b1){
		if(b1->geti_o() == 0)
		    show_content(b1);
		b1 = b1->GetNextNode();
	}
}

void BookList::delete_onebook()
{
	Book *t;
	search(); //找到对应的node
	if(node == rear_ptr){
		t = node->GetNextNode();
		before_node->SetNextNode(t);
		delete node;
		node = NULL;
		rear_ptr = before_node;
		before_node = head_ptr;
		return ;
	} 
	t = node->GetNextNode();
	before_node->SetNextNode(t);
	delete node;
	node = NULL;
	before_node = head_ptr;
	return ;
}

void BookList::change_content()
{
    search();
    int judge[6];
    char searchName[80],temp[256];
    cout<<"what information do you want to change in this book?"<<endl;
	cout<<"Please enter ISBN or BookName or Writer or Publisher or PublishDate";
	cout<<"or BriefIntroduction"<<endl;
	cin>>searchName;
	judge[0] = strcmp(searchName,"ISBN");
	judge[1] = strcmp(searchName,"BookName");
	judge[2] = strcmp(searchName,"Writer");
	judge[3] = strcmp(searchName,"Publisher");
	judge[4] = strcmp(searchName,"PublishDate");
	judge[5] = strcmp(searchName,"BriefIntroduction");
	if(judge[0] == 0){
		cout<<"Please enter the ISBN you want to change\n";
		cin>>temp;
		node->SetISBN(temp);
		return ;
	}
	if(judge[1] == 0){
		cout<<"Please enter the BookName you want to change\n";
		cin>>temp;
		node->SetBookName(temp);
		return ;
	}
	if(judge[2] == 0){
		cout<<"Please enter the Writer you want to change\n";
		cin>>temp;
		node->SetWriter(temp);
		return ;
	}
	if(judge[3] == 0){
		cout<<"Please enter the Publisher you want to change\n";
		cin>>temp;
		node->SetPublisher(temp);
		return ;
	}
	if(judge[4] == 0){
		cout<<"Please enter the PublishDate you want to change\n";
		cin>>temp;
		node->SetPublishDate(temp);
		return ;
	}
	if(judge[5] == 0){
		cout<<"Please enter the BriefIntroduction you want to change\n";
		cin>>temp;
		node->SetBriefIntroduction(temp);
		return ;
	}
}

void BookList::GoInto_BookInfo()
{
	Book *b1;
	b1 = head_ptr->GetNextNode();
	while(b1){
	    show_content(b1);
		b1 = b1->GetNextNode();
	}
}

void BookList::Helper()
{
	cout<<"请务必先登录\n"<<endl;
	cout<<"有借书功能"<<endl;
	cout<<"有还书功能"<<endl;
}

void BookList::Display(int allow)
{
	system("cls");
	int m=1;
	while(1)
	{
		cout<<"输入你想进行的操作\n";
		cout<<"1.查找某一本书"<<endl;
		cout<<"2.展示所有未借出的书本"<<endl;
		cout<<"3.展示所有的图书"<<endl;
		cout<<"4.删除某一本书"<<endl;
		cout<<"5.改变某本书的内容"<<endl;
		cout<<"6.帮助说明"<<endl;
		cout<<"0.退出"<<endl;
		cin>>m;
		switch(m){
			case 1:{
				search();
				system("pause");
				system("cls");
				break;
			}
			case 2:{
				show_all();
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				GoInto_BookInfo();
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				if(allow == 0){
					cout<<"You are not allowed to delete one book"<<endl;
				} 
				else delete_onebook();
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				if(allow == 0){
					cout<<"You are not allowed to change one book"<<endl;
				} 
				else change_content();
				system("pause");
				system("cls");
				break;
			}
			case 6:{
				Helper();
				system("pause");
				system("cls");
				break;
			}
			case 0:{
				return;
			}
		}
	} 
}

//ReaderList

void ReaderList::save_readerfile()
{
	int i;
	fstream out("ReaderList.txt",ios::out|ios::binary);
	before_point = head_point;
	point = before_point->GetNextNode();
	while(point){
		out.write((char*)point->GetReaderName(),80);
		out.write((char*)point->GetPassWord(),80);
		out.write((char*)point->GetBook1(),256);
		out.write((char*)point->GetBook2(),256);
		i = point->Allow();
		out.write((char*)&i,4);
		point = point->GetNextNode();
	}
	out.close();
}

void ReaderList::load_readerfile()
{
	Reader *p;
	fstream in("ReaderList.txt",ios::in|ios::binary);
    char r[80],pa[80];
    char book1[256],book2[256];
    int allow;
    in.read((char*)r,80);
    in.read((char*)pa,80);
    in.read((char*)book1,256);
    in.read((char*)book2,256);
    in.read((char*)&allow,4);
	while(!in.eof())
    {
    	if(allow == 1){
    		p = new administrator;
    		p->SetReaderName(r);
    		p->SetPassword(pa);
    		p->BorrowBook(book1);
    		p->BorrowBook(book2);
    		p->SetNextNode(NULL);
    		Add_Point(p);
    	}
    	else{
    		p = new Reader;
    		p->SetReaderName(r);
    		p->SetPassword(pa);
    		p->BorrowBook(book1);
    		p->BorrowBook(book2);
    		p->SetNextNode(NULL);
    		Add_Point(p);
    	}
    	if(!in.eof()) in.read((char*)r,80);
	    if(!in.eof()) in.read((char*)pa,80);
	    if(!in.eof()) in.read((char*)book1,256);
	    if(!in.eof()) in.read((char*)book2,256);
	    if(!in.eof()) in.read((char*)&allow,4);
    }
	in.close();
}


void ReaderList::reader_register()
{
	int a;
	Reader *in;
	char ReaderName[80],Password[80];
	cout<<"Please enter the ReaderName\n";
	cin>>ReaderName;//判断不能和之前的结点的一样
	while(search_ReaderName(ReaderName) != 0){
		cout<<"This UserName has already been loged\n";
		cout<<"Please enter again\n";
		cin>>ReaderName;
	}
	cout<<"Please enter the Password\n";
	cin>>Password;
	cout<<"Are you administrator? if Yes enter 1,else enter 0\n";
	cin>>a;
	if(a==1){
		in = new administrator(ReaderName,Password);
		in->SetNextNode(NULL);
	    Add_Point(in);
	}
	else{
		in = new Reader(ReaderName,Password);
		in->SetNextNode(NULL);
		Add_Point(in);	
	}
}

void ReaderList::Add_Point(Reader *p)
{
	rear_point->SetNextNode(p);
	rear_point = p;
}

void ReaderList::reader_land()
{
	char r[80],password[80];
	int i = 1,flag = 1;
	cout<<"Please enter your UserName\n";
	cin>>r;
	position = search_ReaderName(r);
	while(!position){
		if(flag == 5){
			cout<<"You have already login in for 5 times\n";
			return;
		}
		system("cls");
		cout<<"This User didn't login in\n";
		cout<<"Please enter again\n";
		flag++;
		cin>>r;
		position = search_ReaderName(r);
	}
	flag = 1;
	before_point = head_point;
	point = head_point->GetNextNode();
	while(i < position && point){
		before_point = point;
		point = point->GetNextNode();
		i++;
	}
	cout<<"Please enter your PassWord\n";
	cin>>password;
	while(strcmp(point->GetPassWord(),password) != 0){
		cout<<"Wrong Password\n";
		cout<<"Please enter again\n";
		cin>>password;
		flag++;
		if(flag == 5){
			cout<<"You have already enter wrong password for 5 times\n";
			point = NULL;
			return ;
		}//输错五次停止输入 
	}
	cout<<"Login success\n";
}

int ReaderList::search_ReaderName(char *p)
{
	int i = 1;
	point = head_point->GetNextNode();
	while(point){
		if(strcmp(point->GetReaderName(),p) == 0)
		    break;
		point = point->GetNextNode();
		i++;
	}
	if(point == NULL){
		return 0;
	}
	else return i;
}

void ReaderList::show_OneReader(Reader *p)
{
	if(p!=NULL)
	{
	    p->showInfo();	
	}	
}

void ReaderList::change_password()
{
	if(point == NULL)
	{
		cout<<"You login in unseccessful\n";
		cout<<"Please login again\n";
		return ;
	}
	char p[80]; 
	cout<<"Please enter the password you want to change\n";
	cin>>p;
	point->SetPassword(p);
}

void ReaderList::delete_reader()
{
	if(point == NULL)
	{
		cout<<"You login in unseccessful\n";
		cout<<"Please login again\n";
		return ;
	}
	if(rear_point == point){
		delete point;
		rear_point = head_point;
		point = NULL;
		return ;
	}
	Reader *p;
	p = point->GetNextNode();
	before_point->SetNextNode(p);
	delete point;
	point = NULL;
	before_point = head_point;
	cout<<"Delete successfully\n";
}

void ReaderList::GoInto_ReaderInfo()
{
	if(point == NULL)
	{
		cout<<"You login in unseccessful\n";
		cout<<"Please login again\n";
		return ;
	}
	show_OneReader(point);
}

void ReaderList::ShowAll()
{
	Reader *p;
	p = head_point->GetNextNode();
	while(p)
	{
		show_OneReader(p);
		p = p->GetNextNode();
	}
}

void ReaderList::DeleteAll()
{
	if(!point->Allow()){
		cout<<"You are not allowed to delete all readers\n";
		return;
	}
	Reader *p;
	before_point = head_point;
	point = head_point->GetNextNode();
	while(point)
	{
		before_point = point;
		p = point->GetNextNode();
		delete point;
		point = p;
	}
	head_point->SetNextNode(NULL);
	rear_point = head_point;
	point = NULL;
	cout<<"Delete All Readers\n";
}

void ReaderList::exit()
{
	before_point = head_point;
	point = NULL;
}

void ReaderList::Helper()
{
	cout<<"a.登录:"<<"需要输入姓名和密码,五次输错密码会强制退出登录界面"<<endl;
	cout<<"b.注册"<<endl;
	cout<<"c.注销当前读者的所有信息."<<endl;
	cout<<"d.修改密码"<<endl;
	cout<<"e.当前界面为帮助说明"<<endl;
	cout<<"f.返回上一层"<<endl;
	cout<<"g.清空全部读者信息,需要一定权限做这个事"<<endl;
}

