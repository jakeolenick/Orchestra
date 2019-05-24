def convert(n):
    notes = [" ", 'C', 'd', 'D', 'e', 'E', 'F', 'g', 'G', 'a', 'A', 'b', 'B', 'C1', 'd1', 'D1']
    #print len (notes)
    keys =  ["-", 'a', 'w' , 's' , 'e', 'd', 'f', 't' , 'g' , 'y', 'h',  'u', 'j', 'k',  'o',  'l']
    #print len (keys)
    return keys [notes.index (n)]

def score (s):
    n = 0
    r = ""
    for c in s:
        r = r + (convert(c)) + "\n"
        n = n + 1
    print n
    return r

print score (["D", "g", "A", "D1", "A", "C", "E", "A", "B", "D", "g", "B", "g", "A", "C", "g", "G", "B", "D", "G", "D", "g", "A", "D", "G", "B", "D", "G", "A", "C", "E", "A"])
