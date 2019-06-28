import numpy as np

def Fibonacci():
    first = 1
    prev = 1
    current = first + prev
    sum = current
    while (current < 4000000):
        current = current + prev
        if (current % 2 == 0):
            sum += current
        prev = current - prev
    return sum
print(Fibonacci())