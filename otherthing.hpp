#pragma once

#include "someservice.hpp"


namespace mpm
{
    inline void get_busy()
    {
        for(uint32_t i = 0; i < 5; i++)
            mpm::global_service.do_a_thing();
    }
}
