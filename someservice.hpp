#pragma once

#include "nifty.hpp"
#include <iostream>

namespace mpm
{
    class some_service
    {
    public:
        some_service() { std::cout << "some_serice ctor" << std::endl; }
        ~some_service() { std::cout << "some_serice dtor" << std::endl; }
        void do_a_thing() const
        {
            static uint32_t i = 0;
            std::cout << (i++) << std::endl;
        }
    };


    some_service& global_service = *reinterpret_cast<some_service*>(nifty_data<some_service>());


    namespace detail
    {
        static struct some_service_ginit
        {
            some_service_ginit()
            {
                if(0 == mpm::nifty_counter<some_service>()++)
                {
                    new (&global_service) some_service();
                }
            }


            ~some_service_ginit()
            {
                if(0 == --mpm::nifty_counter<some_service>())
                {
                    (&global_service)->~some_service();
                }
            }
        } shhhh;
    }
}
