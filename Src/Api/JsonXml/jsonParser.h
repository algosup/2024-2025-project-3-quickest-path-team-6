#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>
#include <vector>

class JsonParser {
public:
    static std::string formatResponse(int travel_time, const std::vector<std::string>& path);
};

#endif // JSON_PARSER_H
