#pragma once

#include <stdint.h>

namespace mpm
{
    class some_service
    {
    public:
        void do_a_thing() const;
    };


    extern some_service& global_service;


    namespace detail
    {
        static class initializer
        {
        public:
            initializer()
            {
                if(0 == count++)
                    init_global();
            }


            ~initializer()
            {
                if(0 == --count)
                    cleanup_global();
            }
        private:
            static uint32_t count;
            static void init_global();
            static void cleanup_global();
        } shhhhh;
    }
}
