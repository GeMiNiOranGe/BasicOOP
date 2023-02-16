#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robot {
public:
	Robot(string = "Robot", string = "NoName", int = 100, int = 0, int = 0);
	Robot(const Robot &);
	~Robot();

	void setName(string);
	void setUserName(string);
	void setEnergyLevel(int);
	void setLocationX(int);
	void setLocationY(int);

	string getName();
	string getUserName();
	int getEnergyLevel();
	int getLocationX();
	int getLocationY();

	void Charge();
	void Display();
	void coCheDiChuyen(int, int, int);
	virtual void diChuyen(int);
	bool Move(int);
private:
	string name, userName;
	int EnergyLevel, LocationX, LocationY;
};
class AdaptiveRobot:public Robot {
public:
	AdaptiveRobot(string = "AdaptiveRobot", string = "NoName", int = 100, int = 0, int = 0);
	~AdaptiveRobot();
	void diChuyen(int);
private:

};

int main() {
	int soLuongRobot, nangLuong, hoanhDoX, tungDoY, huongDiChuyenCuaRobot;
	string tenRobot, tenNguoiDieuKhien;
	vector<int> chuoiSoDiChuyen;
	cin >> soLuongRobot;
	Robot *pointerRobot;
	for (int i = 0; i < soLuongRobot; i++) {
		cin.ignore();
		getline(cin, tenRobot);
		getline(cin, tenNguoiDieuKhien);
		cin >> nangLuong >> hoanhDoX >> tungDoY;
		if (tenRobot.at(0) == 'A') {
			for (; cin >> huongDiChuyenCuaRobot;) {
				if (huongDiChuyenCuaRobot == -1) {
					break;
				}
				chuoiSoDiChuyen.push_back(huongDiChuyenCuaRobot);
			}
			pointerRobot = new AdaptiveRobot(tenRobot, tenNguoiDieuKhien, nangLuong, hoanhDoX, tungDoY);
			for (int i = 0; i < chuoiSoDiChuyen.size(); i++) {
				if (chuoiSoDiChuyen.at(i) == 4) {
					pointerRobot->Charge();
				}
				else if (0 <= chuoiSoDiChuyen.at(i) && chuoiSoDiChuyen.at(i) <= 3) {
					if (pointerRobot->getEnergyLevel() > 50) {
						for (int j = 0; j < 3; j++) {
							pointerRobot->coCheDiChuyen(chuoiSoDiChuyen.at(i), 1, 0);
							i++;
						}
						i--;
						pointerRobot->setEnergyLevel(pointerRobot->getEnergyLevel() - 12);
					}
					else if (pointerRobot->getEnergyLevel() > 20 && pointerRobot->getEnergyLevel() <= 50) {
						for (int j = 0; j < 2; j++) {
							pointerRobot->coCheDiChuyen(chuoiSoDiChuyen.at(i), 1, 0);
							i++;
						}
						pointerRobot->setEnergyLevel(pointerRobot->getEnergyLevel() - 9);
					}
					else {
						pointerRobot->coCheDiChuyen(chuoiSoDiChuyen.at(i), 1, 6);
					}
				}
			}
		}
		else {
			pointerRobot = new Robot(tenRobot, tenNguoiDieuKhien, nangLuong, hoanhDoX, tungDoY);
			for (; cin >> huongDiChuyenCuaRobot;) {
				if (huongDiChuyenCuaRobot == 4) {
					pointerRobot->Charge();
				}
				else if (0 <= huongDiChuyenCuaRobot && huongDiChuyenCuaRobot <= 3) {
					pointerRobot->diChuyen(huongDiChuyenCuaRobot);
				}
				if (huongDiChuyenCuaRobot == -1) {
					break;
				}
			}
		}
		pointerRobot->Display();
	}
	return 0;
}

//class Robot
Robot::Robot(string tenRobot, string tenNguoiDung, int mucNangLuongHienHanh, int toaDoX, int toaDoY) {
	this->name = tenRobot;
	this->userName = tenNguoiDung;
	this->EnergyLevel = mucNangLuongHienHanh;
	this->LocationX = toaDoX;
	this->LocationY = toaDoY;
}
Robot::Robot(const Robot & robotCanDuocSaoChep) {
	this->name = robotCanDuocSaoChep.name;
	this->userName = robotCanDuocSaoChep.userName;
	this->EnergyLevel = robotCanDuocSaoChep.EnergyLevel;
	this->LocationX = robotCanDuocSaoChep.LocationX;
	this->LocationY = robotCanDuocSaoChep.LocationY;
}
Robot::~Robot() {
}

void Robot::setName(string tenRobot) {
	this->name = tenRobot;
}
void Robot::setUserName(string tenNguoiDung) {
	this->userName = tenNguoiDung;
}
void Robot::setEnergyLevel(int mucNangLuongHienHanh) {
	this->EnergyLevel = mucNangLuongHienHanh;
}
void Robot::setLocationX(int toaDoX) {
	this->LocationX = toaDoX;
}
void Robot::setLocationY(int toaDoY) {
	this->LocationY = toaDoY;
}

string Robot::getName() {
	return this->name;
}
string Robot::getUserName() {
	return 	this->userName;
}
int Robot::getEnergyLevel() {
	return 	this->EnergyLevel;
}
int Robot::getLocationX() {
	return 	this->LocationX;
}
int Robot::getLocationY() {
	return 	this->LocationY;
}

void Robot::Charge() {
	this->EnergyLevel += 10;
}
void Robot::Display() {
	cout << "{" << getName() << "}:{" << getUserName() << "}" << endl;
	cout << "(" << getLocationX() << "," << getLocationY() << ")" << endl;
	cout << getEnergyLevel() << endl;
}
void Robot::coCheDiChuyen(int huongDiChuyen, int soBuocDiChuyen, int mucNangLuongBiTru) {
	if (huongDiChuyen == 0) {
		setLocationX(getLocationX() - soBuocDiChuyen);
	}
	else if (huongDiChuyen == 1) {
		setLocationX(getLocationX() + soBuocDiChuyen);
	}
	else if (huongDiChuyen == 2) {
		setLocationY(getLocationY() + soBuocDiChuyen);
	}
	else if (huongDiChuyen == 3) {
		setLocationY(getLocationY() - soBuocDiChuyen);
	}
	setEnergyLevel(getEnergyLevel() - mucNangLuongBiTru);
}
void Robot::diChuyen(int direction) {
	if (Move(direction)) {
		coCheDiChuyen(direction, 1, 5);
	}
}
bool Robot::Move(int direction) {
	if (getEnergyLevel() <= 0 && (direction < 0 && direction > 3)) {
		return false;
	}
	return true;
}

//class AdaptiveRobot
AdaptiveRobot::AdaptiveRobot(string tenRobot, string tenNguoiDung, int mucNangLuongHienHanh, int toaDoX, int toaDoY):Robot(tenRobot, tenNguoiDung, mucNangLuongHienHanh, toaDoX, toaDoY) {
}
AdaptiveRobot::~AdaptiveRobot() {
}

void AdaptiveRobot::diChuyen(int direction) {
	if (Move(direction)) {
		if (getEnergyLevel() > 50) {
			coCheDiChuyen(direction, 3, 12);
		}
		else if (getEnergyLevel() > 20 && getEnergyLevel() <= 50) {
			coCheDiChuyen(direction, 2, 9);
		}
		else {
			coCheDiChuyen(direction, 1, 6);
		}
	}
}
