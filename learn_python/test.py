import re

f = open("C:\\Users\\leekj\\Desktop\\programming\\learn_python\\결과값.txt",'r')

text=""
while True:
    line = f.readline()
    if not line: break
    text+=line
b = re.compile('[가-힣]')

m = b.findall(text.split('\n')[1])
a=''.join(m)
print(a)

''.join(re.compile('[가-힣]').findall(text.split('\n')[1]))