import sys
from string import maketrans

def mask_email(email):
    body = email[2:].strip()
    at = body.find('@')
    return 'E:' + body[0] + '*' * 5 + body[at-1:]

def mask_phone(phone):
    body = phone[2:].strip()
    table = maketrans('', '')
    body = body.translate(table, '- ()')
    # print body
    if body[0] == '+':
        start = '+'
        body = body[1:]
        mid = '-***-***-'
    else:
        start = ''
        mid = '***-***-'
    starts = '*' * (len(body) - 10)
    return 'P:' + start + starts + mid + phone[-4:]

for line in sys.stdin.readlines():
    line = line.strip()
    if line[0] == 'E':
        print mask_email(line)
    else:
        print mask_phone(line)

        ---------



import sys
from string import maketrans


def simplify(exp):
    if type(exp) == list:
        first = True
        nlist = []
        for i in xrange(len(exp)):
            if type(exp[i]) == list:
                if first:
                    nlist.extend(simplify(exp[i]))
                    first = False
                else:
                    nlist.append(simplify(exp[i]))
            else:
                nlist.append(exp[i])
        return nlist
    else:
        return [exp]


def reverse(exp):
    if type(exp) == list:
        exp = exp[::-1]
        for i in xrange(len(exp)):
            exp[i] = reverse(exp[i])
        return exp
    return exp


def parse(s):
    s = s.translate(maketrans('', ''), ' ')
    expstr, cmds = s.split('/')
    cmds = cmds.strip()
    ncmds = []
    prevS = ''

    for cmd in cmds:
        if cmd == 'R' or (cmd == 'S' and prevS != cmd):
            ncmds.append(cmd)
        prevS = cmd

    result = []
    stack = [result]

    for s in expstr:
        if s == '(':
            stack[-1].append([])
            stack.append(stack[-1][-1])
        elif s == ')':
            stack.pop()
        else:
            stack[-1].append(s)
    return result, ncmds


def extract(exp):
    if type(exp) == list:
        return '(' + ''.join(map(extract, exp)) + ')'
    else:
        return exp

# a = [
#     # 'A/',
#     # 'A B /S',
#     # '(AB) C((DE)F)/ R',
#     # '(AB) C((DE)F)/ RR',
#     '(AB) C((DE)F)/ SSS',
# ]
for line in sys.stdin.readlines():
# for line in a:
    exp, cmds = parse(line)
    for cmd in cmds:
        if cmd == 'S':
            exp = simplify(exp)
        else:
            exp = reverse(exp)
    print extract(exp)[1:-1]