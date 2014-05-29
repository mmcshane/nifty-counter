#pragma once

#include <stdint.h>

namespace mpm
{
    template <typename T>
    uint32_t&
    nifty_counter()
    {
        static uint32_t ctr = 0;
        return ctr;
    }


    template <typename T>
    char*
    nifty_data()
    {
        static char svc_data[sizeof(T)]
            __attribute__ ((aligned(__alignof__(T))));
        return svc_data;
    }
}
