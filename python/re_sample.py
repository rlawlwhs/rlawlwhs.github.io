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
# re.compile

pattern = re.compile(r"\d+")  # 숫자 패턴을 컴파일
text = "123 apples and 456 oranges"

matches = pattern.findall(text)
print(matches)  # ['123', '456']

# 다른 메서드에서도 동일한 객체 사용 가능
for match in pattern.finditer(text):
    print(match.group())  # "123", "456"
================================================
# group 1

pattern = r"(\d+)-(\d+)-(\d+)"  # 날짜 패턴
text = "2025-01-03"

match = re.match(pattern, text)
if match:
    year, month, day = match.groups()
    print(f"Year: {year}, Month: {month}, Day: {day}")
================================================
# group 2

pattern = r"(\b\w+)\s+\1"  # 반복된 단어 찾기
text = "hello hello world"

match = re.search(pattern, text)
if match:
    print(f"Repeated word: {match.group(1)}")  # "hello"
================================================
# 비캡쳐그룹

pattern = r"(?:hello|hi) world"
text = "hello world"

match = re.match(pattern, text)
if match:
    print(match.group())  # "hello world"
================================================
# 조건부 매칭
(?...)를 사용하여 조건부 매칭을 구성할 수 있습니다.

(1) 긍정형 전방탐색 ((?=...))
패턴 뒤에 특정 조건이 오는 경우에만 매칭.

python
Copy code
pattern = r"\d+(?= apples)"  # "apples" 앞의 숫자
text = "123 apples and 456 oranges"

match = re.search(pattern, text)
print(match.group())  # "123"
(2) 부정형 전방탐색 ((?!...))
특정 조건이 오지 않는 경우에만 매칭.

python
Copy code
pattern = r"\d+(?! oranges)"  # "oranges" 앞이 아닌 숫자
text = "123 apples and 456 oranges"

match = re.search(pattern, text)
print(match.group())  # "123"
(3) 긍정형 후방탐색 ((?<=...))
패턴 앞에 특정 조건이 있는 경우에만 매칭.

python
Copy code
pattern = r"(?<=\$)\d+"  # "$" 뒤의 숫자
text = "Price: $45"

match = re.search(pattern, text)
print(match.group())  # "45"
(4) 부정형 후방탐색 ((?<!...))
특정 조건이 오지 않는 경우에만 매칭.

python
Copy code
pattern = r"(?<!\$)\d+"  # "$"가 없는 숫자
text = "Price: $45, Code: 123"

match = re.search(pattern, text)
print(match.group())  # "123"
================================================
# 플래그 옵션
플래그를 사용해 정규식 동작을 제어할 수 있습니다.

(1) re.IGNORECASE (re.I)
대소문자를 무시하고 매칭.

python
Copy code
pattern = r"hello"
text = "Hello World"

match = re.match(pattern, text, re.IGNORECASE)
print(match.group())  # "Hello"
(2) re.MULTILINE (re.M)
문자열의 각 줄의 시작(^)과 끝($)을 고려.

python
Copy code
pattern = r"^hello"
text = "hello world\nhello again"

matches = re.findall(pattern, text, re.MULTILINE)
print(matches)  # ['hello', 'hello']
(3) re.DOTALL (re.S)
.가 줄바꿈 문자를 포함하여 모든 문자를 매칭.

python
Copy code
pattern = r"hello.*world"
text = "hello\nworld"

match = re.search(pattern, text, re.DOTALL)
print(match.group())  # "hello\nworld"
================================================
# 고급 패턴 사용
(1) 이름 있는 그룹
(?P<name>...)로 그룹에 이름을 붙이고 참조 가능.

python
Copy code
pattern = r"(?P<year>\d+)-(?P<month>\d+)-(?P<day>\d+)"
text = "2025-01-03"

match = re.match(pattern, text)
if match:
    print(match.group("year"))  # "2025"
(2) 탐욕적 vs 비탐욕적 매칭
기본은 탐욕적 매칭 (*, + 등).
비탐욕적 매칭은 *?, +?, ??로 표현.
python
Copy code
text = "<div>content</div>"

# 탐욕적 매칭
greedy = re.search(r"<.*>", text)
print(greedy.group())  # "<div>content</div>"

# 비탐욕적 매칭
non_greedy = re.search(r"<.*?>", text)
print(non_greedy.group())  # "<div>"
================================================
# 커스텀 사용: 유효성 검사
(1) 정규식으로 파일 이름 필터링
python
Copy code
import re

files = ["file1.txt", "file2.csv", "file3.txt"]
pattern = r".*\.txt$"

txt_files = [f for f in files if re.match(pattern, f)]
print(txt_files)  # ['file1.txt', 'file3.txt']
(2) 특정 형식의 문자열 추출
python
Copy code
pattern = r"\b[A-Z]{2}\d{4}\b"  # 예: "AB1234"
text = "Codes: AB1234, XY5678, and CD0000."

matches = re.findall(pattern, text)
print(matches)  # ['AB1234', 'XY5678', 'CD0000']
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
