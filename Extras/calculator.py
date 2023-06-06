OPERATORS = ['+', '-', '*', '/']

parts = []
selectedOperator = ''

expression = input('Insira uma expressão com dois números separados por um sinal.\n')
expression = expression.replace(' ', '')

for operator in OPERATORS:
    if operator in expression:
        parts = expression.split(operator)
        selectedOperator = operator
        break

for partIndex in range(len(parts)):
    parts[partIndex] = int(parts[partIndex])

match selectedOperator:
    case '+':
        result = parts[0] + parts[1]
    case '-':
        result = parts[0] - parts[1]
    case '*':
        result = parts[0] * parts[1]
    case '/':
        result = parts[0] / parts[1]
    case _:
        raise "invalid operation"

print(result)
