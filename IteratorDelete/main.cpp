#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;
struct People {
    int num;
    string name;
};

long hashString(string str) {
    char *charP = str.data();
    long hashCode = 0;
    for (; *charP; ++charP) {
        hashCode = 5 * hashCode + *charP;
        hashCode %= 2353639;
    }
    return hashCode;
}

int main() {
    //string a = "哈哈";
    size_t s;
    long a = hashString("我爱北京天安门，天安门上太阳升");
    sqrt(9);
    vector<int> numberVector;
    numberVector.push_back(1);
    numberVector.push_back(3);
    for (vector<int>::iterator iter = numberVector.begin(); iter != numberVector.end(); ++iter) {
        cout << *iter << " 地址" << &(*iter) << endl;
    }
    cout << endl;
    numberVector.insert(numberVector.begin() + 1, 2);

    for (vector<int>::iterator iter = numberVector.begin(); iter != numberVector.end(); ++iter) {
        cout << *iter << " 地址" << &(*iter) << endl;
    }
    cout << endl;
    list<int> numberList;
    numberList.push_back(1);
    numberList.push_back(3);

    for (list<int>::iterator iter = numberList.begin(); iter != numberList.end(); ++iter) {
        cout << *iter << " 地址" << &(*iter) << endl;
    }
    cout << endl;
    numberList.insert(numberList.begin(), 2);
    for (list<int>::iterator iter = numberList.begin(); iter != numberList.end(); ++iter) {
        cout << *iter << " 地址" << &(*iter) << endl;
    }
    cout << endl;
    numberList.sort();
    for (list<int>::iterator iter = numberList.begin(); iter != numberList.end(); ++iter) {
        cout << *iter << " 地址" << &(*iter) << endl;
    }
    vector<People> vecPeople;
    People people;
    people.name = "111";
    vecPeople.push_back(people);



//    for (vector<People>::iterator it = vecPeople.begin();it!=vecPeople.end();it++)
//    {
//
//    }
//    for (size_t i = 0 ;i<vecPeople.size();i++)
//    {
//        vecPeople[i]
//    }
//    for each（Prople var in  vecPeople ）
//    {
//        var.string = "123";
//    }



    return 0;
}