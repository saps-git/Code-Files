
import json
from urllib.request import urlopen

#to fetch an api(json file)
with urlopen("https://finance.yahoo.com/webservice/v1/symbols/allcurrencies/quote?format=json") as response:
    source = response.read()


data = json.loads(source) #loading the json into a python obj
#print(json.dumps(data, indent=2))

usd_rates = dict()

for item in data['list']['resources']:
    name = item['resource']['fields']['name']
    price = item['resource']['fields']['price']
    usd_rates[name] = price

print(usd_rates['USD/EUR']) #to access a particilar key
print(50 * float(usd_rates['USD/INR']))
 