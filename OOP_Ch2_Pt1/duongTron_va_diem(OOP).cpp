#include <iostream>
#include <cmath>

using namespace std;

const float pi = 3.14;

class duongTron;
class diem {
private:
	int x, y;
public:
	diem(int = 0, int = 0);

	friend istream& operator>>(istream&, diem&);
	friend ostream& operator<<(ostream&, diem);

	int getX();
	int getY();

	double tinhKhoangCach(diem);
	void diChuyen(int, int);
};

class duongTron {
private:
	diem center;
	double r;
public:
	duongTron(int = 0, int = 0, int = 0);

	friend istream& operator>>(istream&, duongTron&);
	friend ostream& operator<<(ostream&, duongTron);

	diem getDiem();
	double getBanKinh();

	float getChuVi();
	float getDienTich();
	void xacDinhViTriTuongDoiDiem(diem);
	void xacDinhViTriTuongDoi(duongTron);
};

int main() {
	duongTron t1, t2;
	cin >> t1 >> t2;
	cout << "duong tron 1 co chu vi la: " << t1.getChuVi() << endl;
	cout << "duong tron 1 co dien tich la: " << t1.getDienTich() << endl;
	cout << "duong tron 2 co chu vi la: " << t1.getChuVi() << endl;
	cout << "duong tron 2 co dien tich la: " << t1.getDienTich() << endl;
	t1.xacDinhViTriTuongDoi(t2);
	return 0;
}

//class diem
diem::diem(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}

istream& operator>>(istream& is, diem& _diem) {
	is >> _diem.x >> _diem.y;
	return is;
}
ostream& operator<<(ostream& os, diem _diem) {
	os << "(" << _diem.getX() << ", " << _diem.getY() << ")" << endl;
	return os;
}

int diem::getX() {
	return x;
}
int diem::getY() {
	return y;
}

double diem::tinhKhoangCach(diem _diem) {
	//return sqrt(pow(x - _diem.x, 2) + pow(y - _diem.y, 2));
	return sqrt(pow(x - _diem.getX(), 2) + pow(y - _diem.getY(), 2));
}
void diem::diChuyen(int dx, int dy) {
	this->x += dx;
	this->y += dy;
}

//class duong tron
duongTron::duongTron(int _x, int _y, int _r) {
	diem a(_x, _y);
	this->r = _r;
}

istream& operator>>(istream& in, duongTron& _duongTron) {
	cout << "Nhap toa do tam duong tron: ";
	in >> _duongTron.center;
	cout << "Nhap ban kinh duong tron: ";
	in >> _duongTron.r;
	return in;
}
ostream& operator<<(ostream& out, duongTron _duongTron) {
	cout << "Toa do tam duong tron la: ";
	out << _duongTron.center;
	cout << "Ban kinh: ";
	out << _duongTron.r << endl;
	return out;
}

diem duongTron::getDiem() {
	return this->center;
}
double duongTron::getBanKinh() {
	return this->r;
}

float duongTron::getChuVi() {
	return 2 * r * pi;
}
float duongTron::getDienTich() {
	return r * r * pi;
}

void duongTron::xacDinhViTriTuongDoiDiem(diem diemCanXacDinh) {
	double khoangCachTamVaDiem = this->center.tinhKhoangCach(diemCanXacDinh);
	if (khoangCachTamVaDiem > this->r) {
		cout << "Diem nam ngoai duong tron";
	}
	else if (khoangCachTamVaDiem == this->r) {
		cout << "Diem nam tren duong tron";
	}
	else {
		cout << "Diem nam trong duong tron";
	}
}
void duongTron::xacDinhViTriTuongDoi(duongTron duongTronCanXacDinh) {
	double khoangCach2Tam = this->center.tinhKhoangCach(duongTronCanXacDinh.getDiem());
	double banKinh2TamTru = abs(getBanKinh() - duongTronCanXacDinh.getBanKinh());
	double banKinh2TamCong = getBanKinh() + duongTronCanXacDinh.getBanKinh();
	if (banKinh2TamTru < khoangCach2Tam && khoangCach2Tam < banKinh2TamCong) {
		cout << "2 duong tron cat nhau";
	}
	else if (khoangCach2Tam == banKinh2TamCong) {
		cout << "2 duong tron tiep xuc ngoai";
	}
	else if (khoangCach2Tam == banKinh2TamTru) {
		cout << "2 duong tron tiep xuc trong";
	}
	else if (khoangCach2Tam > banKinh2TamCong) {
		cout << "2 duong tron ngoai nhau";
	}
	else if (khoangCach2Tam < banKinh2TamTru) {
		cout << "2 duong tron chua nhau";
	}
	else if (khoangCach2Tam == 0) {
		cout << "2 duong tron dong tam";
	}
}
