row1 = ["o.", "o.", "oo", "oo", "o.", "oo", "oo", "o.", ".o", ".o", "o.", "o.", "oo", "oo", "o.", "oo", "oo", "o.", ".o", ".o", "o.", "o.", ".o", "oo", "oo", "o."]
row2 = ["..", "o.", "..", ".o", ".o", "o.", "oo", "oo", "o.", "oo", "..", "o.", "..", ".o", ".o", "o.", "oo", "oo", "o.", "oo", "..", "o.", "oo", "..", ".o", ".o"]
row3 = ["..", "..", "..", "..", "..", "..", "..", "..", "..", "..", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "o.", "oo", "oo", ".o", "oo", "oo", "oo"]

line1 = ""
line2 = ""
line3 = ""

line = raw_input()
for char in line:
    if char == " ":
        line1 += ".."
        line2 += ".."
        line3 += ".."
    else:
        line1 += row1[ord(char)-65]
        line2 += row2[ord(char)-65]
        line3 += row3[ord(char)-65]
print line1
print line2
print line3
