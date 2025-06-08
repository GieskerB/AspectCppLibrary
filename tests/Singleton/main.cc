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


void AAA() {
	A a1{};
	A a2{};
	B b1{'c', 3.14};
	B b2{};
	// C c1{};
	// C c2{};

	B b3 = b1;

	A *a3 = new A();

	std::cout << "a1.a: " << a1.a << std::endl;
	std::cout << "a2.a: " << a2.a << std::endl;

	std::cout << "b1.b: " << b1.b << std::endl;
	std::cout << "b2.b: " << b2.b << std::endl;

	delete a3;
}

int main() {

	AAA();

	std::cout << "Global variable: " << global_var << std::endl;

	// A a1{};
	// A a2{};

	// std::cout << "a1.a: " << a1.a << std::endl;
	// std::cout << "a2.a: " << a2.a << std::endl;
	B b1{};
	B b2{};

	std::cout << "b1.b: " << b1.b << std::endl;
	std::cout << "b2.b: " << b2.b << std::endl;

	return 0;
}
