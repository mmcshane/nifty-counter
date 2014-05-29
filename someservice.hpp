#pragma once

#include <stdint.h>

namespace mpm
{
    class some_service
    {
    public:
        some_service();
        void do_a_thing() const;

        static uint32_t instance_count;
    };


    extern some_service& global_service;


    namespace detail
    {
        static struct some_service_ginit
        {
            some_service_ginit();
            ~some_service_ginit();
        } shhhh;
    }
}
