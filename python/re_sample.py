# re.match

pattern = r"hello"
text = "hello world"
match = re.match(pattern, text)

if match:
    print("Matched:", match.group())  # "hello"
else:
    print("No match")
================================================
# re.search

pattern = r"world"
text = "hello world"
search = re.search(pattern, text)

if search:
    print("Found:", search.group())  # "world"
else:
    print("Not found")
================================================
# re.findall

pattern = r"\d+"  # 숫자 패턴
text = "There are 12 apples and 34 oranges."
matches = re.findall(pattern, text)
print(matches)  # ['12', '34']
================================================
# re.finditer

pattern = r"\d+"
text = "There are 12 apples and 34 oranges."
matches = re.finditer(pattern, text)

for match in matches:
    print(f"Matched: {match.group()}, Start: {match.start()}, End: {match.end()}")
================================================
# re.sub

pattern = r"apples"
text = "There are 12 apples and 34 oranges."
result = re.sub(pattern, "bananas", text)
print(result)  # "There are 12 bananas and 34 oranges."
================================================
# re.split

pattern = r"\s+"  # 공백 패턴
text = "Split this string into words"
result = re.split(pattern, text)
print(result)  # ['Split', 'this', 'string', 'into', 'words']
================================================
패턴	설명
.	임의의 한 문자 (줄바꿈 제외)
\d	숫자 ([0-9])
\D	숫자가 아닌 문자 ([^0-9])
\w	문자/숫자/밑줄 ([a-zA-Z0-9_])
\W	문자/숫자/밑줄이 아닌 문자 ([^a-zA-Z0-9_])
\s	공백 문자 ([ \t\n\r\f\v])
\S	공백이 아닌 문자 ([^ \t\n\r\f\v])
*	0회 이상 반복
+	1회 이상 반복
?	0회 또는 1회
{m,n}	최소 m회, 최대 n회 반복
`	`
^	문자열의 시작
$	문자열의 끝
()	그룹화 및 캡처
