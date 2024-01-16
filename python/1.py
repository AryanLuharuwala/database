def id1(input_tag):
    y = input_tag % 26
    x = int(input_tag / 26)
    if x != 0 and y != 0:
        return chr(64 + x) + chr(64 + y)
    elif x == 0 and y != 0:
        return " " +chr(64 + y)
    elif y == 0 and x!=0:
       return " " +"Z"
    else:
       return "00"



x=input("Enter Name\n").split(",")
#print(x)
with open("store1.txt","w") as f:
    input_tag=0
    for y in x:
     if (input_tag%5==0):
         f.write("\n")
     f.write(" "+y+chr(2))
     input_tag+=1

print("A")
f.close()
my_list=['']*len(x)

with open("store1.txt","r") as f:
    count=0
    num=0
    for y in f.read():
            
            if (y==chr(2)):
                count+=1
                if(count>=len(my_list)):
                    my_list.append('')
            elif (y=="\n"):
                my_list[count]+=id1(0)
                last=1
            elif (y==" "and last!=1):
                my_list[count]+=id1(num)
                num+=1
                last=0
            else:
                my_list[count]+=y
                last=0

for z in my_list:
    print(z)
