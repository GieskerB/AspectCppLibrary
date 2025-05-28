#ifndef __ACP__TESTS_STACK_TRACE_FALLBACK_FUNCTIONS_HH__
#define __ACP__TESTS_STACK_TRACE_FALLBACK_FUNCTIONS_HH__

void foo() {
	throw std::runtime_error("foo-err");
}

void foobar () {foo();}

void bar () {foobar();}

#endif // __ACP__TESTS_STACK_TRACE_FALLBACK_FUNCTIONS_HH__
