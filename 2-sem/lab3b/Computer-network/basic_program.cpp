#include "basic_program.h"
#include "servers.h"
namespace cn
{
    std::shared_ptr<BasicProgram> BasicProgram::get_other_program()
    {
        if(type == ProgramType::SEND ||type == ProgramType::BOTH)
        {
            auto server = cn::Servers::get_random_server();
            if(server)
            {
                auto program = server->get_random_program();
                if(program.get() != this) return program;
            }
        }
        return nullptr;
    }
    QString BasicProgram::get_sending_type() const
    {
        return sending_type;
    }
    QString program_type_to_string(ProgramType type)
    {
        switch (type)
        {
            case ProgramType::SEND: return "Send";
            case ProgramType::RECEIVE: return "Receive";
        default:break;
        }
        return "Send and Receive";
    }
    ProgramType qstring_to_program_type(const QString& type)
    {
        if(type=="Send") return ProgramType::SEND;
        if(type=="Receive") return ProgramType::RECEIVE;
        return ProgramType::BOTH;
    }
    ProgramType BasicProgram::get_type() const
    {
        return type;
    }
    std::size_t BasicProgram::get_period() const
    {
        return period;
    }
    std::ostream& operator<<(std::ostream& out, const BasicProgram& program)
    {
        out << "Server-name="<<program.info.server_name << std::endl
            << "Program-name="<<program.info.program_name << std::endl
            << "Program-type="<<program_type_to_string(program.type) << std::endl
            << "Sending-type="<<program.sending_type <<std::endl
            << "Sending-period="<<program.period;
        return out;
    }
    std::istream& operator>>(std::istream& in, BasicProgram& program)
    {
        std::vector<std::string> parameters = {
            "Server-name=","Program-name=","Program-type=","Sending-type=","Sending-period="};
        QVector<QString> program_parametrs(parameters.size());
        for(std::size_t i = 0; i < parameters.size(); i++)
        {
            std::string line;
            std::getline(in, line);
            if(line.size()>parameters[i].size()&&
                    line.substr(0,parameters[i].size())==parameters[i])
            {
                program_parametrs[i] = QString(line.substr(parameters[i].size()).c_str());
            }
        }
        program.info.server_name = program_parametrs[0];
        program.info.program_name = program_parametrs[1];
        program.type = qstring_to_program_type(program_parametrs[2]);
        program.sending_type = program_parametrs[3];
        program.period = program_parametrs[4].toULongLong();
        return in;
    }
    BasicProgram::BasicProgram(const QVector<QString>& textes,
                               const ProgramInfo& info, ProgramType type,
                               std::size_t period, const QString& sending_type):
        textes{textes},info{info}, type{type}, period{period},sending_type{sending_type} {}
    BasicProgram::~BasicProgram()
    {
        buffer.clear();
    }
    ProgramInfo BasicProgram::get_info() const
    {
        return info;
    }
    QString BasicProgram::create_text()
    {
       return textes[rand()%textes.size()];
    }
    void BasicProgram::sleep_until_message_sending(const Message& message, std::shared_ptr<BasicProgram> other_program)
    {
        auto other_server = cn::Servers::get_server(other_program->get_info().server_name);
        auto this_server = cn::Servers::get_server(this->get_info().server_name);
        if(other_server.get() != this_server.get())
        {
            std::size_t download_speed = other_server->get_speed().download;
            std::size_t upload_speed = this_server->get_speed().upload;
            std::size_t load_speed = download_speed < upload_speed?download_speed:upload_speed;
            if(load_speed == 0) load_speed = 1;
            std::size_t time_sleep = message.get_message_size()/load_speed;
            time_sleep = std::size_t(double(time_sleep/
                                      cn::Servers::get_acceleration_factor()));
            if(time_sleep == 0) time_sleep = 1;
            for(std::size_t i = 0 ; i < time_sleep; i++)
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    void BasicProgram::send(std::shared_ptr<BasicProgram> other_program, MessageType type)
    {
        if(!other_program || this->type == ProgramType::RECEIVE) return;
        Message message(info, create_text(), type,other_program->get_info(),
                        rand()%SIZE_MAX);
        sleep_until_message_sending(message, other_program);
        other_program->receive(message);
    }
    void BasicProgram::receive(const Message& message)
    {
        if(this->type == ProgramType::SEND) return;
        std::lock_guard<std::mutex> lock(Servers::get_mutex());
        buffer.push_back(message);
    }
    QVector<Message> BasicProgram::get_messages() const
    {
        return buffer;
    }
    void BasicProgram::clear_buffer()
    {
        buffer.clear();
    }
    BasicProgram::BasicProgram( const QVector<QString>& textes,const QString& sending_type):
        textes{textes}, info{ProgramInfo()}, type{ProgramType::BOTH}, period{0},sending_type{sending_type}{}
}

