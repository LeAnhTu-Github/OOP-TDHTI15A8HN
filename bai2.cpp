#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class mayin{
	private:
		char sohieu[30];
		int soluong;
	public:
		void input(){
			cout<<"Nhap vao so hieu: ";
			cin.getline(sohieu,30);
			cout<<"Nhap so luong may: ";
			cin>>soluong;
		}
		void output(){
			cout<<"So hieu may: "<<sohieu<<endl;
			cout<<"So luong: "<<soluong<<endl;
		}
};
class mayinLaze:virtual public mayin{
	public:
		int dpi;
		void getDpi(){
			cout<<"Nhap vao so dpi: ";
			cin>>dpi;
		}
		void putDpi(){
			cout<<"So dpi: "<<dpi<<endl;
		}
};
class mayinColor:virtual public mayin{
	public:
		char maMau[10];
		void getColor(){
			cout<<"Nhap vao ma mau: ";
			cin.getline(maMau, 10);
		}
		void putColor(){
			cout<<"Mau may: "<<maMau<<endl;
		}
};
class LazeColor:public mayinLaze, public mayinColor{
	public:
		void display(){
			output();
			putDpi();
			putColor();
		}
};
int main(){
	LazeColor a;
	a.input();
	a.getDpi();
	fflush(stdin);
	a.getColor();
	a.display();
	return 0;
}
