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

def id2(input_tag):
    y = input_tag % 26
    x = int(input_tag / 26)
    if x != 0 and y != 0:
        return chr(96 + x) + chr(96 + y)
    elif x == 0 and y != 0:
        return " " +chr(96 + y)
    elif y == 0 and x!=0:
       return " " +"z"
    else:
       return "01"


def inputdata():
    x=input("Enter Name\n").split(",")
    #print(x)
    with open("store1.txt","w") as f:
        input_tag=0
        for y in x:
           if (input_tag%5==0):
                f.write("\n")
           f.write(y+chr(2))
           input_tag+=1
    f.close()
    return len(x)

def loaddata():
    with open("store1.txt","r") as f:
        count=0
        num=0
        my_list[0]+=str(5)
        for y in f.read():
                
                if (y=="\n"):
                    my_list[count]+=id2(0)
                    head=0
                    my_list[count]+=str(head)
                elif (y==chr(2)):
                    count+=1
                    if (len(my_list)<=count):
                        my_list.append('')
                    head+=1
                    my_list[count]+=str(head)
                else:
                    my_list[count]+=y

my_list=['']*inputdata()
loaddata()
for z in my_list:
    print(z)
