#include <iostream>
#include <unistd.h>
#include <sys/types.h>
//void TestA() {
//    printf("b");
//}
using namespace std;

int main() {
    cout << "start" << endl;
    pid_t fork1 = fork();
    if (fork1 == 0) {
        cout << "son！" << endl;
        pid_t cpid = fork();
        if (cpid == 0)
            cout << "grandson" << endl;
        else if(cpid > 0)
            cout << "son" << endl;
        else if(cpid < 0)
            cout << "Error" << endl;
    }
    if (fork1 > 0)
        cout << "father" << endl;
    return 0;
}