#include"d_forward_list.h"
#include<string>
int main()
{
    myar::list<int> f1;
    f1.push_front(3);
    f1.push_front(2);
    f1.push_front(5);
    f1.display();
}