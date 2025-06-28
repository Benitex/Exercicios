from lexer import ObsActLexer

string = '''
dispositivo: {Termometro, temperatura}
set temperatura = 40.
'''

string = '''
dispositivo: {celular, movimento}
dispositivo: {higrmetro, umidade}
dispositivo: {lampada, potencia}
dispositivo: {Monitor}
set potencia = 100 .
se umidade < 40 entao enviar alerta "Ar seco detectado"
Monitor .
-- Comentário de teste
se movimento == True entao ligar lampada senao desligar
lampada .
'''

lexer = ObsActLexer()
for token in lexer.tokenize(string):
  print(token)
