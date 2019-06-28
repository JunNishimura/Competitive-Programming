import numpy as np

def calc(range, num1, num2):
    # np.arangeの終点はexclusive
    sum = 0
    list1 = np.arange(0, range, num1)
    list2 = np.arange(0, range, num2)
    list3 = np.arange(0, range, num1 * num2)
    sum += np.sum(list1)
    sum += np.sum(list2)
    sum -= np.sum(list3)
    return sum
print(calc(1000, 3, 5))