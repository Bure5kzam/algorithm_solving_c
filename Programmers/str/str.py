def f(n):
    print("Problem : " + str(n))
    if n == 27:
        url = "http://sharebook.kr"
        print(url.split(".")[1])        
        
#27 split
url = "http://sharebook.kr"
f(27)

print("27 : ".format(url))

#38 
a = "5,969,782,550"
print(a.replace(",", ""))

#40 strip
data = "   삼성전자 "
print(data.strip())

#41 42 
data = "AaBbCcDd"
print("default : ", data)
print("upper : ", data.upper())
print("lower : ", data.lower())