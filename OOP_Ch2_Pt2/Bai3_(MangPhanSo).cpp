/*Thiết kế và cái đặt lớp Mảng Phân Số một chiều có n phần tử (được cấp phát động), mỗi phần tử là một đối tượng phân số.
Hãy xây dựng chương trình để quản lý các đối tượng thuộc lớp Mảng có các chức năng sau:
	- Khởi tạo mảng (mặc định, có tham số, sao chép);
	- Nhập mảng (overloaded function);
		o Với giá trị các phần tử nhập theo ý người dùng;
		o Với giá trị các phần tử được phát sinh ngẫu nhiên;
		o Với giá trị các phần tử được nhập từ tập tin lưu trữ ngoài;
	- Xuất mảng (overloaded function);
		o In mảng ra màn hình;
		o In mảng ra tập tin lưu trữ ngoài;
	- Thay đổi số lượng phần tử mảng:
		o Chèn thêm phần tử mới vào mảng tại vị trí k (0<=k<=n)
		o Xóa phần tử khỏi mảng tại vị trí k (0<=k<=n)
	- Sắp xếp mảng (thuật toán tự chọn)
		o Tăng hay giảm phụ thuộc vào tham số. Vd: MyArray.Sort(“asc”); hoặc MyArray.Sort(“desc”);
Chương trình cho phép người dùng chọn lựa chức năng dưới dạng menu và phải có tính liên tục*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>	//_getch()
#include <ctime>	//time dung trg srand
#include <cstdlib>	//srand, rand

using namespace std;

class mangPS;
class phanSo {
private:
	int tu, mau;
public:
	phanSo();
	phanSo(int);
	phanSo(int, int);
	int getTu();
	int getMau();
	void setTu(int);
	void setMau(int);
	void operator=(phanSo);
	friend istream& operator>>(istream&, phanSo&);
	friend ostream& operator<<(ostream&, phanSo);
};

class mangPS {
private:
	int size;
	phanSo *p;
public:
	mangPS();				//khoi tao mac dinh
	mangPS(int);			//khoi tao co tham so
	mangPS(int, int);
	mangPS(int, int, int);
	mangPS(const mangPS &);	//ham thiet lap sao chep
	~mangPS();				//ham huy bo
	int getSize();
	//void nhap();
	//void xuat();
	void dayCuoi(phanSo);
	void operator=(mangPS);
	phanSo& operator[](int);
	void chenPhanTu(phanSo, int);
	friend istream& operator>>(istream&, mangPS&);
	friend ostream& operator<<(ostream&, mangPS);
};

void nhapSaiRoi();

void chooseMainMenu();
void chooseMenuInput();
void chooseMenuOutput();
void chooseMenuInsertAndRemove();
void chooseMenuSort();

char showMainMenu();
char showMenuInput();
char showMenuOutput();
char showMenuInsertAndRemove();
char showMenuSort();

/*CHÚ Ý:
Muốn khai báo như:
	mangPS a, b(a);
Hoặc:
	mangPS a, b = a;
Ta cần phải có hàm sao chép, hàm sao chép phải nên có const.
VD:
	mangPS(const mangPS &);
Còn nếu muốn:
	mangPS a, b;
	a = b;
Ta phải nạp chồng toán tử gán*/

int main() {
	srand((unsigned int)time(NULL));
	//mangPS a;
	//phanSo ps(0);
	//int viTri;
	//cin >> a;
	//cout << a;

	//mangPS* a = new mangPS(0);
	//cin >> *a;
	//cout << *a;

	chooseMainMenu();

	//vector<int> vect(3);
	//cout << vect.at(0) << " " << vect.at(1);

	/*cout << "nhap mang phan so: ";
	a.nhap();
	cout << "nhap phan so muon chen: ";
	cin >> ps;
	cout << "nhap vi tri mun chen: ";
	cin >> viTri;
	cout << "Mang a truoc khi chen them 1 phan so:" << endl;
	a.xuat();
	cout << endl;
	a.chenPhanTu(ps, viTri);
	cout << "b sau chen" << endl;
	a.xuat();*/

	/*vector<phanSo> mangPhanSo;
	phanSo ps, psVT;
	int viTri;
	cout << "nhap phan so muon chen: ";
	cin >> psVT;
	cout << "nhap vi tri mun chen: ";
	cin >> viTri;
	cout << "nhap phan so mun chen: ";
	for (; cin >> ps;) {
		mangPhanSo.push_back(ps);
	}
	mangPhanSo.insert(mangPhanSo.begin() + viTri, 1, psVT);
	for (int i = 0; i < mangPhanSo.size(); i++) {
		cout << mangPhanSo.at(i) << " ";
	}*/
	return 0;
}

//class phan so
phanSo::phanSo() {
	this->tu = 0;
	this->mau = 1;
}
phanSo::phanSo(int tu) {
	this->tu = tu;
	this->mau = 1;
}
phanSo::phanSo(int tu, int mau) {
	this->tu = tu;
	this->mau = mau;
}

