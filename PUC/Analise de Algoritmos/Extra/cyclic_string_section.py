# The problem is representing a 16 character window of a long string that is cyclically moving to the right

from time import sleep

long_string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit"
max_length = 16

current_index = 0
while True:
    pivot = current_index % len(long_string)

    space_to_use = len(long_string) - pivot
    if space_to_use > max_length: space_to_use = max_length

    result_string = long_string[pivot:pivot + space_to_use]
    if max_length - space_to_use > 0:
        result_string += " "
        result_string += long_string[0:max_length - space_to_use]

    print(result_string)

    current_index += 1
    sleep(.2)
