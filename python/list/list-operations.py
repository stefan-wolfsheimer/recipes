lst = [1, 2, 3, 4, 5, 6, 7, 8]

print lst[0]                            # 1
print lst[7]                            # 8
print lst[-1]                           # 8
print lst[-2]                           # 7
print lst[:]                            # [1,2,3,4,5,6,7,8]
print lst[0:4]                          # [1,2,3,4]
print lst[2:]                           # [3,4,5,6,7,8]
print lst[:2]                           # [1,2]
print lst[-1:]                          # [8]
print lst[-2:]                          # [7,8]
print lst[:-1]                          # [1,2,3,4,5,6,7]
print lst[2:-1]                         # [3,4,5,6,7]
lst.append(9)
print lst                               # [1,2,3,4,5,6,7,8,9]
lst += [10, 11]
print lst                               # [1,2,3,4,5,6,7,8,9,10,11]
print lst + []                          # [1,2,3,4,5,6,7,8,9,10,11]
print lst + [12, 13]                    # [1,2,3,4,5,6,7,8,9,10,11,12,13]
print [a for a in lst]                  # [1,2,3,4,5,6,7,8,9,10,11]
print [a for a in lst if a % 3 == 0]    # [3,6,9]
