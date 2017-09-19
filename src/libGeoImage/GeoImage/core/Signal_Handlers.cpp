/**
 * @file    Signal_Handlers.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Signal_Handlers.hpp"

#include <iostream>


namespace GEO {

/************************************/
/*             UNIX ONLY!           */
/************************************/
#ifndef _WINDOWS

#include <execinfo.h>


/***********************************************/
/*      Stack Trace Signal Handler Method      */
/***********************************************/
void Stack_Trace_Signal_Handler(int sig)//, const char* app_name )
{
    int i, trace_size = 0;
    char **messages = (char **) NULL;
    void *stack_traces[16];

    trace_size = backtrace(stack_traces, 16);
    messages = backtrace_symbols(stack_traces, trace_size);

    /* skip the first couple stack frames (as they are this function and
       our handler) and also skip the last frame as it's (always?) junk. */
    // for (i = 3; i < (trace_size - 1); ++i)
    // we'll use this for now so you can see what's going on
    for (i = 0; i < trace_size; ++i) {
        std::cout << messages[i] << std::endl;

    }
    if (messages) { free(messages); }

    exit(0);
}

#else

void Stack_Trace_Signal_Handler(int sig)//, const char* app_name )
{
    std::cout << "NOT IMPLMENETED IN WINDOWS YET" << std::endl;
    exit(0);
}

#endif

} // End of GEO Namespace