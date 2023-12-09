from cs50 import get_int

#Prompt users for some input
points = get_int("how many points did you lose? ")

#Compare against mine
if points < 2:
    print("you lost fewer points than me.")

elif points > 2:
    print("you lost more point than me.")

else:
    print("You lost the same number of points as me.")
