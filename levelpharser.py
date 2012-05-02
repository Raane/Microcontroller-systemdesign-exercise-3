from sys import stdin

output = ""
for i in range(12):    
    for letter in stdin.readline():
        if not letter == chr(10) and not letter == ' ':
            output = output + chr(ord(letter) - 48)
    #print ""
#while(currentline = stdin.readline()):
for line in stdin.readlines():
    for coor in line.split(','):
        output = output + chr(int(coor))
print output,
