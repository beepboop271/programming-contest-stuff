import re
# dd/mm/yy
pattern1 = re.compile(r"[^a-zA-Z0-9]([0-3][0-9]/[0-1][0-9]/[0-9]{2})[^a-zA-Z0-9]")
# yy.mm.dd
pattern2 = re.compile(r"[^a-zA-Z0-9]([0-9]{2}\.[0-1][0-9]\.[0-3][0-9])[^a-zA-Z0-9]")
# Month dd, yy
pattern3 = re.compile(r"[^a-zA-Z0-9]([A-Z][a-z]{2,8} [0-3][0-9], [0-9]{2})[^a-zA-Z0-9]")
