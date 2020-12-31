#include "vector"
template <typename T>
class MyTemplate
{
private:
    /* data */
    T m_T;

public:
    MyTemplate(T t /* args */) { m_T = t; };
    ~MyTemplate(){};
    T Get() { return m_T; };
};
template <>
class MyTemplate<bool>
{
private:
    /* data */
    bool m_T;

public:
    MyTemplate(bool t /* args */) { m_T = t; };
    ~MyTemplate(){};
    bool Get() { return m_T; };
};
int main()
{
    std::vector<int> vec;
    MyTemplate<int> tem(10);
    int aa = tem.Get();
    MyTemplate<int> temSpec(false);
    temSpec.Get();
}