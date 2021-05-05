#ifndef PROGRAMS_H
#define PROGRAMS_H
#include <memory>
#include "message.h"
#include <sstream>
#include <mutex>
#include <thread>
#include <vector>
/*!
*   \brief computer network
*/
namespace cn
{
    template<typename T>
    class Program
    {
    private:
        std::stringstream buffer;
        const std::vector<std::string>& textes;
        std::string parent_name;
    public:
        Program(const std::vector<std::string>& textes, const std::string& parent_name);
        virtual void send(std::shared_ptr<Program<T>> other_program);
        virtual void receive(const Message& message);
    };
    template<typename T>
    class SendProgram: public Program<T>
    {
        void receive(const Message& message) override = 0;
    };
    template<typename T>
    class ReceiveProgram: public Program<T>
    {
        void send(std::shared_ptr<Program<T>> other_program) override = 0 ;
    };
    template<typename T>
    class SendReceiveProgram: public Program<T>{};
}
namespace cn
{
    template<typename T>
    Program<T>::Program(const std::vector<std::string>& textes, const std::string& parent_name):
        textes{textes},parent_name{parent_name}{}
}

#endif // PROGRAMS_H
