import pygame

class Authenticator:
  is_allowed_to_enter = False
  ask_for_email = True
  ask_for_password = False

  def draw(self, screen: pygame.Surface, font: pygame.font.Font, email: str, password: str):
    screen.fill("black")
    screen.blit(
      source = font.render("Insira seu e-mail", False, "white"),
      dest = (20, 20),
    )
    screen.blit(
      source = font.render(email, False, "white"),
      dest = (20, 50),
    )
    screen.blit(
      source = font.render("Insira sua senha", False, "white"),
      dest = (20, 100),
    )
    screen.blit(
      source = font.render(password, False, "white"),
      dest = (20, 130),
    )
    screen.blit(
      source = font.render("Senha encriptada", False, "white"),
      dest = (20, 160),
    )
    screen.blit(
      source = font.render(self.encrypt_with_caesar_cipher(password), False, "white"),
      dest = (20, 190),
    )
    screen.blit(
      source = font.render("Senha encriptada decriptada", False, "white"),
      dest = (20, 220),
    )
    screen.blit(
      source = font.render(self.decrypt_with_caesar_cipher(self.encrypt_with_caesar_cipher(password)), False, "white"),
      dest = (20, 250),
    )
    pygame.display.update()

  def is_email_valid(self, email: str) -> bool:
    return email[-8:] == "@puc.com"

  def is_password_safe(self, password: str) -> bool:
    if len(password) < 8: return False

    contains_number = False
    contains_letter_in_upper_case = False
    contains_letter_in_lower_case = False

    for character in password:
      if character >= '0' and character <= '9':
        contains_number = True
      elif character >= 'a' and character <= 'z':
        contains_letter_in_lower_case = True
      elif character >= 'A' and character <= 'Z':
        contains_letter_in_upper_case = True

    if not contains_number or not contains_letter_in_upper_case or not contains_letter_in_lower_case:
      return False

    return True

  def encrypt_with_caesar_cipher(self, password: str) -> str:
    if not self.is_message_valid(password):
      return "Senha inválida."
    else:
      encrypted_string = ''
      for character in password:
        if character >= 'x' and character <= 'z':
          encrypted_string += chr(ord('a') + (ord(character) - ord('x')))

        elif character >= '0' and character <= '9':
          encrypted_string += character
          # encrypted_string += chr(ord('0') + (ord(character) - ord('7')))

        else:
          encrypted_string += chr(ord(character) + 3)

      return encrypted_string

  def decrypt_with_caesar_cipher(self, password: str) -> str:
    if not self.is_message_valid(password):
      return "Senha inválida."
    else:
      decrypted_string = ''
      for character in password:
        if character >= 'a' and character <= 'c':
          decrypted_string += chr(ord('x') + (ord(character) - ord('a')))

        elif character >= '0' and character <= '9':
          decrypted_string += character

        else:
          decrypted_string += chr(ord(character) - 3)

      return decrypted_string

  def is_message_valid(self, message: str) -> bool:
    for character in message:
      if not (character >= '0' and character <= '9') and not (character >= 'a' and character <= 'z'):
        return False

    return True
