#include "../prettier_tests.hh"

int global_var = 0;

class [[acp::singleton]]  A {
public:

	int a;

	A() {
		std::cout << "A created" << std::endl;
		a = ++global_var;
	}

	~A() {
		std::cout << "A destroyed" << std::endl;
	}
};

class [[acp::singleton]]  B {
public:
	int b;

	B() {
		std::cout << "B created-" << std::endl;
		b = ++global_var;
	}

	B(char c, double d) {
		std::cout << "B created+" << std::endl;
		b = d;
	}

	~B() {
		std::cout << "B destroyed" << std::endl;
	}
};

class C {
public:
	int c;

	C() {
		std::cout << "C created" << std::endl;
		c = ++global_var;
	}

	~C() {
		std::cout << "C destroyed" << std::endl;
	}
};

int main() {

	A* a1 = A::get_instance();
	A* a2 = A::get_instance();

	std::cout << "a1->a: " << a1->a << std::endl;
	std::cout << "a2->a: " << a2->a << std::endl;

	return 0;
}