int phanSo::getTu() {
	return this->tu;
}
int phanSo::getMau() {
	return this->mau;
}

void phanSo::setTu(int tu) {
	this->tu = tu;
}
void phanSo::setMau(int mau) {
	this->mau = mau;
}

void phanSo::operator=(phanSo ps) {
	tu = ps.getTu();
	mau = ps.getMau();
}

istream & operator>>(istream & in, phanSo & ps) {
	in >> ps.tu >> ps.mau;
	return in;
}
ostream & operator<<(ostream & out, phanSo ps) {
	out << ps.getTu() << "/" << ps.getMau();
	return out;
}

//class mang phan so
mangPS::mangPS() {
	this->size = 0;
	this->p = new phanSo[this->size];
}
mangPS::mangPS(int size) {
	this->size = size;
	this->p = new phanSo[this->size];
}
mangPS::mangPS(int size, int tu) {
	this->size = size;
	this->p = new phanSo[this->size];
	for (int i = 0; i < this->size; i++) {
		p[i].setTu(tu);
	}
}
mangPS::mangPS(int size, int tu, int mau) {
	this->size = size;
	this->p = new phanSo[this->size];
	for (int i = 0; i < this->size; i++) {
		p[i].setTu(tu);
		p[i].setMau(mau);
	}
}
mangPS::mangPS(const mangPS &u) {
	this->size = u.size;
	p = new phanSo[this->size];
	for (int i = 0; i < this->getSize(); i++) {
		p[i] = u.p[i];
	}
}
mangPS::~mangPS() {
	delete[]p;
	p = NULL;
}

int mangPS::getSize() {
	return this->size;
}

//void mangPS::nhap() {
//	if (p == NULL) {
//		p = new phanSo[this->getSize()];
//	}
//	for (int i = 0; i < this->getSize(); i++) {
//		cin >> p[i];
//	}
//}
//void mangPS::xuat() {
//	for (int i = 0; i < this->getSize(); i++) {
//		cout << p[i] << " ";
//	}
//}

void mangPS::dayCuoi(phanSo ps) {
	p[size] = ps;
	this->size++;
}

void mangPS::operator=(mangPS u) {
	this->size = u.getSize();
	p = new phanSo[this->size];
	for (int i = 0; i < this->getSize(); i++) {
		p[i] = u[i];
	}
}
phanSo & mangPS::operator[](int index) {
	return p[index];
}

void mangPS::chenPhanTu(phanSo ps, int viTri) {
	this->size++;
	for (int i = this->getSize(); i > viTri; i--) {
		p[i] = p[i - 1];
	}
	p[viTri] = ps;
}

istream & operator>>(istream & is, mangPS & m) {
	phanSo ps;
	//if (m.p == NULL) {
	//	m.p = new phanSo[m.getSize()];
	//}
	if (m.size == 0) {
		for (; cin >> ps;) {
			m.dayCuoi(ps);
		}
	}
	else {
		for (int i = 0; i < m.getSize(); i++) {
			is >> m[i];
		}
	}
	return is;
}
ostream & operator<<(ostream & os, mangPS m) {
	for (int i = 0; i < m.getSize(); i++) {
		os << m[i] << " ";
	}
	return os;
}

void nhapSaiRoi() {
	int nhapSai = rand() % 9 + 1;
	switch (nhapSai) {
	case 1:
		cout << "Bot said: o kia bn ?? nhap cai gi vay bn ??:D?? nhap lai ik" << endl;
		break;
	case 2:
		cout << "Bot said: cai cau nay, cau toang cau roi =)))) nhap v ma coi dc ??? nhap lai nhanh!!!!!" << endl;
		break;
	case 3:
		cout << "Bot said: r r, tui chiu cau r :<<< nhap tum lum het ak, nhap lai ik" << endl;
		break;
	case 4:
		cout << "Bot said: nhap sai roi ban, hong co dzui >,< nhap lai ik" << endl;
		break;
	case 5:
		cout << "Bot said: dau phong bn, bn dua tui ak :))))) nhap lai nao" << endl;
		break;
	case 6:
		cout << "Bot said: tuk ak, cau nhap v ma coi dc a :Vvvvv nhap lai!!!!" << endl;
		break;
	case 7:
		cout << "Bot said: haizzz em met r, Dev ra chao di kia, nhac bn nhap lai dum em" << endl;
		break;
	case 8:
		cout << "Bot said: u la tr, anh cha thuong em :\"<<< nhap thu em mun ik" << endl;
		break;
	case 9:
		cout << "Bot said: oni oni, neu thuong em thi mua dum cai dong... a khong, nhap lai ik bn -_-*" << endl;
		break;

	}
}

