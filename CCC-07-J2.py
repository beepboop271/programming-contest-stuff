translation = {
    "CU": "see you",
    ":-)": "I'm happy",
    ":-(": "I'm unhappy",
    ";-)": "wink",
    ":-P": "stick out my tongue",
    "(~.~)": "sleepy",
    "TA": "totally awesome",
    "CCC": "Canadian Computing Competition",
    "CUZ": "because",
    "TY": "thank-you",
    "YW": "you're welcome",
    "TTYL": "talk to you later",
}
possible = set(["CU", ":-)", ":-(", ";-)", ":-P", "(~.~)", "TA", "CCC", "CUZ", "TY", "YW", "TTYL"])

i = raw_input().strip()
while i != "TTYL":
    if i in possible:
        print translation.get(i)
    else:
        print i
    i = raw_input().strip()
print "talk to you later"
