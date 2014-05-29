#include "someservice.hpp"
#include <iostream>

namespace mpm
{
    static char svc_data[sizeof(some_service)]
        __attribute__ ((aligned(__alignof__(some_service))));
    some_service& global_service = reinterpret_cast<some_service&>(svc_data);

    uint32_t some_service::instance_count;

    some_service::some_service()
    {
        instance_count++;
    }


    void
    some_service::do_a_thing() const
    {
        static uint32_t i = 0;
        std::cout << (i++) << std::endl;
    }


    namespace detail
    {
        namespace { uint32_t nifty_ctr; }


        some_service_ginit::some_service_ginit()
        {
            if(0 == nifty_ctr++)
            {
                new (&global_service) some_service();
            }
        }


        some_service_ginit::~some_service_ginit()
        {
            if(0 == --nifty_ctr)
            {
                (&global_service)->~some_service();
            }
        }
    }
}
