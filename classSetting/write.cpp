#include<iostream>
#include<fstream>
using namespace std;

struct book
{
	char bookname[256];
	char ISBN[80];
	char writer[256];
	char publisher[256];
	char publishDate[80],briefIntroduction[512];
	char ebook[80],paperbook[80];
	float Ebookprice,BookPrice;
	int y_n;
};

struct person{
	char r[80],pa[80];
	char book1[256],book2[256];
	int allow;
};

int main()
{
	book b;
	char c;
	fstream in("book.txt",ios::in);
	fstream out("Books.txt",ios::out|ios::binary);
	in.getline(b.bookname,256);
	in.getline(b.ISBN,80);
	in.getline(b.writer,256);
	in.getline(b.publisher,256);
	in.getline(b.publishDate,80);
	in.getline(b.briefIntroduction,512);
	in.getline(b.ebook,80);
	in.getline(b.paperbook,80);
	in>>b.Ebookprice;
	in>>b.BookPrice;
	in>>b.y_n;
	c = in.get();
	while(!in.eof())
	{
		out.write((char*)&b,sizeof(b));
		if(!in.eof()) in.getline(b.bookname,256);
		if(!in.eof()) in.getline(b.ISBN,80);
		if(!in.eof()) in.getline(b.writer,256);
		if(!in.eof()) in.getline(b.publisher,256);
		if(!in.eof()) in.getline(b.publishDate,80);
		if(!in.eof()) in.getline(b.briefIntroduction,512);
		if(!in.eof()) in.getline(b.ebook,80);
		if(!in.eof()) in.getline(b.paperbook,80);
		if(!in.eof()) in>>b.Ebookprice;
		if(!in.eof()) in>>b.BookPrice;
		if(!in.eof()){
		    in>>b.y_n;
		    c = in.get();
		} 
	}
	in.close();
	out.close();
	in.open("Books.txt",ios::in|ios::binary);
	in.read((char*)&b,sizeof(b));
	while(!in.eof())
	{
		cout<<b.bookname<<endl;
		cout<<b.ISBN<<endl;
		cout<<b.writer<<endl;
		cout<<b.publisher<<endl;
		cout<<b.publishDate<<endl;
		cout<<b.briefIntroduction<<endl;
		cout<<b.ebook<<endl;
		cout<<b.paperbook<<endl;
		cout<<b.Ebookprice<<endl;
		cout<<b.BookPrice<<endl;
		cout<<b.y_n<<endl;
		in.read((char*)&b,sizeof(b));
	}
	in.close();
	return 0;
}


/*int main()
{
	char bn[256],I[80],w[256],pl[256];
	char pd[80],bi[512];
	char eb[80],pb[80];
	float a,b;
	fstream in("Books.txt",ios::in|ios::binary);
	in.read((char*)&bn,sizeof(bn));
	in.read((char*)&I,sizeof(I));
	in.read((char*)&w,sizeof(w));
	in.read((char*)&pl,sizeof(pl));
	in.read((char*)&pd,sizeof(pd));
	in.read((char*)&bi,sizeof(bi));
	in.read((char*)&eb,sizeof(eb));
	in.read((char*)&pb,sizeof(pb));
	in.read((char*)&a,sizeof(a));
	in.read((char*)&b,sizeof(b));
	while(!in.eof()){
		cout<<bn<<endl;
		cout<<I<<endl;
		cout<<w<<endl;
		cout<<pl<<endl;
		cout<<pd<<endl;
		cout<<bi<<endl;
		cout<<eb<<endl;
		cout<<pb<<endl;
		cout<<a<<endl;
		cout<<b<<endl;
		in.read((char*)&bn,sizeof(bn));
		in.read((char*)&I,sizeof(I));
		in.read((char*)&w,sizeof(w));
		in.read((char*)&pl,sizeof(pl));
		in.read((char*)&pd,sizeof(pd));
		in.read((char*)&bi,sizeof(bi));
		in.read((char*)&eb,sizeof(eb));
		in.read((char*)&pb,sizeof(pb));
		in.read((char*)&(a),sizeof(a));
		in.read((char*)&(b),sizeof(b));
	}
	in.close();
}*/

/*int main()
{
	person p;
	char c;
	fstream in("reader.txt",ios::in);
	fstream out("ReaderList.txt",ios::out|ios::binary);
	in.getline(p.r,80);
	in.getline(p.pa,80);
	in.getline(p.book1,256);
	in.getline(p.book2,256);
	in>>p.allow;
	c = in.get();
	while(!in.eof())
	{
		out.write((char*)&p,sizeof(p));
		if(!in.eof()) in.getline(p.r,80);
		if(!in.eof()) in.getline(p.pa,80);
		if(!in.eof()) in.getline(p.book1,256);
		if(!in.eof()) in.getline(p.book2,256);
		if(!in.eof()) {
			in>>p.allow;
			c = in.get();
		}
		
	}
	in.close();
	out.close();
	in.open("ReaderList.txt",ios::in|ios::binary);
	in.read((char*)&p,sizeof(p));
	while(!in.eof())
	{
		cout<<p.r<<endl;
		cout<<p.pa<<endl;
		cout<<p.book1<<endl;
		cout<<p.book2<<endl;
		cout<<p.allow<<endl;
		in.read((char*)&p,sizeof(p));
	}
	in.close();
	return 0;
}*/
