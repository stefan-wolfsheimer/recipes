import string
print string.lower("LowerCase")
print "LowerCase".lower()
print string.upper("uppercase")
print string.capitalize("uppercase")

print "|".join(string.split("a   b c\t \rd"))
print "|".join(string.split("a##b##c##d", "##"))
