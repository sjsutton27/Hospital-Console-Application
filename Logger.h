#ifndef HOSPITAL_ADMIN_CONSOLE_APP_LOGGER_H
#define HOSPITAL_ADMIN_CONSOLE_APP_LOGGER_H

#include <iostream>
#include <fstream>

class Logger {
public:
    bool debug(bool is_debug_mode) {
        debug_mode = is_debug_mode;
        return debug_mode;
    }

    void log(const std::string output) {
        if (debug_mode) {
            std::cout << output << std::endl;
        } else {
            std::ofstream ofs;
            ofs.open("hospital_system_log.txt",std::ios::app);
            ofs << output << std::endl;
            ofs.close();
        }
    }

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

private:
    Logger() = default;
    ~Logger() = default;
    Logger& operator=(Logger const& logger) = delete;
    Logger(Logger const& logger) = delete;

    bool debug_mode = false;
};

#endif //HOSPITAL_ADMIN_CONSOLE_APP_LOGGER_H
