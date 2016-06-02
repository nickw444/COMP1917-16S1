#!/usr/bin/python2.7 -u

import random
import string
from random import randint

for i in range(1,100):
    nums = []
    while len(nums) < i:
        rand = randint(1,500)
        if rand not in nums:
            nums.append(rand)

    with open("{}.in".format(i), 'w') as f:
        out = '\n'.join(map(str,nums))
        f.write(out + '\n')

    with open("{}.in.expected".format(i), 'w') as f:
        out = 'Largest: {}'.format(max(nums))
        f.write(out + '\n')