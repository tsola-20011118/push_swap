import random

# 重複なし
def rand_ints_nodup(a, b, k):
  ns = []
  while len(ns) < k:
    n = random.randint(a, b)
    if not n in ns:
      ns.append(n)
  for i in ns:
   print(str(i), end=' ')
    #   puts(str(n) + ' ')
  return ns

# print(rand_ints_dup(0, 10, 7))

# rand_ints_nodup(0, 2147483647, 7)
# rand_ints_nodup(0, 2147483647, 7)
rand_ints_nodup(0, 600, 500)