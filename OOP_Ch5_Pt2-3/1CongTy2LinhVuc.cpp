#include <iostream>
#include <string>

using namespace std;

const int soLinhVucMotCongTyDauTu = 2;

class IItem {
public:
	virtual float calculateTax() = 0;
	virtual float calculatePrice() = 0;
	virtual void getInfor() = 0;
private:
};

class ItemCollection {
public:
	IItem** objItems;
	ItemCollection();
	~ItemCollection();
	void getItem();
};

class FixedProperty {
public:
	FixedProperty(string = "chua xac dinh vi tri", bool = true, float = 0);
	FixedProperty(const FixedProperty &);
	~FixedProperty();

	string getLocation();
	bool getInCity();
	float getEstimateValue();

	void setLocation(string);
	void setInCity(bool);
	void setEstimateValue(float);

	void input();
	void output();
private:
	string Location;
	bool InCity;
	float EstimateValue;
};
class Vehicle {
public:
	Vehicle(string = "chua xac duoc bien so xe", float = 0, float = 0);
	Vehicle(const Vehicle &);
	~Vehicle();

	string getRegNumber();
	float getMaxVelocity();
	float getRootValue();

	void setRegNumber(string);
	void setMaxVelocity(float);
	void setRootValue(float);

	void input();
	void output();
private:
	string RegNumber;
	float MaxVelocity;
	float RootValue;
};

class House:public FixedProperty, public IItem {
public:
	House(string = "chua xac dinh vi tri", bool = true, float = 0, float = 0);
	House(const House &);
	~House();

	float getArea();

	void setArea(float);

	float calculateTax();
	float calculatePrice();
	void getInfor();

	void input();
	void output();
private:
	float Area;
};
class Bus:public Vehicle, public IItem {
public:
	Bus(string = "chua xac duoc bien so xe", float = 0, float = 0, int = 0);
	Bus(const Bus &);
	~Bus();

	int getNumSeats();

	void setNumSeats(int);

	float calculateTax();
	float calculatePrice();
	void getInfor();

	void input();
	void output();
private:
	int NumSeats;
};

int main() {
	//test.FixedProperty::output(); //Goi FixedProperty::output();
	cout << fixed;
	ItemCollection linhVuc;
	return 0;
}

//class ItemCollection
ItemCollection::ItemCollection() {
	objItems = new IItem*[soLinhVucMotCongTyDauTu];
	IItem* pointerHouse = new House("20 - duong Nguyen Van - Quan 15 - phuong 20 - tp Nguyen Pho", 0, 1800000000, 60);
	IItem* pointerBus = new Bus("BT-3K-186232", 180, 500000000, 50);
}

ItemCollection::~ItemCollection() {
}

void ItemCollection::getItem() {

}

//class FixedProperty
FixedProperty::FixedProperty(string viTri, bool noiThanhHayNgoaiO, float giaTienNiemYet) {
	this->Location = viTri;
	this->InCity = noiThanhHayNgoaiO;
	this->EstimateValue = giaTienNiemYet;
}
FixedProperty::FixedProperty(const FixedProperty & doiTuongCanSaoChep) {
	this->Location = doiTuongCanSaoChep.Location;
	this->InCity = doiTuongCanSaoChep.InCity;
	this->EstimateValue = doiTuongCanSaoChep.EstimateValue;
}
FixedProperty::~FixedProperty() {
}

string FixedProperty::getLocation() {
	return this->Location;
}
bool FixedProperty::getInCity() {
	return this->InCity;
}
float FixedProperty::getEstimateValue() {
	return this->EstimateValue;
}

void FixedProperty::setLocation(string viTri) {
	this->Location = viTri;
}
void FixedProperty::setInCity(bool noiThanhHayNgoaiO) {
	this->InCity = noiThanhHayNgoaiO;
}
void FixedProperty::setEstimateValue(float giaTienNiemYet) {
	this->EstimateValue = giaTienNiemYet;
}

void FixedProperty::input() {
	cout << "Nhap vi tri: ";
	getline(cin, this->Location);
	cout << "Noi thanh (nhap so 1) hay ngoai o (nhap so 0) (mac dinh la 1): ";
	cin >> this->InCity;
	cout << "Gia tien niem yet: ";
	cin >> this->EstimateValue;
}
void FixedProperty::output() {
	cout << "Vi tri: " << getLocation() << endl;
	if (getInCity()) {
		cout << "Noi thanh" << endl;
	}
	else {
		cout << "Ngoai o" << endl;
	}
	cout << "Gia niem yet: " << getEstimateValue() << endl;
}

