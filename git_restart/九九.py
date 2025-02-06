digits = range(1, 10)
print('|  |', end = '')
print('|'.join('%2d' % i for i in digits))
print('+' + '--+' * 10)
for a in digits:
    print('|%2d|' % a, end = '')
    print(''.join('%2d|' % (a * b) for b in digits))
