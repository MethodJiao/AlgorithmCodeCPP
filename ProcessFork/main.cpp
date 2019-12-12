#include <iostream>
#include <unistd.h>

//void TestA() {
//    printf("b");
//}
using namespace std;

int main() {
    cout << "start" << endl;
    pid_t fork1 = fork();
    if (fork1 == 0) {
        cout << "child" << endl;
        pid_t cpid = fork();
        if (cpid == 0)
            cout << "childFork" << endl;
        else
            cout << "childForkError" << endl;
    }
    if (fork1 > 0)
        cout << "father" << endl;
    return 0;
}