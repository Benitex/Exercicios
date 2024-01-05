# Bandeira difícil

from turtle import *

turtle = Turtle()
colormode(255)

def draw_cuba_flag():
  # Fundo azul
  go_to_without_writing(-400, 280)
  turtle.fillcolor(0, 42, 143)
  turtle.begin_fill()
  draw_rectangle(turtle = turtle, width = 800, height = 560)
  turtle.end_fill()

  # Linhas brancas
  for y in [168, -56]:
    go_to_without_writing(-400, y)
    turtle.fillcolor("white")
    turtle.begin_fill()
    draw_rectangle(turtle = turtle, width = 800, height = 112)
    turtle.end_fill()

  # Triângulo vermelho
  go_to_without_writing(-400, 280)
  draw_red_triangle()

  # Estrela
  go_to_without_writing(-260, 20)
  turtle.fillcolor("white")
  turtle.begin_fill()
  draw_star(turtle)
  turtle.end_fill()

def go_to_without_writing(x: int, y: int):
  turtle.penup()
  turtle.goto(x, y)
  turtle.pendown()

# Desenha um retângulo a partir da posição da turtle, para a direita e baixo
def draw_rectangle(turtle: Turtle, width: int, height: int):
  x = turtle.xcor()
  y = turtle.ycor()

  turtle.goto(x + width, y)
  turtle.goto(x + width, y - height)
  turtle.goto(x, y - height)
  turtle.goto(x, y)

def draw_red_triangle():
  turtle.fillcolor(203, 21, 21)
  turtle.begin_fill()
  turtle.goto(0, 0)
  turtle.goto(-400, -280)
  turtle.end_fill()

# Desenha uma estrela com ponto central na localização da turtle
def draw_star(turtle: Turtle):
  x = turtle.xcor()
  y = turtle.ycor()

  turtle.penup()
  turtle.goto(x, y + 95)
  turtle.pendown()

  turtle.goto(x + 25, y + 25)
  turtle.goto(x + 95, y + 25)
  turtle.goto(x + 42, y - 17)
  turtle.goto(x + 42, y - 17)
  turtle.goto(x + 95, y - 95)
  turtle.goto(x, y - 45)

  turtle.goto(x - 95, y - 95)
  turtle.goto(x - 42, y - 17)
  turtle.goto(x - 42, y - 17)
  turtle.goto(x - 95, y + 25)
  turtle.goto(x - 25, y + 25)
  turtle.goto(x, y + 95)

draw_cuba_flag()
