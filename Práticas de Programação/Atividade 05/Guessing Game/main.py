import random

random_number = random.randint(1, 1023)
number_try = 0

tries_amount = 0

while random_number != number_try:
  number_try = int(input("Insira sua tentativa\n"))
  if random_number < number_try:
    print(-1)
  elif random_number > number_try:
    print(1)
  tries_amount += 1

print(0)
print(f"Foram usadas {tries_amount} tentativas")
