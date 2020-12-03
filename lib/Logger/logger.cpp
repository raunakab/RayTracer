#include "logger.h"

void Logger::spacer(std::string const & title) {
    formatter<std::string>(spacer_id, lines+" "+title);
    return;
}
void Logger::spacer() {
    formatter<std::string>(spacer_id, lines);
    return;
}
void Logger::info(std::string const & msg) {
    formatter<std::string>(info_id, msg);
    return;
}
void Logger::warn(std::string const & msg) {
    formatter<std::string>(warn_id, msg);
    return;
}
void Logger::error(std::string const & msg, int const error_code) {
    formatter<std::string>(error_id, msg);
    std::cout
    << "exit code: " << error_code
    << "\naborted.\n";
    exit(error_code);
}

// void Logger::test(std::string const & msg) {
//     formatter("Test", msg);
//     return;
// }
