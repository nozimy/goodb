/**
 * Project OrganizeMe
 */


#ifndef _MACROS_H
#define _MACROS_H

namespace TMApp {

    class Macros {
    public:

/**
 * @param task
 */
        Task exec(Task task);
    private:
        Task ifTask;
        Task thenTask;
    };

}


#endif //_MACROS_H