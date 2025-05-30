#include "../prettier_tests.hh"


void f1() {

}

void f2() {
	f1();
}
void f3() {
	f1();
	f2();
}
void f4() {

}
void f5() {

}
[[acp::err_code]]void f6() {
	f3();
	f4();
	f5();
}

int main() {
	f6();
	return 0;
}
