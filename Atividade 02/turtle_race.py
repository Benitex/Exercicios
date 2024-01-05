from turtle import *
import random

def turtle_race(number_of_turtles: int):
  if number_of_turtles < 2 or number_of_turtles > 6:
    raise "invalid number of turtles"

  participants = []
  for n in range(number_of_turtles):
    participants.append(Turtle())

  for turtle_number in range(len(participants)):
    turtle = participants[turtle_number]
    turtle.penup()
    turtle.goto(0, 20 * turtle_number)
    turtle.pendown()

  for race_step in range(30):
    for turtle in participants:
      turtle.forward(random.randint(5, 10))

turtle_race(5)
