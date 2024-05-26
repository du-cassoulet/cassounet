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

  while (position.index < input.length() && ('a' <= input[position.index] && input[position.index] <= 'z'))
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

  while (position.index < input.length() && '0' <= input[position.index] && input[position.index] <= '9' || input[position.index] == '.')
  {
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
    else
    {
      throw std::invalid_argument("Invalid character: " + std::string(1, current_char));
    }
  }

  tokens.push_back(Token(TokenType::TT_EOF, position.copy()));
}

void Lexer::print_tokens()
{
  for (Token token : tokens)
  {
    std::cout << token.to_string() << std::endl;
  }
}