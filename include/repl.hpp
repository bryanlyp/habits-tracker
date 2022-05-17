#pragma once
#include <iostream>
#include <string>

enum repl_state
{
    EXECUTE,
    READ,
    PRINT,
    EXIT
};

class repl
{
public:
    void init();
    void read();
    void execute();
    void print();

private:
    repl_state state = READ;
    std::string in_buffer = "";
    std::string out_buffer = "";
};
