#include "someservice.hpp"
#include "otherthing.hpp"
#include <cassert>
#include <iostream>

int main()
{
    assert(1 == mpm::some_service::instance_count &&
            "Expected 1 instance of mpm::some_service");

    std::cout << "Get busy" << std::endl;
    mpm::get_busy(5);

    std::cout << "Do things" << std::endl;
    for(uint32_t i = 0; i < 10; i++)
    {
        mpm::global_service.do_a_thing();
    }
}
