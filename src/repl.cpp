#include "../include/repl.hpp"

void repl::init()
{
    while (this->state != repl_state::EXIT)
    {
        switch (this->state)
        {
        case (EXECUTE):
        {
            execute();
            break;
        }
        case (READ):
        {
            read();
            break;
        }
        case (PRINT):
        {
            print();
            break;
        }
        case (EXIT):
        {
            break;
        }
        }
    }
}

void repl::read()
{
    std::getline(std::cin, this->in_buffer);
    this->state = repl_state::EXECUTE;
}

void repl::execute()
{
    if (this->in_buffer == "exit")
    {
        this->state = repl_state::EXIT;
    }
    else
    {
        this->out_buffer = this->in_buffer;
        this->state = repl_state::PRINT;
    }
}
void repl::print()
{
    std::cout << this->out_buffer << std::endl;
    this->out_buffer = "";
    this->state = READ;
}