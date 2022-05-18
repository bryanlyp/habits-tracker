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

class habit_manager
{
public:
    //habit_manager class implements a read-execute-print loop
    //init() initiates the Repl, and is the only public function.
    //the read, execute and print functions are private and only intended for use by the specific class instance of habit_manager.
    void init();


private:
    repl_state state = READ;
    std::string in_buffer = "";
    std::string out_buffer = "";
    void read();
    void execute();
    void print();
};
