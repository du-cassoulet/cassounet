#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include "./Token.cpp"
#include "../Keywords.cpp"

class Lexer {
private:
  char currentChar;

  static bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
  };  

  static bool is_digit(char c) {
    return c >= '0' && c <= '9';
  };

  void make_identifier() {
    std::string value = "";
    value += currentChar;

    char c = code[0];

    while (is_letter(c) || is_digit(c)) {
      value += c;
      code = code.substr(1);
      c = code[0];
    }


    if (std::find(keywords.begin(), keywords.end(), value) != keywords.end())
      tokens.push_back(Token("KEYWORD", value));
    else
      tokens.push_back(Token("IDENTIFIER", value));
  };

  void make_number() {
    std::string value = "";
    value += currentChar;

    char c = code[0];
    bool dot = false;

    while (is_digit(c) || c == '.') {
      if (c == '.') {
        if (dot) {
          throw std::invalid_argument("Invalid number format");
        } else {
          dot = true;
        }
      }

      value += c;
      code = code.substr(1);
      c = code[0];
    }

    tokens.push_back(Token("NUMBER", value));
  };

  void make_string() {
    std::string value = "";
    char quote = currentChar;
    bool escape = false;

    while (code[0] != quote || escape) {
      if (escape) {
        escape = false;
        value += code[0];
      } else if (code[0] == '\\') {
        escape = true;
      } else {
        value += code[0];
      }

      code = code.substr(1);
    }
    
    code = code.substr(1);

    tokens.push_back(Token("STRING", value));
  };

  void make_equals() {
    if (code[0] == '=') {
      code = code.substr(1);
      tokens.push_back(Token("EQUALS"));
    } else {
      tokens.push_back(Token("ASSIGN"));
    }
  };

public:
  std::string code;
  std::list<Token> tokens;

  Lexer(std::string code) {
    this->code = code;
  };

  void make_tokens() {
    while (code.length() > 0) {
      advance();
    }
  };

  void advance() {
    currentChar = code[0];
    code = code.substr(1);
  
    if (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
      return;
    } else if (is_letter(currentChar)) {
      make_identifier();
    } else if (is_digit(currentChar)) {
      make_number();
    } else if (currentChar == '"' || currentChar == '\'') {
      make_string();
    } else if (currentChar == '=') {
      make_equals();
    } else if (currentChar == ';') {
      tokens.push_back(Token("SEMICOLON"));
    } else if (currentChar == '{') {
      tokens.push_back(Token("LBRACE"));
    } else if (currentChar == '}') {
      tokens.push_back(Token("RBRACE"));
    } else if (currentChar == '(') {
      tokens.push_back(Token("LPAREN"));
    } else if (currentChar == ')') {
      tokens.push_back(Token("RPAREN"));
    } else if (currentChar == ',') {
      tokens.push_back(Token("COMMA"));
    } else if (currentChar == '+') {
      tokens.push_back(Token("PLUS"));
    } else if (currentChar == '-') {
      tokens.push_back(Token("MINUS"));
    } else if (currentChar == '*') {
      tokens.push_back(Token("MUL"));
    } else if (currentChar == '/') {
      tokens.push_back(Token("DIV"));
    } else {
      throw std::invalid_argument("Invalid character");
    }
  };

  void print_tokens() {
    for (Token token : tokens) {
      std::cout << token.to_string() << std::endl;
    }
  };
};
