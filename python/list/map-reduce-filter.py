a = [1, 2, 3, 4]
b = [4, 3, 2, 1]
print "a=" + str(a)
print "b=" + str(b)

a_pow_2 = map(lambda x: pow(x, 2), a)
a_plus_b = map(lambda x, y: x+y, a, b)
print "a^2=" + str(a_pow_2)
print "a+b=" + str(a_plus_b)
