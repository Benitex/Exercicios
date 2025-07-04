from sly import Lexer
from sly.lex import Token

class ObsActLexer(Lexer):
  tokens = {
    "ID", "ID_PLUS",
    "DEVICE", "SET",
    "TURN_ON", "TURN_OFF",
    "ALERT", "TO_ALL",
    "IF", "ELSE", "THEN", "AND",
    "INT", "BOOL", "STRING",
    "LOGICAL_OPERATOR",
  }

  literals = {
    '=',
    '(', ')',
    '{', '}',
    '.', ',',
  }

  ignore = " \t"
  ignore_comment = r'--.*'

  DEVICE = "dispositivo:"
  SET = "set"
  TURN_ON = "ligar"
  TURN_OFF = "desligar"
  ALERT = "enviar alerta"
  TO_ALL = "para todos:"

  BOOL = r"True|False"
  ELSE = "senao"
  IF = "se"
  THEN = "entao"
  AND = "&&"

  ID = r"[a-zA-Z_]+"
  ID_PLUS = r"[a-zA-Z_][a-zA-Z0-9_]*"

  # Logical operators
  LOGICAL_OPERATOR = r'<=|>=|<|>|==|!='

  @_(r'\d+')
  def INT(self, token: Token) -> Token:
    token.value = int(token.value)
    return token

  @_(BOOL)
  def BOOL(self, token: Token) -> Token:
    token.value = (token.value == "True")
    return token

  @_(r'".*?"')
  def STRING(self, token: Token) -> Token:
    token.value = token.value[1:-1]
    return token

  # Line number tracking
  @_(r'\n+')
  def ignore_newline(self, t: Token) -> None:
    self.lineno += t.value.count('\n')

  def error(self, t: Token) -> None:
    print(f"Lexer error at {self.lineno}:")
    print(f'Invalid character "{t.value[0]}" found.')
    self.index += 1
