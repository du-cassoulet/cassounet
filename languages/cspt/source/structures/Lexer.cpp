#include "Lexer.hpp"
#include "Position.hpp"
#include "Token.hpp"
#include "../constants/Keyword.hpp"

Lexer::Lexer(std::string _input, std::string _filename)
: input(_input), position(_input, _filename) {}

void Lexer::advance()
{
  position.advance();
}

void Lexer::make_identifier() {
  Position start = position.copy();
  std::string identifier = "";

  while (
    position.index < input.length() &&
    (
      ('a' <= input[position.index] && input[position.index] <= 'z') ||
      ('A' <= input[position.index] && input[position.index] <= 'Z') ||
      ('0' <= input[position.index] && input[position.index] <= '9') ||
      input[position.index] == '_'
    )
  )
  {
    identifier += input[position.index];
    advance();
  }

  if (Keyword::isKeyword(identifier))
  {
    tokens.push_back(Token(TokenType::TT_KEYWORD, identifier, start, position.copy()));
  }
  else
  {
    tokens.push_back(Token(TokenType::TT_IDENTIFIER, identifier, start, position.copy()));
  }
}

void Lexer::make_number() {
  Position start = position.copy();
  std::string number = "";
  bool dot = false;

  while (position.index < input.length() && ('0' <= input[position.index] && input[position.index] <= '9' || input[position.index] == '.' || input[position.index] == '_'))
  {
    if (input[position.index] == '_')
    {
      advance();
      continue;
    }

    if (input[position.index] == '.')
    {
      if (dot)
      {
        throw std::invalid_argument("Invalid number: " + number + ".");
      }

      dot = true;
      number += '.';
    }
    else
    {
      number += input[position.index];
    }

    advance();
  }

  tokens.push_back(Token(TokenType::TT_NUMBER, number, start, position.copy()));
}

void Lexer::make_string() {
  Position start = position.copy();
  std::string string = "";
  char quote = input[position.index];
  bool escape = false;
  advance();

  while (position.index < input.length() && input[position.index] != quote)
  {
    if (escape)
    {
      switch (input[position.index])
      {
        case 'n':
          string += '\n';
          break;

        case 't':
          string += '\t';
          break;

        default:
          string += input[position.index];
          break;
      }

      escape = false;
    }
    else
    {
      if (input[position.index] == '\\')
      {
        escape = true;
      }
      else
      {
        string += input[position.index];
      }
    }

    advance();
  }

  advance();

  tokens.push_back(Token(TokenType::TT_STRING, string, start, position.copy()));
}

void Lexer::make_equals() {
  Position start = position.copy();
  advance();

  if (position.index < input.length() && input[position.index] == '=')
  {
    advance();
    tokens.push_back(Token(TokenType::TT_EQUALS, start, position.copy()));
  }
  else
  {
    tokens.push_back(Token(TokenType::TT_EQUALS, start, position.copy()));
  }
}

void Lexer::make_or() {
  Position start = position.copy();
  advance();

  if (position.index < input.length() && input[position.index] == '|')
  {
    advance();
    tokens.push_back(Token(TokenType::TT_OR, start, position.copy()));
  }
  else
  {
    throw std::invalid_argument("Invalid character: '|'");
  }
}

void Lexer::make_and() {
  Position start = position.copy();
  advance();

  if (position.index < input.length() && input[position.index] == '&')
  {
    advance();
    tokens.push_back(Token(TokenType::TT_AND, start, position.copy()));
  }
  else
  {
    throw std::invalid_argument("Invalid character: '&'");
  }
}

void Lexer::make_not() {
  Position start = position.copy();
  advance();

  if (position.index < input.length() && input[position.index] == '=')
  {
    advance();
    tokens.push_back(Token(TokenType::TT_NEQUALS, start, position.copy()));
  }
  else
  {
    tokens.push_back(Token(TokenType::TT_NOT, start, position.copy()));
  }
}

void Lexer::make_lower_than() {
  Position start = position.copy();
  advance();

  if (position.index < input.length() && input[position.index] == '=')
  {
    advance();
    tokens.push_back(Token(TokenType::TT_LTE, start, position.copy()));
  }
  else
  {
    tokens.push_back(Token(TokenType::TT_LT, start, position.copy()));
  }
}

void Lexer::make_greater_than() {
  Position start = position.copy();
  advance();

  if (position.index < input.length() && input[position.index] == '=')
  {
    advance();
    tokens.push_back(Token(TokenType::TT_GTE, start, position.copy()));
  }
  else
  {
    tokens.push_back(Token(TokenType::TT_GT, start, position.copy()));
  }
}

void Lexer::make_tokens()
{
  while (position.index < input.length())
  {
    char current_char = input[position.index];

    if (current_char == ' ' || current_char == '\t' || current_char == '\n' || current_char == '\r')
    {
      advance();
      continue;
    }
    else if (('a' <= current_char && current_char <= 'z') || ('A' <= current_char && current_char <= 'Z') || current_char == '_')
    {
      make_identifier();
    }
    else if ('0' <= current_char && current_char <= '9')
    {
      make_number();
    }
    else if (current_char == '"'|| current_char == '\'') {
      make_string();
    }
    else if (current_char == '=')
    {
      make_equals();
    } else if (current_char == '|')
    {
      make_or();
    } else if (current_char == '&')
    {
      make_and();
    }
    else if (current_char == '!')
    {
      make_not();
    }
    else if (current_char == '<')
    {
      make_lower_than();
    }
    else if (current_char == '>')
    {
      make_greater_than();
    }
    else if (current_char == '+')
    {
      tokens.push_back(Token(TokenType::TT_PLUS, position.copy()));
      advance();
    }
    else if (current_char == '-')
    {
      tokens.push_back(Token(TokenType::TT_MINUS, position.copy()));
      advance();
    }
    else if (current_char == '*')
    {
      tokens.push_back(Token(TokenType::TT_MUL, position.copy()));
      advance();
    }
    else if (current_char == '/')
    {
      tokens.push_back(Token(TokenType::TT_DIV, position.copy()));
      advance();
    }
    else if (current_char == '%')
    {
      tokens.push_back(Token(TokenType::TT_MOD, position.copy()));
      advance();
    }
    else if (current_char == '^')
    {
      tokens.push_back(Token(TokenType::TT_POW, position.copy()));
      advance();
    }
    else if (current_char == '(')
    {
      tokens.push_back(Token(TokenType::TT_LPAREN, position.copy()));
      advance();
    }
    else if (current_char == ')')
    {
      tokens.push_back(Token(TokenType::TT_RPAREN, position.copy()));
      advance();
    }
    else if (current_char == ',')
    {
      tokens.push_back(Token(TokenType::TT_COMMA, position.copy()));
      advance();
    }
    else
    {
      throw std::invalid_argument("Invalid character: '" + std::string(1, current_char) + "'");
    }
  }

  advance();
  
  tokens.push_back(Token(TokenType::TT_EOF, position.copy(), position.copy()));
}

void Lexer::print_tokens()
{
  std::cout << "Tokens(" << std::endl;

  for (int i = 0; i < tokens.size(); i++)
  {
    Token token = tokens[i];
    std::cout << "  " + token.to_string() + (i < tokens.size() - 1 ? "," : "") << std::endl;
  }

  std::cout << ")" << std::endl;
}