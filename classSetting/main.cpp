#include"BookListReaderList.cpp"

void GoInto_bor_ret(BookList *book_ptr,ReaderList *reader_ptr)
{
	char *book;
	int flag = 0;
	char c;
	cout<<"Do you want to borrow a book or return a book!\n";
	cout<<"(Please enter b or r)"<<endl;
	cin>>c;
	if(c == 'b'){
		book = book_ptr->borrow_book();
		if(book == NULL){
			cout<<"Didn't exsit this book\n";
			return;
		}
		if(book_ptr->node->geti_o() == 1){
			cout<<"This book has already been borrowed\n";
			return;
		}
		else if(reader_ptr->point->Gety_n() == 2){
			cout<<"This reader can not borrow book anymore\n";
			return;
		}
		else{
			reader_ptr->point->BorrowBook(book);
			book_ptr->node->Seti_o(1);
			return;
		}
	} 
	else{
		book = book_ptr->return_book();
		if(book == NULL){
			cout<<"Didn't exsit this book\n";
			return;
		}
		if(book_ptr->node->geti_o() == 0){
			cout<<"This book has not been borrowed\n";
			return;
		}
		else if(reader_ptr->point->ReturnBook(book) == 0){
			cout<<"Return Book Failed\n";
			return;
		}
		else book_ptr->node->Seti_o(0);
	}
}

int main()
{
	BookList book_ptr;
	ReaderList reader_ptr;
	book_ptr.load_file();
	reader_ptr.load_readerfile();

	int m=1;
	while(1)
	{
		cout<<"输入你想进行的操作\n";
		cout<<"1.登录:"<<endl;
		cout<<"2.查看:"<<endl;
		cout<<"3.注册"<<endl;
		cout<<"4.注销"<<endl;
		cout<<"5.修改密码"<<endl;
		cout<<"6.帮助说明"<<endl;
		cout<<"7.清空全部读者信息"<<endl;
		cout<<"8.借书还书"<<endl;
		cout<<"9.显示所有读者的信息"<<endl;
		cout<<"10.退出登录"<<endl;
		cout<<"11.进入图书系统"<<endl;
		cout<<"0.退出"<<endl;
		cin>>m;
		switch(m){
			case 1:{
				reader_ptr.reader_land();
				system("pause");
				system("cls");
				break;
			}
			case 2:{
				reader_ptr.GoInto_ReaderInfo();
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				reader_ptr.reader_register();
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				reader_ptr.delete_reader();
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				reader_ptr.change_password();
				system("pause");
				system("cls");
				break;
			}
			case 6:{
				reader_ptr.Helper();
				system("pause");
				system("cls");
				break;
			}
			case 7:{
				reader_ptr.DeleteAll();
				system("pause");
				system("cls");
				break;
			}
			case 8:{
				GoInto_bor_ret(&book_ptr,&reader_ptr);
				system("pause");
				system("cls");
				break;
			}
			case 9:{
				if(reader_ptr.point->Allow() == 0){
					cout<<"You are not allowed to see all the readers\n";
				}
				else reader_ptr.ShowAll();
				system("pause");
				system("cls");
				break;
			}
			case 10:{
				reader_ptr.exit();
				system("pause");
				system("cls");
				break;
			}
			case 11:{
				if(reader_ptr.point == NULL){
					cout<<"You haven't login in right now!\n";
				}
				else book_ptr.Display(reader_ptr.point->Allow());
				system("pause");
				system("cls");
				break;
			}
			case 0:{
				cout<<"退出系统"<<endl;
				reader_ptr.save_readerfile();
				book_ptr.save_file();
				exit(0);
			}
		}
	} 
	return 0;
}
 
