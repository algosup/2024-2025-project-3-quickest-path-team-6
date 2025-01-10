#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <string>
#include <vector>

class XmlParser {
public:
    static std::string formatResponse(int travel_time, const std::vector<std::string>& path);
};

#endif // XML_PARSER_H
