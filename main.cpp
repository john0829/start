#include "test.h"
#include "matrix.h"
#include "vector.h"
#include "enter.h"

int main()
{
    TestResult tr;
	TestRegistry::runAllTests(tr);

    return 0;
}

