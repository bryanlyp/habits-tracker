#include "../include/habit_manager.hpp"

void habit_manager::init()
{
    
    bool save_file_found = false;
    if (save_file_found) {
        //TODO: implement file reading functions
    } else {
        std::cout << "No file found. Starting new session." << std::endl;
    }
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

void habit_manager::read()
{
    std::cout << "> "; // print prompt
    std::getline(std::cin, this->in_buffer);
    this->state = repl_state::EXECUTE;
}

void habit_manager::execute()
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
void habit_manager::print()
{
    std::cout << this->out_buffer << std::endl;
    this->out_buffer = "";
    this->state = READ;
}