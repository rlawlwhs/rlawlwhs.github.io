import requests
import time
import random
# 세션 생성
session = requests.Session()

# 사용자 에이전트 설정
session.headers.update({
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36"
})

# 쿠키 추가
cookies = {
    "cookiesession1": "678A3E0FAB99ADD1163D89BAE4D674B5",
    "_ga": "GA1.1.2040283483.1725843918",
    "privacy_agreement": "true",
    "_ga_64GHK0036C": "GS1.1.1725843918.1.1.1725845324.0.0.0"
}

# 요청 헤더 설정
headers = {
    "authority": "",
    "method": "GET",
    "path": "",
    "scheme": "https",
    "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "accept-encoding": "gzip, deflate, br, zstd",
    "accept-language": "en-US,en;q=0.9,ko;q=0.8",
    "cache-control": "max-age=0",
    "priority": "u=0, i",
    "referer": "",
    "sec-ch-ua": '"Chromium";v="128", "Not;A=Brand";v="24", "Google Chrome";v="128"',
    "sec-ch-ua-mobile": "?0",
    "sec-ch-ua-platform": '"Windows"',
    "sec-fetch-dest": "document",
    "sec-fetch-mode": "navigate",
    "sec-fetch-site": "same-origin",
    "sec-fetch-user": "?1",
    "upgrade-insecure-requests": "1"
}

# GET 요청 보내기

for i in range(1, 289):
    response = session.get(
            
        url=f"",
        headers=headers
    )
    response.encoding = 'utf-8'
    print(f"{i} is {response.status_code}")

    with open(f"D:\\test\\test_{i}.txt", "w", encoding='utf-8') as f:
        f.write(response.text)
    time.sleep(random.randint(2, 5))

