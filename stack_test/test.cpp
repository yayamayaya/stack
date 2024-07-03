#include "stack.h"


//#define DEBUG

struct test
{
    int num;
    char name[100];
};

int main(int argc, char const *argv[])
{
    Stack<int> stk = {};
    stk.Ctor(10, "logs/stack_int.log");
    stk.push(10);
    stk.push(15);
    stk.print(IN_CONSOLE);
    int num = 0;
    stk.pop(&num);
    stk.print(IN_FILE);
    stk.Dtor();

    Stack<double> stk2 = {};
    stk2.Ctor(2, "logs/stack_double.log");
    stk2.push(155);
    stk2.push(14.312512);
    stk2.push(-355.136135);
    stk2.print(IN_CONSOLE);
    stk2.pop(NULL);
    stk2.print(IN_CONSOLE);
    stk2.Dtor();

    struct test t1 = {14, "something in the first sentence\n"};
    struct test t2 = {11, "something in the second sentence\n"};

    Stack<test> stk3 = {};
    stk3.Ctor(2, "logs/stk_struct.log");
    stk3.push(t1);
    stk3.push(t2);
    stk3.print(IN_FILE);
    stk3.Dtor();

    return 0;
}
