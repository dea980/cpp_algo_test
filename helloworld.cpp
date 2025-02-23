#include <iostream> // 전처리 지시자

/*
cpp 에서 함수 사용하고자 한다면...?
반드시 그 함수의 원형을 미리 정의해야함
include => import? 느낌임.
*/

using namespace std;
// using namespace std:: ==> import from...? python
// ";" 종결자
// explain namespace std

//if there is no using namespace std::
// "std::" prefix is used to access std namespace

int main() {
    // Print "Hello, cpp world!" to the console
    cout << "Hello, cpp world!" << endl;
    //std::cout << "Hello, cpp world!" << std::endl;
    return 0;
}

