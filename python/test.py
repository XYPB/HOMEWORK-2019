import re
a = '- 1.2 + 3.4'
b = re.match('^(-?) ?([0-9]+[.?][0-9]*) ?(\+|\-)? ?([0-9]+[.?][0-9]*)?', a)
print(b.group())
c = b.group(1) + b.group(2)
print(c)
d = 0