//class Vehicle
Vehicle::Vehicle(string bienSoXe, float vanTocToiDa, float giaGoc) {
	this->RegNumber = bienSoXe;
	this->MaxVelocity = vanTocToiDa;
	this->RootValue = giaGoc;
}
Vehicle::Vehicle(const Vehicle & doiTuongCanSaoChep) {
	this->RegNumber = doiTuongCanSaoChep.RegNumber;
	this->MaxVelocity = doiTuongCanSaoChep.MaxVelocity;
	this->RootValue = doiTuongCanSaoChep.RootValue;
}
Vehicle::~Vehicle() {
}

string Vehicle::getRegNumber() {
	return this->RegNumber;
}
float Vehicle::getMaxVelocity() {
	return this->MaxVelocity;
}
float Vehicle::getRootValue() {
	return this->RootValue;
}

void Vehicle::setRegNumber(string bienSoXe) {
	this->RegNumber = bienSoXe;
}
void Vehicle::setMaxVelocity(float vanTocToiDa) {
	this->MaxVelocity = vanTocToiDa;
}
void Vehicle::setRootValue(float giaGoc) {
	this->RootValue = giaGoc;
}

void Vehicle::input() {
	cout << "Nhap bien so xe: ";
	getline(cin, this->RegNumber);
	cout << "Nhap van toc toi da cua xe: ";
	cin >> this->MaxVelocity;
	cout << "Nhap Gia goc cua xe: ";
	cin >> this->RootValue;
}
void Vehicle::output() {
	cout << "Bien so xe la: " << getRegNumber() << endl;
	cout << "Van toc toi da cua xe la: " << getMaxVelocity() << endl;
	cout << "Gia goc cua xe la: " << getRootValue() << endl;
}

//class House ke thua FixedProperty
House::House(string viTri, bool noiThanhHayNgoaiO, float giaTienNiemYet, float dienTich): FixedProperty(viTri, noiThanhHayNgoaiO, giaTienNiemYet) {
	this->Area = dienTich;
}
House::House(const House & doiTuongCanSaoChep) : FixedProperty(doiTuongCanSaoChep) {
	this->Area = doiTuongCanSaoChep.Area;
}
House::~House() {
}

float House::getArea() {
	return this->Area;
}

void House::setArea(float dienTich) {
	this->Area = dienTich;
}

float House::calculateTax() {
	if (getInCity()) {
		return (getEstimateValue() / 1000) * 5 + 5 * getArea();
	}
	else {
		return (getEstimateValue() / 1000) * 3;
	}
}
float House::calculatePrice() {
	return getEstimateValue() + calculateTax();
}
void House::getInfor() {
	cout << "(Thong tin nha cua)========================" << endl;
	output();
	cout << "Tien thue: " << calculateTax() << endl;
	cout << "Gia tri khi mua ban: " << calculatePrice() << endl;
	cout << "===========================================" << endl;
}

void House::input() {
	FixedProperty::input();
	cout << "Nhap dien tich nha: ";
	cin >> this->Area;
}
void House::output() {
	FixedProperty::output();
	cout << "Dien tich la: " << getArea() << endl;
}

//class Bus ke thua Vehicle
Bus::Bus(string bienSoXe, float vanTocToiDa, float giaGoc, int soGheNgoi): Vehicle(bienSoXe, vanTocToiDa, giaGoc) {
	this->NumSeats = soGheNgoi;
}
Bus::Bus(const Bus & doiTuongCanSaoChep) : Vehicle(doiTuongCanSaoChep) {
	this->NumSeats = doiTuongCanSaoChep.NumSeats;
}
Bus::~Bus() {
}

int Bus::getNumSeats() {
	return this->NumSeats;
}

void Bus::setNumSeats(int soGheNgoi) {
	this->NumSeats = soGheNgoi;
}

float Bus::calculateTax() {
	if (getNumSeats() <= 30) {
		return (getRootValue() / 1000) * 0.6;
	}
	else {
		return (getRootValue() / 1000) * 0.7;
	}
}
float Bus::calculatePrice() {
	return getRootValue() + calculateTax();
}
void Bus::getInfor() {
	cout << "(Thong tin xe buyt)========================" << endl;
	output();
	cout << "Tien thue: " << calculateTax() << endl;
	cout << "Gia tri khi mua ban: " << calculatePrice() << endl;
	cout << "===========================================" << endl;
}

void Bus::input() {
	Vehicle::input();
	cout << "Nhap so ghe ngoi: ";
	cin >> this->NumSeats;
}
void Bus::output() {
	Vehicle::output();
	cout << "So ghe ngoi la: " << getNumSeats() << endl;
}

