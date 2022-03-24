# Get change from the user
change_owed = float(input("How much change do you need?: "))

# create variables
count = 0
cents = change_owed*100

#print(cents) // Test

# Logic ()
while cents >= 25:
        count += 1
        cents -= 25
        
while cents >= 10:
        count += 1
        cents -= 10
        
while cents >= 5:
        count += 1
        cents -= 25
        
while cents >= 1:
        count += 1
        cents -= 1
        
print(f"Your count is: {count}")
