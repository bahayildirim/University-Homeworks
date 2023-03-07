dict = {("Richard","Ringer"):["Germany",(2,11,27)],
        ("Eliud","Kipchoge"):["Kenya",(2,8,38)],
        ("Yavuz","Agrali"):["Turkey",(2,15,5)]}
loop = "Y"

while(loop == "Y"):
    name,surname = input("First and last name: ").split()
    for k,v in dict.items():
        if dict[k] == dict[(name,surname)]:
            print("Country: " + v[0])
            print("Finishing time in hours, minutes, seconds: " + str(v[1][0]) + ", " + str(v[1][1]) + ", " + str(v[1][2]))
            break
    loop=input("Do you want to continue Y/N? ")

sorted_time = []
dict_list = list(dict.items())
print(dict_list)
for i in range(3):
    highest = 0
    index = 0
    for j in range(len(dict_list)):
        if highest < (3600 * dict_list[j][1][1][0] + 60 * dict_list[j][1][1][1] + dict_list[j][1][1][2]):
            highest = 3600 * dict_list[j][1][1][0] + 60 * dict_list[j][1][1][1] + dict_list[j][1][1][2]
            index = j
    sorted_time.append(dict_list.pop(index))

print("Gold Medal: " + sorted_time[2][0][0] + " " + sorted_time[2][0][1] + ", " + sorted_time[2][1][0])
print("Silver Medal: " + sorted_time[1][0][0] + " " + sorted_time[1][0][1] + ", " + sorted_time[1][1][0])
print("Bronze Medal: " + sorted_time[0][0][0] + " " + sorted_time[0][0][1] + ", " + sorted_time[0][1][0])
print("Turkish athletes running under 3 hours: ", end=" ")
for i in sorted_time:
    if ((3600 * 3) > (3600 * i[1][1][0] + 60 * i[1][1][1] + i[1][1][2]) and (i[1][0] == "Turkey")):
        print(i[0][0] + " " + i[0][1], end=" ")