# ask for user input
height =int(input("How high do you want want your pyramid: "))

#logic
count_dot = height - 1
count_hash = 1

for i in range(height):
    while count_hash <= height:
        print((" " * count_dot) + ("#" * count_hash) + " " + ("#" * count_hash))
        count_dot -= 1
        count_hash += 1
