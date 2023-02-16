#include <iostream>
#include <ctime>
using namespace std;
class thoiGian {
public:
	thoiGian();
	thoiGian(int, int, int);
	~thoiGian();
	void xuat12h();
	void xuat24h();
	friend istream& operator>>(istream&, thoiGian&);
	thoiGian operator+(int);
	thoiGian operator-(int);
	void cong2ThoiGian(thoiGian);
	void tru2ThoiGian(thoiGian);

private:
	int h, min, sec;
};

int main() {
	thoiGian dayLaThoiGianThu1, dayLaThoiGianThu2, thoiGianTru, thoiGianCong;
	int n;
	cout << "nhap thoi gian thu 1: ";
	cin >> dayLaThoiGianThu1;
	cout << "nhap thoi gian thu 2: ";
	cin >> dayLaThoiGianThu2;
	cout << "nhap giay cho phep tinh cua thoi gian thu 1: ";
	cin >> n;
	thoiGianCong = dayLaThoiGianThu1 + n;
	thoiGianTru = dayLaThoiGianThu1 - n;
	cout << "--------------------------------------------" << endl;
	cout << "thoi gian thu 1 sau khi cong them so giay" << endl;
	thoiGianCong.xuat12h();
	cout << endl;
	thoiGianCong.xuat24h();
	cout << endl;
	cout << "thoi gian thu 1 sau khi tru di so giay" << endl;
	thoiGianTru.xuat12h();
	cout << endl;
	thoiGianTru.xuat24h();
	cout << endl;
	cout << "--------------------------------------------" << endl;
	thoiGian dayLaThoiGianTam1 = dayLaThoiGianThu1;
	thoiGian dayLaThoiGianTam2 = dayLaThoiGianThu1;
	cout << "thoi gian thu 1 va thu 2 cong lai" << endl;
	dayLaThoiGianTam1.cong2ThoiGian(dayLaThoiGianThu2);
	dayLaThoiGianTam1.xuat12h();
	cout << endl;
	dayLaThoiGianTam1.xuat24h();
	cout << endl;
	cout << "thoi gian thu 1 va thu 2 tru di" << endl;
	dayLaThoiGianTam2.tru2ThoiGian(dayLaThoiGianThu2);
	dayLaThoiGianTam2.xuat12h();
	cout << endl;
	dayLaThoiGianTam2.xuat24h();
	cout << endl;
	cout << "--------------------------------------------" << endl;
	return 0;
}

thoiGian::thoiGian() {
	this->h = 0;
	this->min = 0;
	this->sec = 0;

	//time_t bayGio;
	//struct tm* timeinfo;
	//tm* ltm = localtime(&bayGio);
	//this->h = 1 + ltm->tm_hour;
	//this->min = 1 + ltm->tm_min;
	//this->sec = 1 + ltm->tm_sec;
}

thoiGian::thoiGian(int h, int m = 0, int s = 0) {
	this->h = h;
	this->min = m;
	this->sec = s;
}

thoiGian::~thoiGian() {
}

void thoiGian::xuat12h() {
	if (h > 12) {
		cout << h - 12 << ":" << min << ":" << sec << " pm";
	}
	else {
		cout << h << ":" << min << ":" << sec << " am";
	}
}

void thoiGian::xuat24h() {
	if (h > 23) {
		cout << "00:" << min << ":" << sec;
	}
	else {
		cout << h << ":" << min << ":" << sec;
	}
}

thoiGian thoiGian::operator+(int n) {
	thoiGian tam(0);
	tam.h = h;
	tam.min = min;
	tam.sec = sec;
	if (n + tam.sec >= 60) {
		tam.min++;
		n -= 60;
		if (tam.min > 59) {
			tam.h++;
			tam.min = 0;
		}
		while (n > 59) {
			tam.min++;
			n -= 60;
			if (tam.min > 59) {
				tam.min = 0;
				tam.h++;
			}
		}
	}
	if (tam.sec > 59) {
		tam.min++;
	}
	if (tam.min > 59) {
		tam.min = 0;
		tam.h++;
	}
	tam.sec += n;
	return tam;
}

thoiGian thoiGian::operator-(int n) {
	thoiGian tam(0);
	tam.h = h;
	tam.min = min;
	tam.sec = sec;
	if (n - tam.sec >= 60) {
		tam.min--;
		n -= 60;
		if (tam.min < 0) {
			tam.h--;
			tam.min = 59;
		}
		while (n > 59) {
			tam.min--;
			n -= 60;
			if (tam.min < 0) {
				tam.min = 59;
				tam.h--;
			}
		}
	}
	//if (tam.sec > 59) {
	//	tam.min++;
	//	tam.sec = 0;
	//}
	if (tam.min < 0) {
		tam.min = 59;
		tam.h++;
	}
	tam.sec += n;
	return tam;
}

void thoiGian::cong2ThoiGian(thoiGian a) {
	this->h = this->h + a.h + (this->min + a.min + (this->sec + a.sec) / 60) / 60;
	this->min = (this->min + a.min + (this->sec + a.sec) / 60) % 60;
	this->sec = (this->sec + a.sec) % 60;
}

void thoiGian::tru2ThoiGian(thoiGian a) {
	this->h = abs(this->h - a.h + (this->min - a.min + (this->sec - a.sec) / 60) / 60);
	this->min = abs((this->min - a.min + (this->sec - a.sec) / 60) % 60);
	this->sec = abs((this->sec - a.sec) % 60);
}

istream& operator>>(istream& is, thoiGian& _time) {
	is >> _time.h >> _time.min >> _time.sec;
	return is;
}
