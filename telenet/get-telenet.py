#!/usr/bin/env python3
# get telenet usage info from telemeter using selenium

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys

import re, sys, time

URL='https://www2.telenet.be/content/www-telenet-be/nl/klantenservice/raadpleeg-je-internetverbruik'

try:
    (_, username, password) = sys.argv
except ValueError:
    sys.stderr.write('Get Telenet bandwidth usage. Invalid arguments: <username> <password>\n')
    sys.exit(1)

chrome_options = Options()
chrome_options.add_argument("--headless")
chrome_options.add_argument("--window-size=1280x720")
chrome_options.add_argument("--disable-dev-shm-usage")
chrome_options.add_argument("--no-sandbox")

driver = webdriver.Chrome(options=chrome_options)

driver.get(URL)

driver.find_element_by_link_text('Aanmelden').click()

time.sleep(3)

driver.find_element_by_name('j_username').send_keys(username)
driver.find_element_by_name('j_password').send_keys(password + Keys.RETURN)

time.sleep(3)

used = None

try:
    elem = driver.find_element_by_class_name('currentusage').text

    match = re.search(r'(\d+,\d+) GB', elem)
    if match:
        used = match.group(1).replace(',', '.')
    else:
        sys.stderr.write('Error: Unparsable text ({})\n'.format(elem))

except:
    sys.stderr.write('Error: currentusage class not found. Check username/password\n')

if used:
    print(used)
else:
    driver.save_screenshot('/out/screenshot.png')
    sys.exit(1)

driver.close()
