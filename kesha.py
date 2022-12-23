def dp(now, added):
    global minimal
    if added >= minimal:
        return minimal
    if now == 1:
        minimal = min(minimal, added + 1)
        return added + 1
    if now % 2 == 0:
        return min(dp(now // 2, added), dp(now - 1, added + 1))
    return dp(now - 1, added + 1)


x = int(input())
minimal = x
print(dp(x, 0))
