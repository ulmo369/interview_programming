s = "anagram"
t = "nagaram"

countS, countT = {}, {}

for i in range(len(s)):
    countS[s[i]] = 1 + countS.get(s[i], 0)
    countT[t[i]] = 1 + countT.get(t[i], 0)
for c in countS:
    if countS[c] != countT.get(c, 0):
        print(False)
print(True)
