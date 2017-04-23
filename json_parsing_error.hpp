//parsing error for this project
#ifndef JSON_PARSING_ERROR_HPP
#define JSON_PARSING_ERROR_HPP

#include <exception>
#include <stdexcept>

class JSONParsingError: public std::runtime_error {
public:
  JSONParsingError(const std::string& message): std::runtime_error(message){};
};

#endif