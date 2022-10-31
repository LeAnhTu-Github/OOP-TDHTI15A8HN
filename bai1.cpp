#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std; 
class student{
	char masv[10];
	char hoten[30];
	char gt[4];
	public:
		student(){
			strcpy(masv, "");
			strcpy(hoten, "");
			strcpy(gt, "");
		}
		~student(){}
		friend istream& operator>> (istream& is,student& z)
		{
	        fflush(stdin);
	    	cout<<"Nhap ma sinh vien: ";
	    	is.getline(z.masv,10);
            fflush(stdin);
	    	cout<<"Nhap ho ten sinh vien: ";
	    	is.getline(z.hoten, 30);
	    	cout<<"Nhap gioi tinh: ";
	    	is.getline(z.gt, 4);
			return is;
		}
		friend ostream& operator<< (ostream& os,student& z)
		{
	    	os<<z.masv
	    	  <<setw(15)<<z.hoten
	    	  <<setw(15)<<z.gt;

			return os;
		}	
        char* getGt(){
            return this->gt;
        }
        char* getName(){
            return this->hoten;
        }
};
class monhoc{
	int maMon;
	char tenMon[30];
	public:
		monhoc(){
			maMon = 0;
			strcpy(tenMon, "");
		}
		~monhoc(){}
		friend istream& operator>> (istream& is,monhoc& m)
		{
	        fflush(stdin);
	    	cout<<"Nhap ma mon hoc: ";
	    	is>>m.maMon;
            fflush(stdin);
	    	cout<<"Nhap ten mon hoc: ";
	    	is.getline(m.tenMon, 30);
			return is;
		}
		friend ostream& operator<< (ostream& os,monhoc& m)
		{
	    	os<<setw(15)<<m.maMon
	    	  <<setw(15)<<m.tenMon;
			return os;
		}
        char* getNameMH(){
            return this->tenMon;
        }
};
class DIEMMH:public student, public monhoc{
	float diemthi;
	public:
		friend istream& operator>> (istream& is,DIEMMH& d)
		{
	        fflush(stdin);
			is>>(student&) d;
			is>>(monhoc&) d;
	    	cout<<"Nhap diem thi: ";
	    	is>>d.diemthi;
			return is;
		}
		friend ostream& operator<< (ostream& os,DIEMMH& d)
		{
			os<<(student&) d;
			os<<(monhoc&) d
	    	  <<setw(15)<<d.diemthi<<endl;
			return os;
		}
        float getDiem(){
            return this->diemthi;
        }
		
};
int main(){
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
	DIEMMH sv[n];
// ==================================================
//  1.Input Info
    for(int i=0; i<n; i++){
        cout<<"\nNhap thong tin sinh vien thu "<<i+1<<endl;
        cin>>sv[i];
    }

//  2.Output Info 
    cout<<"\t\t\tDANH SACH SINH VIEN: "<<endl;
    for(int i=0; i<n; i++){
        cout<<sv[i];
    }

//  3.Check 
    cout<<"\t\t\tDANH SACH SINH VIEN NAM: "<<endl;
    for(int i=0; i<n; i++){
        if(strcmpi(sv[i].getGt(), "nam") == 0){
            cout<<sv[i];
        }
    }

//  4.Sum Point
    float sum = 0;
    for(int i=0; i<n; i++){
        sum += sv[i].getDiem();
    }
    cout<<"Diem trung binh mon hoc cua cac sinh vien = "<<sum/n<<endl;

//  5.Find Name X

    char x[30];
    int count = 0;
    cout<<"Nhap ten sinh vien can tim: ";
    fflush(stdin);
    cin.getline(x, 30);
    cout<<"\t\t\t\tDANH SACH SINH VIEN TEN "<<x<<" LA: "<<endl; 
    for(int i=0; i<n; i++){
        if(strcmpi(sv[i].getName(), x) == 0){
            count++;
            cout<<sv[i];
        }
    }

//  6.Find Math Min
    cout<<"\t\t\t THONG TIN SINH VIEN CO DIEM TOAN THAP NHAT: "<<endl;
    for(int i=0; i<n; i++){
        if(strcmpi(sv[i].getNameMH(), "toan") == 0){
            float min = sv[0].getDiem();
            if(sv[i].getDiem() < min){
                cout<<sv[i];
            }
        }
    }

//  7.Sort
    cout<<"\t\t\tDANH SACH SINH VIEN THEO CHIEU GIAM DAN: "<<endl;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(sv[i].getDiem() > sv[j].getDiem()){
                swap(sv[i], sv[j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<sv[i];
    }
	return 0;
}
