#pragma once

#include "someservice.hpp"

namespace mpm
{
    inline void get_busy(uint32_t n)
    {
        for(uint32_t i = 0; i < n; i++)
        {
            mpm::global_service.do_a_thing();
        }
    }
}
