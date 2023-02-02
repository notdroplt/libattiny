/**
 * \file thread.hpp
 * \author notdroplt (117052412+notdroplt@users.noreply.github.com)
 * \brief do those boards actually have more than a thread
 * \version 
 * \date 2022-12-24
 * 
 * because there probabaly isnt any kind of threading, it just "simulates" 
 * multiple of them, as they really do not exist
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "cstdint.hpp"
#include "type_traits.hpp"
namespace tinystd
{
    /**
     * \brief emulates a "thread, just for compatibility
     * 
     */
    class thread 
    {
    public:
        using id = unsigned char; // 
        using native_handler_type = void(*)(void *); //!< just a simple function

        thread(native_handler_type handler, void * args) {
            handler(args);
        }
        
        /**
         * @brief thread destructor
         * 
         */
        ~thread() = default;

        /**
         * @brief join thread (actually does nothing)
         * 
         */
        void constexpr join() noexcept { return; };

        /**
         * @brief returns if a thread is able to be joined (always, as it is already ran)
         *
         * @return true (always)
         */
        bool constexpr joinable() noexcept { return true; }

        /**
         * @brief detach a thread (impossible because there is only one thread on the mcu)
         * 
         */
        void constexpr detach() noexcept { return; }

        /**
         * @brief returns the thread ID (0 because it is the 1st thread)
         * 
         * @return 0 (always)
         */
        unsigned constexpr get_id() noexcept { return 0; }

        /**
         * @brief returns the amount of threads able to run in the microcontroller
         * 
         * @return 1 (always)
         */
        static constexpr unsigned hardware_concurrency() noexcept { return 1; }
    };
    
} // namespace tinystd
