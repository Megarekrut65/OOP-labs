#ifndef PROGRAMS_H
#define PROGRAMS_H
#include "basic_program.h"

namespace cnm
{
    /*!
    *   \brief The program that sends messages with the period of time
    */
    class PeriodicProgram: public BasicProgram
    {
    private:

    public:
        /*!
        *   \brief Creates empty program
        *
        *   \param textes - reference to list of phrases to create messages
        */
        PeriodicProgram(const QVector<QString>& textes);
        /*!
        *   \brief Creates program with given parameters
        *
        *   Sending_type will be created by class name. Other parmeters will be empty.
        *
        *   \param textes - reference to list of phrases
        *   \param info - information about program and server names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        PeriodicProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        /*!
        *   \brief Sends messages with the period of time
        */
        void update() override;
        /*!
        *   \brief Creates same sending_type program with parameters
        *
        *   \param info - information about server and program names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
    /*!
    *   \brief The program that sends messages with random period of time
    */
    class RandomProgram: public BasicProgram
    {
    public:
        /*!
        *   \brief Creates empty program
        *
        *   \param textes - reference to list of phrases to create messages
        */
        RandomProgram(const QVector<QString>& textes);
        /*!
        *   \brief Creates program with given parameters
        *
        *   Sending_type will be created by class name. Other parmeters will be empty.
        *
        *   \param textes - reference to list of phrases
        *   \param info - information about program and server names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        RandomProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        /*!
        *   \brief Sends messages with random period of time
        */
        void update() override;
        /*!
        *   \brief Creates same sending_type program with parameters
        *
        *   \param info - information about server and program names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
    /*!
    *   \brief The program that sends messages after receiving
    */
    class AfterProgram: public BasicProgram
    {
    public:
        /*!
        *   \brief Creates empty program
        *
        *   \param textes - reference to list of phrases to create messages
        */
        AfterProgram(const QVector<QString>& textes);
        /*!
        *   \brief Creates program with given parameters
        *
        *   Sending_type will be created by class name. Other parmeters will be empty.
        *
        *   \param textes - reference to list of phrases
        *   \param info - information about program and server names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        AfterProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        /*!
        *   \brief Sends messages after receiving message
        */
        void update() override;
        /*!
        *   \brief Creates same sending_type program with parameters
        *
        *   \param info - information about server and program names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
    /*!
    *   \brief The program that sends messages after getting some type of messages
    */
    class WaitProgram: public BasicProgram
    {
    public:
        /*!
        *   \brief Creates empty program
        *
        *   \param textes - reference to list of phrases to create messages
        */
        WaitProgram(const QVector<QString>& textes);
        /*!
        *   \brief Creates program with given parameters
        *
        *   Sending_type will be created by class name. Other parmeters will be empty.
        *
        *   \param textes - reference to list of phrases
        *   \param info - information about program and server names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        WaitProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        /*!
        *   \brief Sends messages after getting some type of messages
        */
        void update() override;
        /*!
        *   \brief Creates same sending_type program with parameters
        *
        *   \param info - information about server and program names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
}

#endif // PROGRAMS_H
