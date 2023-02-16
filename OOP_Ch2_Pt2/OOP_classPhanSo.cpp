#include <iostream>

using namespace std;

/*code mau dung struct PhanSo khi viet ham rutGon
struct PhanSo {
	int tu, mau;
	//	C++ van hieu ko nhat thiet phai co toan tu nay
	void operator=(PhanSo a) {
		tu = a.tu;
		mau = a.mau;
	}
	//	gan so nguyen thanh phan so
	void operator=(int b) {
		tu = b;
		mau = 1;
	}
};
	//dung struct thi viet ham rutGon nhu 1 trong 2 ham duoi
PhanSo rutGon(PhanSo ps) {
	int temp = gcd(ps.tu, ps.mau);
	ps.tu /= temp;
	ps.mau /= temp;
	return ps;
}
void rutGon(PhanSo &ps) {
	int a = UCLN(ps.tu, ps.mau);
	ps.tu /= a;
	ps.mau /= a;
}*/

class Fraction {
private:
	int numerator, denominator;
public:
	Fraction(int = 0, int = 1);
	int getNumerator();
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	friend Fraction operator+(Fraction, Fraction);
	friend Fraction operator-(Fraction, Fraction);
	friend Fraction operator*(Fraction, Fraction);
	friend Fraction operator/(Fraction, Fraction);
	//Fraction& operator+=(Fraction&);
	friend Fraction& operator+=(Fraction&, Fraction);
	friend Fraction& operator-=(Fraction&, Fraction);
	friend Fraction& operator*=(Fraction&, Fraction);
	friend Fraction& operator/=(Fraction&, Fraction);
	friend bool operator>(Fraction, Fraction);
	friend bool operator<(Fraction, Fraction);
	friend bool operator==(Fraction, Fraction);
	friend bool operator>=(Fraction, Fraction);
	friend bool operator<=(Fraction, Fraction);
	friend bool operator!=(Fraction, Fraction);
	friend istream& operator>>(istream&, Fraction&);
	friend ostream& operator<<(ostream&, Fraction);
	Fraction inverseFraction();
	Fraction rutGon();
};

int GCD(int parameterOne, int parameterTwo);

int main() {
	Fraction FOne, FTwo;
	cin >> FOne >> FTwo;
	if (FOne.getDenominator() == 0 || FTwo.getDenominator() == 0) {
		cout << "Loi phep tinh..." << endl;
	}
	else {
		cout << "Ket qua tinh tong: " << FOne + FTwo << endl;
		cout << "Ket qua tinh hieu: " << FOne - FTwo << endl;
		cout << "Ket qua tinh tich: " << FOne * FTwo << endl;
		Fraction phanSoThuongTam = FOne / FTwo;
		if (phanSoThuongTam.getDenominator() == 0) {
			cout << "Ket qua tinh thuong: Loi phep tinh..." << endl;
		}
		else {
			cout << "Ket qua tinh thuong: " << FOne / FTwo << endl;
		}
	}
	return 0;
}

Fraction::Fraction(int _numerator, int _denominator) {
	this->numerator = _numerator;
	this->denominator = _denominator;
}

int Fraction::getNumerator() {
	return this->numerator;
}
int Fraction::getDenominator() {
	return this->denominator;
}

void Fraction::setNumerator(int _numerator) {
	this->numerator = _numerator;
}
void Fraction::setDenominator(int _denominator) {
	this->denominator = _denominator;
}

Fraction operator+(Fraction fractionOne, Fraction fractionTwo) {
	Fraction phanSoTong(
		fractionOne.numerator * fractionTwo.getDenominator() + fractionOne.denominator * fractionTwo.getNumerator(), 
		fractionOne.denominator * fractionTwo.getDenominator()
	);
	return phanSoTong.rutGon();
}
Fraction operator-(Fraction fractionOne, Fraction fractionTwo) {
	Fraction phanSoHieu(
		fractionOne.numerator * fractionTwo.getDenominator() - fractionOne.denominator * fractionTwo.getNumerator(), 
		fractionOne.denominator * fractionTwo.getDenominator()
	);
	return phanSoHieu.rutGon();
}
Fraction operator*(Fraction fractionOne, Fraction fractionTwo) {
	Fraction phanSoTich(fractionOne.numerator * fractionTwo.getNumerator(), fractionOne.denominator * fractionTwo.getDenominator());
	return phanSoTich.rutGon();
}
Fraction operator/(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne * fractionTwo.inverseFraction()).rutGon();
}

/*VD:
	a += b;
luu y:
neu tham chieu (dung &) cho thamSoMot, thi ket qua tra ve se duoc gan cho bien a
nguoc lai dung cho thamSoHai, thi ket qua tra ve se duoc gan cho bien b (giai thich vay thoi, ai khung ma di tham chieu thang nay)
cach 1: khong dung ham friend
Fraction& Fraction::operator+=(Fraction& fractionOne) {
	*this = *this + fractionOne;
	return *this;
}
cach 2: dung ham friend
chu y: tham chieu thang nao thi return thang do, nhu code phia duoi*/
Fraction& operator+=(Fraction& fractionOne, Fraction fractionTwo) {
	fractionOne = fractionOne + fractionTwo;
	return fractionOne;
}
Fraction& operator-=(Fraction& fractionOne, Fraction fractionTwo) {
	fractionOne = fractionOne - fractionTwo;
	return fractionOne;
}
Fraction& operator*=(Fraction& fractionOne, Fraction fractionTwo) {
	fractionOne = fractionOne * fractionTwo;
	return fractionOne;
}
Fraction& operator/=(Fraction& fractionOne, Fraction fractionTwo) {
	fractionOne = fractionOne / fractionTwo;
	return fractionOne;
}

bool operator>(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) > (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator<(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) < (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator==(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) == (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator>=(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) >= (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator<=(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) <= (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator!=(Fraction fractionOne, Fraction fractionTwo) {
	return !(fractionOne == fractionTwo);
}

istream& operator>>(istream& in, Fraction& _fraction) {
	in >> _fraction.numerator >> _fraction.denominator;
	return in;
}
ostream& operator<<(ostream& out, Fraction _fraction) {
	if (_fraction.getDenominator() == 1) {
		out << _fraction.getNumerator();
	}
	else {
		out << _fraction.getNumerator() << "/" << _fraction.getDenominator();
	}
	return out;
}

Fraction Fraction::inverseFraction() {
	Fraction inverseFractionTemporary(getDenominator(), getNumerator());
	return inverseFractionTemporary;
}
Fraction Fraction::rutGon() {
	int temp = GCD(numerator, denominator);
	numerator /= temp;
	denominator /= temp;
	return *this;
}

int GCD(int parameterOne, int parameterTwo) {
	parameterOne = abs(parameterOne);
	parameterTwo = abs(parameterTwo);
	if (parameterTwo == 0) {
		return parameterOne;
	}
	return GCD(parameterTwo, parameterOne % parameterTwo);
}