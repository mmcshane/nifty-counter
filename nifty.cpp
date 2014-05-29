#include "someservice.hpp"
#include "otherthing.hpp"
#include <cassert>
#include <iostream>

int main()
{
    std::cout << "Get busy" << std::endl;
    mpm::get_busy(5);

    std::cout << "Do things" << std::endl;
    for(uint32_t i = 0; i < 10; i++)
    {
        mpm::global_service.do_a_thing();
    }
}
