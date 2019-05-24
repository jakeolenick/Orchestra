def convert(n):
    notes = [" ", 'C', 'd', 'D', 'e', 'E', 'F', 'g', 'G', 'a', 'A', 'b', 'B', 'C1', 'd1', 'D1']
    #print len (notes)
    keys =  ["-", 'a', 'w' , 's' , 'e', 'd', 'f', 't' , 'g' , 'y', 'h',  'u', 'j', 'k',  'o',  'l']
    #print len (keys)
    return keys [notes.index (n)]

def score (s):
    r = ""
    for c in s:
        r = r + (convert(c))
    return r

print score (["g", "g", "g", "g", "E", "E", "E", "E", "D", "D", "D", "D", "d", "d", "d", "d", "B", "B", "B", "B", "A", "A", "A", "A", "B", "B", "B", "B", "d", "d", "d", "d"])
