import time
from typing import KeysView
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

import pdb;

chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument('--ignore-certificate-errors-spki-list')
chrome_options.add_argument('--ignore-ssl-errors')
chrome_options.add_argument('--disable-web-security')
#self.driver = webdriver.Chrome(chrome_options=chrome_options)
driver = webdriver.Chrome(options=chrome_options)
vars = {}

driver.get("https://translate.google.co.kr/?sl=ko&tl=en&op=translate")

bf = []

with open("C:\\temp\\before.txt", "r", encoding="utf-8") as f:
    aa = f.readlines()
    for a in aa:
        bf.append("*" + a[:-1])

af = []
textarea = driver.find_element(By.XPATH, '//textarea[@aria-label="원본 텍스트"]')

for a in bf:
    if a == "*":
        continue
    af.append(a)
    time.sleep(1)
    
    textarea.clear()
    textarea.send_keys(a)

    time.sleep(2)

    span_elements = driver.find_elements(By.TAG_NAME, 'span')

    try:
        for span in span_elements:
            if span == None:
                continue

            

            if span.text == '':
                continue

            text = span.text

            if text[0] == '*':
                af.append(text)
    except:
        pass

    af.append('==========================================')

with open("C:\\temp\\after.txt", "w", encoding="utf-8") as f:
    for a in af:
        f.write(a + '\n')


