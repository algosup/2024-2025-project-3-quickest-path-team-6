#include "jsonParser.h"
#include <sstream>

std::string JsonParser::formatResponse(int travel_time, const std::vector<std::string>& path) {
    std::ostringstream oss;
    oss << "{ \"travel_time\": " << travel_time << ", \"path\": [";

    for (size_t i = 0; i < path.size(); ++i) {
        oss << "\"" << path[i] << "\"";
        if (i < path.size() - 1) oss << ", ";
    }

    oss << "] }";

    return oss.str();
}
