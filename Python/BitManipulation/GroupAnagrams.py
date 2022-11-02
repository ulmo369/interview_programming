hashmap = defaultdict(list)
for s in strs:
    # keys can be strings, bcz they are immutable.
    hashmap[str(sorted(s))].append(s) 