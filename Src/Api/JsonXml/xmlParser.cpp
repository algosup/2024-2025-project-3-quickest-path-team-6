#include "xmlParser.h"
#include <sstream>

std::string XmlParser::formatResponse(int travel_time, const std::vector<std::string>& path) {
    std::ostringstream oss;
    oss << "<response>\n";
    oss << "  <travel_time>" << travel_time << "</travel_time>\n";
    oss << "  <path>\n";

    for (const auto& landmark : path) {
        oss << "    <landmark>" << landmark << "</landmark>\n";
    }

    oss << "  </path>\n";
    oss << "</response>\n";

    return oss.str();
}
