#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
struct diem {
	int x, y;
};
int main() {
	diem A, B, C;
	float AB, AC, BC;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	cout << "(" << A.x << "," << A.y << ")" << " " << "(" << B.x << "," << B.y << ")" << " " << "(" << C.x << "," << C.y << ")" << endl;
	AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	AC = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
	BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
	//	printf("AB= %.3f, AC= %.3f, BC= %.3f", AB, AC, BC); //cach xuat = print nhiu gia tri cung 1 luc
	printf("%.3f\n%.3f\n%.3f\n", AB, AC, BC);
	if (AB + AC == BC || AB + BC == AC || AC + BC == AB) {
		cout << "-1";
	}
	else {
		float p = (AB + AC + BC) / 2; //p:  nua chu tam giac
		float S = sqrt(p*(p - AB)*(p - AC)*(p - BC));
		float CV = AB + AC + BC;
		printf("%.3f %.3f\n", S, CV);
	}
	system("pause");
	return 0;
}