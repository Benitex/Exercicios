from sly import Parser
from lexer import ObsActLexer

class ObsActParser(Parser):
  tokens = ObsActLexer.tokens

  start = "program"

  def error(self, t):
    print(f"Syntax error at '{t.value}', line {t.lineno}.")

  @_("devices cmds")
  def program(self, p) -> dict:
    return {
      "devices": p.devices,
      "commands": p.cmds,
    }

  @_("device")
  def devices(self, p):
    return [p.device]

  @_("device devices")
  def devices(self, p):
    return [p.device] + p.devices

  @_("DEVICE '{' ID '}'")
  def device(self, p):
    return p.ID

  @_("DEVICE '{' ID ',' sensor_names '}'")
  def device(self, p):
    return (p.ID, p.sensor_names)

  @_("sensor_name")
  def sensor_names(self, p):
    return [p.sensor_name]

  @_("sensor_name ',' sensor_names")
  def sensor_names(self, p):
    return [p.sensor_name] + p.sensor_names

  @_("ID_PLUS", "ID")
  def sensor_name(self, p):
    return p[0]

  @_("cmd '.'")
  def cmds(self, p):
    return [p.cmd]

  @_("cmd '.' cmds")
  def cmds(self, p):
    return [p.cmd] + p.cmds

  @_("attribute", "act", "conditional")
  def cmd(self, p):
    return p[0]

  @_("SET sensor_name '=' var")
  def attribute(self, p):
    return ("set", p.sensor_name, p.var)

  @_("INT", "BOOL")
  def var(self, p):
    return p[0]

  @_("action ID")
  def act(self, p):
    return (p.action, p.ID)

  @_("TURN_ON", "TURN_OFF")
  def action(self, p):
    return p[0]

  @_("alert ')' ID")
  def act(self, p):
    return ("print", p.alert, p.ID)

  @_("alert ',' sensor_name ')' ID")
  def act(self, p):
    return ("print", p.alert, p.sensor_name, p.ID)

  @_("alert ')' TO_ALL device_names")
  def act(self, p):
    return ("print", p.alert, p.device_names)

  @_("alert ',' sensor_name ')' TO_ALL device_names")
  def act(self, p):
    return ("print", p.alert, p.sensor_name, p.device_names)

  @_("ALERT '(' STRING")
  def alert(self, p):
    return p.STRING

  @_("ID ',' ID")
  def device_names(self, p):
    return [p.ID0, p.ID1]

  @_("ID ',' device_names")
  def device_names(self, p):
    return [p.ID] + p.device_names

  @_("IF condition THEN act")
  def conditional(self, p):
    return ("if", p.condition, p.act)

  @_("IF condition THEN act ELSE act")
  def conditional(self, p):
    return ("if_else", p.condition, p.act0, p.act1)

  @_("sensor_name")
  def condition(self, p):
    return [p.sensor_name]

  @_("sensor_name LOGICAL_OPERATOR var")
  def condition(self, p):
    return [(p.sensor_name, p.LOGICAL_OPERATOR, p.var)]

  @_("sensor_name AND condition")
  def condition(self, p):
    return [p.sensor_name] + p.condition

  @_("sensor_name LOGICAL_OPERATOR var AND condition")
  def condition(self, p):
    return [(p.sensor_name, p.LOGICAL_OPERATOR, p.var)] + p.condition
