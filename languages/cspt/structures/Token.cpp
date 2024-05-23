#include <string>

class Token {
  public:
    std::string name;
    std::string value;

    Token(std::string name, std::string value) {
      this->name = name;
      this->value = value;
    };

    Token(std::string name) {
      this->name = name;
      this->value = "";
    };

    std::string to_string() {
      if (value.length() == 0) {
        return "Token(" + name + ")";
      }

      return "Token(" + name + ", \"" + value + "\")";
    };
};