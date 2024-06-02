def accept_percentage():  
    n= int(input("Enter the number of Students : "))     
    for i in range(n):         
        percentage.append(float(input("Enter the percentage of Student :")))
    print(percentage)
    return percentage

def partition(percentage, low, high):
    pivot = percentage[high]
    i = low - 1
    for j in range(low, high):
        if percentage[j] <= pivot:
            i = i + 1
            (percentage[i], percentage[j]) = (percentage[j], percentage[i])
    (percentage[i + 1], percentage[high]) = (percentage[high], percentage[i + 1])
    return i + 1
  
def quick_sort(percentage, low, high):
    if low < high:
        pi = partition(percentage, low, high)
        quick_sort(percentage, low, pi - 1)
        quick_sort(percentage, pi + 1, high)

percentage=[]
f = 1
while f == 1:
 print("\n---------------------MENU---------------------")
 print("1. Accept Students percentage")
 print("2. Perform quick sort")
 print("3. Display top 5 scores")
 print("4. Exit\n")
 ch = int(input("Enter your choice from 1 to 4: "))
 if ch == 1:
     b=accept_percentage()
 elif ch == 2:
     print("Percentage of students in asending order : \n")
     quick_sort(percentage,0,len(percentage)-1)
     print(percentage)
 elif ch==3:
     print("Top 5 scores are:")
     i=-1
     while i>=-5:
         print(percentage[i])
         i=i-1
         
 elif ch == 4:
     print("Thanks for using program!!")
     f=0
 else:
     print("Wrong choice!!!")
     f = 0


