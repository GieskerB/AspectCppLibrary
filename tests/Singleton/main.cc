#include "../prettier_tests.hh"

int global_var = 0;

class [[acp::singleton]]  A {
public:

	int a;

	A() {
		std::cout << "A created\n";
		a = ++global_var;
	}

	~A() {
		std::cout << "A destroyed\n";
	}
};

class [[acp::singleton]]  B {
public:
	int b;

	B() {
		std::cout << "B created-\n";
		b = ++global_var;
	}

	B(char c, double d) {
		std::cout << "B created+\n";
		b = d;
	}

	~B() {
		std::cout << "B destroyed\n";
	}
};

class C {
public:
	int c;

	C() {
		std::cout << "C created\n";
		c = ++global_var;
	}

	~C() {
		std::cout << "C destroyed\n";
	}
};

int main() {

	acp::test::print_pretty_start("Singleton Test","Class A and B are singletons, C is not");
	acp::test::print_pretty_separator("Instantiation of all classes twice");

	A& a1 = A::get_instance();
	A& a2 = A::get_instance();

	B& b1 = B::get_instance();
	B& b2 = B::get_instance();

	C c1{};
	C c2{};

	acp::test::print_pretty_separator("Value comparison");

	std::cout << "a1.a: " << a1.a << '\n';
	std::cout << "a2.a: " << a2.a << '\n';

	std::cout << "b1.b: " << b1.b << '\n';
	std::cout << "b2.b: " << b2.b << '\n';

	std::cout << "c1.c: " << c1.c << '\n';
	std::cout << "c2.c: " << c2.c << '\n';

	acp::test::print_pretty_end();

	return 0;
}
