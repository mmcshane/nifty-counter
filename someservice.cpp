#include "someservice.hpp"
#include <iostream>

namespace mpm
{
    static char svc_data[sizeof(some_service)]
        __attribute__ ((aligned(__alignof__(some_service))));
    some_service& global_service = reinterpret_cast<some_service&>(svc_data);


    void
    some_service::do_a_thing() const
    {
        static uint32_t i = 0;
        std::cout << (i++) << std::endl;
    }


    namespace detail
    {
        uint32_t initializer::count = 0;

        void
        initializer::init_global()
        {
            new (&global_service) some_service();
        }


        void
        initializer::cleanup_global()
        {
            (&global_service)->~some_service();
        }
    }
}
