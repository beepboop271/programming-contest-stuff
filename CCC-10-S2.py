numChars = input()
chars = []
for i in range(numChars):
    chars.append(raw_input().split())

encoded = raw_input()
decoded = ""

while len(encoded) > 1:
    for i in range(numChars):
        if encoded[:len(chars[i][1])] == chars[i][1]:
            decoded += chars[i][0]
            encoded = encoded[len(chars[i][1]):]

print(decoded)
