#include <cassert>
#include "../my_code/hello.h"

using namespace std;

int main() {
    //hello
	int ret = sayHello();
    assert(ret == 0);
    return ret;
}
