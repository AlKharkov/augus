with open('27_B.txt') as inlet:
    n = int(inlet.readline())
    distance, counts = [0], [0]
    pref, post = [0], [0]
    for i in range(n):
        a, b = map(int, inlet.readline().rstrip().split())
        distance.append(a)
        counts.append(b // 36 + (b % 36 != 0))
        pref.append(pref[-1] + counts[-1])
    pref.append(0)
    distance.append(0)
    counts.append(0)
    for i in range(n, 0, -1):
        post.append(post[-1] + counts[i])
    post.append(0)
    post.reverse()
    left, right = 0, 0
    for i in range(n + 1):
        right += distance[i] * counts[i]
    result = right
    for i in range(1, n + 1):
        left += pref[i - 1] * (distance[i] - distance[i - 1])
        right -= post[i] * (distance[i] - distance[i - 1])
        result = min(result, left + right)
    print(result)
