#python code to evaluate for leap years based on user number of attempts 
#
print("Number of trials to attempt: ")
attempts = int(input())
leap = False
i=0
while(i<attempts):
    print("Year to evaluate: ",end="")
    year = int(input())
    if year%4 ==0 and year % 100!=0:
        leap = True
    elif year%100==0 and year%400==0:
        leap=True
    print(leap)
    i+=1

