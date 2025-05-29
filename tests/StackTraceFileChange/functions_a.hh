#ifndef __ACP__TEST__STACK_TRACE_FILE_CHANGE_FUNCTIONS_A_HH__
#define __ACP__TEST__STACK_TRACE_FILE_CHANGE_FUNCTIONS_A_HH__

void foo() {
	throw std::runtime_error("foo-err");
}

void foobar () {foo();}


#endif // __ACP__TEST__STACK_TRACE_FILE_CHANGE_FUNCTIONS_A_HH__
