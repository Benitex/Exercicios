from lexer import ObsActLexer
from parser import ObsActParser

class ObsActToDartTranspiler:
  lexer = ObsActLexer()
  parser = ObsActParser()

  core_lib: str

  def __init__(self):
    with open("core.dart", "r") as file:
      self.core_lib = file.read()

  def export_file(self, source_path: str, destination_path: str) -> None:
    '''
    Transpiles an ObsAct code file to Dart and saves it to the specified destination path.
    :param source_path: Path to the source ObsAct code file.
    :param destination_path: Path where the transpiled Dart code will be saved.
    '''
    with open(source_path, "r") as file:
      obs_act_code = file.read()

    dart_code = self.transpile(obs_act_code)

    with open(destination_path, "w") as file:
      file.write(dart_code)

  def transpile(self, obs_act_code: str) -> str:
    dart_code = self.core_lib + "\n"
    dart_code += "void main() {\n"

    tokens = self.lexer.tokenize(obs_act_code)
    syntax_dict = self.parser.parse(tokens)

    device_names = []
    variables: dict[str, type] = {}

    for device in syntax_dict["devices"]:
      if isinstance(device, tuple):
        device_names.append(device[0])

        for sensor in device[1]:
          variables[sensor] = int
      else:
        device_names.append(device)

    for variable in variables:
      dart_code += f"  dynamic {variable} = 0;\n"

    for command in syntax_dict["commands"]:
      dart_code += self.__get_code_for_command(command, device_names, variables)

    dart_code += "}\n"

    return dart_code

  def __get_code_for_command(self, command: tuple, device_names: list[str], variables: dict[str, type]) -> str:
    if command[0] == "set":
      if command[1] not in variables:
        self.__error(f"{command[1]} was not declared as a variable.")

      if isinstance(command[2], bool):
        variables[command[1]] = bool
        return f"  {command[1]} = {str(command[2]).lower()};\n"
      elif isinstance(command[2], int):
        variables[command[1]] = int
        return f"  {command[1]} = {command[2]};\n"

    elif command[0] == "if" or command[0] == "if_else":
      code = "  if ("
      code += self.__get_code_for_conditions(command[1], variables)
      code += ") {\n"
      code += "  " + self.__get_code_for_command(command[2], device_names, variables).replace("\n", "\n  ")
      code += "}"

      if command[0] == "if_else":
        code += " else {\n"
        code += "  " + self.__get_code_for_command(command[3], device_names, variables)
        code += "  }\n"
      else:
        code += "\n"

      return code

    elif command[0] == "print":
      string = command[1]

      if len(string) > 100:
        self.__error(f"{string} exceeds character limit.")

      sensor_name = "null"
      if len(command) == 4: sensor_name = command[2]

      if sensor_name != "null" and sensor_name not in variables:
        self.__error(f"{sensor_name} was not declared as a sensor.")

      devices = []
      devices_index = len(command) - 1
      if isinstance(command[devices_index], list):
        devices = command[devices_index]
      else:
        devices = [command[devices_index]]

      devices_list = ", ".join(f'"{device}"' for device in devices)

      new_code = "  for (String deviceName in [%s]) {\n" % devices_list
      new_code += f'    alerta(deviceName, "{string}", {sensor_name}.toString());\n'
      new_code += "  }\n"
      return new_code

    elif command[0] == "ligar" or command[0] == "desligar":
      if command[1] not in device_names:
        self.__error(f"{command[1]} was not declared as a device.")

      return f'  {command[0]}("{command[1]}");\n'

  def __get_code_for_conditions(self, conditions: list, variables: dict[str, type]) -> str:
    code = ""

    for condition in conditions:
      if isinstance(condition, str):
        if condition not in variables:
          self.__error(f"{condition} was not declared as a sensor.")
        if variables[condition] != bool:
          self.__error(f"{condition}({variables[condition]}) is not a boolean value.")

        code += f"{condition} && "

      elif isinstance(condition, tuple):
        if condition[0] not in variables:
          self.__error(f"{condition[0]} was not declared as a sensor.")

        variable_type_1 = variables[condition[0]]
        variable_type_2 = type(condition[2])
        operator = condition[1]

        if variable_type_1 != variable_type_2:
          self.__error(f"Type mismatch in condition {condition}. {condition[0]}({variable_type_1}) and {condition[1]}{type(condition[2])} are not the same type.")

        if (variable_type_1 == bool or variable_type_2 == bool) and operator not in ["==", "!="]:
          self.__error(f"Invalid operator {condition[1]} for boolean values in condition {condition}.")

        if isinstance(condition[2], bool):
          # bool values should be lowercase in Dart
          code += f"{condition[0]} {operator} {str(condition[2]).lower()} && "
        else:
          code += f"{condition[0]} {operator} {condition[2]} && "

    code = code.strip(" && ")
    return code

  def __error(self, message: str) -> None:
    print(f"Semantic error: {message}")
    raise Exception(f"Semantic error: {message}")
