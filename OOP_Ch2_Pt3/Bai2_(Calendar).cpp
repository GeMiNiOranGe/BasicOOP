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

class calendar:public thoiGian {
public:
	calendar();
	~calendar();

private:

};

calendar::calendar() {
	time_t bayGio;
	struct tm* timeinfo;
	tm* ltm = localtime(&bayGio);
	this->h = 1 + ltm->tm_hour;
	this->min = 1 + ltm->tm_min;
	this->sec = 1 + ltm->tm_sec;

}

calendar::~calendar() {
}
int main() {


	return 0;
}