void chooseMainMenu() {
	for (; true; ) {
		char tam = showMainMenu();
		switch (tam) {
		case 27:
			cout << "Dang thoat chuong trinh..." << endl;
			exit(0);
		case 49:
			chooseMenuInput();
			break;
		case 50:
			chooseMenuOutput();
			break;
		case 51:
			chooseMenuInsertAndRemove();
			break;
		case 52:
			chooseMenuSort();
			break;
		default:
			nhapSaiRoi();
			cout << endl;
			break;
		}
		//if (tam == 27) {
		//	exit(0);
		//}
	}
}
void chooseMenuInput() {
	for (; true; ) {
		char tam = showMenuInput();
		switch (tam) {
		case 27:
			cout << "Dang thoat chuong trinh..." << endl;
			exit(0);
		case 49:
			cout << "Nhap tu man hinh" << endl;
			break;
		case 50:
			cout << "Nhap phan so ngau nhien" << endl;
			break;
		case 51:
			cout << "Nhap tu tep(file)" << endl;
			break;
		case 48:
			cout << "Quay ve" << endl << endl;
			return;
		default:
			nhapSaiRoi();
			break;
		}
		//if (tam == 27) {
		//	exit(0);
		//}
		//if (tam == 48) {
		//	break;
		//}
	}
}
void chooseMenuOutput() {
	for (; true; ) {
		char tam = showMenuOutput();
		switch (tam) {
		case 27:
			cout << "Dang thoat chuong trinh..." << endl;
			exit(0);
		case 49:
			cout << "Xuat tren man hinh" << endl;
			break;
		case 50:
			cout << "Xuat vao tep(file)" << endl;
			break;
		case 48:
			cout << "Quay ve" << endl << endl;
			return;
		default:
			nhapSaiRoi();
			break;
		}
	}
}
void chooseMenuInsertAndRemove() {
	for (; true; ) {
		char tam = showMenuInsertAndRemove();
		switch (tam) {
		case 27:
			cout << "Dang thoat chuong trinh..." << endl;
			exit(0);
		case 49:
			cout << "Chen phan so" << endl;
			break;
		case 50:
			cout << "Xoa phan so" << endl;
			break;
		case 48:
			cout << "Quay ve" << endl << endl;
			return;
		default:
			nhapSaiRoi();
			break;
		}
	}
}
void chooseMenuSort() {
	for (; true; ) {
		char tam = showMenuSort();
		switch (tam) {
		case 27:
			cout << "Dang thoat chuong trinh..." << endl;
			exit(0);
		case 49:
			cout << "Sap xep tang dan" << endl;
			break;
		case 50:
			cout << "Sap xep giam dan" << endl;
			break;
		case 48:
			cout << "Quay ve" << endl << endl;
			return;
		default:
			nhapSaiRoi();
			break;
		}
	}
}

char showMainMenu() {
	system("cls");
	cout << "Main menu" << endl;
	cout << "******************************" << endl;
	cout << "* (Esc): Thoat chuong trinh  *" << endl;
	cout << "* 1. Nhap phan so            *" << endl;
	cout << "* 2. Xuat phan so            *" << endl;
	cout << "* 3. Chen hoac xoa phan so   *" << endl;
	cout << "* 4. Sap xep mang phan so    *" << endl;
	cout << "******************************" << endl;
	cout << "Moi chon chuc nang" << endl;
	return _getch();
}
char showMenuInput() {
	system("cls");
	cout << "Input" << endl;
	cout << "******************************" << endl;
	cout << "* (Esc): Thoat chuong trinh  *" << endl;
	cout << "* 1. Nhap tu man hinh        *" << endl;
	cout << "* 2. Nhap phan so ngau nhien *" << endl;
	cout << "* 3. Nhap tu tep(file)       *" << endl;
	cout << "* 0. Quay ve                 *" << endl;
	cout << "******************************" << endl;
	cout << "Moi chon chuc nang" << endl;
	return _getch();
}
char showMenuOutput() {
	system("cls");
	cout << "Output" << endl;
	cout << "******************************" << endl;
	cout << "* (Esc): Thoat chuong trinh  *" << endl;
	cout << "* 1. Xuat tren man hinh      *" << endl;
	cout << "* 2. Xuat vao tep(file)      *" << endl;
	cout << "* 0. Quay ve                 *" << endl;
	cout << "******************************" << endl;
	cout << "Moi chon chuc nang" << endl;
	return _getch();
}
char showMenuInsertAndRemove() {
	system("cls");
	cout << "Insert and remove" << endl;
	cout << "******************************" << endl;
	cout << "* (Esc): Thoat chuong trinh  *" << endl;
	cout << "* 1. Chen phan so            *" << endl;
	cout << "* 2. Xoa phan so             *" << endl;
	cout << "* 0. Quay ve                 *" << endl;
	cout << "******************************" << endl;
	cout << "Moi chon chuc nang" << endl;
	return _getch();
}
char showMenuSort() {
	system("cls");
	cout << "Sort" << endl;
	cout << "******************************" << endl;
	cout << "* (Esc): Thoat chuong trinh  *" << endl;
	cout << "* 1. Sap xep tang dan        *" << endl;
	cout << "* 2. Sap xep giam dan        *" << endl;
	cout << "* 0. Quay ve                 *" << endl;
	cout << "******************************" << endl;
	cout << "Moi chon chuc nang" << endl;
	return _getch();
}
